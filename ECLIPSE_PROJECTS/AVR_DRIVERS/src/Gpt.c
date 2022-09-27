/*
 * Gpt.c
 *
 *  Created on: Sep 23, 2022
 *      Author: ahmad
 */
#include <std_types.h>
#include <Macros.h>
#include <Registers.h>
#include <Interrupts.h>
#include <Gpt_private.h>
#include <Gpt_cfg.h>
#include <Gpt.h>

/******************************************************************
 * Timer ISR
 *****************************************************************/
void (*Gpt_CallbackTim0_Compare)(void);
void (*Gpt_CallbackTim0_Overflow)(void);
void (*Gpt_CallbackTim1A_Compare)(void);
void (*Gpt_CallbackTim1B_Compare)(void);
void (*Gpt_CallbackTim1_Overflow)(void);
void (*Gpt_CallbackTim2_Compare)(void);
void (*Gpt_CallbackTim2_Overflow)(void);

ISR(VECTOR_TIM0_COMP)
{
    Gpt_CallbackTim0_Compare();
}
ISR(VECTOR_TIM0_OV)
{
    Gpt_CallbackTim0_Overflow();
}
ISR(VECTOR_TIM1A_COMP)
{
    Gpt_CallbackTim1A_Compare();
}
ISR(VECTOR_TIM1B_COMP)
{
    // TODO
}
ISR(VECTOR_TIM1_OV)
{
    // TODO
}
ISR(VECTOR_TIM2_COMP)
{
    // TODO
}
ISR(VECTOR_TIM2_OV)
{
    // TODO
}

void Gpt_Init(void)
{

/******************************************************************
 * Timer 0 Init
 *****************************************************************/
#if GPT_TIM0_STATUS == GPT_ON

/* Waveform Generation Mode */
#if   GPT_TIM0_WAVEFORM_MODE == GPT_WAVEFORM_MODE_NORMAL
    CLR_BIT(TCCR0, TCCR0_WGM00);
    CLR_BIT(TCCR0, TCCR0_WGM01);
#elif GPT_TIM0_WAVEFORM_MODE == GPT_WAVEFORM_MODE_CTC
    CLR_BIT(TCCR0, TCCR0_WGM00);
    SET_BIT(TCCR0, TCCR0_WGM01);
#else
#error "Invalid WAVEFORM_MODE For TIM0"
#endif

/* Compare Match Output Mode */
#if   GPT_TIM0_COMPARE_OUTPUT_MODE == GPT_COMPARE_OUTPUT_MODE_DISCONNECTED
    CLR_BIT(TCCR0, TCCR0_COM00);
    CLR_BIT(TCCR0, TCCR0_COM01);
#elif GPT_TIM0_COMPARE_OUTPUT_MODE == GPT_COMPARE_OUTPUT_MODE_TOG
    // TODO
#elif GPT_TIM0_COMPARE_OUTPUT_MODE == GPT_COMPARE_OUTPUT_MODE_CLR
    // TODO
#elif GPT_TIM0_COMPARE_OUTPUT_MODE == GPT_COMPARE_OUTPUT_MODE_SET
    // TODO
#else
#error "Invalid COMPARE_OUTPUT_MODE For TIM0"
#endif

/* Clock Select */
#if   GPT_TIM0_CLK == GPT_CLK_OFF
    // TODO
#elif GPT_TIM0_CLK == GPT_CLK_PRESCALER_1
    // TODO
#elif GPT_TIM0_CLK == GPT_CLK_PRESCALER_8
    CLR_BIT(TCCR0, TCCR0_CS00);
    SET_BIT(TCCR0, TCCR0_CS01);
    CLR_BIT(TCCR0, TCCR0_CS02);
#elif GPT_TIM0_CLK == GPT_CLK_PRESCALER_64
    // TODO
#elif GPT_TIM0_CLK == GPT_CLK_PRESCALER_256
    // TODO
#elif GPT_TIM0_CLK == GPT_CLK_PRESCALER_1024
    // TODO
#elif GPT_TIM0_CLK == GPT_CLK_PRESCALER_EXT_FALLING
    // TODO
#elif GPT_TIM0_CLK == GPT_CLK_PRESCALER_EXT_RISING
    // TODO
#else
#error "Invalid Configuration for CLK in TIM0"
#endif

#endif


/******************************************************************
 * Timer 1 Init
 *****************************************************************/
#if GPT_TIM1_STATUS == GPT_ON

/* Waveform Generation Mode */
#if   GPT_TIM1_WAVEFORM_MODE == GPT_WAVEFORM_MODE_NORMAL
    // TODO
#elif GPT_TIM1_WAVEFORM_MODE == GPT_WAVEFORM_MODE_CTC
    // TODO
#else
#error "Invalid WAVEFORM_MODE For TIM1"
#endif

/* Compare Match Output Mode For Channel A */
#if   GPT_TIM1A_COMPARE_OUTPUT_MODE == GPT_COMPARE_OUTPUT_MODE_DISCONNECTED
    // TODO
#elif GPT_TIM1A_COMPARE_OUTPUT_MODE == GPT_COMPARE_OUTPUT_MODE_TOG
    // TODO
#elif GPT_TIM1A_COMPARE_OUTPUT_MODE == GPT_COMPARE_OUTPUT_MODE_CLR
    // TODO
#elif GPT_TIM1A_COMPARE_OUTPUT_MODE == GPT_COMPARE_OUTPUT_MODE_SET
    // TODO
#else
#error "Invalid COMPARE_OUTPUT_MODE For TIM1A"
#endif

/* Compare Match Output Mode For Channel B */
#if   GPT_TIM1B_COMPARE_OUTPUT_MODE == GPT_COMPARE_OUTPUT_MODE_DISCONNECTED
    // TODO
#elif GPT_TIM1B_COMPARE_OUTPUT_MODE == GPT_COMPARE_OUTPUT_MODE_TOG
    // TODO
#elif GPT_TIM1B_COMPARE_OUTPUT_MODE == GPT_COMPARE_OUTPUT_MODE_CLR
    // TODO
#elif GPT_TIM1B_COMPARE_OUTPUT_MODE == GPT_COMPARE_OUTPUT_MODE_SET
    // TODO
#else
#error "Invalid COMPARE_OUTPUT_MODE For TIM1B"
#endif

/* Clock Select */
#if   GPT_TIM1_CLK == GPT_CLK_OFF
    // TODO
#elif GPT_TIM1_CLK == GPT_CLK_PRESCALER_1
    // TODO
#elif GPT_TIM1_CLK == GPT_CLK_PRESCALER_8
    // TODO
#elif GPT_TIM1_CLK == GPT_CLK_PRESCALER_64
    // TODO
#elif GPT_TIM1_CLK == GPT_CLK_PRESCALER_256
    // TODO
#elif GPT_TIM1_CLK == GPT_CLK_PRESCALER_1024
    // TODO
#elif GPT_TIM1_CLK == GPT_CLK_PRESCALER_EXT_FALLING
    // TODO
#elif GPT_TIM1_CLK == GPT_CLK_PRESCALER_EXT_RISING
    // TODO
#else
#error "Invalid Configuration for CLK in TIM1"
#endif

#endif


/******************************************************************
 * Timer 2 Init
 *****************************************************************/
#if GPT_TIM2_STATUS == GPT_ON

/* Waveform Generation Mode */
#if   GPT_TIM2_WAVEFORM_MODE == GPT_WAVEFORM_MODE_NORMAL
    // TODO
#elif GPT_TIM2_WAVEFORM_MODE == GPT_WAVEFORM_MODE_CTC
    // TODO
#else
#error "Invalid WAVEFORM_MODE For TIM2"
#endif

/* Compare Match Output Mode */
#if   GPT_TIM2_COMPARE_OUTPUT_MODE == GPT_COMPARE_OUTPUT_MODE_DISCONNECTED
    // TODO
#elif GPT_TIM2_COMPARE_OUTPUT_MODE == GPT_COMPARE_OUTPUT_MODE_TOG
    // TODO
#elif GPT_TIM2_COMPARE_OUTPUT_MODE == GPT_COMPARE_OUTPUT_MODE_CLR
    // TODO
#elif GPT_TIM2_COMPARE_OUTPUT_MODE == GPT_COMPARE_OUTPUT_MODE_SET
    // TODO
#else
#error "Invalid COMPARE_OUTPUT_MODE For TIM2"
#endif

/* Clock Select */
#if   GPT_TIM2_CLK == GPT_CLK_OFF
    // TODO
#elif GPT_TIM2_CLK == GPT_CLK_PRESCALER_1
    // TODO
#elif GPT_TIM2_CLK == GPT_CLK_PRESCALER_8
    // TODO
#elif GPT_TIM2_CLK == GPT_CLK_PRESCALER_32
    // TODO
#elif GPT_TIM2_CLK == GPT_CLK_PRESCALER_64
    // TODO
#elif GPT_TIM2_CLK == GPT_CLK_PRESCALER_128
    // TODO
#elif GPT_TIM2_CLK == GPT_CLK_PRESCALER_256
    // TODO
#elif GPT_TIM2_CLK == GPT_CLK_PRESCALER_1024
    // TODO
#else
#error "Invalid Configuration for CLK in TIM2"
#endif

#endif
}

void Gpt_Start(Gpt_ChannelType channel, u16 ticks)
{
    switch (channel)
    {
    case GPT_CHANNEL_TIM0:
        OCR0 = ticks;
        break;
    case GPT_CHANNEL_TIM1A:
        // TODO
        break;
    case GPT_CHANNEL_TIM1B:
        // TODO
        break;
    case GPT_CHANNEL_TIM2:
        // TODO
        break;
    default:
        break;
    }
}

void Gpt_ResetAndStart(Gpt_ChannelType channel, u16 ticks)
{
    switch (channel)
    {
    case GPT_CHANNEL_TIM0:
        OCR0 = ticks;
        TCNT0 = 0;
        break;
    case GPT_CHANNEL_TIM1A:
        // TODO
        break;
    case GPT_CHANNEL_TIM1B:
        // TODO
        break;
    case GPT_CHANNEL_TIM2:
        // TODO
        break;
    default:
        break;
    }
}

u16 Gpt_GetTimeElapsed(Gpt_ChannelType channel)
{
    u16 result = 0;
    switch (channel)
    {
    case GPT_CHANNEL_TIM0:
        result = TCNT0;
        break;

    case GPT_CHANNEL_TIM1A:
    case GPT_CHANNEL_TIM1B:
        // TODO
        break;

    case GPT_CHANNEL_TIM2:
        // TODO
        break;

    default:
        break;
    }
    return result;
}


u16 Gpt_GetTimeRemaining(Gpt_ChannelType channel)
{
    u16 result = 0;
    switch (channel)
    {
    case GPT_CHANNEL_TIM0:
#if   GPT_TIM0_WAVEFORM_MODE == GPT_WAVEFORM_MODE_CTC
        result = OCR0 - TCNT0;
#elif GPT_TIM0_WAVEFORM_MODE == GPT_WAVEFORM_MODE_NORMAL
        result = 0xFF - TCNT0;
#endif
        break;

    case GPT_CHANNEL_TIM1A:
        // TODO
        break;

    case GPT_CHANNEL_TIM1B:
        // TODO
        break;

    case GPT_CHANNEL_TIM2:
        // TODO
        break;

    default:
        break;
    }
    return result;
}

void Gpt_EnableNotification(Gpt_InterruptSourceType channel, void (*callback)(void))
{
    switch (channel)
    {
    case GPT_INT_SOURCE_TIM0_OV:
        Gpt_CallbackTim0_Overflow = callback;
        SET_BIT(TIMSK, TIMSK_OCIE0);
        break;
    case GPT_INT_SOURCE_TIM0_COMP:
        Gpt_CallbackTim0_Compare = callback;
        SET_BIT(TIMSK, TIMSK_TOIE0);
        break;
    case GPT_INT_SOURCE_TIM1_OV:
        // TODO
        break;
    case GPT_INT_SOURCE_TIM1A_COMP:
        // TODO
        break;
    case GPT_INT_SOURCE_TIM1B_COMP:
        // TODO
        break;
    case GPT_INT_SOURCE_TIM2_OV:
        // TODO
        break;
    case GPT_INT_SOURCE_TIM2_COMP:
        // TODO
        break;
    }
}

void Gpt_DisableNotification(Gpt_InterruptSourceType channel)
{
    switch (channel)
    {
    case GPT_INT_SOURCE_TIM0_OV:
        CLR_BIT(TIMSK, TIMSK_OCIE0);
        break;
    case GPT_INT_SOURCE_TIM0_COMP:
        CLR_BIT(TIMSK, TIMSK_TOIE0);
        break;
    case GPT_INT_SOURCE_TIM1_OV:
        // TODO
        break;
    case GPT_INT_SOURCE_TIM1A_COMP:
        // TODO
        break;
    case GPT_INT_SOURCE_TIM1B_COMP:
        // TODO
        break;
    case GPT_INT_SOURCE_TIM2_OV:
        // TODO
        break;
    case GPT_INT_SOURCE_TIM2_COMP:
        // TODO
        break;
    }
}
