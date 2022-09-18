/*
 * Interrupts.h
 *
 *  Created on: Sep 10, 2022
 *      Author: ahmad
 */

#ifndef INC_INTERRUPTS_H_
#define INC_INTERRUPTS_H_

/* External Interrupt Vector */
#define VECTOR_INT0         __vector_1
#define VECTOR_INT1         __vector_2
#define VECTOR_INT2         __vector_3
/* ADC Vector */
#define VECTOR_ADC          __vector_16


/* ISR Macro Definition */
#define ISR(vector) \
void vector(void) __attribute__((signal)); \
void vector(void)

#endif /* INC_INTERRUPTS_H_ */
