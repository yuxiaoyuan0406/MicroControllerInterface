#include <reg52.H>

// keyboard port
#define		KEY_MAT		P1

typedef unsigned char	uint8_t;
typedef unsigned int	uint16_t;
typedef unsigned long	uint32_t;

static uint8_t receiveData;
static uint8_t sendBuff;

// soft delay
void delay_ms(uint16_t nCount);
void delay(uint16_t nCount);

// keyboard initiate
void KeyboardInit();

/**
	key matrix scan function
 * 
 ___________________________________________
|											|
|			col-0	col-1	col-2	col-3	|
|											|
|	row-1	S1		S2		S3		S4		|
|											|
|	row-2	S5		S6		S7		S8		|
|											|
|	row-3	S9		S10		S11		S12		|
|											|
|	row-4	S13		S14		S15		S16		|
|___________________________________________|

 * @param	unsigned char row		:	row number, 0 ~ 3
 * @return	unsigned char			:	col number, 1 ~ 4
 **/
uint8_t scan_col(uint8_t col);

void UART_init();

void UART_send_byte(uint8_t dat);

int main()
{
	uint8_t matrix_row	= 0,			// 按键按下的行
			matrix_col	= 0;			// 按键按下的列
	uint8_t picked = 0;					// 按下的按键编号(1 ~ 16)
	
	KeyboardInit();
	UART_init();
	
	matrix_row = 0;
	picked = 0;
	
	P2 = 0xFF;
	
	while(matrix_row == 0)
	{
		for(matrix_col = 0; matrix_col < 4 && matrix_row == 0; matrix_col++)
		{
			matrix_row = scan_col(matrix_col);
		}
	}
	
	picked = ((matrix_row - 1) << 2) + matrix_col;
	
	P2 = ~picked;
	
	UART_send_byte(picked);
	
	while(1)
		;
}

void delay_ms(uint16_t nCount)
{
	uint16_t i;
	for(; nCount; nCount--)
		for(i = 0; i < 123; i++)
			;
}

void delay(uint16_t nCount)
{
	for(; nCount; nCount--)
		;
}

// key matrix scan function
uint8_t scan_col(uint8_t col)		// 列扫描
{
	switch(col)
	{
		case 0:
			KEY_MAT = ~0x8;		// ~0000 1000
			break;
		case 1:
			KEY_MAT = ~0x4;		// ~0000 0100
			break;
		case 2:
			KEY_MAT = ~0x2;		// ~0000 0010
			break;
		case 3:
			KEY_MAT = ~0x1;		// ~0000 0001
			break;
		default:
			return 0;
	}
	delay(0x03);
	if((~KEY_MAT) & 0x80)				// 1000 0000
	{
		while((~KEY_MAT) & 0x80)
			;
		return 1;
	}
	else if((~KEY_MAT) & 0x40)			// 0100 0000
	{
		while((~KEY_MAT) & 0x40)
			;
		return 2;
	}
	else if((~KEY_MAT) & 0x20)			// 0010 0000
	{
		while((~KEY_MAT) & 0x20)
			;
		return 3;
	}
	else if((~KEY_MAT) & 0x10)			// 0001 0000
	{
		while((~KEY_MAT) & 0x10)
			;
		return 4;
	}
	else
		return 0;
}

// keyboard initiate
void KeyboardInit()
{
	KEY_MAT = 0x00;
}

void UART_init()
{
	SCON = 0X50;			//设置为工作方式1
	TMOD |= 0X20;			//设置计数器工作方式2
	PCON = 0X80;			//波特率加倍
	TH1 = 0XF3;				//计数器初始值设置，注意波特率是4800的
	TL1 = 0XF3;
	ES = 1;						//打开接收中断
	EA = 1;						//打开总中断
	TR1 = 1;					//打开计数器
}

void UART_send_byte(uint8_t dat)
{
	SBUF = dat;
	while(TI == 0)
		;
	TI = 0;
}

void Usart() interrupt 4
{
	if(RI == 1)
	{
		receiveData=SBUF;//出去接收到的数据
		P2 = ~SBUF;
		RI = 0;//清除接收中断标志位
		return;
	}
}
