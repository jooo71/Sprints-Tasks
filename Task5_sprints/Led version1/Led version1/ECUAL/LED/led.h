/*
 * led.h
 *
 * Created: 8/22/2023 3:56:35 AM
 *  Author: PC
 */ 
#include "../MCAL/DIO/dio.h" // enter into folder and get file
//#include "../MCAL/DIO/dio.h"

#ifndef LED_H_
#define LED_H_

uint8_t LED_init(uint8_t ledport , uint8_t ledpin);
uint8_t LED_on(uint8_t ledport , uint8_t ledpin);
uint8_t LED_off(uint8_t ledport , uint8_t ledpin);
uint8_t LED_toggle(uint8_t ledport , uint8_t ledpin);




#endif /* LED_H_ */