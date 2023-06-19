/*
 * button_press_check.c
 *
 *  Created on: 15 мая 2023 г.
 *      Author: User
 */

#include <button_press_check.h>
#include "../../Modules/Button/button.h"
#include <gas_sensor.h>
#include <window_drawer.h>
#include "../../Modules/LCD/stm32_adafruit_lcd.h"

void button_led_init() {
	HAL_GPIO_WritePin(ON_OFF_LED_GPIO_Port, ON_OFF_LED_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(HEAT_LED_GPIO_Port, HEAT_LED_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(MIX_LED_GPIO_Port, MIX_LED_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(O2_LED_GPIO_Port, O2_LED_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(KEY_EN_GPIO_Port, KEY_EN_Pin, GPIO_PIN_SET);
}

void button_on() {
	HAL_GPIO_WritePin(ON_OFF_LED_GPIO_Port, ON_OFF_LED_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LCD_BL_GPIO_Port, LCD_BL_Pin, GPIO_PIN_SET);
}

void button_off() {
	HAL_GPIO_WritePin(ON_OFF_LED_GPIO_Port, ON_OFF_LED_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LCD_BL_GPIO_Port, LCD_BL_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(HEAT_LED_GPIO_Port, HEAT_LED_Pin, PIN_ON);
	HAL_GPIO_WritePin(MIX_LED_GPIO_Port, MIX_LED_Pin, PIN_ON);
	HAL_GPIO_WritePin(O2_LED_GPIO_Port, O2_LED_Pin, PIN_ON);
	HAL_GPIO_WritePin(O2_VALVE_GPIO_Port, O2_VALVE_Pin, PIN_OFF);
	HAL_GPIO_WritePin(MIX_VALVE_GPIO_Port, MIX_VALVE_Pin, PIN_OFF);
}

void button_check(I2C_HandleTypeDef hi2c1, uint8_t *o2_mode, uint8_t *mix_mode,
		DUPLO_MODE *cur_mode, uint8_t *mute_counter, bool *settings_open,
		uint8_t *set_mode) {
	char string[8];

	if (BUTTON_GetAction(BUTTON_OK) == BUTTON_LONG_PRESS) {
		if (!*settings_open) {
			delete_main_frame();
			*settings_open = true;
			settings_frame();
			circle_draw(set_mode, 0);
		} else {
			switch (*set_mode) {
			case 1:
				cur_mode->ar_setting = 300;
				break;
			case 2:
				cur_mode->ar_setting = 350;
				break;
			case 3:
				cur_mode->ar_setting = 400;
				break;
			case 4:
				cur_mode->o2_setting = 300;
				break;
			case 5:
				cur_mode->o2_setting = 350;
				break;
			case 6:
				cur_mode->o2_setting = 400;
				break;
			case 7:
				*settings_open = false;
				delete_main_frame();
				main_page();
				for (int i = 0; i < cur_mode->vent; i++) {
					change_vent_mode(i);
				}
				*set_mode = 1;
				break;
			}

		}

	}

	if (BUTTON_GetAction(BUTTON_OK) == BUTTON_VERY_LONG_PRESS) {
		sprintf(string, "OK");
		BSP_LCD_DisplayStringAt(220, 180, (uint8_t*) string, LEFT_MODE); // gas

		calOxy(hi2c1, 0xD2, 0x00);
	}

	if (BUTTON_GetAction(BUTTON_UP) == BUTTON_LONG_PRESS) {
		if (*set_mode > 1 && *settings_open) {
			*set_mode -= 1;
			circle_draw(set_mode, *set_mode + 1);
		}
	}

	if (BUTTON_GetAction(BUTTON_DOWN) == BUTTON_LONG_PRESS) {
		if (*set_mode < 7 && *settings_open) {
			*set_mode += 1;
			circle_draw(set_mode, *set_mode - 1);
		}
	}

	if (BUTTON_GetAction(BUTTON_HEAT) == BUTTON_LONG_PRESS) {
		switch (HAL_GPIO_ReadPin(HEAT_LED_GPIO_Port, HEAT_LED_Pin)) {
		case GPIO_PIN_SET:
			HAL_GPIO_WritePin(HEAT_LED_GPIO_Port, HEAT_LED_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(HEAT_VALVE_GPIO_Port, HEAT_VALVE_Pin,
					GPIO_PIN_SET);
			break;
		case GPIO_PIN_RESET:
			HAL_GPIO_WritePin(HEAT_LED_GPIO_Port, HEAT_LED_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(HEAT_VALVE_GPIO_Port, HEAT_VALVE_Pin,
					GPIO_PIN_RESET);
			break;
		default:
			break;
		}
	}

	if (BUTTON_GetAction(BUTTON_O2) == BUTTON_LONG_PRESS) {
		switch (HAL_GPIO_ReadPin(O2_LED_GPIO_Port, O2_LED_Pin)) {
		case GPIO_PIN_SET:
			HAL_GPIO_WritePin(O2_LED_GPIO_Port, O2_LED_Pin, GPIO_PIN_RESET);
			*o2_mode = 1;
			break;
		case GPIO_PIN_RESET:
			HAL_GPIO_WritePin(O2_LED_GPIO_Port, O2_LED_Pin, GPIO_PIN_SET);
			*o2_mode = 0;
			break;
		default:
			break;
		}
	}

	if (BUTTON_GetAction(BUTTON_MIX) == BUTTON_LONG_PRESS) {
		switch (HAL_GPIO_ReadPin(MIX_LED_GPIO_Port, MIX_LED_Pin)) {
		case GPIO_PIN_SET:
			HAL_GPIO_WritePin(MIX_LED_GPIO_Port, MIX_LED_Pin, GPIO_PIN_RESET);
			*mix_mode = 1;
			break;
		case GPIO_PIN_RESET:
			HAL_GPIO_WritePin(MIX_LED_GPIO_Port, MIX_LED_Pin, GPIO_PIN_SET);
			*mix_mode = 0;
			break;
		default:
			break;
		}
	}

	if (BUTTON_GetAction(BUTTON_VENT) == BUTTON_LONG_PRESS && !*settings_open) {
		cur_mode->vent = change_vent_mode(cur_mode->vent);
	}

	if (BUTTON_GetAction(BUTTON_MUTE) == BUTTON_LONG_PRESS)
		*mute_counter = 120;

	cur_mode->mode = (*mix_mode + (*o2_mode * 10));
}
