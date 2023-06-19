
#ifndef WINDOW_DRAWER_H
#define WINDOW_DRAWER_H

#include "main.h"

#define VREF 3.25

void menu_open(uint8_t rect_y);
void delete_menu();
void sensors_draw(uint16_t o2_value, uint16_t adc_t, uint16_t adc_h, uint16_t adc_co, uint16_t ar_value, DUPLO_MODE *cur_mode);
void delete_main_frame();
void settings_frame();
void circle_draw(uint8_t *cur_mode, uint8_t prev_mode);
void button_up(uint8_t *mix_setting);
void button_down(uint8_t *mix_setting);
void settings_draw(DUPLO_MODE *cur_mode);
void main_page();
void work_mode(uint8_t mode);
uint8_t change_vent_mode(uint8_t ven_mode);

#endif
