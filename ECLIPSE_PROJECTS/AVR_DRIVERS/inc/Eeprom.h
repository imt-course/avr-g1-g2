/*
 * Eeprom.h
 *
 *  Created on: Oct 15, 2022
 *      Author: ahmad
 */

#ifndef INC_EEPROM_H_
#define INC_EEPROM_H_

#define EEPROM_MODEL_AT24C02 1
#define EEPROM_MODEL_AT24C04 2
#define EEPROM_MODEL_AT24C08 3

#define EEPROM_MODEL EEPROM_MODEL_AT24C08

typedef enum {
    EEPROM_DEVICE_NUMBER_0,
    EEPROM_DEVICE_NUMBER_1,
#if (EEPROM_MODEL == EEPROM_MODEL_AT24C04) || (EEPROM_MODEL == EEPROM_MODEL_AT24C02)
    EEPROM_DEVICE_NUMBER_2,
    EEPROM_DEVICE_NUMBER_3,
#endif
#if (EEPROM_MODEL == EEPROM_MODEL_AT24C02)
    EEPROM_DEVICE_NUMBER_4,
    EEPROM_DEVICE_NUMBER_5,
    EEPROM_DEVICE_NUMBER_6,
    EEPROM_DEVICE_NUMBER_7,
#endif
} Eeprom_DeviceType;

typedef enum {
    EEPROM_FAILED,
    EEPROM_SUCCESS
} Eeprom_StateType;

Eeprom_StateType Eeprom_WriteByte(Eeprom_DeviceType device, u8 data, u16 address);
Eeprom_StateType Eeprom_ReadByte(Eeprom_DeviceType device, u8 *data, u16 address);

/*** OPTIONS For device:
 * -> For EEPROM_MODEL_AT24C02
 *      A2_A1_A0 = 0_0_0 -> EEPROM_DEVICE_NUMBER_0
 *      A2_A1_A0 = 0_0_1 -> EEPROM_DEVICE_NUMBER_1
 *      A2_A1_A0 = 0_1_0 -> EEPROM_DEVICE_NUMBER_2
 *      A2_A1_A0 = 0_1_1 -> EEPROM_DEVICE_NUMBER_3
 *      A2_A1_A0 = 1_0_0 -> EEPROM_DEVICE_NUMBER_4
 *      A2_A1_A0 = 1_0_1 -> EEPROM_DEVICE_NUMBER_5
 *      A2_A1_A0 = 1_1_0 -> EEPROM_DEVICE_NUMBER_6
 *      A2_A1_A0 = 1_1_1 -> EEPROM_DEVICE_NUMBER_7
 * -> For EEPROM_MODEL_AT24C04
 *      A2_A1 = 0_0 -> EEPROM_DEVICE_NUMBER_0
 *      A2_A1 = 0_1 -> EEPROM_DEVICE_NUMBER_1
 *      A2_A1 = 1_0 -> EEPROM_DEVICE_NUMBER_2
 *      A2_A1 = 1_1 -> EEPROM_DEVICE_NUMBER_3
 * -> For EEPROM_MODEL_AT24C08
 *      A2 = 0 -> EEPROM_DEVICE_NUMBER_0
 *      A2 = 1 -> EEPROM_DEVICE_NUMBER_1
*/

#endif /* INC_EEPROM_H_ */
