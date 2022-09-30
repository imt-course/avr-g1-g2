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

/******************************************************************
 * Software ICU Example
 *****************************************************************/

volatile u16 timer_counter = 0;
volatile u16 Time;
volatile u16 Time_on;

void Handler_ExtInt0(void);
void Hanlder_Timer(void);
void ICU_SW(void);

int main(void)
{
	ICU_SW();
}

void ICU_SW(void)
{
	Lcd_Init();
	Gpt_Init();
	ExtInterrupt_Init();
	Pwm_Init(PWM_CHANNEL_1A);
	Gpt_EnableNotification(GPT_INT_SOURCE_TIM0_OV, Hanlder_Timer);
	ExtInterrupt_EnableNotification(EXT_INTERRUPT_INT0, Handler_ExtInt0);
	Pwm_SetPrescaler(PWM_PRESCALER_8);
	Pwm_SetTopValueChannel1(200);
	Pwm_SetCompareValue(100);
	Gie_Enable();
	while (1)
	{
		Lcd_DisplayClear();
		Lcd_DisplayString("Time = ");
		Lcd_DisplayNumber(Time);
		Lcd_SetCursorPosition(1, 0);
		Lcd_DisplayString("Time On = ");
		Lcd_DisplayNumber(Time_on);
		_delay_ms(1000);
	}
}

void Hanlder_Timer(void)
{
	timer_counter++;
}

void Handler_ExtInt0(void)
{
	static u8 counter = 1;
	switch (counter)
	{
	case 1:
		Gpt_ResetAndStart(GPT_CHANNEL_TIM0, 0);
		timer_counter = 0;
		counter++;
		break;
	case 2:
		Time = Gpt_GetTimeElapsed(GPT_CHANNEL_TIM0) + timer_counter * 255;
		ExtInterrupt_SetDetectEdge(EXT_INTERRUPT_INT0, EXT_INT_DETECT_FALLING);
		counter++;
		break;
	case 3:
		Time_on = Gpt_GetTimeElapsed(GPT_CHANNEL_TIM0) + timer_counter * 255 - Time;
		ExtInterrupt_SetDetectEdge(EXT_INTERRUPT_INT0, EXT_INT_DETECT_RISING);
		counter = 1;
		break;
	default:
		break;
	}
}
