#include "uart.h"

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
//	if(TI == 1)
//	{
//		while(TI == 0)
//			;
//		TI = 0;
//		return;
//	}
}
