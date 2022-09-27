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

/* Timer Driver Example */

volatile u16 counter;
void Timer0Handler (void);

int main (void) {
	Dio_SetPinMode(DIO_PORTA, DIO_PIN0, DIO_PIN_OUTPUT);
	Gpt_Init();
	Gpt_Start(GPT_CHANNEL_TIM0, 250);
	Gpt_EnableNotification(GPT_INT_SOURCE_TIM0_COMP, Timer0Handler);
	Gie_Enable();
	while (1)
	{
		if (counter == 4000) {
			counter = 0;
			Dio_FlipPinLevel(DIO_PORTA, DIO_PIN0);
		}
	}
}

void Timer0Handler (void) {
	counter++;
}
