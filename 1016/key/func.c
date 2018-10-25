#include "func.h"

extern unsigned char flag;
extern unsigned char en;

/*
 * ��ʱ����
 */
void delay(uint16 i)
{
	for(;i;i--)
		;
}

/*
 * ���ƺ���
 */
uint8 crol(uint8 target, uint8 i)
{
	return ~(~target << i);
}

/*
 * ���ƺ���
 */
uint8 cror(uint8 target, uint8 i)
{
	return ~(~target >> i);
}

/*
 * Ч��1
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
	IT0	= 1;  //�жϴ�����ʽΪ�͵�ƽ������IT0=1��Ϊ�±��ش���
	IT1 = 1;
	
	EX0	= 1;  //���ⲿ�ж�0
	EX1 = 1;
	
	EA	= 1;    //���ж��ܿ���
	
	// initialize flag
	flag = 0;
	en = 0;
	
	// initialize led
	LED=0xff;
}

