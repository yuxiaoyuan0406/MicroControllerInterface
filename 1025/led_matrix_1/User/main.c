#include "main.h"

#define display_time 0x2f

void main()
{
	uint8_t picked		= 0;
	uint8_t matrix_row	= 0,
			matrix_col	= 0;
	
	KeyboardInit();
	MatrixInit();
	
	while(matrix_col == 0)
	{
		for(matrix_row = 0; matrix_row < 4 && matrix_col == 0; matrix_row++)
		{
			Display_figure(figure_of_waiting[matrix_row]);
			matrix_col = scan_row(matrix_row);
		}
	}
	
	picked = ((matrix_row - 1) << 2) + matrix_col;
	
	while(1)
	{
		Display_figure(figure_of_number[picked]);
	}
}
