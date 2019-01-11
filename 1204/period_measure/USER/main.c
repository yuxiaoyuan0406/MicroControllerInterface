#include "system.h"
#include "digital.h"
#include "interrupt.h"
#include <stdio.h>

uint8_t display_buff[9] = "\0";		// ��ʾ�õĻ���, ��ʼ��Ϊ���ַ���

uint32_t measurement_buff[BUFF_LENGTH] = {0};	// ��Ų���ֵ�Ļ���, ��ʼ��ȫ��Ϊ0

uint16_t average(const uint32_t *, uint8_t);	// ��ƽ��ֵ�ĺ���, ��������ͳ���

int main()
{
	uint32_t ave;	// ��������ƽ��ֵ�ı���
	
	DigitalInit();	// ��ʼ��
	InterruptInit();
	
	while(1)		// �����ܺ���
	{
		ave = average(
			measurement_buff, 
			BUFF_LENGTH);	// ��ƽ��
		sprintf(display_buff, "%ld", ave);	
							// ƽ��ֵ�������ʾ��������
		delay_ms(500);		// ��ʱ500ms
	}
}

uint16_t average(const uint32_t *input, uint8_t length)
{
	uint32_t val = 0;	// ������ƽ���õı���
	uint8_t i;			// ����ѭ������õı���
	for(i = 0; i < length; i++)
	{
		val += input[i];// ���
	}
	return val/length;	// ����ƽ��ֵ
}
