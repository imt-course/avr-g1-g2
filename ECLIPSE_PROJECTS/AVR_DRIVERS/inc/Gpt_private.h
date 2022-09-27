/*
 * Gpt_private.h
 *
 *  Created on: Sep 23, 2022
 *      Author: ahmad
 */

#ifndef INC_GPT_PRIVATE_H_
#define INC_GPT_PRIVATE_H_

/******************************************************************
 * GPT Configuration Options
 *****************************************************************/
#define GPT_OFF                                 0
#define GPT_ON                                  1

#define GPT_WAVEFORM_MODE_NORMAL                1
#define GPT_WAVEFORM_MODE_CTC                   2

#define GPT_COMPARE_OUTPUT_MODE_DISCONNECTED    1
#define GPT_COMPARE_OUTPUT_MODE_TOG             2
#define GPT_COMPARE_OUTPUT_MODE_CLR             3
#define GPT_COMPARE_OUTPUT_MODE_SET             4

#define GPT_CLK_OFF                             1
#define GPT_CLK_PRESCALER_1                     2
#define GPT_CLK_PRESCALER_8                     3
#define GPT_CLK_PRESCALER_32                    4
#define GPT_CLK_PRESCALER_64                    5
#define GPT_CLK_PRESCALER_128                   6
#define GPT_CLK_PRESCALER_256                   7
#define GPT_CLK_PRESCALER_1024                  8
#define GPT_CLK_PRESCALER_EXT_FALLING           9
#define GPT_CLK_PRESCALER_EXT_RISING            10


/******************************************************************
 * GPT Registers Bits
 *****************************************************************/
#define TCCR0_CS00      0
#define TCCR0_CS01      1
#define TCCR0_CS02      2
#define TCCR0_WGM01     3
#define TCCR0_COM00     4
#define TCCR0_COM01     5
#define TCCR0_WGM00     6
#define TCCR0_FOC0      7
#define TIMSK_OCIE2     5
#define TIMSK_TOIE2     5
#define TIMSK_TICIE1    5
#define TIMSK_OCIE1A    4
#define TIMSK_OCIE1B    3
#define TIMSK_TOIE1     2
#define TIMSK_OCIE0     1
#define TIMSK_TOIE0     0


#endif /* INC_GPT_PRIVATE_H_ */
