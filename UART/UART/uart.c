#include "uart.h"

void UART_init()
{
	SCON=0X50;			//����Ϊ������ʽ1
	TMOD|=0X20;			//���ü�����������ʽ2
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

void Usart() interrupt 4
{
	if(RI == 1)
	{
		receiveData=SBUF;//��ȥ���յ�������
		P2 = ~SBUF;
		RI = 0;//��������жϱ�־λ
		return;
	}
//	if(TI == 1)
//	{
//		while(TI == 0)
//			;
//		TI = 0;
//		return;
//	}
}
