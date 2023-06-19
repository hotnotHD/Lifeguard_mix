/*
 * button_press_check.h
 *
 *  Created on: 15 мая 2023 г.
 *      Author: User
 */

#ifndef INC_BUTTON_PRESS_CHECK_H_
#define INC_BUTTON_PRESS_CHECK_H_

#include "main.h"

void button_led_init();
void button_check(I2C_HandleTypeDef hi2c1, uint8_t *o2_mode, uint8_t *mix_mode, DUPLO_MODE *cur_mode, uint8_t *mute_counter, bool *settings_open, uint8_t *set_mode);
void button_off();
void button_on();
#endif /* INC_BUTTON_PRESS_CHECK_H_ */
