/*
 * Ldr.c
 *
 *  Created on: Sep 17, 2022
 *      Author: ahmad
 */
#include <std_types.h>
#include <Adc.h>
#include <Ldr.h>

static u16 Ldr_Map(u16 x);

u16 Ldr_GetReading(void)
{
    u16 result;
    Adc_StartConversionSync(LDR_CHANNEL);
    result = Adc_GetResultSync();
    result = ((u32)result * 5000) / 1024;
    return Ldr_Map(result);
}

static u16 Ldr_Map(u16 x)
{
    u16 y = (((LDR_RANGE_MAX - LDR_RANGE_MIN) * x) 
            / LDR_MAX_MILLI_VOLTAGE) + LDR_RANGE_MIN;
    return y;
}