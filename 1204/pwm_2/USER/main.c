#include "system.h"
#include "pwm.h"
#include "interrupt.h"

void breath();

void period();

int main()
{
	
	PwmInit();
	InterruptInit();
	setPeriod(10000);
//	setWidth(128);
	
	
	
//	while(1);
	
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
