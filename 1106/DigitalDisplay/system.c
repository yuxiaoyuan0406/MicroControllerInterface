#include "system.h"

// soft delay
void delay(uint16_t nCount)
{
	for(; nCount; nCount--)
		;
}

// initiate
void DigitalInit()
{
	COMMON ^= 0x7 << 2;
	DIGITAL = 0x00;
}

// display function
void Display_str(char * str, uint8_t nArg)
{
	char item;
	uint8_t i;
	if(nArg <= 8)
	{
		for(i = 0; i < nArg; i++)
		{
			DigitalInit();
			item = str[8 - 1 - i];
			if('0' <= item && item <= '9')
				Display_number(i, item - '0');
			else if(item == '\0')
				Display_empty(i);
			else
				Display_number(i, 8);
			delay(0xff);
		}
	}
	else
	{
		for(i = 0; i < nArg; i++)
		{
			DigitalInit();
			Display_number(i, 8);
			delay(0xff);
		}
	}
}

void Display_int(uint32_t num)
{
	uint8_t item;
	uint8_t i;
	for(i = 0; num; i++)
	{
		item = num % 10;
		Display_number(i, item);
		num /= 10;
		delay(0xA0);
	}
}
