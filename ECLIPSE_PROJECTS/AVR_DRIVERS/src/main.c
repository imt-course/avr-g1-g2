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


#define ICU_HW


/******************************************************************
 * Hardware ICU Example
 *****************************************************************/
#ifdef ICU_HW

volatile u32 Time;
volatile u32 Time_on;
volatile u32 counter_timer = 0;

void Handler_Icu(u16 value);
void handler_Timer1_Ov(void);

int main (void) {
	Lcd_Init();
	Icu_Init();
	Gpt_Init();
	Pwm_Init(PWM_CHANNEL_0);
	Pwm_SetPrescaler(PWM_CHANNEL_0, PWM_PRESCALER_8);
	Pwm_SetCompareValue(PWM_CHANNEL_0, 120);
	Icu_SetEdge(ICU_EDGE_RISING);
	Icu_EnableNotifications(Handler_Icu);
	Gpt_EnableNotification(GPT_INT_SOURCE_TIM1_OV, handler_Timer1_Ov);
	Gie_Enable();
	while (1)
	{
		Lcd_DisplayClear();
		Lcd_Print("Time = %d", Time);
		Lcd_SetCursorPosition(1, 0);
		Lcd_Print("Time On = %d", Time_on);
		_delay_ms(1000);
	}
}

void Handler_Icu(u16 value) {
	static u8 counter = 1;
	static u16 temp;
	switch (counter)
	{
	case 1:
		temp = value;
		counter_timer = 0;
		counter++;
		break;
	case 2:
		Time = value + counter_timer*0xFFFF - temp;
		counter++;
		Icu_SetEdge(ICU_EDGE_FALLING);
		break;
	case 3:
		Time_on = value + counter_timer*0xFFFF - Time - temp;
		counter = 1;
		Icu_SetEdge(ICU_EDGE_RISING);
		break;
	default:
		break;
	}
}

void handler_Timer1_Ov(void) {
	counter_timer++;
}

#endif





/******************************************************************
 * Software ICU Example
 *****************************************************************/
#ifdef ICU_SW

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
	Pwm_SetPrescaler(PWM_CHANNEL_1A, PWM_PRESCALER_8);
	Pwm_SetTopValue(200);
	Pwm_SetCompareValue(PWM_CHANNEL_1A, 100);
	Gie_Enable();
	while (1)
	{
		Lcd_DisplayClear();
		Lcd_Print("Time = %d", Time);
		Lcd_SetCursorPosition(1, 0);
		Lcd_Print("Time On = %d", Time_on);
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
		ExtInterrupt_SetDetectEdge(EXT_INTERRUPT_INT0, EXT_INTERRUPT_DETECT_FALLING);
		counter++;
		break;
	case 3:
		Time_on = Gpt_GetTimeElapsed(GPT_CHANNEL_TIM0) + timer_counter * 255 - Time;
		ExtInterrupt_SetDetectEdge(EXT_INTERRUPT_INT0, EXT_INTERRUPT_DETECT_RISING);
		counter = 1;
		break;
	default:
		break;
	}
}

#endif