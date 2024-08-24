/*
 * dio.c
 *
 * Created: 8/27/2023 8:49:22 PM
 *  Author: PC
 */ 

#include "dio.h"

/* Function description
* this function to initialize pins to output or input
* take port name and pin number and direction (output/input)
* check if pin number not correct will return error
*/

uint8_t DIO_init(uint8_t a_portNumber, uint8_t a_pinNumber, uint8_t a_direction)
{
	if (a_pinNumber>7)
	{
		return DIOERRORSTATE;
	}
	else
	{
		switch(a_portNumber)
		{
			case PORT_A:
			if (a_direction == IN)
			{
				DDRA &=~(1<<a_pinNumber);
			}
			else if(a_direction == OUT)
			{
				DDRA |=(1<<a_pinNumber);
			}
			else
			{
				return DIOERRORSTATE;
			}
			break;
			case PORT_B:
			if (a_direction == IN)
			{
				DDRB &=~(1<<a_pinNumber);
			}
			else if(a_direction == OUT)
			{
				DDRB |=(1<<a_pinNumber);
			}
			else
			{
				return DIOERRORSTATE;
			}
			break;
			case PORT_C:
			if (a_direction == IN)
			{
				DDRC &=~(1<<a_pinNumber);
			}
			else if(a_direction == OUT)
			{
				DDRC |=(1<<a_pinNumber);
			}
			else
			{
				return DIOERRORSTATE;
			}
			break;
			case PORT_D:
			if (a_direction == IN)
			{
				DDRD &=~(1<<a_pinNumber);
			}
			else if(a_direction == OUT)
			{
				DDRD |=(1<<a_pinNumber);
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

}


/* Function description
* this function to write on pin high or low
* take port name , pin number and a_value
* return error if port name or a_value not correct
*/

uint8_t DIO_write(uint8_t a_portNumber, uint8_t a_pinNumber, uint8_t a_value)
{
	switch(a_portNumber)
	{
		case PORT_A:
		if (a_value == LOW)
		{
			PORTA &=~(1<<a_pinNumber); // write 0
		}
		else if(a_value == HIGH)
		{
			PORTA |=(1<<a_pinNumber); // write 1
		}
		else
		{
			return DIOERRORSTATE;
		}
		break;
		case PORT_B:
		if (a_value == LOW)
		{
			PORTB &=~(1<<a_pinNumber);
		}
		else if(a_value == HIGH)
		{
			PORTB |=(1<<a_pinNumber);
		}
		else
		{
			return DIOERRORSTATE;
		}
		break;
		case PORT_C:
		if (a_value == LOW)
		{
			PORTC &=~(1<<a_pinNumber);
		}
		else if(a_value == HIGH)
		{
			PORTC |=(1<<a_pinNumber);
		}
		else
		{
			return DIOERRORSTATE;
		}
		break;
		case PORT_D:
		if (a_value == LOW)
		{
			PORTD &=~(1<<a_pinNumber);
		}
		else if(a_value == HIGH)
		{
			PORTD |=(1<<a_pinNumber);
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


/* Function description
* this function to toggle a_value on pin 
* take port name , pin number 
* return error if port name not correct
*/

uint8_t DIO_toggle(uint8_t a_portNumber, uint8_t a_pinNumber)
{
	switch(a_portNumber)
	{
		case PORT_A:
		PORTA ^=(1<<a_pinNumber);
		break;
		case PORT_B:
		PORTB ^=(1<<a_pinNumber);
		break;
		case PORT_C:
		PORTC ^=(1<<a_pinNumber);
		break;
		case PORT_D:
		PORTD ^=(1<<a_pinNumber);
		break;
		default:
		return DIOERRORSTATE;
		
	}
	return SUCCESS;
}


/* Function description
* this function to read a_value on pin
* take port name , pin number and return a_value
* return error if port name not correct
*/

uint8_t DIO_read(uint8_t a_portNumber, uint8_t a_pinNumber, uint8_t *a_value)
{
	switch(a_portNumber)
	{
		case PORT_A:
		*a_value = (PINA & (1<<a_pinNumber))>> a_pinNumber;
		break;
		case PORT_B:
		*a_value = (PINB & (1<<a_pinNumber))>> a_pinNumber;
		break;
		case PORT_C:
		*a_value = (PINC & (1<<a_pinNumber))>> a_pinNumber;
		break;
		case PORT_D:
		*a_value = (PIND & (1<<a_pinNumber))>> a_pinNumber;
		break;
		default:
		return DIOERRORSTATE;
	}
	return SUCCESS;
}


/* Function description
* this function to write on whole port 
* take port name and a_value
* return error if port name not correct
*/

uint8_t DIO_writePort(uint8_t a_portNumber , uint8_t a_value)
{
	switch(a_portNumber)
	{
		case PORT_A:
		PORTA =a_value;
		break;
		case PORT_B:
		PORTB =a_value;
		break;
		case PORT_C:
		PORTC =a_value;
		break;
		case PORT_D:
		PORTD =a_value;
		break;
		default:
		return DIOERRORSTATE;
	}
	return SUCCESS;
}