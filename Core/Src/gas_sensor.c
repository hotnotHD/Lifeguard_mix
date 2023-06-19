/*
 * gas_sensor.c
 *
 *  Created on: 28 июн. 2022 г.
 *      Author: Admin
 */

#include "gas_sensor.h"

void getSN(I2C_HandleTypeDef hi2c1, char *out) {
	uint8_t comCode = GETSNCOM;
	uint8_t answer2[] = { 0x00, 0x00 };
	int16_t res = 0;
	char string[8];

	HAL_I2C_Master_Transmit(&hi2c1, (I2C_ADDRESS << 1), &comCode, 1, 5);
	HAL_Delay(5);
	HAL_I2C_Master_Receive(&hi2c1, (I2C_ADDRESS << 1), &answer2[0], 1, 5);
	HAL_I2C_Master_Receive(&hi2c1, (I2C_ADDRESS << 1), &answer2[1], 1, 5);
	res = answer2[1] * 16 * 16 + answer2[0];

	sprintf(string, "%d", res);
	strcpy(out, string);
}

void getGasType(I2C_HandleTypeDef hi2c1, char *out) {
	uint8_t answer = 0x00;
	uint8_t comCode = GETGASTYPE;
	char *string;

	HAL_I2C_Master_Transmit(&hi2c1, (I2C_ADDRESS << 1), &comCode, 1, 5);
	HAL_Delay(5);
	HAL_I2C_Master_Receive(&hi2c1, (I2C_ADDRESS << 1), &answer, 1, 5);

	switch (answer) {
	case 0: {
		string = "Ar";
		break;
	}
	case 1: {
		string = "Ar+Xe";
		break;
	}
	default:
		break;
	}
	strcpy(out, string);
}

void getGasValue (I2C_HandleTypeDef hi2c1, char * out){

	uint8_t answer3[3] = {0x00, 0x00, 0x00};
	uint8_t comCode = GETGASVALUE;
	int8_t res = 0;
	uint8_t res1 = 0;
	char string[16];

	HAL_I2C_Master_Transmit(&hi2c1, (I2C_ADDRESS << 1), &comCode, 1, 5);
	HAL_Delay(5);
	HAL_I2C_Master_Receive(&hi2c1, (I2C_ADDRESS << 1), answer3, 3, 5);

	res = (answer3[1] * 16 * 16  + answer3[0]);
	res1 = res % 10;
	res = res / 10;

	sprintf(string, "%d.%d  ", res, res1);
    strcpy (out, string);
}

void setGasType(I2C_HandleTypeDef hi2c1, int num) {
	uint8_t comCode[2] = { SETGASTYPE, 0x00 };
	if (num == 1) {
		comCode[1] = 0x01;
	} else
		comCode[1] = 0x00;
	uint8_t answer0 = 0x00;
	HAL_I2C_Master_Transmit(&hi2c1, (I2C_ADDRESS << 1), comCode, 2, 5);
	HAL_Delay(5);
	HAL_I2C_Master_Receive(&hi2c1, (I2C_ADDRESS << 1), &answer0, 3, 5);
}

void getOxyValue(I2C_HandleTypeDef hi2c1, char *out) {
	uint8_t answer3[] = { 0x00, 0x00, 0x00 };
	uint8_t comCode = GETOXYVALUE;
	uint8_t res = 0;
	uint8_t res1 = 0;
	char string[8];

	HAL_I2C_Master_Transmit(&hi2c1, (I2C_ADDRESS << 1), &comCode, 1, 1);

	HAL_Delay(1);
	HAL_I2C_Master_Receive(&hi2c1, (I2C_ADDRESS << 1), answer3, 3, 1);

	res = (answer3[1] * 16 * 16 + answer3[0]);
	res1 = res % 10;
	res = res / 10;

	sprintf(string, "%d.%d  ", res, res1);

	strcpy(out, string);
}

void get_both(I2C_HandleTypeDef hi2c1, uint16_t out[]) {
	uint8_t answer5[] = { 0x00, 0x00, 0x00, 0x00, 0x00 };
	uint8_t comCode = GETBOTH;

	HAL_I2C_Master_Transmit(&hi2c1, (I2C_ADDRESS << 1), &comCode, 1, 5);
	HAL_Delay(5);
	HAL_I2C_Master_Receive(&hi2c1, (I2C_ADDRESS << 1), answer5, 5, 5);

	if (sum_check(answer5[0], answer5[1], answer5[2], answer5[3], answer5[4])) {
		out[0] = ((answer5[1] << 8) + answer5[0]);
		out[1] = ((answer5[3] << 8) + answer5[2]);
	}
}

uint8_t calOxy(I2C_HandleTypeDef hi2c1, uint8_t lbyte, uint8_t hbyte) {

	// lbyte and hbyte must be hexadecimal | format: (0x00)

	uint8_t cbyte = ~(lbyte + hbyte);
	uint8_t comCode[4] = { CALOXY, lbyte, hbyte, cbyte };
	uint8_t answer = 0x00;
	HAL_I2C_Master_Transmit(&hi2c1, (I2C_ADDRESS << 1), comCode, 4, 10);
	HAL_Delay(5);
	HAL_I2C_Master_Receive(&hi2c1, (I2C_ADDRESS << 1), &answer, 1, 10);

	return answer;
}

bool sum_check(uint8_t hi, uint8_t lo, uint8_t hi2, uint8_t lo2,
		uint8_t sum_ans) {
	uint8_t sum = 0;
	sum = hi + lo + hi2 + lo2;
	sum = ~sum;
	sum = sum & 255;
	if (sum_ans == sum)
		return true;
	else
		return false;
}

