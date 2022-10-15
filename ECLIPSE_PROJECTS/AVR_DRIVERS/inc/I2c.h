/*
 * I2c.h
 *
 *  Created on: Oct 13, 2022
 *      Author: ahmad
 */

#ifndef INC_I2C_H_
#define INC_I2C_H_

typedef enum
{

    /************************************************************************
     * Master Status
     ***********************************************************************/

    /* A START condition has been transmitted */
    I2C_STATUS_MASTER_START_SENT = 0x08,

    /* A repeated START condition has been transmitted */
    I2C_STATUS_MASTER_REP_START_SENT = 0x10,

    /* SLA+W has been transmitted; ACK has been received */
    I2C_STATUS_MASTER_SA_W_ACK = 0x18,

    /* SLA+W has been transmitted; NOT ACK has been received */
    I2C_STATUS_MASTER_SA_W_NACK = 0x20,

    /* SLA+R has been transmitted; ACK has been received */
    I2C_STATUS_MASTER_SA_R_ACK = 0x40,

    /* SLA+R has been transmitted; NOT ACK has been received */
    I2C_STATUS_MASTER_SA_R_NACK = 0x48,

    /* Data byte has been transmitted; ACK has been received */
    I2C_STATUS_MASTER_DATA_SENT_ACK = 0x28,

    /* Data byte has been transmitted; NOT ACK has been received */
    I2C_STATUS_MASTER_DATA_SENT_NACK = 0x30,

    /* Data byte has been received; ACK has been returned */
    I2C_STATUS_MASTER_DATA_RECEIVED_ACK = 0x50,

    /* Data byte has been received; NOT ACK has been returned */
    I2C_STATUS_MASTER_DATA_RECEIVED_NACK = 0x58,

    /* Arbitration lost */
    I2C_STATUS_MASTER_ARBITRATION_LOST = 0x38,

    /************************************************************************
     * Slave Status
     ***********************************************************************/

    /* Own SLA+W has been received; ACK has been returned */
    I2C_STATUS_SLAVE_SA_W_RECEIVED = 0x60,

    /* Own SLA+R has been received; ACK has been returned */
    I2C_STATUS_SLAVE_SA_R_RECEIVED = 0xA8,

    /* General call address has been received; ACK has been returned */
    I2C_STATUS_SLAVE_GC_RECEIVED = 0x70,

    /* Previously addressed with own SLA+W; data has been received; ACK has been returned */
    I2C_STATUS_SLAVE_SA_DATA_RECEIVED_ACK = 0x80,

    /* Previously addressed with own SLA+W; data has been received; NOT ACK has been returned */
    I2C_STATUS_SLAVE_SA_DATA_RECEIVED_NACK = 0x88,

    /* Previously addressed with general call; data has been received; ACK has been returned */
    I2C_STATUS_SLAVE_GC_DATA_RECEIVED_ACK = 0x90,

    /* Previously addressed with general call; data has been received; NOT ACK has been returned */
    I2C_STATUS_SLAVE_GC_DATA_RECEIVED_NACK = 0x98,

    /* Last data byte in TWDR has been transmitted (TWEA = “0”); ACK has been received */
    I2C_STATUS_SLAVE_LAST_DATA_SENT_ACK = 0xC8,

    /* Data byte in TWDR has been transmitted; ACK has been received */
    I2C_STATUS_SLAVE_DATA_SENT_ACK = 0xB8,

    /* Data byte in TWDR has been transmitted; NOT ACK has been received */
    I2C_STATUS_SLAVE_DATA_SENT_NACK = 0xC0,

    /* A STOP condition or repeated START condition has been received while still addressed as slave */
    I2C_STATUS_SLAVE_STOP_OR_REP_START_RECEIVED = 0xA0

} I2c_StatusType;

typedef enum
{
    I2C_REQUEST_WRITE = 0,
    I2C_REQUEST_READ = 1
} I2c_RequestType;

typedef enum
{
    I2C_ERROR_SLA_NACK,
    I2C_ERROR_DATA_NACK,
    I2C_ERROR_DATA_NOT_RECEIVED,
    I2C_ERROR_WRITE_REQUEST_NOT_RECEIVED,
    I2C_ERROR_READ_REQUEST_NOT_RECEIVED,
    I2C_ERROR_START_NOT_SENT,
    I2C_NO_ERROR
} I2c_ErrorStateType;


void I2c_Slave_Init(u8 address);
void I2c_Master_Init(u8 address);
void I2c_Master_SendStop(void);
I2c_StatusType I2c_Master_SendStart(void);
I2c_StatusType I2c_Master_SendSlaveAddress(u8 address, I2c_RequestType request);
I2c_StatusType I2c_WriteData(u8 data);
I2c_StatusType I2c_ReadData(u8 *data);
I2c_StatusType I2c_GetStatus(void);
u8 I2c_GetFlag(void);
void I2c_ClearFlag(void);
void I2c_EnableAck(void);
void I2c_DisableAck(void);
void I2c_EnableGeneralCall(void);
void I2c_DisableGeneralCall(void);
I2c_ErrorStateType I2c_Master_Transmit (u8 slave_address, u8 dataBuffer[], u8 length);
I2c_ErrorStateType I2c_Master_Receive (u8 slave_address, u8 dataBuffer[], u8 length);
I2c_ErrorStateType I2c_Slave_Transmit (u8 dataBuffer[], u8 length);
I2c_ErrorStateType I2c_Slave_Receive (u8 dataBuffer[], u8 length);
#endif /* INC_I2C_H_ */
