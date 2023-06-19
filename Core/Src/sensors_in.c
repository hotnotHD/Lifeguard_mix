/*
 * sensors_in.c
 *
 *  Created on: 14 мая 2023 г.
 *      Author: User
 */

#include <sensors_in.h>

float co2_adc(int a, int vref, float c) {
	return (((float) a * vref / 4096.) - 0.40) * c;
}

uint16_t crc16(const unsigned char *buf, unsigned int len) {
	static const uint16_t table[2] = { 0x0000, 0xA001 };
	uint16_t crc = 0xFFFF;
	unsigned int i = 0;
	char bit = 0;
	unsigned int xor = 0;

	for (i = 0; i < len; i++) {
		crc ^= buf[i];

		for (bit = 0; bit < 8; bit++) {
			xor = crc & 0x01;
			crc >>= 1;
			crc ^= table[xor];
		}
	}
	return crc;
}

void modbus_get_temp_hum(UART_HandleTypeDef huart2, uint16_t *temp,
		uint16_t *hum) {
	uint8_t TxData[16] = { 0x00 };
	uint8_t RxData[16] = { 0x00 };
	uint16_t crc1;

	TxData[0] = 0x01;
	TxData[1] = 0x03;
	TxData[2] = 0x00;
	TxData[3] = 0x00;
	TxData[4] = 0x00;
	TxData[5] = 0x02;
	TxData[6] = 0xC4;
	TxData[7] = 0x0B;

	HAL_GPIO_WritePin(RX_TX_RS_GPIO_Port, RX_TX_RS_Pin, GPIO_PIN_SET);
	HAL_UART_Transmit(&huart2, TxData, 16, 25);
	HAL_GPIO_WritePin(RX_TX_RS_GPIO_Port, RX_TX_RS_Pin, GPIO_PIN_RESET);
	HAL_UART_Receive(&huart2, RxData, 16, 25);

	crc1 = crc16(RxData + 1, 7);

	if (crc1 % 256 == RxData[8] && crc1 / 256 == RxData[9]) {
		*temp = ((RxData[4] << 8) + RxData[5]);
		*hum = ((RxData[6] << 8) + RxData[7]);
	}
}
