/*
 * gpio.c
 *
 *  Created on: Oct 9, 2024
 *      Author: f1rset
 */

#include "gpio.h"
#include "main.h"
void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LCD1_RST_Pin|LCD1_DC_Pin|LCD1_CS_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, LCD2_RST_Pin|LCD2_DC_Pin|LCD2_CS_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : LCD1_RST_Pin LCD1_DC_Pin LCD1_CS_Pin */
  GPIO_InitStruct.Pin = LCD1_RST_Pin|LCD1_DC_Pin|LCD1_CS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : LCD2_RST_Pin LCD2_DC_Pin LCD2_CS_Pin */
  GPIO_InitStruct.Pin = LCD2_RST_Pin|LCD2_DC_Pin|LCD2_CS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}
