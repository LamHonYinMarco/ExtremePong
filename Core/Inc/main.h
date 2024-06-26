/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
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
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

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
#define a1_Pin GPIO_PIN_5
#define a1_GPIO_Port GPIOE
#define f1_Pin GPIO_PIN_6
#define f1_GPIO_Port GPIOE
#define K2_Pin GPIO_PIN_13
#define K2_GPIO_Port GPIOC
#define K2_EXTI_IRQn EXTI15_10_IRQn
#define K1_Pin GPIO_PIN_0
#define K1_GPIO_Port GPIOA
#define K1_EXTI_IRQn EXTI0_IRQn
#define c1_Pin GPIO_PIN_4
#define c1_GPIO_Port GPIOA
#define d1_Pin GPIO_PIN_5
#define d1_GPIO_Port GPIOA
#define g1_Pin GPIO_PIN_6
#define g1_GPIO_Port GPIOA
#define e1_Pin GPIO_PIN_7
#define e1_GPIO_Port GPIOA
#define b1_Pin GPIO_PIN_4
#define b1_GPIO_Port GPIOC
#define c2_Pin GPIO_PIN_12
#define c2_GPIO_Port GPIOB
#define d2_Pin GPIO_PIN_13
#define d2_GPIO_Port GPIOB
#define g2_Pin GPIO_PIN_14
#define g2_GPIO_Port GPIOB
#define e2_Pin GPIO_PIN_15
#define e2_GPIO_Port GPIOB
#define a2_Pin GPIO_PIN_6
#define a2_GPIO_Port GPIOC
#define f2_Pin GPIO_PIN_7
#define f2_GPIO_Port GPIOC
#define player2Touch_Pin GPIO_PIN_8
#define player2Touch_GPIO_Port GPIOA
#define player1Touch_Pin GPIO_PIN_11
#define player1Touch_GPIO_Port GPIOA
#define b2_Pin GPIO_PIN_8
#define b2_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
