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

void appstart(void);

#endif /* APP_H_ */