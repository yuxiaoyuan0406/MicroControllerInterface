#include "system.h"

// soft delay
void delay(uint16_t nCount)
{
	for(; nCount; nCount--)
		;
}
