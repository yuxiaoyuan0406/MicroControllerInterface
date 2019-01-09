#include "interrupt.h"
#include "system.h"
#include "uart.h"

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
	delay_ms(1);		// ��ʱ1ms����
	if(P32 == 1)		// �ٴ��ж�״̬����
		return;
	if(buff_change == 1)
		return;
	buff = (buff == 0x80)? 0x01: (buff << 1);
	UART_send_byte(buff);
}

void K4() interrupt 2	// INT1
{
	delay_ms(1);
	if(P33 == 1)
		return;
	if(buff_change == 1)
		return;
	buff = (buff == 0x01)? 0x80: (buff >> 1);
	UART_send_byte(buff);
}
