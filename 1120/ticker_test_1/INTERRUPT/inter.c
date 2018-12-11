#include "system.h"

// 这里输入的t单位是ms
#define TICKER_0_RESET(t)					\
	TH0 = (65536 - 500 * t + 9) / 256;		\
	TL0 = (65536 - 500 * t + 9) % 256


sbit led = P2 ^ 0;

static uint16_t ticker_counter = 0;

void InterruptInit()
{
	TMOD = 0x01;
	//TICKER_0_RESET(10);
	TH0 = 0xFF;
	TL0 = 0xFF;
	EA = 1;
	ET0 = 1;
	TR0 = 1;
}

void timer0() interrupt 1
{
//	TICKER_0_RESET(1);
	TH0 = 0xFF;
	TL0 = 0xFF;
//	if(ticker_counter == 500)
	{
		led = ~led;
		ticker_counter = 0;
	}
	ticker_counter++;
}
