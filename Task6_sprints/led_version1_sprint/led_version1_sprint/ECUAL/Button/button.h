/*
 * button.h
 *
 * Created: 8/27/2023 8:53:45 PM
 *  Author: PC
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_
typedef enum BUTTONSTATE
{
	BUTTON_ERROR_STATE , BUTTON_SUCCESS
}BUTTONSTATE;
#include "../MCAL/DIO DRIVER/dio.h"
#include "../MCAL/Interrupt/interrupt.h"

uint8_t BUTTON_init(uint8_t buttonport ,uint8_t buttonpin);

uint8_t BUTTON_read(uint8_t buttonport,uint8_t buttonpin,uint8_t *value);



#endif /* BUTTON_H_ */