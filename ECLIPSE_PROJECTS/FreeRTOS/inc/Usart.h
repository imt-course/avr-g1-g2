/*
 * USART.h
 *
 *  Created on: Oct 7, 2022
 *      Author: ahmad
 */

#ifndef INC_USART_H_
#define INC_USART_H_



void Usart_Init (void);
u8 Usart_Receive (void);
void Usart_Transmit (u8 data);
void Usart_EnableReceiveNotification (void (*callback) (u8 data));
void Usart_DisableReceiveNotification (void);

void Usart_SendString(const u8 *str);
void Usart_SendNumber(s64 num);
void Usart_Print(const u8 *str, ...);

#endif /* INC_USART_H_ */
