#include "system.h"
#include "interrupt.h"

#define TICKER_RESET()	\
	TH0 = 0;			\
	TL0 = 0

static uint8_t measurement_flag;

extern uint16_t measurement_buff[];

void InterruptInit()
{
	measurement_flag = 0;	// 初始化测量值的写入标记位
	
	IT0 = 1;		//设置INT0下降沿触发
	EX0 = 1;		//使能
	P32 = 1;		//设置引脚默认上拉
	
	TMOD |= 0x01;			// 设置定时器工作模式
	TICKER_RESET();
	ET0 = 1;				// 开启定时器0工作
	TR0 = 1;				// 使用TCON寄存器
	
	EA 	= 1;		//中断总开关
}

void K3() interrupt 0	// INT0
{
	uint8_t * buff;
	measurement_flag %= BUFF_LENGTH;
	buff = (uint8_t *)(measurement_buff + measurement_flag);
	*buff = TL0;
	*(buff+1) = TH0;
	
	TICKER_RESET();
	measurement_flag++;
}

void timer0() interrupt 1	// T0
{
	TICKER_RESET();					// 调用宏来初始化定时计数器
}
