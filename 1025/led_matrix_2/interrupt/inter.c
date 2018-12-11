#include "system.h"
#include "inter.h"
#include "matrix.h"

// 这里输入的t单位是ms
#define TICKER_0_RESET(t)					\
	TH0 = (65536 - 500 * t + 9) / 256;		\
	TL0 = (65536 - 500 * t + 9) % 256

static uint8_t ticker_counter = 0;

void InterruptInit()
{
	TMOD = 0x01;
	TICKER_0_RESET(10);
	EA = 1;
	ET0 = 1;
	TR0 = 1;
}

void timer0() interrupt 1
{
	TICKER_0_RESET(10);
	if(ticker_counter == 50)
	{
		
	}
	ticker_counter++;
}
