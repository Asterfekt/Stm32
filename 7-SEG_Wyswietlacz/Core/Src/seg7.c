/*
 * seg7.c
 *
 *  Created on: Feb 27, 2023
 *      Author: Mateusz Krzyściak
 */


#include <stdbool.h>
#include "seg7.h"
#include "gpio.h"

static void set_output(uint8_t mask)
{
	HAL_GPIO_WritePin(SEG_A_GPIO_Port, SEG_A_Pin, mask & 0x01);
	HAL_GPIO_WritePin(SEG_B_GPIO_Port, SEG_B_Pin, mask & 0x02);
	HAL_GPIO_WritePin(SEG_C_GPIO_Port, SEG_C_Pin, mask & 0x04);
	HAL_GPIO_WritePin(SEG_D_GPIO_Port, SEG_D_Pin, mask & 0x08);
	HAL_GPIO_WritePin(SEG_E_GPIO_Port, SEG_E_Pin, mask & 0x10);
	HAL_GPIO_WritePin(SEG_F_GPIO_Port, SEG_F_Pin, mask & 0x20);
	HAL_GPIO_WritePin(SEG_G_GPIO_Port, SEG_G_Pin, mask & 0x40);
}
void seg7_show_digit(uint32_t value)
{
	switch (value % 10) {
	case 0:
		set_output(0b1000000);
		break;
	case 1:
		set_output(0b1111001);
		break;
	case 2:
		set_output(0b0100100);
		break;
	case 3:
		set_output(0b0110000);
		break;
	case 4:
		set_output(0b0011001);
		break;
	case 5:
		set_output(0b0010010);
		break;
	case 6:
		set_output(0b0000010);
		break;
	case 7:
		set_output(0b1111000);
		break;
	case 8:
		set_output(0b0000000);
		break;
	case 9:
		set_output(0b0010000);
		break;
	}
}
static uint32_t actual_value;
static uint32_t active_digit;

void seg7_show(uint32_t value)
{
	actual_value = value;
}

void seg7_update(void)
{
	HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, GPIO_PIN_RESET);

	switch (active_digit) {
	case 0:
		seg7_show_digit(actual_value);
		HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, GPIO_PIN_SET);
		active_digit = 1;

		break;
	case 1:
		seg7_show_digit(actual_value/2 );
		HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, GPIO_PIN_SET);
		active_digit = 0;

		break;
	}
}
