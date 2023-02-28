/*
 * L2930.c
 *
 *  Created on: Feb 28, 2023
 *      Author: Mateusz Krzyściak
 */
#include <L293D.h>
#include "stdint.h"
#include "stdio.h"
#include "gpio.h"
#include "tim.h"

void L293D_mode_control(L293D_Mode mode)
{
	if(mode == Phase_Enable_Mode)
		HAL_GPIO_WritePin(MODE_GPIO_Port, MODE_Pin, SET);
	else if(mode == In_In_Mode)
		HAL_GPIO_WritePin(MODE_GPIO_Port, MODE_Pin, RESET);
}
void L293D_set_motorA_direction(L293D_Direction dir)
{
	if(dir == CW)
		HAL_GPIO_WritePin(APHASE_GPIO_Port, APHASE_Pin, SET);
	else if(dir == CCW)
		HAL_GPIO_WritePin(APHASE_GPIO_Port, APHASE_Pin, RESET);
}
void L293D_set_motorA_speed(uint8_t speed)
{
	if(speed >= htim2.Instance->ARR)
		speed = htim2.Instance->ARR;

	__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_3, speed);
}
void L293D_init()
{
	L293D_mode_control(Phase_Enable_Mode);
	L293D_set_motorA_direction(CCW);
	L293D_set_motorA_speed(0);

	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_3);
}
