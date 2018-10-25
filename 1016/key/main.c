#include <reg52.h>
#include "func.h"

unsigned char flag;
unsigned char en;

sbit led_test_0 = P2 ^ 0;
sbit led_test_1 = P2 ^ 1;


void main()
{
	setup();
	
	led_test_0 = 0;
	led_test_1 = 0;
	
	while(1)
		;
	
//	while (1)
//	{
//		if(en)
//		{
//			switch(flag)
//			{
//			case 1:
//				display_1();
//				break;
//			default:
//				break;
//			}
//		}
//		else
//		{
//			flag = 0;
//			LED == 0xff;
//		}
//	}
}

void clear_INT1(void) interrupt 2
{
//	EA = 0;
//	delay(200);
	led_test_1 = ~led_test_1;
//	en = !en;
	//EA = 1;
}

void display_INT0(void) interrupt 0
{
//	EA = 0;
//	delay(200);
	led_test_1 = ~led_test_0;
//	flag = 1;
//	EA = 1;
}
