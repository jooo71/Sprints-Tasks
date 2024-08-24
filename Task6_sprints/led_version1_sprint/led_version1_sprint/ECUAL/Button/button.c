/*
 * CFile1.c
 *
 * Created: 8/27/2023 8:53:29 PM
 *  Author: PC
 */ 

#include "button.h"

uint8_t BUTTON_init(uint8_t buttonport ,uint8_t buttonpin)
{
	int res =DIO_init(buttonport,buttonpin,IN);
	if (res == BUTTON_ERROR_STATE)
	{
		return BUTTON_ERROR_STATE;
	}
		
	return BUTTON_SUCCESS;
}

uint8_t BUTTON_read(uint8_t buttonport,uint8_t buttonpin,uint8_t *value)
{
	int res = DIO_read(buttonport,buttonpin,value);
	if (res == BUTTON_ERROR_STATE)
	{
		return BUTTON_ERROR_STATE;
	}
		
	return BUTTON_SUCCESS;
}