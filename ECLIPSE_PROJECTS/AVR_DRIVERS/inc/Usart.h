/*
 * USART.h
 *
 *  Created on: Oct 7, 2022
 *      Author: ahmad
 */

#ifndef INC_USART_H_
#define INC_USART_H_

void Usart_Init (void);
void Usart_Transmit (u8 data);
u8 Usart_Receive (void);


#endif /* INC_USART_H_ */
