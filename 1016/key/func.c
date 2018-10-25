#include "func.h"

extern unsigned char flag;
extern unsigned char en;

/*
 * 延时函数
 */
void delay(uint16 i)
{
	for(;i;i--)
		;
}

/*
 * 左移函数
 */
uint8 crol(uint8 target, uint8 i)
{
	return ~(~target << i);
}

/*
 * 右移函数
 */
uint8 cror(uint8 target, uint8 i)
{
	return ~(~target >> i);
}

/*
 * 效果1
 */
void display_1()
{
	unsigned char i;
	for(i = 0; i < 7; i++)
	{
		LED = crol(LED, 1);
		delay(50000);
	}
	for(i = 0; i < 7; i++)
	{
		LED = cror(LED, 1);
		delay(50000);
	}
}

void steup()
{
	// initialize interrupt
	IT0	= 1;  //中断触发方式为低电平触发，IT0=1则为下边沿触发
	IT1 = 1;
	
	EX0	= 1;  //打开外部中断0
	EX1 = 1;
	
	EA	= 1;    //打开中断总开关
	
	// initialize flag
	flag = 0;
	en = 0;
	
	// initialize led
	LED=0xff;
}

