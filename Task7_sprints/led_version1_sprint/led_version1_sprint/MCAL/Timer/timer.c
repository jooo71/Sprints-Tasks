/*
 * timer.c
 *
 * Created: 9/3/2023 8:48:10 PM
 *  Author: PC
 */ 
#include "timer.h"
#include "../registers.h"
#include <math.h>
void init_timer(void)
{
	//choose mode
	TCCR0 = 0x00; // normal mode
	//timer set initial value
	TCNT0 = 0x00;
}

void set_prescaler(void)
{
	//timer start -> setting clock source
	TCCR0 |= (1<<0); //(he choose no prescaler)
}

void stop_timer(void)
{
	//timer stop
	TCCR0 = 0x00;
}

void delay(int timer_delay)
{
	unsigned int overflowcounter=0;
	int number_of_flows=0;
	number_of_flows=(timer_delay*pow(10,-3))/(256*pow(10,-6));
	while(overflowcounter < number_of_flows)
	{
		//will be repeated 2000 times
		//stop after one overflow -> 256 micro second
		//wait until the overflow flag to be set
		while((TIFR &(1<<0)) == 0);
						
		//clear overflow flag
		TIFR |= (1<<0);
						
		overflowcounter++;
	}
	overflowcounter =0;
	stop_timer();
	
}

