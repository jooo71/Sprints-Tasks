/*
 * dio.h
 *
 * Created: 8/27/2023 8:49:30 PM
 *  Author: PC
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "../util/registers.h"
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

/* Function description
* this function to initialize pins to output or input
* take port name and pin number and direction (output/input)
* check if pin number not correct will return error
*/

uint8_t DIO_init(uint8_t a_portNumber, uint8_t a_pinNumber, uint8_t a_direction);


/* Function description
* this function to write on pin high or low
* take port name , pin number and value
* return error if port name or value not correct
*/ 

uint8_t DIO_write(uint8_t a_portNumber, uint8_t a_pinNumber, uint8_t a_value);


/* Function description
* this function to toggle value on pin
* take port name , pin number
* return error if port name not correct
*/

uint8_t DIO_toggle(uint8_t a_portNumber, uint8_t a_pinNumber);


/* Function description
* this function to read value on pin
* take port name , pin number and return value
* return error if port name not correct
*/

uint8_t DIO_read(uint8_t a_portNumber, uint8_t a_pinNumber, uint8_t *a_value);


/* Function description
* this function to write on whole port
* take port name and value
* return error if port name not correct
*/

uint8_t DIO_writePort(uint8_t a_portNumber , uint8_t a_value);



#endif /* DIO_H_ */