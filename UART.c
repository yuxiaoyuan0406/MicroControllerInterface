#include <STC89C5xRC.H>

typedef unsigned char	uint8_t;
typedef unsigned int	uint16_t;
typedef unsigned char	u8;
typedef unsigned int	u16;

static uint8_t receiveData;
static uint8_t sendBuff;

uint8_t buff[] =
{
	0x01,
	0x02,
	0x04,
	0x08,
	0x10,
	0x20,
	0x40,
	0x80,
};

void delay_ms(uint16_t nCount)
{
	uint8_t i;
	for(; nCount; nCount--)
		for(i = 0; i < 123; i++)
			;
}

void UART_init()
{
	SCON=0X50;			//设置为工作方式1
	TMOD=0X20;			//设置计数器工作方式2
	PCON=0X80;			//波特率加倍
	TH1=0XF3;				//计数器初始值设置，注意波特率是4800的
	TL1=0XF3;
	ES=1;						//打开接收中断
	EA=1;						//打开总中断
	TR1=1;					//打开计数器
}

void UART_send_byte(uint8_t dat)
{
	SBUF = dat;
	while(TI == 0)
		;
	TI = 0;
}

void main()
{
	uint8_t i;
	UART_init();  //	串口初始化
	UART_send_byte(0);
	
	while(1)
	{
//		for(i = 0; i < 8; i++)
//		{
//			UART_send_byte(buff[i]);
//			delay_ms(200);
//		}
	}
}


void Usart() interrupt 4
{
	if(RI == 1)
	{
		receiveData=SBUF;//出去接收到的数据
		P2 = ~SBUF;
		RI = 0;//清除接收中断标志位
		
		delay_ms(200);
		SBUF = receiveData + 1;
		
		while(!TI);
		TI = 0;
		return;
	}
}
