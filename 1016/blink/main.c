#include <reg52.h>

sbit led = P1 ^ 5;

void delay(unsigned int i)
{
	for(;i;i--)
		;
}

int main()
{
	led = 1;
	while(1)
	{
		led = ~led;
		delay(50);
	}
}
