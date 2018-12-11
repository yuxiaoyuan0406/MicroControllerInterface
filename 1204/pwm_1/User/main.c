#include "system.h"
#include "pwm.h"

int main()
{
	uint8_t i;
	
	PwmInit();
	Pwm_period_us(10000);
	Pwm_pulse_width_us(1000);
	while(1)
	{
		Pwm_pulse_width_us(1000);
		delay_ms(1000);
		Pwm_pulse_width_us(9000);
		delay_ms(1000);
//		for(i = 0; i < 100; i++)
//		{
//			Pwm_pulse_width_us(i * 10);
//			delay_ms(5);
//		}
//		
//		for(i = 100; i > 0; i--)
//		{
//			Pwm_pulse_width_us(i * 10);
//			delay_ms(5);
//		}
	}
}
