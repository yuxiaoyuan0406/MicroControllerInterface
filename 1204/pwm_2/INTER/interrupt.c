#include "interrupt.h"
#include "pwm.h"

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
	EA = 0;
	
	delay_ms(1);		// 延时1ms消抖
	if(P32 == 1)		// 再次判断状态消抖
		return;
//	setWidth(pwm_width-1);
	pwm_width = pwm_width - 1;
	ticker_counter = 0;
	
	EA = 1;
}

void K4() interrupt 2	// INT1
{
	EA = 0;
	
	delay_ms(1);
	if(P33 == 1)
		return;
//	setWidth(pwm_width+1);
	pwm_width = pwm_width + 1;
	ticker_counter = 0;
	
	EA = 1;	
}


