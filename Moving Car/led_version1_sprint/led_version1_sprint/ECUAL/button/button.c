/*
 * CFile1.c
 *
 * Created: 8/27/2023 8:53:29 PM
 *  Author: PC
 */ 

#include "button.h"

/* Function description 
* this function make initialization of pin to make it button 
* this function take port name and number of pin 
* check if there any error in port name or pin will return error 
*/

uint8_t BUTTON_init(uint8_t a_buttonport ,uint8_t a_buttonpin)
{
	int res =DIO_init(a_buttonport,a_buttonpin,IN);
	if (res == BUTTON_ERROR_STATE)
	{
		return BUTTON_ERROR_STATE;
	}
		
	return BUTTON_SUCCESS;
}


/* Function description
* this function read value in pin
* take port name , number of pin and return value in pin 
* check if there any error in port name or pin will return error
*/

uint8_t BUTTON_read(uint8_t a_buttonport,uint8_t a_buttonpin,uint8_t *a_value)
{
	int res = DIO_read(a_buttonport,a_buttonpin,a_value);
	if (res == BUTTON_ERROR_STATE)
	{
		return BUTTON_ERROR_STATE;
	}
		
	return BUTTON_SUCCESS;
}