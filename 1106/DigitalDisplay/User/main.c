#include "system.h"

void main()
{
	const char * value = "370502199804061218";
	char * iterator;
	uint8_t delay_time = 0x2f;
	
	DigitalInit();
	
	while(1)
	{
		DigitalInit();
		SOFT_DELAY;
		for (iterator = value; iterator[7] != '\0'; iterator++)
		{
			for(delay_time = 0x2f;
				delay_time != 0;// && display_digs == 8;
				delay_time--)
			{
				Display_str(iterator, 8);
			}
		}
	}
}
