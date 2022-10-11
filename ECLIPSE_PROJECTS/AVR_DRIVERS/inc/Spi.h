/*
 * Spi.h
 *
 *  Created on: Oct 8, 2022
 *      Author: ahmad
 */

#ifndef INC_SPI_H_
#define INC_SPI_H_

void Spi_Init(void);
u8 Spi_Transfer(u8 data);
void Spi_EnableNotification(void (*callback)(u8 data));
void Spi_DisableNotification(void);
void Spi_WriteDate(u8 data);

#endif /* INC_SPI_H_ */
