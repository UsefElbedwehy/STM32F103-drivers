/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
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

#include <stdint.h>

#include "ErrType.h"
#include "Stm32F103xx.h"

#include "SYSTICK_prv.h"
#include "SYSTICK_interface.h"

#include "RCC_Private.h"
#include "RCC_Interface.h"

#include "LED_prv.h"
#include "LED_interface.h"


int main(void)
{
	RCC_SetClkSts(CLK_SRC_HSE , RCC_ON);
	RCC_SetSysClk(CLK_SRC_HSE);
	RCC_APB2EnableClock(APB2_IOPA);
	LED_Init(PORTA, PIN1);
	/* Loop forever */
	while(1)
	{
		LED_On(PORTA, PIN1);
		SYSTICK_DelayMs(2000);
		LED_Off(PORTA, PIN1);
		SYSTICK_DelayMs(2000);
	}
}