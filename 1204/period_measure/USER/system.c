#include "system.h"

void delay_ms(uint16_t nCount)
{
	uint16_t i;
	for(; nCount; nCount--)
		for(i = 0; i < 123; i++)
			;
}

//void delay(uint16_t nCount)
//{
//	for(; nCount; nCount--)
//		;
//}
