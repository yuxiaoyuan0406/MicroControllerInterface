#ifndef __MATRIX_H
#define __MATRIX_H

#include <reg52.h>
#include "system.h"

// led matrix port
#define		ROW					P0	//行寄存器

// matrix row operator
#define		ENABLE_ROW(pos)		ROW = ~(1 << pos)
#define		DISABLE_ROW()		ROW = 0xff
#define		TOGGLE_ROW()		ROW = ~ROW

// soft delay
#define		BUFFER_DELAY()		delay(0x03)

// HC595 port
sbit Out	=	P3 ^ 4;		//串行数据线
sbit R_CLK	=	P3 ^ 5;		//数据并行输出控制
sbit S_CLK	=	P3 ^ 6;		//串行时钟线

// HC595 buffer function
void BufferSendData(uint8_t SendVal);

// HC595 operator
#define ENABLE_BUFFER()			\
do{								\
	R_CLK=0;					\
	BUFFER_DELAY();				\
	R_CLK=1;					\
}while(0)

#define 	DISABLE_BUFFER()	\
do{								\
	BufferSendData(0x00);		\
	ENABLE_BUFFER();			\
}while(0)

// initiate
void MatrixInit();

// display
void Display_figure(uint8_t * fig);

#endif	// !__MATRIX_H
