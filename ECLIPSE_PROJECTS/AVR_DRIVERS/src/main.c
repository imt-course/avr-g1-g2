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


void ToggleLed (void) {
	Dio_FlipPinLevel(DIO_PORTD, DIO_PIN0);
}

int main(void)
{
	Dio_SetPinMode(DIO_PORTD, DIO_PIN2, DIO_PIN_INPUT_PULLUP);	/* External Interrupt Pin Input Pullup */
	Dio_SetPinMode(DIO_PORTD, DIO_PIN0, DIO_PIN_OUTPUT);		/* LED Pin Output */
	ExtInterrupt_Init();
	ExtInterrupt_EnableNotification(EXT_INTERRUPT_INT0, ToggleLed);
	Gie_Enable();
	while (1)
	{

	}
}
