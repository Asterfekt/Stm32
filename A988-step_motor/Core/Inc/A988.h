/*
 * A988.h
 *
 *  Created on: Mar 7, 2023
 *      Author: Mateusz Krzyściak
 */

#ifndef INC_A988_H_
#define INC_A988_H_

#pragma once

#include "stm32f4xx.h"

typedef enum
{
	NOSTEP = 0,
	STEP = 1
}STEP_Mode;

typedef enum
{
	FIRST_DIRECTION= 1,
	SECOND_DIRICETION= 0
}DIR_Mode;

typedef enum
{
	NOSLEEP= 0,
	SLEEP= 1,
}SLEEP_Mode;


//Function prototype
void step(STEP_Mode);
void dir(DIR_Mode);
void sleep(SLEEP_Mode);


#endif /* INC_A988_H_ */
