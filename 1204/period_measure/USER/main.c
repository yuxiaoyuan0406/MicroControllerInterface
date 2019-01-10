#include "system.h"
#include "digital.h"
#include "interrupt.h"
#include <stdio.h>

uint8_t display_buff[9] = "\0";

uint16_t measurement_buff[BUFF_LENGTH] = {0};

uint16_t average(const uint16_t *, uint8_t);

int main()
{
	uint32_t ave;
	
	DigitalInit();
	InterruptInit();
	
	while(1)
	{
		ave = average(
			measurement_buff, 
			BUFF_LENGTH);
		sprintf(display_buff, "%ld", ave);
		delay_ms(100);
	}
}

uint16_t average(const uint16_t *input, uint8_t length)
{
	uint16_t val = 0;
	uint8_t i;
	for(i = 0; i < length; i++)
	{
		val += input[i];
	}
	return val/length;
}
