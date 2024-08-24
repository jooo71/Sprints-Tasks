/*
 * register.h
 *
 * Created: 8/25/2023 5:00:06 PM
 *  Author: PC
 */ 


#ifndef REGISTER_H_
#define REGISTER_H_


#include "../Typdef/typdef.h"

/*PORTA REGISTERS*/
#define PORTA *((volatile uint8_t*)0x3B)
#define DDRA *((volatile uint8_t*)0x3A)
#define PINA *((volatile uint8_t*)0x39)

/*PORTB REGISTERS*/
#define PORTB *((volatile uint8_t*)0x38)
#define DDRB *((volatile uint8_t*)0x37)
#define PINB *((volatile uint8_t*)0x36)

/*PORTC REGISTERS*/
#define PORTC *((volatile uint8_t*)0x35)
#define DDRC *((volatile uint8_t*)0x34)
#define PINC *((volatile uint8_t*)0x33)

/*PORTD REGISTERS*/
#define PORTD *((volatile uint8_t*)0x32)
#define DDRD *((volatile uint8_t*)0x31)
#define PIND *((volatile uint8_t*)0x30)


#endif /* REGISTER_H_ */