#ifndef __SNAKE_H
#define __SNAKE_H

#include "system.h"

#define SNAKE_LENGTH 6

enum {
	START, UP, DOWN, LEFT, RIGHT, END,
};

bit turn_on_one(uint8_t pos);

bit turn_off_one(uint8_t pos);

void move_snake(uint8_t dir);

#endif	// !__SNAKE_H
