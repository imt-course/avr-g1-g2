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

int main(void)
{
	u16 result;
	/* Set ADC Pins as Input */
	Dio_SetPinMode(DIO_PORTA, DIO_PIN0, DIO_PIN_INPUT_FLOATING);
	Dio_SetPinMode(DIO_PORTA, DIO_PIN1, DIO_PIN_INPUT_FLOATING);
	/* Initialize ADC */
	Adc_Init(&Adc_Cfg);
	/* Initialize LCD */
	Lcd_Init();
	while(1) {
		/* Reading Temperature */
		result = Lm35_GetTemperature();
		Lcd_DisplayClear();
		Lcd_DisplayString("Temperature = ");
		Lcd_DisplayNumber(result);
		Lcd_DisplayString(" C");
		/* Reading LDR */
		result = Ldr_GetReading();
		Lcd_SetCursorPosition(1,0);
		Lcd_DisplayString("LDR = ");
		Lcd_DisplayNumber(result);
		Lcd_DisplayString(" mV");
		_delay_ms(1000);
	}
}
