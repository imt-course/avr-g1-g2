/*
 * main.c
 *
 *  Created on: Aug 26, 2022
 *      Author: ahmad
 */

#include <std_types.h>
#include <Macros.h>
#include <cpu_freq.h>
#include <Keypad.h>
#include <Lcd.h>
#include <Dio.h>
#include <Ssd.h>
#include <Registers.h>
#include <Calculator.h>
#include <Gie.h>
#include <ExtInterrupt.h>
#include <Adc.h>
#include <Ldr.h>
#include <Lm35.h>
#include <Gpt.h>
#include <Interrupts.h>
#include <Pwm.h>
#include <Icu.h>
#include <Usart.h>
#include <Spi.h>

#define APP_MASTER	1
#define APP_SLAVE	2

/********************************************************************************/
#define APP_MODE	APP_MASTER
/********************************************************************************/

#if APP_MODE == APP_MASTER

volatile u8 g_receive_flag = 0;
volatile u8 g_data;

void Handler_Usart (u8 data) {
	g_data = data;
	g_receive_flag = 1;
}

int main (void) {
	Spi_Init();
	Usart_Init();
	Usart_EnableNotification(USART_INT_SOURCE_RX);
	Usart_SetCallbackReceive(Handler_Usart);
	Gie_Enable();
	while (1)
	{
		if (g_receive_flag == 1) {
			g_receive_flag = 0;
			Spi_Transfer(g_data);
		}
	}
}

/********************************************************************************/

#elif APP_MODE == APP_SLAVE

volatile u8 g_receive_flag = 0;
volatile u8 g_data;

void Handler_Spi (u8 data) {
	g_data = data;
	g_receive_flag = 1;
}

int main (void) {
	Spi_Init();
	Usart_Init();
	Spi_EnableNotification(Handler_Spi);
	Gie_Enable();
	while (1)
	{
		if (g_receive_flag == 1) {
			g_receive_flag = 0;
			Usart_Transmit(g_data);
		}
	}
}

#endif