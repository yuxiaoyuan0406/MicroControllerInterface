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
	uint8_t pos;
	if(0 < nArg && nArg <= 8)
	{
		for(i = 0; i < 8; i++)
		{
			DigitalInit();
			pos = nArg - i - 1;
			if(i < nArg)
				item = str[i];
			else
				item = '\0';
			
			if('0' <= item && item <= '9')
				Display_number(pos, item - '0');
			else if('a' <= item && item <= 'f')
				Display_number(pos, item - 'a' + 10);
			else if('A' <= item && item <= 'F')
				Display_number(pos, item - 'A' + 10);
			else
				Display_empty(i);
			
			delay(0xff);
		}
	}
	else if(nArg == 0)
	{
		for(i = 0; i < 8; i++)
		{
			DigitalInit();
			Display_empty(i);
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

//void Display_int(uint32_t num)
//{
//	uint8_t item;
//	uint8_t i;
//	for(i = 0; num; i++)
//	{
//		item = num % 10;
//		Display_number(i, item);
//		num /= 10;
//		delay(0xA0);
//	}
//}
