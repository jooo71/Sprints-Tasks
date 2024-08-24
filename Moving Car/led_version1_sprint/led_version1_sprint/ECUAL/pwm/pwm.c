/*
 * pwm.c
 *
 * Created: 9/18/2023 2:54:24 PM
 *  Author: PC
 */ 

#include "pwm.h"

/* Function description
* this void function to initialize PWM
*/

void PWM_init()
{
	/*set fast PWM mode with non-inverted output*/
	TCCR2 = (1<<6) | (1<<5) | (1<<0);

}


/* Function description
* this function take percentage of speed
*/

void PWM_ocr_value(int a_percentage)
{
	uint8_t duty_cycle = (a_percentage*255)/100;
	OCR2 = duty_cycle;
}


/* Function description
* this function to initialize ocr pin
*/

void PWM_ocr_init(uint8_t a_ocrport ,uint8_t a_ocrpin)
{
	DIO_init(a_ocrport,a_ocrpin,OUT);
}