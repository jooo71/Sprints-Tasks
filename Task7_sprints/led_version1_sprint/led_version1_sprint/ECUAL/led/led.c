/*
 * led.c
 *
 * Created: 8/27/2023 8:51:07 PM
 *  Author: PC
 */ 
#include "led.h"
#include <assert.h>
uint8_t LED_init(uint8_t ledport , uint8_t ledpin)
{
	uint8_t res = DIO_init(ledport,ledpin,OUT);
	if (res == LED_STATE_ERRORSTATE)
	{
		return LED_STATE_ERRORSTATE;
	}
	return LED_STATE_SUCCESS;
}
uint8_t LED_on(uint8_t ledport , uint8_t ledpin)
{
	uint8_t res= DIO_write(ledport,ledpin,HIGH);
	if (res == LED_STATE_ERRORSTATE)
	{
		return LED_STATE_ERRORSTATE;
	}
	return LED_STATE_SUCCESS;
}
uint8_t LED_off(uint8_t ledport , uint8_t ledpin)
{
	uint8_t res = DIO_write(ledport,ledpin,LOW);
	if (res == LED_STATE_ERRORSTATE)
	{
		return LED_STATE_ERRORSTATE;
	}
	return LED_STATE_SUCCESS;
}
uint8_t LED_toggle(uint8_t ledport , uint8_t ledpin)
{
	uint8_t res= DIO_toggle(ledport,ledpin);
	if (res == LED_STATE_ERRORSTATE)
	{
		return LED_STATE_ERRORSTATE;
	}
	return LED_STATE_SUCCESS;
}

void led_test()
{
	
	uint8_t res;
	res=  LED_init(PORT_A,PIN0);
	if (res == SUCCESS)
	{
		LED_on(PORT_A,PIN0);
	}
	
	
}