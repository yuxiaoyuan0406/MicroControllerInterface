#include "func.h"

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
