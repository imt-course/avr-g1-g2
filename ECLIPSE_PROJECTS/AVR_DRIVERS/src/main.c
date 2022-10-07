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


int main (void) {
	Usart_Init();
	Dio_SetPinMode(DIO_PORTD, DIO_PIN3, DIO_PIN_OUTPUT);
	u8 data;
	while (1)
	{
		data = Usart_Receive();
		Usart_Transmit(data);

		/*Usart_Transmit('L');
		Usart_Transmit('E');
		Usart_Transmit('D');
		Usart_Transmit(' ');
		if (data == 'a') {
			Dio_SetPinLevel(DIO_PORTD, DIO_PIN3, STD_HIGH);
			Usart_Transmit('O');
			Usart_Transmit('N');
			Usart_Transmit('\n');
		}
		else if (data == 'b') {
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
		}*/
	}
	
}