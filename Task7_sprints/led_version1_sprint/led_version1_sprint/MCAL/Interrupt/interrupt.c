/*
 * interrupt.c
 *
 * Created: 8/30/2023 1:57:56 PM
 *  Author: PC
 */ 
#include "interrupt.h"
#include "../registers.h"
void init_interrupt(void)
{
	sei();
	MCUCR |= (1<<ISC00) |(1<<ISC01);
	GICR |=(1<<INT0);
	
	MCUCR |= (1<<ISC10) |(1<<ISC11);
	GICR |=(1<<INT1);
}