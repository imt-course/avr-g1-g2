/*
 * Icu.c
 *
 *  Created on: Oct 1, 2022
 *      Author: ahmad
 */
#include <std_types.h>
#include <Macros.h>
#include <Registers.h>
#include <Interrupts.h>
#include <Dio.h>
#include <Icu.h>

#define TCCR1B_ICNC1 7
#define TCCR1B_ICES1 6
#define TIMSK_TICIE1 5

void (*Icu_Callback)(u16 value);

ISR(VECTOR_ICU) {
    Icu_Callback(ICR1);
}


void Icu_Init()
{
    /* Input Capture Noise Canceler */
    SET_BIT(TCCR1B, TCCR1B_ICNC1);
    /* Set ICP Pin Input Floating */
    Dio_SetPinMode(DIO_PORTD, DIO_PIN6, DIO_PIN_INPUT_FLOATING);
}

void Icu_SetEdge(Icu_EdgeType edge)
{
    switch (edge)
    {
    case ICU_EDGE_FALLING:
        CLR_BIT(TCCR1B, TCCR1B_ICES1);
        break;
    case ICU_EDGE_RISING:
        SET_BIT(TCCR1B, TCCR1B_ICES1);
        break;
    default:
        break;
    }
}
void Icu_EnableNotifications(void (*callback)(u16 value))
{
    Icu_Callback = callback;
    SET_BIT(TIMSK, TIMSK_TICIE1);
}

void Icu_DisableNotification(void)
{
    CLR_BIT(TIMSK, TIMSK_TICIE1);
}
