#ifndef __KEYBOARD_H
#define __KEYBOARD_H

#include "system.h"

// keyboard port
#define		KEY_MAT		P1

// keyboard initiate
void KeyboardInit();

// key matrix scan function
uint8_t scan_row(uint8_t row);



#endif	// !__KEYBOARD_H
