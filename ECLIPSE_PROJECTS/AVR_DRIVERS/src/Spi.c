/*
 * Spi.c
 *
 *  Created on: Oct 8, 2022
 *      Author: ahmad
 */

#include <std_types.h>
#include <Macros.h>
#include <Registers.h>
#include <Dio.h>
#include <Interrupts.h>
#include <Spi_cfg.h>
#include <Spi_private.h>
#include <Spi.h>

void (*Spi_Callback) (u8 data);

ISR (VECTOR_SPI) {
    Spi_Callback(SPDR);
}

void Spi_Init(void) {

    /* Data Order */
#if SPI_DATA_ORDER == SPI_DATA_ORDER_LSB
    SET_BIT(SPCR, SPCR_DORD);
#elif SPI_DATA_ORDER == SPI_DATA_ORDER_MSB
    CLR_BIT(SPCR, SPCR_DORD);
#else
    #error "INVALID DATA ORDER FOR SPI"
#endif

#if SPI_POLARITY == SPI_POLARITY_IDLE_HIGH
    SET_BIT(SPCR, SPCR_CPOL);
#elif SPI_POLARITY == SPI_POLARITY_IDLE_LOW
    CLR_BIT(SPCR, SPCR_CPOL);
#else
    #error "INVALID POLARITY FOR SPI"
#endif

#if SPI_PHASE == SPI_PHASE_SAMPLE_SETUP
    CLR_BIT(SPCR, SPCR_CPHA);
#elif SPI_PHASE == SPI_PHASE_SETUP_SAMPLE
    SET_BIT(SPCR, SPCR_CPHA);
#else
    #error "INVALID PHASE FOR SPI"
#endif



#if SPI_MODE == SPI_MASTER
    /* Master/Slave Select */
    SET_BIT(SPCR, SPCR_MSTR);
    /* SPI Clock Rate Select */
#if SPI_PRESCALER == SPI_PRESCALER_2
    CLR_BIT(SPCR, SPCR_SPR0);
    CLR_BIT(SPCR, SPCR_SPR1);
    SET_BIT(SPSR, SPSR_SPI2X);
#elif SPI_PRESCALER == SPI_PRESCALER_4
    // TODO
#elif SPI_PRESCALER == SPI_PRESCALER_8
    // TODO
#elif SPI_PRESCALER == SPI_PRESCALER_16
    // TODO
#elif SPI_PRESCALER == SPI_PRESCALER_32
    // TODO
#elif SPI_PRESCALER == SPI_PRESCALER_64
    // TODO
#elif SPI_PRESCALER == SPI_PRESCALER_128
    // TODO
#else
#error "INVALID PRESCALER FOR SPI"
#endif
    /* Pin Init */
    Dio_SetPinMode(SPI_PIN_MISO, DIO_PIN_INPUT_FLOATING);
    Dio_SetPinMode(SPI_PIN_MOSI, DIO_PIN_OUTPUT);
    Dio_SetPinMode(SPI_PIN_SCK, DIO_PIN_OUTPUT);

#elif SPI_MODE == SPI_SLAVE
    /* Master/Slave Select */
    CLR_BIT(SPCR, SPCR_MSTR);
    /* Pin Init */
    Dio_SetPinMode(SPI_PIN_MISO, DIO_PIN_OUTPUT);
    Dio_SetPinMode(SPI_PIN_MOSI, DIO_PIN_INPUT_FLOATING);
    Dio_SetPinMode(SPI_PIN_SCK, DIO_PIN_INPUT_FLOATING);
    Dio_SetPinMode(SPI_PIN_SS, DIO_PIN_INPUT_PULLUP);
#else
#error "INVALID SPI MODE"
#endif

    /* SPI Enable */
    SET_BIT(SPCR, SPCR_SPE);
}

u8 Spi_Transfer(u8 data) {
    SPDR = data;
    while (GET_BIT(SPSR, SPSR_SPIF) == 0);
    return SPDR;
}

void Spi_EnableNotification(void (*callback)(u8 data)) {
    Spi_Callback = callback;
    SET_BIT(SPCR, SPCR_SPIE);
}

void Spi_DisableNotification(void) {
    CLR_BIT(SPCR, SPCR_SPIE);
}

