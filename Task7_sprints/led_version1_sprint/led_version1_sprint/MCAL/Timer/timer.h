/*
 * timer.h
 *
 * Created: 9/3/2023 8:48:41 PM
 *  Author: PC
 */ 


#ifndef TIMER_H_
#define TIMER_H_

void init_timer(void);
void set_prescaler(void);
void stop_timer(void);
void delay(int timer_delay);


#define BLINK_1 0
#define BLINK_2 1
#define BLINK_3 2
#define BLINK_4 3
#define BLINK_5 4


#endif /* TIMER_H_ */