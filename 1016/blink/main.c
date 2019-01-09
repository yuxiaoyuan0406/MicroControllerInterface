//#include <STC12C2052AD.H>
//#include <reg52.h>

//#define GPIO_P2		* (unsigned char *)(0xA0)
//	
//typedef unsigned int uint16_t;
//typedef unsigned char uint8_t;
//	
//void delay_ms(uint16_t nCount)
//{
//	uint16_t i;
//	for(; nCount; nCount--)
//		for(i = 0; i < 123; i++)
//			;
//}

//int main()
//{
//	while(1)
//	{
//		GPIO_P2 = 0xf;
//		delay_ms(250);
//		GPIO_P2 = 0x0;
//		delay_ms(250);
//	}
//}

//sbit led = P2 ^ 0;

//void delay(unsigned int nCount)
//{
//	unsigned int i;
//	for(; nCount; nCount--)
//		for(i = 0; i < 123; i++)
//			;
//}

//int main()
//{
//	led = 1;
//	while(1)
//	{
//		led = ~led;
//		delay(1);
//	}
//}

//sbit LED = P1^7;
//sbit KEY = P3^7;

//void main (void) {
//   P3M0 = 0x80;P3M1 = 0x00;	//����
//   LED=1; // LED = P1^7; �����趨KEY��״̬����Ϊ���ᱻ�����


//	while (1)
//	{
//		LED=~KEY;
//	}

//}

#include <STC89C5xRC.H>

typedef unsigned char	uint8_t;
typedef unsigned int	uint16_t;
typedef unsigned char	u8;
typedef unsigned int	u16;

static uint8_t receiveData;
static uint8_t sendBuff;

uint8_t buff[] =
{
	0x01,
	0x02,
	0x04,
	0x08,
	0x10,
	0x20,
	0x40,
	0x80,
};

void delay_ms(uint16_t nCount)
{
	uint8_t i;
	for(; nCount; nCount--)
		for(i = 0; i < 123; i++)
			;
}

void UART_init()
{
	SCON=0X50;			//����Ϊ������ʽ1
	TMOD=0X20;			//���ü�����������ʽ2
	PCON=0X80;			//�����ʼӱ�
	TH1=0XF3;				//��������ʼֵ���ã�ע�Ⲩ������4800��
	TL1=0XF3;
	ES=1;						//�򿪽����ж�
	EA=1;						//�����ж�
	TR1=1;					//�򿪼�����
}

void UART_send_byte(uint8_t dat)
{
	SBUF = dat;
	while(TI == 0)
		;
	TI = 0;
}

void main()
{
	uint8_t i;
	UART_init();  //	���ڳ�ʼ��
	UART_send_byte(0);
	
	while(1)
	{
//		for(i = 0; i < 8; i++)
//		{
//			UART_send_byte(buff[i]);
//			delay_ms(200);
//		}
	}
}


void Usart() interrupt 4
{
	if(RI == 1)
	{
		receiveData=SBUF;//��ȥ���յ�������
		P2 = ~SBUF;
		RI = 0;//��������жϱ�־λ
		
		delay_ms(200);
		SBUF = receiveData + 1;
		
		
		while(!TI);
		TI = 0;
		return;
	}
}
