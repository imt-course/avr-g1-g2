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

#define APP_MASTER 1
#define APP_SLAVE 2

#define APP_MODE APP_MASTER

#if APP_MODE == APP_MASTER

int main (void) {

}
#elif APP_MODE == APP_SLAVE

int main (void) {
	
}

#endif

#if 0
volatile u8 g_data;
volatile u8 receive_flag = 0;
void Handler_UsartRx(u8 data) {
	g_data = data;
	receive_flag = 1;
}

int main (void) {
	Usart_Init();
	Dio_SetPinMode(DIO_PORTD, DIO_PIN3, DIO_PIN_OUTPUT);
	Usart_SetCallbackReceive(Handler_UsartRx);
	Usart_EnableNotification(USART_INT_SOURCE_RX);
	Usart_Transmit('L');
	Gie_Enable();
	while (1)
	{
		if (receive_flag == 1) {
			receive_flag = 0;
			Usart_Transmit('L');
			Usart_Transmit('E');
			Usart_Transmit('D');
			Usart_Transmit(' ');
			if (g_data == 'a') {
				Dio_SetPinLevel(DIO_PORTD, DIO_PIN3, STD_HIGH);
				Usart_Transmit('O');
				Usart_Transmit('N');
				Usart_Transmit('\n');
			}
			else if (g_data == 'b') {
				Dio_SetPinLevel(DIO_PORTD, DIO_PIN3, STD_LOW);
				Usart_Transmit('O');
				Usart_Transmit('F');
				Usart_Transmit('F');
				Usart_Transmit('\n');
			}
			else {
				Usart_Transmit('E');
				Usart_Transmit('R');
				Usart_Transmit('R');
				Usart_Transmit('\n');
			}
		}
		
	}
	
}
#endif