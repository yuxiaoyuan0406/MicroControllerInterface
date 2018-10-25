#include "func.h"

/*
 * ÑÓÊ±º¯Êı
 */
void delay(uint16 i)
{
	for(;i;i--)
		;
}

/*
 * ×óÒÆº¯Êı
 */
uint8 crol(uint8 target, uint8 i)
{
	return ~(~target << i);
}

/*
 * ÓÒÒÆº¯Êı
 */
uint8 cror(uint8 target, uint8 i)
{
	return ~(~target >> i);
}
