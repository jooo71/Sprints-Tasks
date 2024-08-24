/*
 * timer.h
 *
 * Created: 9/3/2023 8:48:41 PM
 *  Author: PC
 */ 


#ifndef TIMER_H_
#define TIMER_H_
#include "../MCAL/dio/dio.h" // enter into folder and get file
#include "../util/registers.h"



#define BLINK_1 0
#define BLINK_2 1
#define BLINK_3 2
#define BLINK_4 3
#define BLINK_5 4


/* Function description
* this void function to initialize timer
* choose initial value and mode
*/

void TIMER_init(void);


/* Function description
* this void function to start timer
*/

void TIMER_set_prescaler(void);


/* Function description
* this void function to stop timer
*/

void TIMER_stop(void);


/* Function description
* this function take amount of delay
* calculate number of flows and looping until end
* then stop timer
*/

void TIMER_delay(int a_timer_delay);




#endif /* TIMER_H_ */