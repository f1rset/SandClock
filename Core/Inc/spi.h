/*
 * spi.h
 *
 *  Created on: Oct 9, 2024
 *      Author: f1rset
 */

#ifndef SPI_H
#define SPI_H

#include "stm32f1xx_hal.h"  // Include your HAL library

// Declare hspi1 and hspi2 as an extern variables
extern SPI_HandleTypeDef hspi2;
extern SPI_HandleTypeDef hspi1;

void MX_SPI1_Init(void);
void MX_SPI2_Init(void);

#endif /* SPI_H */

