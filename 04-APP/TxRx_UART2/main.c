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

#include "Stm32F103xx.h"
#include "ErrType.h"

#include "RCC_Private.h"
#include "RCC_Interface.h"

#include "GPIO_prv.h"
#include "GPIO_interface.h"

#include "USART_prv.h"
#include "USART_interface.h"

int main(void)
{
	PinConfig_t Local_LEDConfig={
			.Port = PORTC,
			.PinNum = PIN13,
			.Mode = OUTPUT_MODE10MHZ,
			.OutputConf = GP_OUTPUT_PP,
			.InputConf = FLOATING_INPUT
	};
	PinConfig_t Local_LEDConfig_2={
			.Port = PORTC,
			.PinNum = PIN14,
			.Mode = OUTPUT_MODE10MHZ,
			.OutputConf = GP_OUTPUT_PP,
			.InputConf = FLOATING_INPUT
	};

	PinConfig_t Local_TxConfig={
			.Port = PORTA,
			.PinNum = PIN2,
			.Mode = OUTPUT_MODE10MHZ,
			.OutputConf = AF_OUTPUT_PP,
			.InputConf = FLOATING_INPUT
	};
	PinConfig_t Local_RxConfig={
			.Port = PORTA,
			.PinNum = PIN3,
			.Mode = INPUT_MODE,
			.OutputConf = OUTPUT_MODE10MHZ,
			.InputConf = FLOATING_INPUT
	};
	USART_ConfigReg_t Local_USART2Tx={
			.USART_BAUDRATE = 9600,
			.USART_HWFLOWCONTROL = USART_HW_FLOW_CONTROL_OFF,
			.USART_MODE = USART_RXTX,
			.USART_PARITYBIT = PARITY_CONTROL_DISABLE,
			.USART_STOPBITS = _1_STOP_BIT,
			.USART_SYNCHMODE = CLOCK_DISABLE,
			.USART_USARTNUMBER = USART_NUM2,
			.USART_WORDLENGTH = _8_DATA_BITS
	};


	uint16_t Local_RxData = 0;


	RCC_SetClkSts(CLK_SRC_HSE,RCC_ON);
	RCC_SetSysClk(CLK_SRC_HSE);
	/*Enable APB1 for USART2*/
	RCC_APB1EnableClock(APB1_USART2);
	RCC_APB2EnableClock(APB2_IOPA);
	RCC_APB2EnableClock(APB2_IOPC);
	GPIO_u8PinInit(&Local_LEDConfig);
	GPIO_u8PinInit(&Local_LEDConfig_2);
	GPIO_u8PinInit(&Local_TxConfig);
	GPIO_u8PinInit(&Local_RxConfig);

	USART_Init(&Local_USART2Tx);


	USART_TransmitString(&Local_USART2Tx,"enter ur number: ");


	while(1)
	{
		USART_ReceiveData(&Local_USART2Tx, &Local_RxData);

		if(Local_RxData == '1')
		{
			USART_TransmitString(&Local_USART2Tx," Welcome Amr");
			GPIO_u8SetPinValue(PORTC, PIN14, 1);
			GPIO_u8SetPinValue(PORTC, PIN13, 0);
		}
		else if(Local_RxData == '2')
		{
			USART_TransmitString(&Local_USART2Tx," Welcome Usef");
			GPIO_u8SetPinValue(PORTC, PIN13, 1);
			GPIO_u8SetPinValue(PORTC, PIN14, 0);
		}

	}
}
