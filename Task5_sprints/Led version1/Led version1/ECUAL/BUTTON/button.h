/*
 * button.h
 *
 * Created: 8/22/2023 11:30:52 PM
 *  Author: PC
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "../MCAL/DIO/dio.h"

uint8_t BUTTON_init(uint8_t buttonport ,uint8_t buttonpin);

uint8_t BUTTON_read(uint8_t buttonport,uint8_t buttonpin,uint8_t *value);




#endif /* BUTTON_H_ */