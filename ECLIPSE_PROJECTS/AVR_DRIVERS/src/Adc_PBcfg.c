/*
 * Adc_PBcfg.c
 *
 *  Created on: Sep 17, 2022
 *      Author: ahmad
 */

#include <std_types.h>
#include <Adc.h>

Adc_ConfigType Adc_Cfg = {
    ADC_REF_AVCC,
    ADC_TRIGGER_OFF,
    ADC_PRESCALER_128
};
