#include "system.h"

#define display_time 0xf

void main()
{
	char value[64] = "0123456789abcdef";
	char * iterator;
	uint8_t delay_time = 0x1f;
	uint8_t digs;
	
	DigitalInit();
	
	while(1)
	{
		DigitalInit();
		digs = 0;
		SOFT_DELAY;
		
		for (iterator = value; iterator[7] != '\0'; iterator++)
		{
			while(digs < 8)
			{
				for(delay_time = display_time;
					delay_time != 0;
					delay_time--)
				{
					Display_str(iterator, digs);
				}
				digs++;
			}
				
			for(delay_time = display_time;
				delay_time != 0;
				delay_time--)
			{
				Display_str(iterator, 8);
			}
		}
		
		for (; iterator[0] != '\0'; iterator++)
		{
//			iterator[7] = '\0';
			for(delay_time = display_time;
				delay_time != 0;
				delay_time--)
			{
				Display_str(iterator, 8);
			}
		}
		
//		Display_str(value, );
		
	}
}
