#ifndef __SYSTEM_H
#define __SYSTEM_H

#define MAXIUM_NUM 0x5F5E0FF	// 数码管能显示的最大数值9999 9999

#include <STC89C5xRC.H>			// 包含stc官方头文件

typedef unsigned char	uint8_t;	//  8位无符号
typedef unsigned int	uint16_t;	// 16位无符号
typedef unsigned long	uint32_t;	// 32位无符号

// soft delay
void delay_ms(uint16_t nCount);		// 软件延时, 单位毫秒

typedef union {						// 联合体, 用于显示时的定时计数器赋值
	uint16_t value;					// 外部写入时使用的接口
	uint8_t T[2];					// 中断函数内部复位使用的接口
} ticker_union;						// 联合体名

#endif	// !__SYSTEM_H
