/*
 * motor.c
 *
 * Created: 9/9/2023 2:11:56 PM
 *  Author: PC
 */ 
#include "motor.h"


/* Function description
* this void function
* make motors to move 
*/

void MOTOR_move(void)
{
	/*fisrt two motors*/
	DIO_write(PORT_C,PIN0,HIGH);
	DIO_write(PORT_C,PIN1,LOW);
	DIO_write(PORT_C,PIN2,HIGH);
	DIO_write(PORT_C,PIN3,LOW);
	/*second two motors*/
	DIO_write(PORT_C,PIN4,HIGH);
	DIO_write(PORT_C,PIN5,LOW);
	DIO_write(PORT_C,PIN6,HIGH);
	DIO_write(PORT_C,PIN7,LOW);
}


/* Function description
* this void function
* make motors to shutdown
*/

void MOTOR_shut_down(void)
{
	DIO_write(PORT_C,PIN0,LOW);
	DIO_write(PORT_C,PIN1,LOW);
	DIO_write(PORT_C,PIN2,LOW);
	DIO_write(PORT_C,PIN3,LOW);
	DIO_write(PORT_C,PIN4,LOW);
	DIO_write(PORT_C,PIN5,LOW);
	DIO_write(PORT_C,PIN6,LOW);
	DIO_write(PORT_C,PIN7,LOW);
}


/* Function description
* this function take port name and pin number
* make initialization for pins to make it output for motors pins
*/

void MOTOR_init(uint8_t a_motorport ,uint8_t a_motorpin)
{
	DIO_init(a_motorport,a_motorpin,OUT);
}
