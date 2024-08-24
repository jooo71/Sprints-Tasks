/*
 * led.h
 *
 * Created: 8/27/2023 8:51:18 PM
 *  Author: PC
 */ 


#ifndef LED_H_
#define LED_H_
#include "../MCAL/dio/dio.h" // enter into folder and get file
#include "../MCAL/Interrupt/interrupt.h"
#include "Timer/timer.h"
#include "pwm/pwm.h"

typedef enum LEDSTATE
{
	LED_STATE_ERRORSTATE , LED_STATE_SUCCESS
}LEDSTATE;


/* Function description
* this function make initialization of pin to make it led
* take port name and number of pin
* check if there any error in port name or pin will return error
*/

uint8_t LED_init(uint8_t a_ledport , uint8_t a_ledpin);


/* Function description
* this function make led to be on through write high on bin
* take port name , number of pin and return value in pin
* check if there any error in port name or pin will return error
*/

uint8_t LED_on(uint8_t a_ledport , uint8_t a_ledpin);


/* Function description
* this function make led to be off through write low on bin
* take port name , number of pin and return value in pin
* check if there any error in port name or pin will return error
*/

uint8_t LED_off(uint8_t a_ledport , uint8_t a_ledpin);


/* Function description
* this function toggle value in pin
* take port name , number of pin and return value in pin
* check if there any error in port name or pin will return error
*/

uint8_t LED_toggle(uint8_t a_ledport , uint8_t a_ledpin);


/* Function description
* this void function
* test function for led_init
* check if there any error in initialization will return error
*/

void led_test(void); 

#endif /* LED_H_ */