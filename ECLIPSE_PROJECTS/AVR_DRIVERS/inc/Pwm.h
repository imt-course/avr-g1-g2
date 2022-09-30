/*
 * Pwm.h
 *
 *  Created on: Sep 27, 2022
 *      Author: ahmad
 */

#ifndef INC_PWM_H_
#define INC_PWM_H_

typedef enum {
    PWM_CHANNEL_0,
    PWM_CHANNEL_1A,
    PWM_CHANNEL_1B,
    PWM_CHANNEL_2
} Pwm_ChannelType;

typedef enum {
    PWM_PRESCALER_1          ,
    PWM_PRESCALER_8          ,
    PWM_PRESCALER_32         ,
    PWM_PRESCALER_64         ,
    PWM_PRESCALER_128        ,
    PWM_PRESCALER_256        ,
    PWM_PRESCALER_1024       ,
    PWM_PRESCALER_EXT_FALLING,
    PWM_PRESCALER_EXT_RISING 
} Pwm_PrescalerType;

void Pwm_Init(Pwm_ChannelType channel);
void Pwm_SetPrescaler(Pwm_ChannelType channel, Pwm_PrescalerType prescaler);
void Pwm_SetCompareValue(Pwm_ChannelType channel, u16 value);
void Pwm_SetTopValue(u16 value);




#endif /* INC_PWM_H_ */
