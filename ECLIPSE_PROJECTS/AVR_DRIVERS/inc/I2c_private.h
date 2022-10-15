/*
 * I2c_private.h
 *
 *  Created on: Oct 13, 2022
 *      Author: ahmad
 */

#ifndef INC_I2C_PRIVATE_H_
#define INC_I2C_PRIVATE_H_

#define TWBR_TWBR0      0
#define TWBR_TWBR1      1
#define TWBR_TWBR2      2
#define TWBR_TWBR3      3
#define TWBR_TWBR4      4
#define TWBR_TWBR5      5
#define TWBR_TWBR6      6
#define TWBR_TWBR7      7

#define TWCR_TWIE       0
#define TWCR_TWEN       2
#define TWCR_TWWC       3
#define TWCR_TWSTO      4
#define TWCR_TWSTA      5
#define TWCR_TWEA       6
#define TWCR_TWINT      7

#define TWSR_TWPS0      0
#define TWSR_TWPS1      1

#define TWAR_TWGCE      0

#define TWDR_TWDR0      0
#define I2C_GET_STATUS() (TWSR&0xF8)

#define I2C_ON  1
#define I2C_OFF 0

#endif /* INC_I2C_PRIVATE_H_ */
