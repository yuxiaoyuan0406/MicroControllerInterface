#include "system.h"
#include "pwm.h"

#define TICKER_0_RESET_US(t)			\
	TH0 = (0xFFFF - t + 20) >> 8;		\
	TL0 = (0xFFFF - t + 20) & 0xFF

#define TICKER_0_RESET(i)			\
	TH0 = (0xFFFF - i) >> 8;		\
	TL0 = (0xFFFF - i) & 0xff
	
void PwmInit()
{
	TMOD = 0x01;
	TH0 = 0xFF;
	TL0 = 0xFF;
	EA = 1;
	ET0 = 1;
	TR0 = 1;
	
	pwm_width = 0;
	ticker_counter = 0;
}

void setPeriod(uint16_t period)
{
	EA = 0;
	pwm_period_us = period;
	ticker_period = pwm_period_us >> 8;

	ticker_counter = 0;
	EA = 1;
}

void setWidth(uint8_t width)
{
	EA = 0;
	pwm_width = width;
	
	ticker_counter = 0;
	EA = 1;
}

void timer0() interrupt 1
{
#ifdef PERIOD_MODE
	TICKER_0_RESET(ticker_period);
	if(ticker_counter == 1)//pwm_width)
	{
		P2 = 0;
		ticker_counter = 0;
	}
	else if(ticker_counter == 0)
	{
		P2 = 0xff;
		ticker_counter = 1;
	}
#else
	TICKER_0_RESET_US(ticker_period);
	if(ticker_counter == pwm_width)
	{
		P2 = 0;
	}
	else if(ticker_counter == 0)
	{
		P2 = 0xff;
	}
	ticker_counter++;
#endif	// PERIOD_MODE
}
