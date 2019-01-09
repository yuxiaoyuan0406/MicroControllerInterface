#include "interrupt.h"
#include "system.h"
#include "uart.h"

void InterruptInit()
{
	IT0 = 1;		//设置INT0下降沿触发
	EX0 = 1;		//使能
	P32 = 1;		//设置引脚默认上拉
	
	IT1 = 1;		//设置INT1下降沿触发
	EX1 = 1;		//使能
	P33 = 1;		//设置引脚默认上拉
	
	EA 	= 1;		//中断总开关
}

void K3() interrupt 0	// INT0
{
	delay_ms(1);		// 延时1ms消抖
	if(P32 == 1)		// 再次判断状态消抖
		return;
	if(buff_change == 1)
		return;
	buff = (buff == 0x80)? 0x01: (buff << 1);
	UART_send_byte(buff);
}

void K4() interrupt 2	// INT1
{
	delay_ms(1);
	if(P33 == 1)
		return;
	if(buff_change == 1)
		return;
	buff = (buff == 0x01)? 0x80: (buff >> 1);
	UART_send_byte(buff);
}
