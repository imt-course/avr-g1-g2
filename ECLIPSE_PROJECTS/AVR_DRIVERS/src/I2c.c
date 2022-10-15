/*
 * I2c.c
 *
 *  Created on: Oct 13, 2022
 *      Author: ahmad
 */

#include <std_types.h>
#include <Macros.h>
#include <Registers.h>
#include <Interrupts.h>
#include <Usart.h>
#include <I2c_private.h>
#include <I2c_cfg.h>
#include <I2c.h>

void I2c_Slave_Init(u8 address)
{
    /* Address Register */
    TWAR = (address << 1);
    /* TWI Enable Bit */
    SET_BIT(TWCR, TWCR_TWEN);
}

void I2c_Master_Init(u8 address)
{
    /* Address Register */
    TWAR = (address << 1);
    /* Bit Rate Select */
    TWBR = I2C_TWBR_VALUE;
    TWSR &= 0xFC;
    TWSR |= (I2C_TWPS_VALUE & 0x03);
    /* TWI Enable Bit */
    SET_BIT(TWCR, TWCR_TWEN);
}

void I2c_Master_SendStop(void)
{
    /* Clear TWI Interrupt Flag; And Send STOP Condition */
    TWCR |= (1 << TWCR_TWINT) | (1 << TWCR_TWSTO);
}

I2c_StatusType I2c_Master_SendStart(void)
{
    /* Clear TWI Interrupt Flag; And Send START Condition */
    TWCR |= (1 << TWCR_TWINT) | (1 << TWCR_TWSTA);
    /* Wait till start condition is transmitted */
    while (GET_BIT(TWCR, TWCR_TWINT) == 0)
        ;
    /* Getting I2C Status */
    return I2C_GET_STATUS();
}

I2c_StatusType I2c_Master_SendSlaveAddress(u8 address, I2c_RequestType request)
{
    TWDR = ((address << 1) | request);
    /* Clear TWI Interrupt Flag and Clear Start */
    TWCR = (1<<TWCR_TWINT) | (1<<TWCR_TWEN);
    /* Wait till complete TWDR byte transmitted */
    while (GET_BIT(TWCR, TWCR_TWINT) == 0)
        ;
    /* Getting I2C Status */
    return I2C_GET_STATUS();
}

I2c_StatusType I2c_WriteData(u8 data)
{
    TWDR = data;
    /* Clear TWI Interrupt Flag */
    SET_BIT(TWCR, TWCR_TWINT);
    /* Wait till complete TWDR byte transmitted */
    while (GET_BIT(TWCR, TWCR_TWINT) == 0)
        ;
    /* Getting I2C Status */
    return I2C_GET_STATUS();
}

I2c_StatusType I2c_ReadData(u8 *data)
{
    /* Clear TWI Interrupt Flag */
    SET_BIT(TWCR, TWCR_TWINT);
    /* Wait till complete TWDR byte transmitted */
    while (GET_BIT(TWCR, TWCR_TWINT) == 0)
        ;
    /* Reading Data */
    *data = TWDR;
    /* Getting I2C Status */
    return I2C_GET_STATUS();
}

u8 I2c_GetFlag(void)
{
    return GET_BIT(TWCR, TWCR_TWINT);
}
void I2c_ClearFlag(void)
{
    SET_BIT(TWCR, TWCR_TWINT);
}

I2c_StatusType I2c_GetStatus(void)
{
    return I2C_GET_STATUS();
}

void I2c_EnableAck(void)
{
    SET_BIT(TWCR, TWCR_TWEA);
}

void I2c_DisableAck(void)
{
    CLR_BIT(TWCR, TWCR_TWEA);
}

void I2c_EnableGeneralCall(void)
{
    SET_BIT(TWAR, TWAR_TWGCE);
}

void I2c_DisableGeneralCall(void)
{
    CLR_BIT(TWAR, TWAR_TWGCE);
}

I2c_ErrorStateType I2c_Master_Transmit(u8 slave_address, u8 dataBuffer[], u8 length)
{
    u8 i;
    I2c_StatusType status;

    status = I2c_Master_SendStart();
    if (status != I2C_STATUS_MASTER_START_SENT)
    {
        return I2C_ERROR_START_NOT_SENT;
    }

    status = I2c_Master_SendSlaveAddress(slave_address, I2C_REQUEST_WRITE);
    if (status != I2C_STATUS_MASTER_SA_W_ACK)
    {
        I2c_Master_SendStop();
        return I2C_ERROR_SLA_NACK;
    }

    for (i = 0; i < length; i++)
    {
        status = I2c_WriteData(dataBuffer[i]);
        if (status != I2C_STATUS_MASTER_DATA_SENT_ACK)
        {
            I2c_Master_SendStop();
            return I2C_ERROR_DATA_NACK;
        }
    }

    I2c_Master_SendStop();
    return I2C_NO_ERROR;
}

I2c_ErrorStateType I2c_Master_Receive(u8 slave_address, u8 dataBuffer[], u8 length)
{
    // TODO
}

I2c_ErrorStateType I2c_Slave_Transmit(u8 dataBuffer[], u8 length)
{
    // TODO
}

I2c_ErrorStateType I2c_Slave_Receive(u8 dataBuffer[], u8 length)
{
    u8 i;
    u8 temp_data;
    I2c_StatusType status = 0;
    I2c_EnableAck();

    /* Clear TWI Interrupt Flag */
    SET_BIT(TWCR, TWCR_TWINT);

    /* Wait for flag */
    while (GET_BIT(TWCR, TWCR_TWINT) == 0)
        ;

    /* Getting I2C Status */
    status = I2C_GET_STATUS();

    if (status != I2C_STATUS_SLAVE_SA_W_RECEIVED)
    {
        return I2C_ERROR_WRITE_REQUEST_NOT_RECEIVED;
    }

    for (i = 0; i < length; i++)
    {
        status = I2c_ReadData(&temp_data);
        if (status != I2C_STATUS_SLAVE_SA_DATA_RECEIVED_ACK)
        {
            return I2C_ERROR_DATA_NOT_RECEIVED;
        }
        else
        {
            dataBuffer[i] = temp_data;
        }
    }
    I2c_DisableAck();
    return I2C_NO_ERROR;
}
