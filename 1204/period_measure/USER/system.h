#ifndef __SYSTEM_H
#define __SYSTEM_H

#define MAXIUM_NUM 0x5F5E0FF	// ���������ʾ�������ֵ9999 9999

#include <STC89C5xRC.H>			// ����stc�ٷ�ͷ�ļ�

typedef unsigned char	uint8_t;	//  8λ�޷���
typedef unsigned int	uint16_t;	// 16λ�޷���
typedef unsigned long	uint32_t;	// 32λ�޷���

// soft delay
void delay_ms(uint16_t nCount);		// �����ʱ, ��λ����

typedef union {						// ������, ������ʾʱ�Ķ�ʱ��������ֵ
	uint16_t value;					// �ⲿд��ʱʹ�õĽӿ�
	uint8_t T[2];					// �жϺ����ڲ���λʹ�õĽӿ�
} ticker_union;						// ��������

#endif	// !__SYSTEM_H
