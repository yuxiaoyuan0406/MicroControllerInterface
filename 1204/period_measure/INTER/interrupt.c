#include "system.h"
#include "interrupt.h"

#define TICKER_RESET()	\
	TH0 = 0;			\
	TL0 = 0

static uint8_t measurement_flag;

extern uint16_t measurement_buff[];

void InterruptInit()
{
	measurement_flag = 0;	// ��ʼ������ֵ��д����λ
	
	IT0 = 1;		//����INT0�½��ش���
	EX0 = 1;		//ʹ��
	P32 = 1;		//��������Ĭ������
	
	TMOD |= 0x01;			// ���ö�ʱ������ģʽ
	TICKER_RESET();
	ET0 = 1;				// ������ʱ��0����
	TR0 = 1;				// ʹ��TCON�Ĵ���
	
	EA 	= 1;		//�ж��ܿ���
}

void K3() interrupt 0	// INT0
{
	uint8_t * buff;
	measurement_flag %= BUFF_LENGTH;
	buff = (uint8_t *)(measurement_buff + measurement_flag);
	*buff = TL0;
	*(buff+1) = TH0;
	
	TICKER_RESET();
	measurement_flag++;
}

void timer0() interrupt 1	// T0
{
	TICKER_RESET();					// ���ú�����ʼ����ʱ������
}
