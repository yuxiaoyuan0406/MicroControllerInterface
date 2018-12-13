#include "system.h"
#include "square_wave.h"

volatile ticker_union ticker_0;

#define TICKER_0_RESET_US(t)			\
	TH0 = (0xFFFF - t + 5) >> 8;		\
	TL0 = (0xFFFF - t + 5) & 0xFF

#define TICKER_0_RESET()	\
	TH0 = high_8;			\
	TL0 = low_8

/**	方波初始化
 */
void SquareWaveInit()
{
	TMOD = 0x01;
	TH0 = 0xFF;
	TL0 = 0xFF;
	EA = 1;
	ET0 = 1;
	TR0 = 1;
}
/** 设置方波周期
 *	单位: 微秒
 */
void setPeriod(uint16_t period)
{
//	EA = 0;
	wave_period_us = period;
	ticker_0.value = 0x10008 - (period >> 1);	// 经过计算在这种情况下设置单位为微秒

//	EA = 1;
}

/**	定时计数器0服务函数
 */
void timer0() interrupt 1
{
	TL0 = ticker_0.T[1];
	TH0 = ticker_0.T[0];
//	TL0 = low_8;
//	TH0 = high_8;
	P2 = ~P2;
}
