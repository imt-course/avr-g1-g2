/*
 * Lm35.c
 *
 *  Created on: Sep 17, 2022
 *      Author: ahmad
 */

#include <std_types.h>
#include <Adc.h>
#include <Lm35.h>

u8 Lm35_GetTemperature(void) {
    u8 temperature;
    Adc_StartConversionSync(LM35_CHANNEL);
    temperature = Adc_GetResultSync();
    temperature = ((u32)temperature * 500) / 1024;
    return temperature;
}
