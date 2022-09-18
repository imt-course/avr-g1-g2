/*
 * registers.h
 *
 *  Created on: Aug 27, 2022
 *      Author: ahmad
 */

#ifndef INC_REGISTERS_H_
#define INC_REGISTERS_H_

/******************************************************************
 * Dio Registers
 *****************************************************************/
#define PORTA	                        *((volatile u8*)0x3B)
#define DDRA	                        *((volatile u8*)0x3A)
#define PINA	                        *((volatile u8*)0x39)
#define PORTB	                        *((volatile u8*)0x38)
#define DDRB	                        *((volatile u8*)0x37)
#define PINB	                        *((volatile u8*)0x36)
#define PORTC	                        *((volatile u8*)0x35)
#define DDRC	                        *((volatile u8*)0x34)
#define PINC	                        *((volatile u8*)0x33)
#define PORTD	                        *((volatile u8*)0x32)
#define DDRD	                        *((volatile u8*)0x31)
#define PIND	                        *((volatile u8*)0x30)

/******************************************************************
 * External Interrupt Registers
 *****************************************************************/
#define MCUCR	                        *((volatile u8*)0x55)
#define MCUCSR	                        *((volatile u8*)0x54)
#define GICR	                        *((volatile u8*)0x5B)
#define GIFR	                        *((volatile u8*)0x5A)

/******************************************************************
 * Global Interrupt Enable Registers
 *****************************************************************/
#define SREG	                        *((volatile u8*)0x5F)

/******************************************************************
 * ADC Registers
 *****************************************************************/
#define ADMUX	                        *((volatile u8*)0x27)
#define ADCSRA	                        *((volatile u8*)0x26)
#define ADCH	                        *((volatile u8*)0x25)
#define ADCL	                        *((volatile u8*)0x24)
#define ADC_DATA                        *((volatile u16*)0x24)
#define SFIOR                           *((volatile u8*)0x50)


#endif /* INC_REGISTERS_H_ */
