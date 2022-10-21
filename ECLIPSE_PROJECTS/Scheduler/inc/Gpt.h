/*
 * Gpt.h
 *
 *  Created on: Sep 23, 2022
 *      Author: ahmad
 */

#ifndef INC_GPT_H_
#define INC_GPT_H_

typedef enum {
    GPT_CHANNEL_TIM0,
    GPT_CHANNEL_TIM1A,
    GPT_CHANNEL_TIM1B,
    GPT_CHANNEL_TIM2
} Gpt_ChannelType;

typedef enum {
    GPT_INT_SOURCE_TIM0_OV,
    GPT_INT_SOURCE_TIM0_COMP,
    GPT_INT_SOURCE_TIM1_OV,
    GPT_INT_SOURCE_TIM1A_COMP,
    GPT_INT_SOURCE_TIM1B_COMP,
    GPT_INT_SOURCE_TIM2_OV,
    GPT_INT_SOURCE_TIM2_COMP
} Gpt_InterruptSourceType;

void Gpt_Init(void);
void Gpt_Start(Gpt_ChannelType channel, u16 ticks);
void Gpt_ResetAndStart(Gpt_ChannelType channel, u16 ticks);
u16 Gpt_GetTimeElapsed(Gpt_ChannelType channel);
u16 Gpt_GetTimeRemaining(Gpt_ChannelType channel);
void Gpt_EnableNotification(Gpt_InterruptSourceType channel, void (*callback)(void));
void Gpt_DisableNotification(Gpt_InterruptSourceType channel);



#endif /* INC_GPT_H_ */
