/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f3xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

typedef struct
{
  uint8_t mode;
  uint8_t vent;
  uint16_t ar_setting;
  uint16_t o2_setting;
} DUPLO_MODE;


/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LOCK_SIGNAL_Pin GPIO_PIN_13
#define LOCK_SIGNAL_GPIO_Port GPIOC
#define ON_OFF_BUTTON_Pin GPIO_PIN_14
#define ON_OFF_BUTTON_GPIO_Port GPIOC
#define O2_BUTTON_Pin GPIO_PIN_15
#define O2_BUTTON_GPIO_Port GPIOC
#define MUTE_BUTTON_Pin GPIO_PIN_1
#define MUTE_BUTTON_GPIO_Port GPIOF
#define ON_OFF_LED_Pin GPIO_PIN_0
#define ON_OFF_LED_GPIO_Port GPIOC
#define O2_LED_Pin GPIO_PIN_1
#define O2_LED_GPIO_Port GPIOC
#define MIX_LED_Pin GPIO_PIN_2
#define MIX_LED_GPIO_Port GPIOC
#define HEAT_LED_Pin GPIO_PIN_3
#define HEAT_LED_GPIO_Port GPIOC
#define HUM_ANALOG_Pin GPIO_PIN_1
#define HUM_ANALOG_GPIO_Port GPIOA
#define TEMP_ANALOG_Pin GPIO_PIN_4
#define TEMP_ANALOG_GPIO_Port GPIOF
#define KEY_EN_Pin GPIO_PIN_4
#define KEY_EN_GPIO_Port GPIOA
#define LCD_DC_Pin GPIO_PIN_6
#define LCD_DC_GPIO_Port GPIOA
#define FAN_BUTTON_Pin GPIO_PIN_0
#define FAN_BUTTON_GPIO_Port GPIOB
#define MIX_VALVE_Pin GPIO_PIN_1
#define MIX_VALVE_GPIO_Port GPIOB
#define RX_TX_RS_Pin GPIO_PIN_2
#define RX_TX_RS_GPIO_Port GPIOB
#define MUTE_VALVE_Pin GPIO_PIN_10
#define MUTE_VALVE_GPIO_Port GPIOB
#define HEAT_BUTTON_Pin GPIO_PIN_11
#define HEAT_BUTTON_GPIO_Port GPIOB
#define LCD_BL_Pin GPIO_PIN_12
#define LCD_BL_GPIO_Port GPIOB
#define MIX_BUTTON_Pin GPIO_PIN_8
#define MIX_BUTTON_GPIO_Port GPIOC
#define UP_BUTTON_Pin GPIO_PIN_8
#define UP_BUTTON_GPIO_Port GPIOA
#define OK_BUTTON_Pin GPIO_PIN_9
#define OK_BUTTON_GPIO_Port GPIOA
#define DOWN_BUTTON_Pin GPIO_PIN_10
#define DOWN_BUTTON_GPIO_Port GPIOA
#define LCD_RST_Pin GPIO_PIN_11
#define LCD_RST_GPIO_Port GPIOA
#define LCD_CS_Pin GPIO_PIN_12
#define LCD_CS_GPIO_Port GPIOA
#define I2C_SCL_INSOFT_Pin GPIO_PIN_15
#define I2C_SCL_INSOFT_GPIO_Port GPIOA
#define HEAT_VALVE_Pin GPIO_PIN_4
#define HEAT_VALVE_GPIO_Port GPIOB
#define PWM_VENT_Pin GPIO_PIN_5
#define PWM_VENT_GPIO_Port GPIOB
#define I2C_SDA_INSOFT_Pin GPIO_PIN_7
#define I2C_SDA_INSOFT_GPIO_Port GPIOB
#define O2_VALVE_Pin GPIO_PIN_9
#define O2_VALVE_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

#define PIN_OFF (GPIO_PIN_RESET)
#define PIN_ON (GPIO_PIN_SET)

#define SETTING_AR_HI 400 //40
#define SETTING_AR_LOW 350

#define SETTING_O2_HI 400  //37-40
#define SETTING_O2_LOW 370

#define SETTING_O2_ON_AR_HI 350
#define SETTING_O2_ON_AR_LO 330

#define SPEED_0 0
#define SPEED_1 1
#define SPEED_2 2
#define SPEED_3 3

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
