/*
 * app.c
 *
 * Created: 8/27/2023 8:48:43 PM
 *  Author: PC
 */ 
#include "app.h"
// #include <assert.h>
// #include <avr/interrupt.h>
#define NUMBER_OF_PRESSED 7
uint8_t led_number=0;

void appstart(void)
{
		/**************LED1***************/
// 		uint8_t button_read = BUTTON_RELEASED;
// 		uint8_t transitions_flag = RESET_TRANSITION_FLAG;
// 		uint8_t button_state = BUTTON_RELEASED;
// 		uint8_t data = LEDS_OFF;
		/**************LED1***************/
		/*check argument*/
		LED_init(PORT_A,PIN0);
		LED_init(PORT_A,PIN1);
		LED_init(PORT_A,PIN2);
		LED_init(PORT_A,PIN3);
		BUTTON_init(PORT_D,PIN2);
		init_interrupt();

// 		led_test();
	while (1)
	{

// 	/**************LED1***************/
		
// 		BUTTON_read(PORT_D,PIN2,&button_read);
// 		if (button_read == BUTTON_PRESSED )
// 		{
// 			if (button_state == BUTTON_RELEASED)
// 			{
// 				if (transitions_flag >= NUMBER_OF_LEDS)
// 				{
// 					data&=~(HIGH<<(transitions_flag-NUMBER_OF_LEDS));
// 				}
// 				else
// 				{
// 					data|=(HIGH<<transitions_flag);
// 				}
// 				DIO_writePort(PORT_A,data);
// 				transitions_flag++;
// 				if (transitions_flag > NUMBER_OF_TRANSITIONS)
// 				{
// 					transitions_flag = RESET_TRANSITION_FLAG;
// 				}
// 				button_state = BUTTON_PRESSED;
// 			}
// 		}
// 		else
// 		{
// 			button_state = BUTTON_RELEASED;
// 		}
// 
// 	}
/**************LED1***************/
/**********interrupt*************/
// 		switch(led_number)
// 		{
// 			case led0:
// 				LED_off(PORT_A,PIN0);
// 				LED_off(PORT_A,PIN1);
// 				LED_off(PORT_A,PIN2);
// 				LED_off(PORT_A,PIN3);
// 				break;
// 			case  led1:
// 				LED_on(PORT_A,PIN0);
// 				break;
// 			case led2:
// 				LED_on(PORT_A,PIN1);
// 				break;
// 			case led3:
// 				LED_on(PORT_A,PIN2);
// 				break;		
// 			case led4:
// 				LED_on(PORT_A,PIN3);
// 				break;
// 			case led5:
// 				LED_off(PORT_A,PIN0);
// 				break;
// 			case led6:
// 				LED_off(PORT_A,PIN1);
// 				break;
// 			case led7:
// 				LED_off(PORT_A,PIN2);
// 				break;	
// 			case led8:
// 				LED_off(PORT_A,PIN3);
// 				break;
// 			default:
// 				/*DO nothing*/	
// 				break;
// 		}

	/**********interrupt*************/
	LED_on(PORT_A,PIN0);
// 	for (uint8_t i=0; i<=300000 ; i++);
// 	LED_toggle(PORT_A,PIN0);

	}

}
ISR(EXIT_INT_0)
{
	if (led_number< NUMBER_OF_PRESSED)
	{
		led_number++;
	}
	else
	{
		led_number=0;
	}
}

