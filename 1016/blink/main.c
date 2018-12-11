#include <STC12C2052AD.H>
//#include <reg52.h>

sbit led = P2 ^ 0;

void delay(unsigned int nCount)
{
	unsigned int i;
	for(; nCount; nCount--)
		for(i = 0; i < 123; i++)
			;
}

int main()
{
	led = 1;
	while(1)
	{
		led = ~led;
		delay(1);
	}
}

//sbit LED = P1^7;
//sbit KEY = P3^7;

//void main (void) {
//   P3M0 = 0x80;P3M1 = 0x00;	//高阻
//   LED=1; // LED = P1^7; 无需设定KEY的状态，因为不会被输出！


//	while (1)
//	{
//		LED=~KEY;
//	}

//}