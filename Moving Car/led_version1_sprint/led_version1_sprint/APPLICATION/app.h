/*
 * app.h
 *
 * Created: 8/27/2023 8:48:52 PM
 *  Author: PC
 */ 


#ifndef APP_H_
#define APP_H_


#include "../ECUAL/led/led.h"
#include "../ECUAL/Button/button.h"
#include "../ECUAL/motor/motor.h"


#define	NUMBER_OF_LEDS				4
#define	NUMBER_OF_TRANSITIONS		7
#define RESET_TRANSITION_FLAG		0
#define LEDS_OFF					0

#define led0						0
#define led1						1
#define led2						2
#define led3						3
#define led4						4
#define led5						5
#define led6						6
#define led7						7
#define led8						8

#define  startup_delay				1000
#define  longest_way_delay			3000
#define  stop_delay					500
#define  rotate_dealy				100
#define  shortest_way_delay			2000
#define  haif_percentage_speed		50
#define	 thirty_percentage_speed	30

void appstart(void);



#endif /* APP_H_ */