#include "system.h"
#include "matrix.h"
#include "keyboard.h"
#include "snake.h"

#define display_time 0x2f

uint8_t img[] = 
{
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

uint8_t snake[SNAKE_LENGTH] = 
{
	000, 000, 000, 000, 000, 000, 		// 八进制数, 高位为行 低位为列
};

void Display_snake(void)
{
	
}

int main()
{
	uint8_t delay_time;
	uint8_t direction = LEFT;
	uint8_t iterator;
	
	MatrixInit();
	KeyboardInit();
	
	for(iterator = 0; iterator < SNAKE_LENGTH; iterator++)
	{
		turn_on_one(snake[iterator]);
	}

//	turn_on_one(000);
	
	while(1)
	{
		for(delay_time = 0; delay_time < display_time; delay_time++)
		{
			
		}
		Display_figure(img);
	}
}
