/*
 * motor.h
 *
 * Created: 9/9/2023 2:12:09 PM
 *  Author: PC
 */ 


#ifndef MOTOR_H_
#define MOTOR_H_
#include "../MCAL/dio/dio.h" // enter into folder and get file



#define  ON		1
#define  OFF	0

#define STOP	1

#define ACTIVE	0
#define NON_ACTIVE 1


/* Function description
* this void function
* make motors to move
*/
void MOTOR_move(void);


/* Function description
* this void function
* make motors to shutdown
*/

void MOTOR_shut_down(void);


/* Function description
* this function take port name and pin number
* make initialization for pins to make it output for motors pins
*/

void MOTOR_init(uint8_t a_motorport ,uint8_t a_motorpin);

#endif /* MOTOR_H_ */