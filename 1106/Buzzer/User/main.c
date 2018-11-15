#include <reg52.h>
#include <math.h>

#define PI 0.0000314159265

sbit buzzer = P1 ^ 5;

void delay(unsigned int nCount)
{
	for(; nCount; nCount--)
		;
}

int main()
{
	unsigned long i;
	buzzer = 1;
	for(;;)
	{
		for(i = 0; i < 100000; i++)
		{
			buzzer = 1;
			delay((int)(100.0 * sin(i * PI)));
			buzzer = 0;
			delay((int)(100.0 * sin(i * PI)));
		}
		buzzer = ~buzzer;
//		delay(100);
	}
}
