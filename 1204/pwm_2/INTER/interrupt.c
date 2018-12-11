#include "interrupt.h"
#include "pwm.h"

void InterruptInit()
{
	IT0 = 1;		//����INT0�½��ش���
	EX0 = 1;		//ʹ��
	P32 = 1;		//��������Ĭ������
	
	IT1 = 1;		//����INT1�½��ش���
	EX1 = 1;		//ʹ��
	P33 = 1;		//��������Ĭ������
	
	EA 	= 1;		//�ж��ܿ���
}

void K3() interrupt 0	// INT0
{
	EA = 0;
	
	delay_ms(1);		// ��ʱ1ms����
	if(P32 == 1)		// �ٴ��ж�״̬����
		return;
//	setWidth(pwm_width-1);
	pwm_width = pwm_width - 1;
	ticker_counter = 0;
	
	EA = 1;
}

void K4() interrupt 2	// INT1
{
	EA = 0;
	
	delay_ms(1);
	if(P33 == 1)
		return;
//	setWidth(pwm_width+1);
	pwm_width = pwm_width + 1;
	ticker_counter = 0;
	
	EA = 1;	
}


