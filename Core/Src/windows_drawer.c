/*
 * windows_drower.c
 *
 *  Created on: 22 сент. 2022 г.
 *      Author: Admin
 */

#include <window_drawer.h>
#include "../../Modules/Button/button.h"
#include "../../Modules/LCD/stm32_adafruit_lcd.h"

void main_page() {
	BSP_LCD_SetFont(&Font24);

	BSP_LCD_DisplayStringAt(66, 80, (uint8_t*) "O2", LEFT_MODE);

	BSP_LCD_DisplayStringAt(220, 80, (uint8_t*) "CO2", LEFT_MODE);
	BSP_LCD_DisplayStringAt(360, 80, (uint8_t*) "Ar+Xe", LEFT_MODE);

	BSP_LCD_DisplayStringAt(66, 220, (uint8_t*) "T", LEFT_MODE);
	BSP_LCD_DisplayStringAt(55, 280, (uint8_t*) "`C", LEFT_MODE);

	BSP_LCD_DisplayStringAt(210, 220, (uint8_t*) "Vent", LEFT_MODE);
	BSP_LCD_DisplayStringAt(370, 220, (uint8_t*) "Hum.", LEFT_MODE);

	// Вентилятор индикатор
	BSP_LCD_DrawRect(200, 280, 15, 30);
	BSP_LCD_DrawRect(230, 260, 15, 50);
	BSP_LCD_DrawRect(260, 240, 15, 70);
	BSP_LCD_SetFont(&Font20_rus);
	BSP_LCD_DisplayStringAt(25, 10, (uint8_t*) "KGXL-1", LEFT_MODE);

	BSP_LCD_DisplayStringAt(380, 280, (uint8_t*) "%", LEFT_MODE);
	BSP_LCD_DisplayStringAt(50, 140, (uint8_t*) "ob.%", LEFT_MODE);
	BSP_LCD_DisplayStringAt(220, 140, (uint8_t*) "ob.%", LEFT_MODE);
	BSP_LCD_DisplayStringAt(370, 140, (uint8_t*) "ob.%", LEFT_MODE);
	BSP_LCD_DisplayStringAt(208, 10, (uint8_t*) "Re#im      ", LEFT_MODE);

	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);

	// Вывод сетки на экран
	BSP_LCD_DrawLine(0, 0, 480, 0);
	BSP_LCD_DrawLine(0, 0, 0, 320);
	BSP_LCD_DrawLine(0, 320, 480, 320);
	BSP_LCD_DrawLine(480, 0, 480, 320);
	BSP_LCD_DrawLine(160, 0, 160, 320);
	BSP_LCD_DrawLine(0, 40, 480, 40);
	BSP_LCD_DrawLine(0, 180, 480, 180);
	BSP_LCD_DrawLine(320, 40, 320, 320);
}

void menu_open(uint8_t rect_y) {
	BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
	BSP_LCD_FillRect(1, 41, 140, 130);
	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);

	BSP_LCD_DrawLine(0, 80, 160, 80);
	BSP_LCD_DrawLine(0, 120, 160, 120);
	BSP_LCD_DrawLine(0, 160, 160, 160);

	BSP_LCD_SetFont(&Font20_rus);
	BSP_LCD_DisplayStringAt(30, 50, (uint8_t*) "Re#im 1", LEFT_MODE);
	BSP_LCD_DisplayStringAt(30, 90, (uint8_t*) "Re#im 2", LEFT_MODE);
	BSP_LCD_DisplayStringAt(30, 130, (uint8_t*) "Re#im 3", LEFT_MODE);

	// текущее выделение
	BSP_LCD_FillCircle(145, 20, 7);

	BSP_LCD_SetTextColor(LCD_COLOR_RED);
	BSP_LCD_DrawRect(1, rect_y, 159, 39);
	BSP_LCD_DrawRect(2, rect_y + 1, 157, 37);
	BSP_LCD_DrawRect(3, rect_y + 2, 159 - 4, 39 - 4);

	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
}

void delete_menu() {
	BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
	BSP_LCD_FillRect(0, 0, 160, 180);
	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
}

void sensors_draw(uint16_t o2_value, uint16_t adc_t, uint16_t adc_h,
		uint16_t adc_co, uint16_t ar_value, DUPLO_MODE *cur_mode) {
	char string[8];
	// O2
	BSP_LCD_SetFont(&Font20_rus);
	if (HAL_GPIO_ReadPin(O2_VALVE_GPIO_Port, O2_VALVE_Pin))
		BSP_LCD_SetTextColor(LCD_COLOR_BLUE);
	if (o2_value < 190) {
		BSP_LCD_SetTextColor(LCD_COLOR_RED);
	}
	if (o2_value <= 1000) {
		sprintf(string, "%.1f(%d) ", (float) o2_value / 10,
				cur_mode->o2_setting / 10);
		BSP_LCD_DisplayStringAt(30, 120, (uint8_t*) string, LEFT_MODE);
	}
	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);

	// ar set
	if (HAL_GPIO_ReadPin(MIX_VALVE_GPIO_Port, MIX_VALVE_Pin))
		BSP_LCD_SetTextColor(LCD_COLOR_GREEN);
	if (ar_value < 100) { //10
		ar_value = 0;
	}
	if (ar_value <= 1000) {
		sprintf(string, "%.1f(%d) ", (float) ar_value / 10,
				cur_mode->ar_setting / 10);
		BSP_LCD_DisplayStringAt(350, 120, (uint8_t*) string, LEFT_MODE);
	}
	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);

	// CO2
	if (adc_co > 100) { //1
		BSP_LCD_SetTextColor(LCD_COLOR_RED);
	}
	sprintf(string, "%.2f ", ((float) adc_co / 100.));
	BSP_LCD_DisplayStringAt(220, 120, (uint8_t*) string, LEFT_MODE);
	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);

	// Temperature
	if (adc_t > 4000)
		BSP_LCD_SetTextColor(LCD_COLOR_RED);
	sprintf(string, "%.1f ", ((float) adc_t / 100.));
	BSP_LCD_DisplayStringAt(50, 250, (uint8_t*) string, LEFT_MODE);
	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);

	// Humidity
	sprintf(string, "%.0f ", ((float) adc_h / 100.));
	BSP_LCD_DisplayStringAt(370, 250, (uint8_t*) string, LEFT_MODE);
}

void work_mode(uint8_t mode) {
	BSP_LCD_SetFont(&Font20_rus);
	switch (mode) {
	case 0:
		BSP_LCD_DisplayStringAt(208, 10, (uint8_t*) "Re#im      ", LEFT_MODE);
		break;
	case 1:
		BSP_LCD_DisplayStringAt(208, 10, (uint8_t*) "Re#im", LEFT_MODE);
		BSP_LCD_SetFont(&Font24);
		BSP_LCD_DisplayStringAt(292, 10, (uint8_t*) "AR    ", LEFT_MODE);
		BSP_LCD_SetFont(&Font20_rus);
		break;
	case 10:
		BSP_LCD_DisplayStringAt(208, 10, (uint8_t*) "Re#im", LEFT_MODE);
		BSP_LCD_SetFont(&Font24);
		BSP_LCD_DisplayStringAt(292, 10, (uint8_t*) "O2    ", LEFT_MODE);
		BSP_LCD_SetFont(&Font20_rus);
		break;
	case 11:
		BSP_LCD_DisplayStringAt(208, 10, (uint8_t*) "Re#im", LEFT_MODE);
		BSP_LCD_SetFont(&Font24);
		BSP_LCD_DisplayStringAt(292, 10, (uint8_t*) "AR+O2 ", LEFT_MODE);
		BSP_LCD_SetFont(&Font20_rus);
		break;
	default:
		BSP_LCD_DisplayStringAt(208, 10, (uint8_t*) "Re#im      ", LEFT_MODE);
		break;
	}
}

uint8_t change_vent_mode(uint8_t ven_mode) {
	switch (ven_mode) {
	case 0:
		BSP_LCD_FillRect(200, 280, 15, 30);
		TIM3->CCR2 = 75;
		return ++ven_mode;
		break;
	case 1:
		BSP_LCD_FillRect(230, 260, 15, 50);
		TIM3->CCR2 += 25;
		return ++ven_mode;
		break;
	case 2:
		BSP_LCD_FillRect(260, 240, 15, 70);
		TIM3->CCR2 += 25;
		return ++ven_mode;
		break;
	case 3:
		BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
		BSP_LCD_FillRect(261, 241, 13, 68);
		BSP_LCD_FillRect(231, 261, 13, 48);
		BSP_LCD_FillRect(201, 281, 13, 28);
		BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
		TIM3->CCR2 = 0;
		return 0;
		break;
	}
	return 0;
}

void delete_main_frame() {
	BSP_LCD_Clear(LCD_COLOR_BLACK);
}

void settings_draw(DUPLO_MODE *cur_mode) {
	char string[16];
	BSP_LCD_SetFont(&Font24);
	sprintf(string, "Ar:%d O2:%d ", cur_mode->ar_setting / 10,
			cur_mode->o2_setting / 10);
	BSP_LCD_DisplayStringAt(190, 15, (uint8_t*) string, LEFT_MODE);
}

void settings_frame() {
	BSP_LCD_SetFont(&Font20_rus);

	for (int i = 0; i < 320; i += 40) {
		BSP_LCD_DrawLine(0, i, 480, i);
	}
	BSP_LCD_DrawLine(0, 0, 0, 320);
	BSP_LCD_DrawLine(0, 320, 480, 320);
	BSP_LCD_DrawLine(480, 0, 480, 320);
	BSP_LCD_DrawLine(160, 0, 160, 40);
	BSP_LCD_DisplayStringAt(20, 15, (uint8_t*) "Nastro*ka", LEFT_MODE);
	BSP_LCD_SetFont(&Font24);
	BSP_LCD_DisplayStringAt(40, 55, (uint8_t*) "Ar 30", LEFT_MODE);
	BSP_LCD_DisplayStringAt(40, 95, (uint8_t*) "Ar 35", LEFT_MODE);
	BSP_LCD_DisplayStringAt(40, 135, (uint8_t*) "Ar 40", LEFT_MODE);
	BSP_LCD_DisplayStringAt(40, 175, (uint8_t*) "O2 30", LEFT_MODE);
	BSP_LCD_DisplayStringAt(40, 215, (uint8_t*) "O2 35", LEFT_MODE);
	BSP_LCD_DisplayStringAt(40, 255, (uint8_t*) "O2 40", LEFT_MODE);
	BSP_LCD_SetFont(&Font20_rus);
	BSP_LCD_DisplayStringAt(40, 295, (uint8_t*) "V$hod", LEFT_MODE);
}

void circle_draw(uint8_t *cur_mode, uint8_t prev_mode) {
	if (prev_mode != 0) {
		BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
		BSP_LCD_FillCircle(20, 25 + 40 * prev_mode, 7);
		BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
	}
	BSP_LCD_FillCircle(20, 25 + 40 * *cur_mode, 7);
}

