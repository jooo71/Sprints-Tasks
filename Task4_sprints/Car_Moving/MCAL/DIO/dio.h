/*
 * dio.h
 *
 *  Created on: Aug 19, 2023
 *      Author: PC
 */

#ifndef MCAL_DIO_DIO_H_
#define MCAL_DIO_DIO_H_

void dio_init(uint8_t PortName, uint8_t PinNum);
void dio_write(uint8_t PinNum);
void dio_read(uint8_t PinNum);

#endif /* MCAL_DIO_DIO_H_ */
