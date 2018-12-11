#include "main.h"

#define display_time 0x2f

void main()
{
	uint8_t picked		= 0;		//	记录选中的数字
	uint8_t matrix_row	= 0,		//	记录行, 迭代用
			matrix_col	= 0;		//	记录列, 迭代返回的结果
	
	KeyboardInit();			//	初始化键盘
	MatrixInit();			//	初始化点阵
	
	while(matrix_col == 0)
	{
		for(matrix_row = 0; matrix_row < 4 && matrix_col == 0; matrix_row++)
		{
			Display_figure(figure_of_waiting[matrix_row]);
			matrix_col = scan_row(matrix_row);
		}
	}
	
	picked = ((matrix_row - 1) << 2) + matrix_col;		//	计算选中的数字
	
	while(1)
	{
		Display_figure(figure_of_number[picked]);		//	显示数组figure_of_number中标号为picked的一行
	}
}
