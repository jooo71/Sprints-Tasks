/*
 * interrupt.h
 *
 * Created: 8/27/2023 9:22:18 PM
 *  Author: PC
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_

/*External interrupt request 0*/
#define EXIT_INT_0 __vector_1

/*External interrupt request 1*/
#define EXIT_INT_1 __vector_2

/*External interrupt request 2*/
#define EXIT_INT_2 __vector_3

/* set global interrupt , set I bit in status register to 1*/
#define  sei() __asm__ __volatile__ ("sei" ::: "memory")

/* clear global interrupt , set I bit in status register to 0*/
#define  cli() __asm__ __volatile__ ("cli" ::: "memory")

/*ISR definition*/
#define ISR(INT_VECT)void INT_VECT(void) __attribute__ ((signal,used));\
void INT_VECT(void)

#define ISC00 0
#define ISC01 1
#define ISC10 2
#define ISC11 3
#define INT0  6
#define INT1  7

void init_interrupt(void);

#endif /* INTERRUPT_H_ */