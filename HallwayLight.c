#include <reg52.H>

sbit led = P2 ^ 0;
sbit P32 = P3 ^ 2;
sbit P33 = P3 ^ 3;

#define TIMER_SET(trig)	\
do{						\
	ET0 = trig;			\
	TR0 = trig;			\
}while(0)

// ���������t��λ��ms
#define TICKER_0_RESET(t)					\
	TH0 = (0xffff - 1005 * t) / 256;		\
	TL0 = (0xffff - 1005 * t) % 256

typedef unsigned char	uint8_t;
typedef unsigned int	uint16_t;
typedef unsigned long	uint32_t;

// soft delay
void delay_ms(uint16_t nCount);

void InterruptInit();

int main()
{
	InterruptInit();	// ʱ���жϳ�ʼ��
	while(1)
	{
		;
	}
}

void delay_ms(uint16_t nCount)
{
	uint16_t i;
	for(; nCount; nCount--)
		for(i = 0; i < 150; i++)
			;
}

void InterruptInit()
{
	IT0 = 1;		//����INT0�½��ش���
	EX0 = 1;		//ʹ��
	P32 = 1;		//��������Ĭ������
	
	IT1 = 1;		//����INT1�½��ش���
	EX1 = 1;		//ʹ��
	P33 = 1;		//��������Ĭ������
	
	TMOD = 0x01;			// ���ö�ʱ������ģʽ
	TICKER_0_RESET(10);		// ��ʼ����ʱ10ms
	ET0 = 1;				// ������ʱ��0����
	TR0 = 1;				// ʹ��TCON�Ĵ���
	
	EA 	= 1;		//�ж��ܿ���
}

void K3() interrupt 0	// INT0
{
	delay_ms(1);		// ��ʱ1ms����
	if(P32 == 1)		// �ٴ��ж�״̬����
		return;
	led = ~led;			// Ϩ����ߵ���LED
}

void timer0() interrupt 1	// T0
{
	static uint16_t ticker_counter;		// ��ʱ���ʱ��Ҫһ����ļ�������
	TICKER_0_RESET(1);					// ���ú�����ʼ����ʱ������
	if(led == 0)						// ���LED�ǵ�����
	{
		if(ticker_counter == 5000)		// ���������������5000
		{
			led = 1;					// Ϩ��LED
			ticker_counter = 0;			// ��ռ�������
			return;						// ��һ��ûɶ��
		}
		else
			ticker_counter++;			// ���������������5000, ��ô�Լ�һ, ��Ϩ��LED
	}
	else
	{
		ticker_counter = 0;				// ���LED��Ϩ�����ô���ּ�������Ϊ0
	}
}

void K4() interrupt 2	// INT1
{
	delay_ms(1);
	if(P33 == 1)
		return;
	led = ~led;
}
