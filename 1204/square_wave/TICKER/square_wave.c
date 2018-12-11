#include "system.h"
#include "square_wave.h"

#define ADJUST_PARAM 5

#define TICKER_0_RESET_US(t)			\
	TH0 = (0xFFFF - t + 5) >> 8;		\
	TL0 = (0xFFFF - t + 5) & 0xFF

#define TICKER_0_RESET()	\
	TH0 = high_8;			\
	TL0 = low_8

void SquareWaveInit()
{
	TMOD = 0x01;
	TH0 = 0xFF;
	TL0 = 0xFF;
	EA = 1;
	ET0 = 1;
	TR0 = 1;
}

//void setPeriod(uint16_t period)
//{
////	EA = 0;
//	wave_period_us = period;
//	ticker_period = wave_period_us >> 1;
//	high_8 = ticker_period >> 8;
//	low_8 = ticker_period & 0xFF;

////	EA = 1;
//}

void timer0() interrupt 1
{
//	TICKER_0_RESET();
	TH0 = 0xff;
	TL0 = 0xfe;
	P2 = ~P2;
}
