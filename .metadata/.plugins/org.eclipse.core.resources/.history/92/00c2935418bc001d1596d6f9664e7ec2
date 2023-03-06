/*
 * L2930.h
 *
 *  Created on: Feb 28, 2023
 *      Author: Mateusz Krzyściak
 */

#ifndef INC_L293D_H_
#define INC_L293D_H_
#include "stdint.h"
typedef enum
{
	In_In_Mode = 0,
	Phase_Enable_Mode = 1
}L293D_Mode;

typedef enum
{
	CW = 0,
	CCW = 1
}L293D_Direction;

void L293D_init();
void L293D_mode_control(L293D_Mode);
void L293D_set_motorA_direction(L293D_Direction);
void L293D_set_motorA_speed(uint8_t);

#endif /* INC_L293D_H_ */
