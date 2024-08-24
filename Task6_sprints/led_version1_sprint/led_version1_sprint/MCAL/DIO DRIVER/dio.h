/*
 * dio.h
 *
 * Created: 8/27/2023 8:49:30 PM
 *  Author: PC
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "../registers.h"
typedef enum DIOSTATE
{
	DIOERRORSTATE , SUCCESS
}DIOSTATE;
//all internal drivers typdefs
// all driver macros
#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

#define BUTTON_PRESSED  1
#define BUTTON_RELEASED 0

/*Directions defines*/
#define IN 0
#define OUT 1

/*value define*/
#define LOW 0
#define HIGH 1

// all driver function prototypes

uint8_t DIO_init(uint8_t portNumber, uint8_t pinNumber, uint8_t direction); // initialize dio direction

uint8_t DIO_write(uint8_t portNumber, uint8_t pinNumber, uint8_t value); // write data to dio

uint8_t DIO_toggle(uint8_t portNumber, uint8_t pinNumber);

uint8_t DIO_read(uint8_t portNumber, uint8_t pinNumber, uint8_t *value);

uint8_t DIO_writePort(uint8_t portName , uint8_t value);



#endif /* DIO_H_ */