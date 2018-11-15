#include "system.h"
#include "digital.h"
#include "keyboard.h"
#include "displayStruct.h"
#include <stdio.h>
#include <string.h>

#define BUFF_LENGTH 8

/*
		'1'		'2'		'3'		↑
		S1		S2		S3		S4
		'4'		'5'		'6'		↓
		S5		S6		S7		S8
		'7'		'8'		'9'		'\n'
		S9		S10		S11		S12
				'0'				'\b'
		S13		S14		S15		S16
*/

int main()
{
	unsigned char buff[BUFF_LENGTH][9];	// 输入缓存
	uint8_t buff_row = 0,				// 读写缓存的行
			buff_row_swap;				// 换行符号专用迭代标记变量
	uint8_t matrix_row	= 0,			// 按键按下的行
			matrix_col	= 0;			// 按键按下的列
	uint8_t picked = 0;					// 按下的按键编号(1 ~ 16)
	uint8_t digs = 0;					// 显示在屏幕上的位数(右对齐)
	
	for(buff_row = 0; buff_row < BUFF_LENGTH; buff_row++)
		buff[buff_row][0] = '\0';
	
	KeyboardInit();
	DigitalInit();
	
	buff_row = 0;
	
	while(1)
	{
		matrix_row = 0;
		picked = 0;
		
		while(matrix_row == 0)
		{
			Display_str(*(buff+buff_row), digs);
			for(matrix_col = 0; matrix_col < 4 && matrix_row == 0; matrix_col++)
			{
				matrix_row = scan_col(matrix_col);
			}
		}
		
		picked = ((matrix_row - 1) << 2) + matrix_col;
		
		if(picked == 4)				//	↑
		{
			if(buff_row == 0)
				continue;
			else
			{
				buff_row--;
				for(digs = 0; 
					buff[buff_row][digs] != '\0';
					digs++);
			}
		}
		else if(picked == 8)		//	↓
		{
			if(buff_row == BUFF_LENGTH - 1)
				continue;
			else
			{
				buff_row++;
				for(digs = 0; 
					buff[buff_row][digs] != '\0';
					digs++);
			}
		}
		else if(picked == 12)		// '\n'
		{
			if(buff_row == BUFF_LENGTH - 1)
				continue;
			else
			{
				buff_row++;
				for(buff_row_swap = BUFF_LENGTH - 1;
					buff_row_swap > buff_row;
					buff_row_swap--)
				{
					strcpy(buff[buff_row_swap], buff[buff_row_swap - 1]);
				}
				buff[buff_row][0] = '\0';
				digs = 0;
			}
		}
		else if(picked == 16)		// '\b'
		{
			if(digs == 0)
				continue;
			else
			{
				buff[buff_row][--digs] = '\0';
			}
		}
		else						// '0' ~ '9'
		{
			if(digs == 8)
				continue;
		}

		switch(picked)
		{
			case 1: case 2: case 3:
				buff[buff_row][digs] = '0' + picked;
				buff[buff_row][++digs] = '\0';
				break;
			case 5: case 6: case 7:
				buff[buff_row][digs] = '0' + picked - 1;
				buff[buff_row][++digs] = '\0';
				break;
			case 9: case 10: case 11:
				buff[buff_row][digs] = '0' + picked - 2;
				buff[buff_row][++digs] = '\0';
				break;
			case 14:
				buff[buff_row][digs] = '0';
				buff[buff_row][++digs] = '\0';
				break;
			default:
				break;
		}
	}
}
