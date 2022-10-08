/*
 * Spi_private.h
 *
 *  Created on: Oct 8, 2022
 *      Author: ahmad
 */

#ifndef INC_SPI_PRIVATE_H_
#define INC_SPI_PRIVATE_H_

/******************************************************************
 * Configurations
 *****************************************************************/

#define SPI_PIN_MOSI                DIO_PORTB,DIO_PIN5
#define SPI_PIN_MISO                DIO_PORTB,DIO_PIN6
#define SPI_PIN_SCK                 DIO_PORTB,DIO_PIN7
#define SPI_PIN_SS                  DIO_PORTB,DIO_PIN4

#define SPI_SLAVE                   1
#define SPI_MASTER                  2

#define SPI_DATA_ORDER_MSB          1
#define SPI_DATA_ORDER_LSB          2

#define SPI_POLARITY_IDLE_HIGH      1
#define SPI_POLARITY_IDLE_LOW       2

#define SPI_PHASE_SAMPLE_SETUP      1
#define SPI_PHASE_SETUP_SAMPLE      2

#define SPI_PRESCALER_2             1
#define SPI_PRESCALER_4             2
#define SPI_PRESCALER_8             3
#define SPI_PRESCALER_16            4
#define SPI_PRESCALER_32            5
#define SPI_PRESCALER_64            6
#define SPI_PRESCALER_128           7

/******************************************************************
 * Registers Bits
 *****************************************************************/

#define SPCR_SPR0                   0
#define SPCR_SPR1                   1
#define SPCR_CPHA                   2
#define SPCR_CPOL                   3
#define SPCR_MSTR                   4
#define SPCR_DORD                   5
#define SPCR_SPE                    6
#define SPCR_SPIE                   7

#define SPSR_SPI2X                  0
#define SPSR_WCOL                   6
#define SPSR_SPIF                   7

#endif /* INC_SPI_PRIVATE_H_ */
