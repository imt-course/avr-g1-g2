/*
 * Pwm.c
 *
 *  Created on: Sep 27, 2022
 *      Author: ahmad
 */
#include <std_types.h>
#include <Macros.h>
#include <Registers.h>
#include <Dio.h>
#include <Pwm.h>

/******************************************************************
 * Registers Bits
 *****************************************************************/
#define TCCR0_CS00      0
#define TCCR0_CS01      1
#define TCCR0_CS02      2
#define TCCR0_WGM01     3
#define TCCR0_COM00     4
#define TCCR0_COM01     5
#define TCCR0_WGM00     6
#define TCCR0_FOC0      7

#define TCCR1A_WGM10    0
#define TCCR1A_WGM11    1
#define TCCR1A_FOC1A    2
#define TCCR1A_FOC1B    3
#define TCCR1A_COM1B0   4
#define TCCR1A_COM1B1   5
#define TCCR1A_COM1A0   6
#define TCCR1A_COM1A1   7

#define TCCR1B_CS10     0
#define TCCR1B_CS11     1
#define TCCR1B_CS12     2
#define TCCR1B_WGM12    3
#define TCCR1B_WGM13    4
#define TCCR1B_ICES1    6
#define TCCR1B_ICNC1    7

#define TCCR2_CS20      0
#define TCCR2_CS21      1
#define TCCR2_CS22      2
#define TCCR2_WGM21     3
#define TCCR2_COM20     4
#define TCCR2_COM21     5
#define TCCR2_WGM20     6
#define TCCR2_FOC2      7


/******************************************************************
 * Functions Implementation
 *****************************************************************/
void Pwm_Init(Pwm_ChannelType channel)
{
    switch (channel)
    {
    case PWM_CHANNEL_0:
        /* Waveform Generation Mode: Fast PWM */
        SET_BIT(TCCR0, TCCR0_WGM00);
        SET_BIT(TCCR0, TCCR0_WGM01);
        /* Clock Select: No Prescaler */
        SET_BIT(TCCR0, TCCR0_CS00);
        CLR_BIT(TCCR0, TCCR0_CS01);
        CLR_BIT(TCCR0, TCCR0_CS02);
        /* Set OC0 Pin as Output */
        Dio_SetPinMode(DIO_PORTB, DIO_PIN3, DIO_PIN_OUTPUT);
        /* Compare Match Output Mode:
                Clear OC0 on compare match, set OC0 at TOP */
        CLR_BIT(TCCR0, TCCR0_COM00);
        SET_BIT(TCCR0, TCCR0_COM01);
        break;

    case PWM_CHANNEL_1A:
    case PWM_CHANNEL_1B:
        /* Waveform Generation Mode: Fast PWM, TOP=ICR1 */
        CLR_BIT(TCCR1A, TCCR1A_WGM10);
        SET_BIT(TCCR1A, TCCR1A_WGM11);
        SET_BIT(TCCR1B, TCCR1B_WGM12);
        SET_BIT(TCCR1B, TCCR1B_WGM13);
        /* Clock Select: No Prescaler */
        SET_BIT(TCCR1B, TCCR1B_CS10);
        CLR_BIT(TCCR1B, TCCR1B_CS11);
        CLR_BIT(TCCR1B, TCCR1B_CS12);
        if (channel == PWM_CHANNEL_1A)
        {
            /* Compare Match Output Mode:
                    Clear OC1A on compare match, set OC1A at TOP */
            CLR_BIT(TCCR1A, TCCR1A_COM1A0);
            SET_BIT(TCCR1A, TCCR1A_COM1A1);
            /* Set OC1A Pin as Output */
            Dio_SetPinMode(DIO_PORTD, DIO_PIN5, DIO_PIN_OUTPUT);
        }
        else if (channel == PWM_CHANNEL_1B)
        {
            /* Compare Match Output Mode:
                    Clear OC1B on compare match, set OC1B at TOP */
            CLR_BIT(TCCR1A, TCCR1A_COM1B0);
            SET_BIT(TCCR1A, TCCR1A_COM1B1);
            /* Set OC1B Pin as Output */
            Dio_SetPinMode(DIO_PORTD, DIO_PIN4, DIO_PIN_OUTPUT);
        }
        break;
    case PWM_CHANNEL_2:
        // TODO
    default:
        break;
    }
}

void Pwm_SetPrescaler(Pwm_ChannelType channel, Pwm_PrescalerType prescaler)
{
    switch (channel)
    {
    case PWM_CHANNEL_0:
        switch (prescaler)
        {
        case PWM_PRESCALER_1:
            CLR_BIT(TCCR0, TCCR0_CS00);
            CLR_BIT(TCCR0, TCCR0_CS01);
            CLR_BIT(TCCR0, TCCR0_CS02);
            break;
        case PWM_PRESCALER_8:
            CLR_BIT(TCCR0, TCCR0_CS00);
            SET_BIT(TCCR0, TCCR0_CS01);
            CLR_BIT(TCCR0, TCCR0_CS02);
            break;
        case PWM_PRESCALER_64:
            // TODO
            break;
        case PWM_PRESCALER_256:
            // TODO
            break;
        case PWM_PRESCALER_1024:
            // TODO
            break;
        case PWM_PRESCALER_EXT_FALLING:
            // TODO
            break;
        case PWM_PRESCALER_EXT_RISING:
            // TODO
            break;
        default:
            break;
        }
        break;

    case PWM_CHANNEL_1A:
    case PWM_CHANNEL_1B:
        switch (prescaler)
        {
        case PWM_PRESCALER_1:
            CLR_BIT(TCCR1B, TCCR1B_CS10);
            CLR_BIT(TCCR1B, TCCR1B_CS11);
            CLR_BIT(TCCR1B, TCCR1B_CS12);
            break;
        case PWM_PRESCALER_8:
            CLR_BIT(TCCR1B, TCCR1B_CS10);
            SET_BIT(TCCR1B, TCCR1B_CS11);
            CLR_BIT(TCCR1B, TCCR1B_CS12);
            break;
        case PWM_PRESCALER_64:
            // TODO
            break;
        case PWM_PRESCALER_256:
            // TODO
            break;
        case PWM_PRESCALER_1024:
            // TODO
            break;
        case PWM_PRESCALER_EXT_FALLING:
            // TODO
            break;
        case PWM_PRESCALER_EXT_RISING:
            // TODO
            break;
        default:
            break;
        }
        break;

    case PWM_CHANNEL_2:
        switch (prescaler)
        {
        case PWM_PRESCALER_1:
            // TODO
            break;
        case PWM_PRESCALER_8:
            // TODO
            break;
        case PWM_PRESCALER_32:
            // TODO
            break;
        case PWM_PRESCALER_64:
            // TODO
            break;
        case PWM_PRESCALER_128:
            // TODO
            break;
        case PWM_PRESCALER_256:
            // TODO
            break;
        case PWM_PRESCALER_1024:
            // TODO
            break;
        default:
            break;
        }
        break;

    default:
        break;
    }
}

void Pwm_SetCompareValue(Pwm_ChannelType channel, u16 value)
{
    switch (channel)
    {
    case PWM_CHANNEL_0:
        OCR0 = value;
        break;
    case PWM_CHANNEL_1A:
        OCR1A = value;
        break;
    case PWM_CHANNEL_1B:
        OCR1B = value;
        break;
    case PWM_CHANNEL_2:
        OCR2 = value;
        break;
    default:
        break;
    }
}

void Pwm_SetTopValue(u16 value)
{
    ICR1 = value;
}
