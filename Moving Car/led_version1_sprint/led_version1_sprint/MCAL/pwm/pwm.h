/*
 * pwm.h
 *
 * Created: 9/18/2023 2:51:56 PM
 *  Author: PC
 */ 


#ifndef PWM_H_
#define PWM_H_

#include "../MCAL/dio/dio.h" // enter into folder and get file

/* Function description
* this void function to initialize PWM
*/

void PWM_init();


/* Function description
* this function take percentage of speed
*/

void PWM_ocr_value(int a_percentage);


/* Function description
* this function to initialize ocr pin
*/

void PWM_ocr_init(uint8_t a_ocrport ,uint8_t a_ocrpin);


#endif /* PWM_H_ */