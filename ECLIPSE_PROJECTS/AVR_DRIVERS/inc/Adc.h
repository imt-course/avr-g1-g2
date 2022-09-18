/*
 * Adc.h
 *
 *  Created on: Sep 16, 2022
 *      Author: ahmad
 */

#ifndef INC_ADC_H_
#define INC_ADC_H_

/******************************************************************
 * Types Definition
 *****************************************************************/
typedef enum
{
    ADC_STATE_BUSY,
    ADC_STATE_IDLE
} Adc_StateType;

typedef enum
{
    ADC_CONVERSION_NOT_COMPLETE,
    ADC_CONVERSION_COMPLETE
} Adc_ConversionStateType;

typedef enum
{
    ADC_CHANNEL_ADC0,
    ADC_CHANNEL_ADC1,
    ADC_CHANNEL_ADC2,
    ADC_CHANNEL_ADC3,
    ADC_CHANNEL_ADC4,
    ADC_CHANNEL_ADC5,
    ADC_CHANNEL_ADC6,
    ADC_CHANNEL_ADC7,
    ADC_CHANNEL_ADC0_ADC0_10X,
    ADC_CHANNEL_ADC1_ADC0_10X,
    ADC_CHANNEL_ADC0_ADC0_200X,
    ADC_CHANNEL_ADC1_ADC0_200X,
    ADC_CHANNEL_ADC2_ADC2_10X,
    ADC_CHANNEL_ADC3_ADC2_10X,
    ADC_CHANNEL_ADC2_ADC2_200X,
    ADC_CHANNEL_ADC3_ADC2_200X,
    ADC_CHANNEL_ADC0_ADC1_1X,
    ADC_CHANNEL_ADC1_ADC1_1X,
    ADC_CHANNEL_ADC2_ADC1_1X,
    ADC_CHANNEL_ADC3_ADC1_1X,
    ADC_CHANNEL_ADC4_ADC1_1X,
    ADC_CHANNEL_ADC5_ADC1_1X,
    ADC_CHANNEL_ADC6_ADC1_1X,
    ADC_CHANNEL_ADC7_ADC1_1X,
    ADC_CHANNEL_ADC0_ADC2_1X,
    ADC_CHANNEL_ADC1_ADC2_1X,
    ADC_CHANNEL_ADC2_ADC2_1X,
    ADC_CHANNEL_ADC3_ADC2_1X,
    ADC_CHANNEL_ADC4_ADC2_1X,
    ADC_CHANNEL_ADC5_ADC2_1X,
    ADC_CHANNEL_1_22_V,
    ADC_CHANNEL_GND
} Adc_ChannelType;

typedef enum
{
    ADC_REF_AREF,
    ADC_REF_AVCC,
    ADC_REF_INT
} Adc_ReferenceType;

typedef enum
{
    ADC_TRIGGER_FREE_RUNNING,
    ADC_TRIGGER_AC,
    ADC_TRIGGER_INT0,
    ADC_TRIGGER_TIM0_CM,
    ADC_TRIGGER_TIM0_OF,
    ADC_TRIGGER_TIMB_CM,
    ADC_TRIGGER_TIM1_OF,
    ADC_TRIGGER_TIM1_CE,
    ADC_TRIGGER_OFF
} Adc_TriggerType;

typedef enum
{
    ADC_PRESCALER_2,
    ADC_PRESCALER_4,
    ADC_PRESCALER_8,
    ADC_PRESCALER_16,
    ADC_PRESCALER_32,
    ADC_PRESCALER_64,
    ADC_PRESCALER_128
} Adc_PrescalerType;

typedef struct
{
    Adc_ReferenceType refernce;
    Adc_TriggerType trigger;
    Adc_PrescalerType prescaler;
} Adc_ConfigType;

/******************************************************************
 * Configuration Struct
 *****************************************************************/
extern Adc_ConfigType Adc_Cfg;

/******************************************************************
 * Functions Prototype
 *****************************************************************/
void Adc_Init(const Adc_ConfigType *config);
void Adc_EnableNotification(void (*callback)(u16 res));
void Adc_DisableNotification(void);
void Adc_StartConversionSync(Adc_ChannelType channel);
Adc_StateType Adc_StartConversionAsync(Adc_ChannelType channel);
Adc_ConversionStateType Adc_GetResultAsync(u16 *result);
u16 Adc_GetResultSync(void);

#endif /* INC_ADC_H_ */
