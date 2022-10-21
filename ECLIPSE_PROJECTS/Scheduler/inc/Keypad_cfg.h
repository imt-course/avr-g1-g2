/*
 * Keypad_cfg.h
 *
 *  Created on: Sep 3, 2022
 *      Author: ahmad
 */

#ifndef INC_KEYPAD_CFG_H_
#define INC_KEYPAD_CFG_H_

/***********************************************
*   B00   *   B01   *   B02   *   B03   *  ROW1*
*   B04   *   B05   *   B06   *   B07   *  ROW2*
*   B08   *   B09   *   B10   *   B11   *  ROW3*
*   B12   *   B13   *   B14   *   B15   *  ROW4*
* COLOMN1   COLUMN2   COLUMN3   COLUMN4 *      *
***********************************************/


/*************** Keypad Rows Connections ***************/
#define KEYPAD_PIN_R1  DIO_PORTC,DIO_PIN0
#define KEYPAD_PIN_R2  DIO_PORTC,DIO_PIN1
#define KEYPAD_PIN_R3  DIO_PORTC,DIO_PIN2
#define KEYPAD_PIN_R4  DIO_PORTC,DIO_PIN3

/*************** Keypad Columns Connections ***************/
#define KEYPAD_PIN_C1  DIO_PORTC,DIO_PIN4
#define KEYPAD_PIN_C2  DIO_PORTC,DIO_PIN5
#define KEYPAD_PIN_C3  DIO_PORTC,DIO_PIN6
#define KEYPAD_PIN_C4  DIO_PORTC,DIO_PIN7

#endif /* INC_KEYPAD_CFG_H_ */
