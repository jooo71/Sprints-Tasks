/*
 * led.h
 *
 * Created: 8/27/2023 8:51:18 PM
 *  Author: PC
 */ 


#ifndef LED_H_
#define LED_H_
#include "../MCAL/DIO DRIVER/dio.h" // enter into folder and get file
#include "../MCAL/Interrupt/interrupt.h"
#include "Timer/timer.h"
typedef enum LEDSTATE
{
	LED_STATE_ERRORSTATE , LED_STATE_SUCCESS
}LEDSTATE;
uint8_t LED_init(uint8_t ledport , uint8_t ledpin);
uint8_t LED_on(uint8_t ledport , uint8_t ledpin);
uint8_t LED_off(uint8_t ledport , uint8_t ledpin);
uint8_t LED_toggle(uint8_t ledport , uint8_t ledpin);

void led_test(void); 

#endif /* LED_H_ */