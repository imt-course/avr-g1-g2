/*
 * Dio.h
 *
 *  Created on: Aug 27, 2022
 *      Author: ahmad
 */

#ifndef INC_DIO_H_
#define INC_DIO_H_

typedef enum {
	DIO_PORTA,
    DIO_PORTB,
    DIO_PORTC,
    DIO_PORTD
} Dio_PortType;

typedef enum {
    DIO_PIN0,
    DIO_PIN1,
    DIO_PIN2,
    DIO_PIN3,
    DIO_PIN4,
    DIO_PIN5,
    DIO_PIN6,
    DIO_PIN7
} Dio_PinType;

typedef enum {
    DIO_PIN_OUTPUT,
    DIO_PIN_INPUT_FLOATING,
    DIO_PIN_INPUT_PULLUP
} Dio_PinModeType;

typedef enum {
    STD_LOW,
    STD_HIGH
} Dio_PinLevelType;

void Dio_SetPinMode (Dio_PortType port, Dio_PinType pin, Dio_PinModeType mode);
void Dio_SetPinLevel (Dio_PortType port, Dio_PinType pin,Dio_PinLevelType level);
Dio_PinLevelType Dio_FlipPinLevel (Dio_PortType port, Dio_PinType pin);
Dio_PinLevelType Dio_ReadPinLevel (Dio_PortType port, Dio_PinType pin);

#endif /* INC_DIO_H_ */
