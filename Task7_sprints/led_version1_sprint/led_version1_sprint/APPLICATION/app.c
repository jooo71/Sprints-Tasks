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
#define NUMBER_OF_MODES   4

#define		NUMBER_OF_OVERFLOWS 2000

uint8_t led_number=0;
uint8_t blink_mode=0;

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
		BUTTON_init(PORT_D,PIN3);
		init_interrupt();
		init_timer();
		/*unsigned int overflowcounter=0;*/

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
			
			/**********Timer****************/
		switch(blink_mode)
		{
			case BLINK_1:
					switch(led_number)
					{
						case led0:
						LED_off(PORT_A,PIN0);
						LED_off(PORT_A,PIN1);
						LED_off(PORT_A,PIN2);
						LED_off(PORT_A,PIN3);
						break;
						case led1:
						set_prescaler();
						LED_toggle(PORT_A,PIN0);
						delay(100);
						set_prescaler();
						LED_toggle(PORT_A,PIN0);
						delay(900);
						break;
						case led2:
						set_prescaler();
						LED_toggle(PORT_A,PIN1);
						LED_toggle(PORT_A,PIN0);
						delay(100);
						
						set_prescaler();
						LED_toggle(PORT_A,PIN1);
						LED_toggle(PORT_A,PIN0);
						delay(900);
						break;
						case led3:
						set_prescaler();
						LED_toggle(PORT_A,PIN2);
						LED_toggle(PORT_A,PIN1);
						LED_toggle(PORT_A,PIN0);
						delay(100);
						
						set_prescaler();
						LED_toggle(PORT_A,PIN2);
						LED_toggle(PORT_A,PIN1);
						LED_toggle(PORT_A,PIN0);
						delay(900);
						break;
						case led4:
						set_prescaler();
						LED_toggle(PORT_A,PIN3);
						LED_toggle(PORT_A,PIN0);
						LED_toggle(PORT_A,PIN1);
						LED_toggle(PORT_A,PIN2);
						delay(100);
						
						set_prescaler();
						LED_toggle(PORT_A,PIN3);
						LED_toggle(PORT_A,PIN0);
						LED_toggle(PORT_A,PIN1);
						LED_toggle(PORT_A,PIN2);
						delay(900);
						break;
						case led5:
						LED_off(PORT_A,PIN0);
						set_prescaler();
						LED_toggle(PORT_A,PIN3);
						LED_toggle(PORT_A,PIN1);
						LED_toggle(PORT_A,PIN2);
						delay(100);
						
						set_prescaler();
						LED_toggle(PORT_A,PIN3);
						LED_toggle(PORT_A,PIN1);
						LED_toggle(PORT_A,PIN2);
						delay(900);
						break;
						case led6:
						LED_off(PORT_A,PIN0);
						LED_off(PORT_A,PIN1);
						set_prescaler();
						LED_toggle(PORT_A,PIN3);
						LED_toggle(PORT_A,PIN2);
						delay(100);
						
						set_prescaler();
						LED_toggle(PORT_A,PIN3);
						LED_toggle(PORT_A,PIN2);
						delay(900);
						break;
						case led7:
						LED_off(PORT_A,PIN0);
						LED_off(PORT_A,PIN1);
						LED_off(PORT_A,PIN2);
						set_prescaler();
						LED_toggle(PORT_A,PIN3);
						delay(100);
						
						set_prescaler();
						LED_toggle(PORT_A,PIN3);
						delay(900);
						break;
						case led8:
						LED_off(PORT_A,PIN0);
						LED_off(PORT_A,PIN1);
						LED_off(PORT_A,PIN2);
						LED_off(PORT_A,PIN3);
						break;
						
					}
					break;
			case BLINK_2:
						switch(led_number)
						{
							case led0:
							LED_off(PORT_A,PIN0);
							LED_off(PORT_A,PIN1);
							LED_off(PORT_A,PIN2);
							LED_off(PORT_A,PIN3);
							break;
							case led1:
							set_prescaler();
							LED_toggle(PORT_A,PIN0);
							delay(200);
							set_prescaler();
							LED_toggle(PORT_A,PIN0);
							delay(800);
							break;
							case led2:
							set_prescaler();
							LED_toggle(PORT_A,PIN1);
							LED_toggle(PORT_A,PIN0);
							delay(200);
							
							set_prescaler();
							LED_toggle(PORT_A,PIN1);
							LED_toggle(PORT_A,PIN0);
							delay(800);
							break;
							case led3:
							set_prescaler();
							LED_toggle(PORT_A,PIN2);
							LED_toggle(PORT_A,PIN1);
							LED_toggle(PORT_A,PIN0);
							delay(200);
							
							set_prescaler();
							LED_toggle(PORT_A,PIN2);
							LED_toggle(PORT_A,PIN1);
							LED_toggle(PORT_A,PIN0);
							delay(800);
							break;
							case led4:
							set_prescaler();
							LED_toggle(PORT_A,PIN3);
							LED_toggle(PORT_A,PIN0);
							LED_toggle(PORT_A,PIN1);
							LED_toggle(PORT_A,PIN2);
							delay(200);
							
							set_prescaler();
							LED_toggle(PORT_A,PIN3);
							LED_toggle(PORT_A,PIN0);
							LED_toggle(PORT_A,PIN1);
							LED_toggle(PORT_A,PIN2);
							delay(800);
							break;
							case led5:
							LED_off(PORT_A,PIN0);
							set_prescaler();
							LED_toggle(PORT_A,PIN3);
							LED_toggle(PORT_A,PIN1);
							LED_toggle(PORT_A,PIN2);
							delay(200);
							
							set_prescaler();
							LED_toggle(PORT_A,PIN3);
							LED_toggle(PORT_A,PIN1);
							LED_toggle(PORT_A,PIN2);
							delay(800);
							break;
							case led6:
							LED_off(PORT_A,PIN0);
							LED_off(PORT_A,PIN1);
							set_prescaler();
							LED_toggle(PORT_A,PIN3);
							LED_toggle(PORT_A,PIN2);
							delay(200);
							
							set_prescaler();
							LED_toggle(PORT_A,PIN3);
							LED_toggle(PORT_A,PIN2);
							delay(800);
							break;
							case led7:
							LED_off(PORT_A,PIN0);
							LED_off(PORT_A,PIN1);
							LED_off(PORT_A,PIN2);
							set_prescaler();
							LED_toggle(PORT_A,PIN3);
							delay(200);
							
							set_prescaler();
							LED_toggle(PORT_A,PIN3);
							delay(800);
							break;
							case led8:
							LED_off(PORT_A,PIN0);
							LED_off(PORT_A,PIN1);
							LED_off(PORT_A,PIN2);
							LED_off(PORT_A,PIN3);
							break;
							
						}
						break;
				
			case BLINK_3:
						switch(led_number)
						{
							case led0:
							LED_off(PORT_A,PIN0);
							LED_off(PORT_A,PIN1);
							LED_off(PORT_A,PIN2);
							LED_off(PORT_A,PIN3);
							break;
							case led1:
							set_prescaler();
							LED_toggle(PORT_A,PIN0);
							delay(300);
							set_prescaler();
							LED_toggle(PORT_A,PIN0);
							delay(700);
							break;
							case led2:
							set_prescaler();
							LED_toggle(PORT_A,PIN1);
							LED_toggle(PORT_A,PIN0);
							delay(300);
							
							set_prescaler();
							LED_toggle(PORT_A,PIN1);
							LED_toggle(PORT_A,PIN0);
							delay(700);
							break;
							case led3:
							set_prescaler();
							LED_toggle(PORT_A,PIN2);
							LED_toggle(PORT_A,PIN1);
							LED_toggle(PORT_A,PIN0);
							delay(300);
							
							set_prescaler();
							LED_toggle(PORT_A,PIN2);
							LED_toggle(PORT_A,PIN1);
							LED_toggle(PORT_A,PIN0);
							delay(700);
							break;
							case led4:
							set_prescaler();
							LED_toggle(PORT_A,PIN3);
							LED_toggle(PORT_A,PIN0);
							LED_toggle(PORT_A,PIN1);
							LED_toggle(PORT_A,PIN2);
							delay(300);
							
							set_prescaler();
							LED_toggle(PORT_A,PIN3);
							LED_toggle(PORT_A,PIN0);
							LED_toggle(PORT_A,PIN1);
							LED_toggle(PORT_A,PIN2);
							delay(700);
							break;
							case led5:
							LED_off(PORT_A,PIN0);
							set_prescaler();
							LED_toggle(PORT_A,PIN3);
							LED_toggle(PORT_A,PIN1);
							LED_toggle(PORT_A,PIN2);
							delay(300);
							
							set_prescaler();
							LED_toggle(PORT_A,PIN3);
							LED_toggle(PORT_A,PIN1);
							LED_toggle(PORT_A,PIN2);
							delay(700);
							break;
							case led6:
							LED_off(PORT_A,PIN0);
							LED_off(PORT_A,PIN1);
							set_prescaler();
							LED_toggle(PORT_A,PIN3);
							LED_toggle(PORT_A,PIN2);
							delay(300);
							
							set_prescaler();
							LED_toggle(PORT_A,PIN3);
							LED_toggle(PORT_A,PIN2);
							delay(700);
							break;
							case led7:
							LED_off(PORT_A,PIN0);
							LED_off(PORT_A,PIN1);
							LED_off(PORT_A,PIN2);
							set_prescaler();
							LED_toggle(PORT_A,PIN3);
							delay(300);
							
							set_prescaler();
							LED_toggle(PORT_A,PIN3);
							delay(700);
							break;
							case led8:
							LED_off(PORT_A,PIN0);
							LED_off(PORT_A,PIN1);
							LED_off(PORT_A,PIN2);
							LED_off(PORT_A,PIN3);
							break;
							
						}
						break;
			case BLINK_4:
						switch(led_number)
						{
							case led0:
							LED_off(PORT_A,PIN0);
							LED_off(PORT_A,PIN1);
							LED_off(PORT_A,PIN2);
							LED_off(PORT_A,PIN3);
							break;
							case led1:
							set_prescaler();
							LED_toggle(PORT_A,PIN0);
							delay(500);
							set_prescaler();
							LED_toggle(PORT_A,PIN0);
							delay(500);
							break;
							case led2:
							set_prescaler();
							LED_toggle(PORT_A,PIN1);
							LED_toggle(PORT_A,PIN0);
							delay(500);
							
							set_prescaler();
							LED_toggle(PORT_A,PIN1);
							LED_toggle(PORT_A,PIN0);
							delay(500);
							break;
							case led3:
							set_prescaler();
							LED_toggle(PORT_A,PIN2);
							LED_toggle(PORT_A,PIN1);
							LED_toggle(PORT_A,PIN0);
							delay(500);
							
							set_prescaler();
							LED_toggle(PORT_A,PIN2);
							LED_toggle(PORT_A,PIN1);
							LED_toggle(PORT_A,PIN0);
							delay(500);
							break;
							case led4:
							set_prescaler();
							LED_toggle(PORT_A,PIN3);
							LED_toggle(PORT_A,PIN0);
							LED_toggle(PORT_A,PIN1);
							LED_toggle(PORT_A,PIN2);
							delay(500);
							
							set_prescaler();
							LED_toggle(PORT_A,PIN3);
							LED_toggle(PORT_A,PIN0);
							LED_toggle(PORT_A,PIN1);
							LED_toggle(PORT_A,PIN2);
							delay(500);
							break;
							case led5:
							LED_off(PORT_A,PIN0);
							set_prescaler();
							LED_toggle(PORT_A,PIN3);
							LED_toggle(PORT_A,PIN1);
							LED_toggle(PORT_A,PIN2);
							delay(500);
							
							set_prescaler();
							LED_toggle(PORT_A,PIN3);
							LED_toggle(PORT_A,PIN1);
							LED_toggle(PORT_A,PIN2);
							delay(500);
							break;
							case led6:
							LED_off(PORT_A,PIN0);
							LED_off(PORT_A,PIN1);
							set_prescaler();
							LED_toggle(PORT_A,PIN3);
							LED_toggle(PORT_A,PIN2);
							delay(500);
							
							set_prescaler();
							LED_toggle(PORT_A,PIN3);
							LED_toggle(PORT_A,PIN2);
							delay(500);
							break;
							case led7:
							LED_off(PORT_A,PIN0);
							LED_off(PORT_A,PIN1);
							LED_off(PORT_A,PIN2);
							set_prescaler();
							LED_toggle(PORT_A,PIN3);
							delay(500);
							
							set_prescaler();
							LED_toggle(PORT_A,PIN3);
							delay(500);
							break;
							case led8:
							LED_off(PORT_A,PIN0);
							LED_off(PORT_A,PIN1);
							LED_off(PORT_A,PIN2);
							LED_off(PORT_A,PIN3);
							break;
							
						}
						break;
			case BLINK_5:
						switch(led_number)
						{
							case led0:
							LED_off(PORT_A,PIN0);
							LED_off(PORT_A,PIN1);
							LED_off(PORT_A,PIN2);
							LED_off(PORT_A,PIN3);
							break;
							case led1:
							set_prescaler();
							LED_toggle(PORT_A,PIN0);
							delay(800);
							set_prescaler();
							LED_toggle(PORT_A,PIN0);
							delay(200);
							break;
							case led2:
							set_prescaler();
							LED_toggle(PORT_A,PIN1);
							LED_toggle(PORT_A,PIN0);
							delay(800);
							
							set_prescaler();
							LED_toggle(PORT_A,PIN1);
							LED_toggle(PORT_A,PIN0);
							delay(200);
							break;
							case led3:
							set_prescaler();
							LED_toggle(PORT_A,PIN2);
							LED_toggle(PORT_A,PIN1);
							LED_toggle(PORT_A,PIN0);
							delay(800);
							
							set_prescaler();
							LED_toggle(PORT_A,PIN2);
							LED_toggle(PORT_A,PIN1);
							LED_toggle(PORT_A,PIN0);
							delay(200);
							break;
							case led4:
							set_prescaler();
							LED_toggle(PORT_A,PIN3);
							LED_toggle(PORT_A,PIN0);
							LED_toggle(PORT_A,PIN1);
							LED_toggle(PORT_A,PIN2);
							delay(800);
							
							set_prescaler();
							LED_toggle(PORT_A,PIN3);
							LED_toggle(PORT_A,PIN0);
							LED_toggle(PORT_A,PIN1);
							LED_toggle(PORT_A,PIN2);
							delay(200);
							break;
							case led5:
							LED_off(PORT_A,PIN0);
							set_prescaler();
							LED_toggle(PORT_A,PIN3);
							LED_toggle(PORT_A,PIN1);
							LED_toggle(PORT_A,PIN2);
							delay(800);
							
							set_prescaler();
							LED_toggle(PORT_A,PIN3);
							LED_toggle(PORT_A,PIN1);
							LED_toggle(PORT_A,PIN2);
							delay(200);
							break;
							case led6:
							LED_off(PORT_A,PIN0);
							LED_off(PORT_A,PIN1);
							set_prescaler();
							LED_toggle(PORT_A,PIN3);
							LED_toggle(PORT_A,PIN2);
							delay(800);
							
							set_prescaler();
							LED_toggle(PORT_A,PIN3);
							LED_toggle(PORT_A,PIN2);
							delay(200);
							break;
							case led7:
							LED_off(PORT_A,PIN0);
							LED_off(PORT_A,PIN1);
							LED_off(PORT_A,PIN2);
							set_prescaler();
							LED_toggle(PORT_A,PIN3);
							delay(800);
							
							set_prescaler();
							LED_toggle(PORT_A,PIN3);
							delay(200);
							break;
							case led8:
							LED_off(PORT_A,PIN0);
							LED_off(PORT_A,PIN1);
							LED_off(PORT_A,PIN2);
							LED_off(PORT_A,PIN3);
							break;
							
						}
						break;
		}
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
ISR(EXIT_INT_1)
{
	if (blink_mode< NUMBER_OF_MODES)
	{
		blink_mode++;
	}
	else
	{
		blink_mode=0;
	}
}


