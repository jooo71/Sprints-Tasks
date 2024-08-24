/*
 * timer.h
 *
 *  Created on: Aug 19, 2023
 *      Author: PC
 */

#ifndef MCAL_TIMER_TIMER_H_
#define MCAL_TIMER_TIMER_H_
typedef unsigned int uint32_t;
typedef unsigned char uint8_t;

void Timer_Init(void);
void Timer_StartTimer(uint32_t OverFlowTicks);
uint8_t Timer_CheckTimeIsElapsed(void);
uint32_t Timer_GetElapsedTime(void);


#endif /* MCAL_TIMER_TIMER_H_ */
