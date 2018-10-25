//#include <reg52.h>
//#include <intrins.h>
#include "func.h"

#define led P2

/*
 * Ö÷º¯Êý
 * blink
 */
int main()
{
	uint8 i;
	const uint16 time = 50000;
	led = 0xfe;			//1111 1110
	while(1)
	{
		for(i = 0; i < 7; i++)
		{
			led = crol(led, 1);
			delay(time);
		}
		for(i = 0; i < 7; i++)
		{
			led = cror(led, 1);
			delay(time);
		}
	}
}
