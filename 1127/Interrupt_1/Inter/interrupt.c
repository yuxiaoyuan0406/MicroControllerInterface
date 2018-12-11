#include "interrupt.h"
#include "system.h"

// 这里输入的t单位是ms
#define TICKER_0_RESET(t)					\
	TH0 = (0xffff - 1005 * t) / 256;		\
	TL0 = (0xffff - 1005 * t) % 256

void InterruptInit()
{
	IT0 = 1;		//设置INT0下降沿触发
	EX0 = 1;		//使能
	P32 = 1;		//设置引脚默认上拉
	
	IT1 = 1;		//设置INT1下降沿触发
	EX1 = 1;		//使能
	P33 = 1;		//设置引脚默认上拉
	
	TMOD = 0x01;			// 设置定时器工作模式
	TICKER_0_RESET(10);		// 初始化定时10ms
	ET0 = 1;				// 开启定时器0工作
	TR0 = 1;				// 使用TCON寄存器
	
	EA 	= 1;		//中断总开关
}

void K3() interrupt 0	// INT0
{
	delay_ms(1);		// 延时1ms消抖
	if(P32 == 1)		// 再次判断状态消抖
		return;
	led = ~led;			// 熄灭或者点亮LED
}

void timer0() interrupt 1	// T0
{
	static uint16_t ticker_counter;		// 长时间计时需要一个大的计数变量
	TICKER_0_RESET(1);					// 调用宏来初始化定时计数器
	if(led == 0)						// 如果LED是点亮的
	{
		if(ticker_counter == 5000)		// 如果计数变量到达5000
		{
			led = 1;					// 熄灭LED
			ticker_counter = 0;			// 清空计数变量
			return;						// 这一句没啥用
		}
		else
			ticker_counter++;			// 如果计数变量不到5000, 那么自加一, 不熄灭LED
	}
	else
	{
		ticker_counter = 0;				// 如果LED是熄灭的那么保持计数变量为0
	}
}

void K4() interrupt 2	// INT1
{
	delay_ms(1);
	if(P33 == 1)
		return;
	led = ~led;
}


