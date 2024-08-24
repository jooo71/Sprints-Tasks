/*
 * button.c
 *
 * Created: 8/22/2023 11:30:41 PM
 *  Author: PC
 */ 
#include "button.h"

uint8_t BUTTON_init(uint8_t buttonport ,uint8_t buttonpin)
{
	DIO_init(buttonport,buttonpin,IN);
	return SUCCESS;
}

uint8_t BUTTON_read(uint8_t buttonport,uint8_t buttonpin,uint8_t *value)
{
	DIO_read(buttonport,buttonpin,value);
	return SUCCESS;
}