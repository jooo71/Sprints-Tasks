/*
 * led.c
 *
 * Created: 8/27/2023 8:51:07 PM
 *  Author: PC
 */ 
#include "led.h"
#include <assert.h>

/* Function description
* this function make initialization of pin to make it led
* take port name and number of pin
* check if there any error in port name or pin will return error
*/
uint8_t LED_init(uint8_t a_ledport , uint8_t a_ledpin)
{
	uint8_t res = DIO_init(a_ledport,a_ledpin,OUT);
	if (res == LED_STATE_ERRORSTATE)
	{
		return LED_STATE_ERRORSTATE;
	}
	return LED_STATE_SUCCESS;
}

/* Function description
* this function make led to be on through write high on bin
* take port name , number of pin and return value in pin
* check if there any error in port name or pin will return error
*/


uint8_t LED_on(uint8_t a_ledport , uint8_t a_ledpin)
{
	uint8_t res= DIO_write(a_ledport,a_ledpin,HIGH);
	if (res == LED_STATE_ERRORSTATE)
	{
		return LED_STATE_ERRORSTATE;
	}
	return LED_STATE_SUCCESS;
}

/* Function description
* this function make led to be off through write low on bin
* take port name , number of pin and return value in pin
* check if there any error in port name or pin will return error
*/

uint8_t LED_off(uint8_t a_ledport , uint8_t a_ledpin)
{
	uint8_t res = DIO_write(a_ledport,a_ledpin,LOW);
	if (res == LED_STATE_ERRORSTATE)
	{
		return LED_STATE_ERRORSTATE;
	}
	return LED_STATE_SUCCESS;
}

/* Function description
* this function toggle value in pin
* take port name , number of pin and return value in pin
* check if there any error in port name or pin will return error
*/

uint8_t LED_toggle(uint8_t a_ledport , uint8_t a_ledpin)
{
	uint8_t res= DIO_toggle(a_ledport,a_ledpin);
	if (res == LED_STATE_ERRORSTATE)
	{
		return LED_STATE_ERRORSTATE;
	}
	return LED_STATE_SUCCESS;
}

/* Function description
* this void function
* test function for led_init 
* check if there any error in initialization will return error
*/

void led_test()
{
	
	uint8_t res;
	res=  LED_init(PORT_A,PIN0);
	if (res == SUCCESS)
	{
		LED_on(PORT_A,PIN0);
	}
	
	
}