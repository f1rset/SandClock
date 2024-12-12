/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "i2c.h"
#include "spi.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "lcd5110.h"
#include <string.h>
#include <stdio.h>
#include "mpu6050.h"
#include "SandClockF1rset.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
LCD5110_display lcd1;
LCD5110_display lcd2;
MPU6050_t MPU6050;
SandClock clock;
// Global variable to track timer expiration
volatile uint32_t elapsed_time_s = 0;
volatile uint32_t time = 0;

// Callback function for timer interrupt
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if (htim->Instance == TIM1)  // Check if the interrupt is from TIM1
    {
        elapsed_time_s++;
    }
}
//void print_arr(uint8_t arr[84][48], LCD5110_conf* lcd){
//	for (int i = 0; i < 84; i++){
//		  for (int j = 0; j < 48; j++){
//			  LCD5110_putpix(i, j, arr[i][j], &lcd);
//		  }
//	  }
//	  LCD5110_refresh(&lcd);
//
//}

void LCD5110_arr_out(uint8_t arr[ROWS][COLS], int match, LCD5110_display *lcd){
  for (int i = 0; i < COLS; i++) {
    for (int j = 0; j < ROWS; j++) {
        LCD5110_putpix(18+i, 47-j, arr[j][i], &lcd->hw_conf);
    }
  }
  LCD5110_refresh(lcd);
}
void LCD5110_arr_out_bottom(uint8_t arr[ROWS][COLS], int match, LCD5110_display *lcd){
  for (int i = 0; i < COLS; i++) {
    for (int j = 0; j < ROWS; j++) {
        LCD5110_putpix(18+i, j, arr[j][i], &lcd->hw_conf);
    }
  }
  LCD5110_refresh(lcd);
}


/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_SPI1_Init();
  MX_SPI2_Init();
  MX_TIM1_Init();
  MX_USART1_UART_Init();
  MX_I2C1_Init();
  /* USER CODE BEGIN 2 */
  lcd1.hw_conf.spi_handle = &hspi1;
  lcd1.hw_conf.spi_cs_pin =  LCD1_CS_Pin;
  lcd1.hw_conf.spi_cs_port = LCD1_CS_GPIO_Port;
  lcd1.hw_conf.rst_pin =  LCD1_RST_Pin;
  lcd1.hw_conf.rst_port = LCD1_RST_GPIO_Port;
  lcd1.hw_conf.dc_pin =  LCD1_DC_Pin;
  lcd1.hw_conf.dc_port = LCD1_DC_GPIO_Port;
  lcd1.def_scr = lcd5110_def_scr;
  LCD5110_init(&lcd1.hw_conf, LCD5110_NORMAL_MODE, 0x40, 2, 3);

  while(MPU6050_Init(&hi2c1)==1);

  lcd2.hw_conf.spi_handle = &hspi2;
  lcd2.hw_conf.spi_cs_pin =  LCD2_CS_Pin;
  lcd2.hw_conf.spi_cs_port = LCD2_CS_GPIO_Port;
  lcd2.hw_conf.rst_pin =  LCD2_RST_Pin;
  lcd2.hw_conf.rst_port = LCD2_RST_GPIO_Port;
  lcd2.hw_conf.dc_pin =  LCD2_DC_Pin;
  lcd2.hw_conf.dc_port = LCD2_DC_GPIO_Port;
  lcd2.def_scr = lcd5110_def_scr;
  LCD5110_init(&lcd2.hw_conf, LCD5110_NORMAL_MODE, 0x40, 2, 3);

//  time = 10120000;

  generate_displays(&clock);

//  HAL_TIM_Base_Start_IT(&htim1);
//  LCD5110_clear_scr(&lcd1);
//  LCD5110_clear_scr(&lcd1);
//  LCD5110_arr_out(sand, 1, &lcd1);
  //  LLCD5110_refreshCD5110_array(5, 5, 40, 40, &arr, &lcd1.hw_conf);
//  LCD5110_fill_region(5, 5, 40, 40, 1, &lcd1.hw_conf);

//  (&lcd1);
//  uint8_t message1[50];
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  int temp = 1;
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
//	  if (elapsed_time_s %1000 == 0){
		  MPU6050_Read_All(&hi2c1, &MPU6050);
//		  LCD5110_clear_scr(&lcd1);
//		  LCD5110_set_cursor(0, 0, &lcd1);
//		  char message1[50];
//		  sprintf(message1, "%0.2f x,\n %0.2f y,\n %0.2f z\n",MPU6050.Ax, MPU6050.Ay, MPU6050.Az);
//		  LCD5110_print(message1, BLACK, &lcd1);
//		  MPU6050_Read_Accel(&hi2c1, &MPU6050);
		  if (temp > 0 && MPU6050.Az < 0){
			  temp = -1;
			  drawLines(clock.upper_screen, 0);
			  rotate(clock.upper_screen);
			  rotate(clock.bottom_screen);
			  drawLines(clock.bottom_screen, 1);
		  }
		  if (temp < 0 && MPU6050.Az > 0){
			  temp = 1;
			  rotate(clock.upper_screen);
			  drawLines(clock.upper_screen, 1);
			  drawLines(clock.bottom_screen, 0);
			  rotate(clock.bottom_screen);
		  }

		  if (temp >0){
			  sandTick(clock.upper_screen, clock.bottom_screen);
			  update(clock.upper_screen);
			  updateBottom(clock.bottom_screen);
			  LCD5110_clear_scr(&lcd1);
			  LCD5110_clear_scr(&lcd2);
			  drawLines(clock.upper_screen, 0);
			  LCD5110_arr_out(clock.upper_screen, 1, &lcd2);
			  drawLines(clock.upper_screen, 1);
			  LCD5110_arr_out_bottom(clock.bottom_screen, 1, &lcd1);
		  }
		  if (temp < 0){
			  sandTick(clock.bottom_screen, clock.upper_screen);
			  update(clock.bottom_screen);
			  updateBottom(clock.upper_screen);
			  LCD5110_clear_scr(&lcd1);
			  LCD5110_clear_scr(&lcd2);
			  LCD5110_arr_out_bottom(clock.upper_screen, 1, &lcd2);
			  drawLines(clock.bottom_screen, 0);
			  LCD5110_arr_out(clock.bottom_screen, 1, &lcd1);
			  drawLines(clock.bottom_screen, 1);
		  }
//	  }

//	  if (elapsed_time_s >= time){
//		  HAL_TIM_Base_Stop_IT(&htim1);
//	  }
		  HAL_Delay(100);
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI_DIV2;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL16;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
