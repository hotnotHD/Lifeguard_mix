/*
 * gas_sensor.h
 *
 *  Created on: 28 июн. 2022 г.
 *      Author: Admin
 */

#ifndef INC_GAS_SENSOR_H_
#define INC_GAS_SENSOR_H_

#define I2C_ADDRESS 0x00
#define GETSNCOM 0x01
#define GETGASTYPE 0x02
#define GETBOTH 0x03
#define GETGASVALUE 0x04
#define GETOXYVALUE 0x05
#define GETBOTH 0x03
#define SETGASTYPE 0x06
#define SETLEDMODE 0x07
#define CALOXY 0x0b

#include "stm32f3xx_hal.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void getSN (I2C_HandleTypeDef hi2c1, char * out);

void getGasType (I2C_HandleTypeDef hi2c1, char * out);

//void getGasValue (I2C_HandleTypeDef hi2c1, char * out);

void setGasType(I2C_HandleTypeDef hi2c1, int num);

void test_gas_sensor (I2C_HandleTypeDef hi2c1);

void getOxyValue(I2C_HandleTypeDef hi2c1, char * out);

void get_both(I2C_HandleTypeDef hi2c1, uint16_t out[]);

uint8_t calOxy(I2C_HandleTypeDef hi2c1, uint8_t lbyte, uint8_t hbyte);

bool sum_check(uint8_t hi, uint8_t lo, uint8_t hi2, uint8_t lo2, uint8_t sum_ans);

#endif /* INC_GAS_SENSOR_H_ */
