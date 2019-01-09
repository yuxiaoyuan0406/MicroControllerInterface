#include <reg52.H>

#define		SOFT_DELAY()		delay(0xFFFF)

// led matrix port
#define		ROW					P0	//行寄存器

// matrix row operator
#define		ENABLE_ROW(pos)		ROW = ~(1 << pos)
#define		DISABLE_ROW()		ROW = 0xff
#define		TOGGLE_ROW()		ROW = ~ROW

// soft delay
#define		BUFFER_DELAY()		delay(0x03)

typedef unsigned char	uint8_t;
typedef unsigned int	uint16_t;
typedef unsigned long	uint32_t;

// HC595 port
sbit Out	=	P3 ^ 4;		//串行数据线
sbit R_CLK	=	P3 ^ 5;		//数据并行输出控制
sbit S_CLK	=	P3 ^ 6;		//串行时钟线

uint8_t picked = 0;			//	记录收到的数据, 初始化为0

// soft delay
void delay(uint16_t nCount);
void delay_ms(uint16_t nCount);

// HC595 buffer function
void BufferSendData(uint8_t SendVal);

// HC595 operator
#define		ENABLE_BUFFER()		\
do{								\
	R_CLK=0;					\
	BUFFER_DELAY();				\
	R_CLK=1;					\
}while(0)

#define 	DISABLE_BUFFER()	\
do{								\
	BufferSendData(0x00);		\
	ENABLE_BUFFER();			\
}while(0)

// initiate
void MatrixInit();

// display
void Display_figure(uint8_t * fig);

// initiate
void UART_init();

static unsigned char code figure_of_number[][8] =
{
	0x00, 0x00, 0x3C, 0x42, 0x42, 0x3C, 0x00, 0x00,		// number 0
	0x00, 0x00, 0x02, 0x7E, 0x22, 0x00, 0x00, 0x00,		// number 1
	0x00, 0x00, 0x32, 0x4A, 0x46, 0x32, 0x00, 0x00,		// number 2
	0x00, 0x00, 0x2C, 0x52, 0x42, 0x24, 0x00, 0x00,		// number 3
	0x00, 0x00, 0x7E, 0x08, 0x08, 0x78, 0x00, 0x00,		// number 4
	0x00, 0x00, 0x4C, 0x52, 0x52, 0x74, 0x00, 0x00,		// number 5
	0x00, 0x00, 0x0C, 0x52, 0x52, 0x3C, 0x00, 0x00,		// number 6
	0x00, 0x00, 0x60, 0x50, 0x4E, 0x40, 0x00, 0x00,		// number 7
	0x00, 0x00, 0x2C, 0x52, 0x52, 0x2C, 0x00, 0x00,		// number 8
	0x00, 0x00, 0x3C, 0x4A, 0x4A, 0x30, 0x00, 0x00,		// number 9
	0x3C, 0x42, 0x42, 0x3C, 0x00, 0x02, 0x7E, 0x22,		// number 10
	0x00, 0x02, 0x7E, 0x22, 0x02, 0x7E, 0x22, 0x00,		// number 11
	0x32, 0x4A, 0x46, 0x32, 0x00, 0x02, 0x7E, 0x22,		// number 12
	0x2C, 0x52, 0x42, 0x24, 0x00, 0x02, 0x7E, 0x22,		// number 13
	0x7E, 0x08, 0x08, 0x78, 0x00, 0x02, 0x7E, 0x22,		// number 14
	0x4C, 0x52, 0x52, 0x74, 0x00, 0x02, 0x7E, 0x22,		// number 15
	0x0C, 0x52, 0x52, 0x3C, 0x00, 0x02, 0x7E, 0x22,		// number 16
};

static unsigned char code figure_of_waiting[][8] = 
{
	0x00, 0x00, 0x00, 0x00, 0x10, 0x20, 0x40, 0x80, 
	0x80, 0x40, 0x20, 0x10, 0x00, 0x00, 0x00, 0x00, 
	0x01, 0x02, 0x04, 0x08, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x08, 0x04, 0x02, 0x01,
};

// main
void main()
{
	uint8_t i;				//  循环计数变量
	
	UART_init();
	MatrixInit();			//	初始化点阵
	
	while(picked == 0)
	{
		for(i = 0; i < 4; i++)
		{
			Display_figure(figure_of_waiting[i]);
			delay_ms(20);
		}
	}
	
	while(1)
	{
		Display_figure(figure_of_number[picked]);
	}
}

// soft delay
void delay(uint16_t nCount)
{
	for(; nCount; nCount--)
		;
}

void delay_ms(uint16_t nCount)
{
	uint16_t i;
	for(; nCount; nCount--)
		for(i = 0; i < 123; i++)
			;
}

// HC595 function
void BufferSendData(uint8_t SendVal)
{
	uint8_t i;
	for(i = 0; i < 8; i++) 
	{
		if(SendVal & (0x80 >> i))
			Out=1;
		else
			Out=0;

		//产生数据移位信号
		S_CLK=0;
		BUFFER_DELAY();
		S_CLK=1;
	}
}

// display
void Display_figure(uint8_t * fig)
{
	uint8_t pos;
	for(pos = 0; pos < 8; pos++)
	{
		DISABLE_BUFFER();
		BufferSendData(fig[pos]);
		ENABLE_ROW(pos);
		ENABLE_BUFFER();
//		delay(0xf);
	}
}

// initiate
void MatrixInit()
{
	DISABLE_ROW();
	DISABLE_BUFFER();
}

void UART_init()
{
	SCON=0X50;			//设置为工作方式1
	TMOD|=0X20;			//设置计数器工作方式2
	PCON=0X80;			//波特率加倍
	TH1=0XF3;				//计数器初始值设置，注意波特率是4800的
	TL1=0XF3;
	ES=1;						//打开接收中断
	EA=1;						//打开总中断
	TR1=1;					//打开计数器
}

void Usart() interrupt 4
{
	if(RI == 1)
	{
		picked=SBUF;//出去接收到的数据
		P2 = ~SBUF;
		RI = 0;//清除接收中断标志位
		return;
	}
}
