#include "system.h"
#include "digital.h"
#include <stdio.h>

uint8_t display_buff[9] = "\0";

int main()
{
	uint32_t i;
	
	DigitalInit();
	
//	sprintf(display_buff, "%ld", 65535);
//	while(1);
	while(1)
	{
		for(i = MAXIUM_NUM; i > 0; i--)
		{
			sprintf(display_buff, "%ld", i);
			delay_ms(100);
		}
		for(i = 0; i < MAXIUM_NUM; i++)
		{
			sprintf(display_buff, "%ld", i);
			delay_ms(100);
		}
	}
}
