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
#include <I2c.h>
#include <Eeprom.h>

#define APP_SPI_MASTER	1
#define APP_SPI_SLAVE	2
#define APP_EEPROM		3

/********************************************************************************/
#define APP_MODE	APP_SPI_SLAVE
/********************************************************************************/

#if APP_MODE == APP_EEPROM

volatile u8 g_data;
volatile u8 received_flag = 0;
void HandlerUsart(u8 data) {
	received_flag = 1;
	g_data = data;
}

int main (void) {
	Usart_Init();
	I2c_Master_Init(0);
	Usart_EnableNotification(USART_INT_SOURCE_RX);
	Usart_SetCallbackReceive(HandlerUsart);
	Eeprom_ReadByte(EEPROM_DEVICE_NUMBER_0, &g_data, 0);
	Usart_Print("Last Number: %d\n", g_data);
	Gie_Enable();

	while (1)
	{
		if (received_flag == 1) {
			received_flag = 0;
			Eeprom_WriteByte(EEPROM_DEVICE_NUMBER_0, g_data, 0);
			_delay_ms(10);
			Usart_Print("You Entered %d\n", g_data);
		}
	}
}

/********************************************************************************/

#elif APP_MODE == APP_SPI_MASTER

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

#elif APP_MODE == APP_SPI_SLAVE

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