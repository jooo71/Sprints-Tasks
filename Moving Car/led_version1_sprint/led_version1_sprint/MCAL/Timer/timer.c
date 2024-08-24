/*
 * timer.c
 *
 * Created: 9/3/2023 8:48:10 PM
 *  Author: PC
 */ 

#include "timer.h"
#include <math.h>

/* Function description
* this void function to initialize timer
* choose initial value and mode
*/

void TIMER_init(void)
{
	//timer set initial value
	TCNT0 = 0x00;
	//choose mode
	TCCR0 = 0x00; // normal mode
}


/* Function description
* this void function to start timer
*/

void TIMER_set_prescaler(void)
{
	//timer start -> setting clock source
	TCCR0 |= (1<<0); //(he choose no prescaler)
}


/* Function description
* this void function to stop timer
*/

void TIMER_stop(void)
{
	//timer stop
	TCCR0 = 0x00;
}


/* Function description
* this function take amount of delay
* calculate number of flows and looping until end
* then stop timer
*/

void TIMER_delay(int a_timer_delay)
{
	uint32_t overflowcounter=0;
	i32_t number_of_flows=0;
	number_of_flows=(a_timer_delay*pow(10,-3))/(256*pow(10,-6));
	while(overflowcounter < number_of_flows)
	{
		//will be repeated number_of_flows times
		//stop after one overflow -> 256 micro second
		//wait until the overflow flag to be set
		while((TIFR &(1<<0)) == 0);
						
		//clear overflow flag
		TIFR |= (1<<0);
						
		overflowcounter++;
	}
	overflowcounter =0;
	TIMER_stop();
	
}


