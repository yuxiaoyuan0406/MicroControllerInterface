#include <reg52.H>

#define TICKER_0_RESET_US(t)			\
	TH0 = (0xFFFF - t + 20) >> 8;		\
	TL0 = (0xFFFF - t + 20) & 0xFF

#define TICKER_0_RESET(i)			\
	TH0 = (0xFFFF - i) >> 8;		\
	TL0 = (0xFFFF - i) & 0xff

typedef unsigned char	uint8_t;
typedef unsigned int	uint16_t;
typedef unsigned long	uint32_t;

// soft delay
void delay_ms(uint16_t nCount);

static uint16_t pwm_period_us;
static uint8_t ticker_period;

static uint8_t pwm_width;
static uint8_t ticker_counter;

void setPeriod(uint16_t);

void setWidth(uint8_t);

void PwmInit();

void breath();

int main()
{
	PwmInit();
	setPeriod(10000);
	breath();
	return 0;
}

void breath()
{
	uint8_t i;
	while(1)
	{
		for(i = 0; i < 255; i++)
		{
			setWidth(i);
			delay_ms(2);
		}
		
		for(i = 255; i > 0; i--)
		{
			setWidth(i);
			delay_ms(2);
		}
	}
}

void delay_ms(uint16_t nCount)
{
	uint16_t i;
	for(; nCount; nCount--)
		for(i = 0; i < 123; i++)
			;
}

void PwmInit()
{
	TMOD |= 0x01;
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
}

