/*
 * Ldr.h
 *
 *  Created on: Sep 17, 2022
 *      Author: ahmad
 */

#ifndef INC_LDR_H_
#define INC_LDR_H_

#define LDR_CHANNEL ADC_CHANNEL_ADC1
#define LDR_RANGE_MIN 0
#define LDR_RANGE_MAX 100
#define LDR_MAX_MILLI_VOLTAGE 5000
#if LDR_RANGE_MAX < LDR_RANGE_MIN
#error "LDR_RANGE_MAX should be greater than LDR_RANGE_MIN"
#endif
#if LDR_MAX_MILLI_VOLTAGE <= 0
#error "LDR_MAX_MILLI_VOLTAGE should be greater than zero"
#endif


u16 Ldr_GetReading(void);


#endif /* INC_LDR_H_ */
