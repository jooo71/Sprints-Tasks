/*
 * dio.c
 *
 * Created: 8/25/2023 4:35:18 PM
 *  Author: PC
 */ 
/*
 * dio.c
 *
 * Created: 8/22/2023 2:19:00 AM
 *  Author: PC
 */ 
//include.h
#include "dio.h"
// global variable
//function definitions

uint8_t DIO_init(uint8_t portNumber, uint8_t pinNumber, uint8_t direction)
{
	switch(portNumber)
	{
		case PORT_A:
			if (direction == IN)
			{
				DDRA &=~(1<<pinNumber);
			} 
			else if(direction == OUT)
			{
				DDRA |=(1<<pinNumber);
			}
			else
			{
				return DIOERRORSTATE;
			}
			break;
		case PORT_B:
			if (direction == IN)
			{
				DDRB &=~(1<<pinNumber);
			}
			else if(direction == OUT)
			{
				DDRB |=(1<<pinNumber);
			}
			else
			{
				return DIOERRORSTATE;
			}
			break;		
		case PORT_C:
			if (direction == IN)
			{
				DDRC &=~(1<<pinNumber);
			}
			else if(direction == OUT)
			{
				DDRC |=(1<<pinNumber);
			}
			else
			{
				return DIOERRORSTATE;
			}
			break;
		case PORT_D:
			if (direction == IN)
			{
				DDRD &=~(1<<pinNumber);
			}
			else if(direction == OUT)
			{
				DDRD |=(1<<pinNumber);
			}
			else
			{
				return DIOERRORSTATE;
			}
			break;
		default:
			return DIOERRORSTATE;
	}
	return SUCCESS;
}

uint8_t DIO_write(uint8_t portNumber, uint8_t pinNumber, uint8_t value)
{
	switch(portNumber)
	{
		case PORT_A:
			if (value == LOW)
			{
				PORTA &=~(1<<pinNumber); // write 0
			}
			else if(value == HIGH)
			{
				PORTA |=(1<<pinNumber); // write 1
			}
			else
			{
				return DIOERRORSTATE;
			}
			break;
		case PORT_B:
			if (value == LOW)
			{
				PORTB &=~(1<<pinNumber);
			}
			else if(value == HIGH)
			{
				PORTB |=(1<<pinNumber);
			}
			else
			{
				return DIOERRORSTATE;
			}
			break;
		case PORT_C:
			if (value == LOW)
			{
				PORTC &=~(1<<pinNumber);
			}
			else if(value == HIGH)
			{
				PORTC |=(1<<pinNumber);
			}
			else
			{
				return DIOERRORSTATE;
			}
			break;
		case PORT_D:
			if (value == LOW)
			{
				PORTD &=~(1<<pinNumber);
			}
			else if(value == HIGH)
			{
				PORTD |=(1<<pinNumber);
			}
			else
			{
				return DIOERRORSTATE;
			}
			break;
		default:
			return DIOERRORSTATE;

	}
	return SUCCESS;
}

uint8_t DIO_toggle(uint8_t portNumber, uint8_t pinNumber)
{
	switch(portNumber)
	{
		case PORT_A:
			PORTA ^=(1<<pinNumber);
			break;
		case PORT_B:
			PORTB ^=(1<<pinNumber);
			break;
		case PORT_C:
			PORTC ^=(1<<pinNumber);
			break;
		case PORT_D:
			PORTD ^=(1<<pinNumber);
			break;
		default:
			return DIOERRORSTATE;
			
	}
	return SUCCESS;
}

uint8_t DIO_read(uint8_t portNumber, uint8_t pinNumber, uint8_t *value)
{
	switch(portNumber)
	{
		case PORT_A:
			*value = (PINA & (1<<pinNumber))>> pinNumber;
			break;
		case PORT_B:
			*value = (PINB & (1<<pinNumber))>> pinNumber;
			break;
		case PORT_C:
			*value = (PINC & (1<<pinNumber))>> pinNumber;
			break;
		case PORT_D:
			*value = (PIND & (1<<pinNumber))>> pinNumber;
			break;
		default:
			return DIOERRORSTATE;
	}
	return SUCCESS;
}

uint8_t DIO_writePort(uint8_t portName , uint8_t value)
{
	switch(portName)
	{
		case PORT_A:
			PORTA =value;
			break;
		case PORT_B:
			PORTB =value;
			break;
		case PORT_C:
			PORTC =value;
			break;
		case PORT_D:
			PORTD =value;
			break;
		default:
			return DIOERRORSTATE;
	}
	return SUCCESS;
}