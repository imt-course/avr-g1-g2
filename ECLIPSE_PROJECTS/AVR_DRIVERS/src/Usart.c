/*
 * Usart.c
 *
 *  Created on: Oct 7, 2022
 *      Author: ahmad
 */
#include <std_types.h>
#include <Macros.h>
#include <Registers.h>
#include <Dio.h>
#include <Usart.h>

void Usart_Init (void) {
    u8 temp;
    /* Rx Enable */
    SET_BIT(UCSRB, 4);
    Dio_SetPinMode(DIO_PORTD, DIO_PIN0, DIO_PIN_INPUT_FLOATING);
    /* Tx Enable */
    SET_BIT(UCSRB, 3);
    Dio_SetPinMode(DIO_PORTD, DIO_PIN1, DIO_PIN_OUTPUT);
    /* Select UCSRC Register */
    temp = 0;
    SET_BIT(temp, 7);
    /* Data Size Select */
    SET_BIT(temp, 0);
    SET_BIT(temp, 1);
    CLR_BIT(UCSRB, 2);
    UCSRC = temp;
    /* Baud Rate Select */
    UBRRL = 51;
    UBRRH = 0;
}
void Usart_Transmit (u8 data) {
    while (GET_BIT(UCSRA, 5) == 0);
    UDR = data;
    while (GET_BIT(UCSRA, 6) == 0);
    SET_BIT(UCSRA, 6);
}
u8 Usart_Receive (void) {
    while (GET_BIT(UCSRA, 7) == 0);
    return UDR;
}
