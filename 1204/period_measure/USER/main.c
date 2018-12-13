#include "system.h"
#include "digital.h"
#include <stdio.h>

uint8_t display_buff[9] = "\0";

int main()
{
	uint16_t i;
	
	DigitalInit();
	
	sprintf(display_buff, "%d", 1234);
	while(1)
	{
		for(i = 0; i < 0xffff; i++)
		{
			sprintf(display_buff, "%d", i);
			delay_ms(500);
		}
	}
}
