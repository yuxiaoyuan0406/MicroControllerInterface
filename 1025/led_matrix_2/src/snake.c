#include "snake.h"

extern uint8_t img[];
extern uint8_t snake[SNAKE_LENGTH];

bit turn_on_one(uint8_t pos)
{
	uint8_t row, col;
	pos &= 077;
	row = pos / 8;		// 行
	col = pos % 8;		// 列
	
	if(img[col] & (0x01 << row))
		return 0;
	else
	{
		img[col] |=  0x01 << row;
		return 1;
	}
}

bit turn_off_one(uint8_t pos)
{
	uint8_t row, col;
	pos &= 077;
	row = pos / 8;		// 行
	col = pos % 8;	// 列
	
	if(!(img[col] & (0x01 << row)))
		return 0;
	else
	{
		img[col] &=  ~(0x01 << row);
		return 1;
	}
}

void move_snake(uint8_t dir)
{
	
}
