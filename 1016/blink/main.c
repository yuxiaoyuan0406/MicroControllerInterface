#include <reg52.h>

sbit led = P2 ^ 0;

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
		delay(0);
	}
}
