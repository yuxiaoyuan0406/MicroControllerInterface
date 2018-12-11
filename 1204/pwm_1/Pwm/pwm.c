#include "pwm.h"

#define TICKER_0_RESET_US(t)				\
	TH0 = (0x10000 - t / 50) / 0x100;		\
	TL0 = (0x10000 - t / 50) % 0x100

//enum {
//	MODE_DUTY	=	0, 
//	MODE_WIDTH 	=	1
//};

static uint16_t period;

static uint16_t pulse_width;

static float duty;

static bit status;

sbit pwm_pin = P2 ^ 0;

void PwmInit()
{
	period = 100;
	pulse_width = 0;
	status = 1;
	duty = 0.0;
	
	TMOD = 0x01;
	TH0 = 0xFF;
	TL0 = 0xFF;
	EA = 1;
	ET0 = 1;
	TR0 = 1;
}

void Pwm_period_us(uint16_t T)
{
	if(T < 100)
		return;
	period = T;
	pulse_width = 0;
}

void Pwm_pulse_width_us(uint16_t w)
{
	pulse_width = w > period ? period : w;
}

void timer0() interrupt 1
{
	if(status == 0)
	{
		TICKER_0_RESET_US(pulse_width);
	}
	else
	{
		TICKER_0_RESET_US(period - pulse_width);
	}
	status = ~status;
	pwm_pin = status;
}
