#include "digital.h"

// ����������, �ױ��
volatile ticker_union ticker_1;

// ��ʾ�õĻ���, �ַ���, �ڱ𴦶���
extern uint8_t display_buff[];

// ���ö�ʱ������1��ʱ��
// ����Ĳ������Ǿ���ֵ
#define TICKER_1_SET_US(t)	ticker_1.value = 0x10008 - (t >> 1)

// ����
#define CLEAR()			\
	COMMON = 0x7 << 2;	\
	DIGITAL = 0x00
	
// initiate
void DigitalInit()
{
	CLEAR();		// ������
	
	TMOD |= 0x10;	// ���ö�ʱ������1������ʽ
	TH1 = 0xff;		// ���ö�ʱ������1��ֵ
	TL1 = 0xff;
	EA = 1;			// �����ж�
	ET1 = 1;		// ���ն�ʱ������1�ж��ź�
	TR1 = 1;		// ��ʱ��������ʼ����
	
	TICKER_1_SET_US(1250);		// ��������Ϊ1250us
}

// ��ʱ�������жϷ�����
void timer1() interrupt 3
{
	static uint8_t pos = 0;		// ���ڴ�����ʾ��һλ
	TL1 = ticker_1.T[1];		// ��ʱ��������λ
	TH1 = ticker_1.T[0];
	CLEAR();					// ����
	if(display_buff[pos] != '\0')	// ֻҪ��Ҫ��ʾ����һλ����'\0'
	{								// ��ô��ʾ��һλ����, �����
		Display_number(7 - pos, display_buff[pos] - '0');
	}
	else			// �������Ҫ��ʾ��λ��'\0'
	{				// ˵���ַ����ߵ�ͷ��
		pos = 0;	// ��ͷ����
		return;		// ��������, pos����
	}
	pos = (++pos) % 8;	// Ϊ����ʾ��һλ�Ͳ����, �Լ�һ����8����
}
