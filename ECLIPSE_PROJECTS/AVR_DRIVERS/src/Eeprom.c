/*
 * Eeprom.c
 *
 *  Created on: Oct 15, 2022
 *      Author: ahmad
 */

#include <std_types.h>
#include <Macros.h>
#include <I2c.h>
#include <Eeprom.h>
#include <Usart.h>


Eeprom_StateType Eeprom_WriteByte(Eeprom_DeviceType device, u8 data, u16 address) {
    u8 device_address = 0b1010000;
    I2c_StatusType status;

#if     EEPROM_MODEL == EEPROM_MODEL_AT24C02
    device_address |= device;
#elif   EEPROM_MODEL == EEPROM_MODEL_AT24C04
    device_address |= device<<1 | (GET_BIT(address,8));
#elif   EEPROM_MODEL == EEPROM_MODEL_AT24C08
    device_address |= device<<2 | (GET_BIT(address,9)<<1) | (GET_BIT(address,8));
#endif

    status = I2c_Master_SendStart();
    if (status != I2C_STATUS_MASTER_START_SENT) {
        return EEPROM_FAILED;
    }

    status = I2c_Master_SendSlaveAddress(device_address, I2C_REQUEST_WRITE);
    if (status != I2C_STATUS_MASTER_SA_W_ACK) {
        I2c_Master_SendStop();
        return EEPROM_FAILED;
    }

    status = I2c_WriteData((u8)address);
    if (status != I2C_STATUS_MASTER_DATA_SENT_ACK) {
        I2c_Master_SendStop();
        return EEPROM_FAILED;
    }

    status = I2c_WriteData(data);
    if (status != I2C_STATUS_MASTER_DATA_SENT_ACK) {
        I2c_Master_SendStop();
        return EEPROM_FAILED;
    }

    I2c_Master_SendStop();
    return EEPROM_SUCCESS;
}


Eeprom_StateType Eeprom_ReadByte(Eeprom_DeviceType device, u8 *data, u16 address) {
    u8 device_address = 0b1010000;
    u8 tempData;
    I2c_StatusType status;

#if     EEPROM_MODEL == EEPROM_MODEL_AT24C02
    device_address |= device;
#elif   EEPROM_MODEL == EEPROM_MODEL_AT24C04
    device_address |= device<<1 | (GET_BIT(address,8));
#elif   EEPROM_MODEL == EEPROM_MODEL_AT24C08
    device_address |= device<<2 | (GET_BIT(address,9)<<1) | (GET_BIT(address,8));
#endif

    status = I2c_Master_SendStart();
    if (status != I2C_STATUS_MASTER_START_SENT) {
        return EEPROM_FAILED;
    }

    status = I2c_Master_SendSlaveAddress(device_address, I2C_REQUEST_WRITE);
    if (status != I2C_STATUS_MASTER_SA_W_ACK) {
        I2c_Master_SendStop();
        return EEPROM_FAILED;
    }

    status = I2c_WriteData((u8)address);
    if (status != I2C_STATUS_MASTER_DATA_SENT_ACK) {
        I2c_Master_SendStop();
        return EEPROM_FAILED;
    }

    status = I2c_Master_SendStart();
    if (status != I2C_STATUS_MASTER_REP_START_SENT) {
        I2c_Master_SendStop();
        return EEPROM_FAILED;
    }

    status = I2c_Master_SendSlaveAddress(device_address, I2C_REQUEST_READ);
    if (status != I2C_STATUS_MASTER_SA_R_ACK) {
        I2c_Master_SendStop();
        return EEPROM_FAILED;
    }

    I2c_EnableAck();
    status = I2c_ReadData(&tempData);
    if (status != I2C_STATUS_MASTER_DATA_RECEIVED_ACK) {
        I2c_DisableAck();
        I2c_Master_SendStop();
        return EEPROM_FAILED;
    }
    else {
        *data = tempData;
    }
    I2c_DisableAck();

    I2c_Master_SendStop();
    return EEPROM_SUCCESS;
}
