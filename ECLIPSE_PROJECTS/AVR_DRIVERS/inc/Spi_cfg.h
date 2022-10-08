/*
 * Spi_cfg.h
 *
 *  Created on: Oct 8, 2022
 *      Author: ahmad
 */

#ifndef INC_SPI_CFG_H_
#define INC_SPI_CFG_H_

/*******************************************************************
--> Options:
        SPI_SLAVE
        SPI_MASTER
*/
#define SPI_MODE                SPI_MASTER
/*******************************************************************
--> Options:
        SPI_DATA_ORDER_MSB
        SPI_DATA_ORDER_LSB
*/
#define SPI_DATA_ORDER          SPI_DATA_ORDER_MSB
/*******************************************************************
--> Options:
        SPI_POLARITY_IDLE_HIGH
        SPI_POLARITY_IDLE_LOW
*/
#define SPI_POLARITY            SPI_POLARITY_IDLE_HIGH
/*******************************************************************
--> Options:
        SPI_PHASE_SAMPLE_SETUP
        SPI_PHASE_SETUP_SAMPLE
*/
#define SPI_PHASE               SPI_PHASE_SAMPLE_SETUP
/*******************************************************************
--> Options:
        SPI_PRESCALER_2
        SPI_PRESCALER_4
        SPI_PRESCALER_8
        SPI_PRESCALER_16
        SPI_PRESCALER_32
        SPI_PRESCALER_64
        SPI_PRESCALER_128
*/
#define SPI_PRESCALER           SPI_PRESCALER_2
/*******************************************************************/

#endif /* INC_SPI_CFG_H_ */
