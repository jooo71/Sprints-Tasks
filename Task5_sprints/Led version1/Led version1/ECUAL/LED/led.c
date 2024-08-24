/*
 * led.c
 *
 * Created: 8/25/2023 4:39:37 PM
 *  Author: PC
 */ 
/*
 * led.c
 *
 * Created: 8/22/2023 3:56:25 AM
 *  Author: PC
 */ 
#include "led.h"
#include "../Typdef/typdef.h"
uint8_t LED_init(uint8_t ledport , uint8_t ledpin)
{
	DIO_init(ledport,ledpin,OUT);
	return SUCCESS;
}
uint8_t LED_on(uint8_t ledport , uint8_t ledpin)
{
	DIO_write(ledport,ledpin,HIGH);
	return SUCCESS;
}
uint8_t LED_off(uint8_t ledport , uint8_t ledpin)
{
	DIO_write(ledport,ledpin,LOW);
	return SUCCESS;
}
uint8_t LED_toggle(uint8_t ledport , uint8_t ledpin)
{
	DIO_toggle(ledport,ledpin);
	return SUCCESS;
}