/*
 * button.h
 *
 * Created: 8/27/2023 8:53:45 PM
 *  Author: PC
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_
typedef enum BUTTONSTATE
{
	BUTTON_ERROR_STATE , BUTTON_SUCCESS
}BUTTONSTATE;
#include "../MCAL/dio/dio.h"
#include "../MCAL/Interrupt/interrupt.h"
#include "Timer/timer.h"
#include "pwm/pwm.h"

/* Function description
* this function make initialization of pin to make it button
* this function take port name and number of pin
* check if there any error in port name or pin will return error
*/
uint8_t BUTTON_init(uint8_t a_buttonport ,uint8_t a_buttonpin);

/* Function description
* this function read value in pin
* take port name , number of pin and return value in pin
* check if there any error in port name or pin will return error
*/
uint8_t BUTTON_read(uint8_t a_buttonport,uint8_t a_buttonpin,uint8_t *a_value);



#endif /* BUTTON_H_ */