/*
 * sensors_in.h
 *
 *  Created on: 14 мая 2023 г.
 *      Author: User
 */

#ifndef INC_SENSORS_IN_H_
#define INC_SENSORS_IN_H_

#include <main.h>

float co2_adc(int a, int vref, float c);
uint16_t crc16(const unsigned char *buf, unsigned int len);
void modbus_get_temp_hum(UART_HandleTypeDef huart2, uint16_t *temp, uint16_t *hum);

#endif /* INC_SENSORS_IN_H_ */
