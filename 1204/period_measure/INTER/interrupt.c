#include "system.h"
#include "interrupt.h"

// �궨��Ķ�ʱ������0��λ
#define TICKER_RESET()	\
	TH0 = 0;			\
	TL0 = 0

static uint8_t measurement_flag;	// ���������¼��д�����ֵ�ڲ������������е�λ��

extern uint32_t measurement_buff[];	// ������������, �ڱ𴦶���

uint8_t overflow_flag;		// ��ʱ���������ʱ�ı��λ
	// ���ǵ���ʱ����������С�ڷ���������
	// ��ô��һ�����������ڶ�ʱ�������ᴥ���ж�
	// ʹ��������λ�ķ�ʽ�������Ӳ�����Χ

// initiate
void InterruptInit()
{
	measurement_flag = 0;	// ��ʼ������ֵ��д����λ
	overflow_flag = 0;		// ��ʼ����ʱ������������λ
	
	IT0 = 1;		//����INT0�½��ش���
	EX0 = 1;		//ʹ��
	P32 = 1;		//��������Ĭ������
	
	TMOD |= 0x01;			// ���ö�ʱ������ģʽ
	TICKER_RESET();
	ET0 = 1;				// ������ʱ��0����
	TR0 = 1;				// ʹ��TCON�Ĵ���
	
	EA 	= 1;		//�ж��ܿ���
}

void K3() interrupt 0	// �ⲿ�ж�0, P32�˿�
{
	uint8_t * buff;		// д���õ�ָ��
	
	buff = (uint8_t *)(measurement_buff + measurement_flag);
	// measurement_buff��32λ�޷���������
	// ��measurement_flag���ʾ���Ǵ�ŵ�ǰ����ֵ�������е�λ��
	// ǿ��ת��Ϊ8λָ��, ���԰�32λ������һ������Ϊ4�ֽڵ�8λ��������ʹ��
	
	*buff = TL0;		
	// ֱ��Ѱַbuff��ʾ����measurement_buff[measurement_flag]��0~7λ
	*(buff+1) = TH0;
	// Ѱַbuff+1��ʾ������measurement_buff[measurement_flag]��8~15λ
	*(buff+2) = overflow_flag;
	// Ѱַbuff+2��ʾ������measurement_buff[measurement_flag]��16~23λ
	
	overflow_flag = 0;	// ��ʱ������������λÿ�ζ�ȡ������Ҫ����
	
	measurement_flag++;	// д������һ����Ԫ��Ҫ�Լ�һ
	measurement_flag %= BUFF_LENGTH;	// ��ֹ�������鳤��, ȡģ
	
	TICKER_RESET();		// ��ʱ����������, ��������������
}

void timer0() interrupt 1	// T0
{
	TICKER_RESET();			// ���ú�����ʼ����ʱ������
	overflow_flag++;		// �����ж�˵���Ѿ����, ������λ���һ
}
