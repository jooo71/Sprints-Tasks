/*
 * app.c
 *
 * Created: 8/27/2023 8:48:43 PM
 *  Author: PC
 */ 
#include "app.h"



uint8_t g_motor_move=OFF;
uint8_t g_startup_flag=ACTIVE;
uint8_t g_stop_flag=ACTIVE;

void appstart(void)
{
		LED_init(PORT_A,PIN0);
		LED_init(PORT_A,PIN1);
		LED_init(PORT_A,PIN2);
		LED_init(PORT_A,PIN3);
		
		BUTTON_init(PORT_D,PIN2);
		BUTTON_init(PORT_D,PIN3);
		
		MOTOR_init(PORT_C,PIN0);
		MOTOR_init(PORT_C,PIN1);
		MOTOR_init(PORT_C,PIN2);
		MOTOR_init(PORT_C,PIN3);
		MOTOR_init(PORT_C,PIN4);
		MOTOR_init(PORT_C,PIN5);
		MOTOR_init(PORT_C,PIN6);
		MOTOR_init(PORT_C,PIN7);

		PWM_ocr_init(PORT_D,PIN7);
		
		INTERRUPT_init();
		TIMER_init();
		PWM_init();

// 		led_test();
	while (1)
	{

		
		if (g_motor_move==ON)
		{
				
				LED_off(PORT_A,PIN3);
				if (g_startup_flag==ON)
				{
					TIMER_set_prescaler();
					LED_off(PORT_A,PIN0);
					TIMER_delay(startup_delay);
				}

				PWM_ocr_value(haif_percentage_speed);
				if (g_stop_flag==ACTIVE)
				{
					TIMER_set_prescaler();     //move 3 seconds
					LED_on(PORT_A,PIN0);
					MOTOR_move();
					TIMER_delay(longest_way_delay);
				}
				else
				{
					MOTOR_shut_down();	
				}

				
				TIMER_set_prescaler(); // stop 0.5
				LED_on(PORT_A,PIN2);	
				MOTOR_shut_down();
				LED_off(PORT_A,PIN0);
				TIMER_delay(stop_delay);
				LED_off(PORT_A,PIN2);	
				
				if (g_stop_flag==ACTIVE)
				{
					LED_on(PORT_A,PIN3); // rotate
					TIMER_set_prescaler();
					TIMER_delay(rotate_dealy);
					LED_off(PORT_A,PIN3);
				}
				else
				{
					MOTOR_shut_down();	
				}
							


				TIMER_set_prescaler(); //stop 0.5
				LED_on(PORT_A,PIN2);
				TIMER_delay(stop_delay);
				PWM_ocr_value(thirty_percentage_speed);
				LED_off(PORT_A,PIN2);
				if (g_stop_flag==ACTIVE)
				{
					
					TIMER_set_prescaler(); // move 2 seconds
					LED_on(PORT_A,PIN1);
					MOTOR_move();
					TIMER_delay(shortest_way_delay);
				} 
				else
				{
					MOTOR_shut_down();
				}
									

									
				TIMER_set_prescaler(); // stop 0.5
				LED_on(PORT_A,PIN2);
				MOTOR_shut_down();
				LED_off(PORT_A,PIN1);
				TIMER_delay(stop_delay);
				LED_off(PORT_A,PIN2);
				if (g_stop_flag==ACTIVE)
				{
					LED_on(PORT_A,PIN3); // rotate
					TIMER_set_prescaler();
					TIMER_delay(rotate_dealy);
					LED_off(PORT_A,PIN3);
				} 
				else
				{
					MOTOR_shut_down();
				}
									


				TIMER_set_prescaler(); //stop 0.5
				LED_on(PORT_A,PIN2);
				TIMER_delay(stop_delay);
				LED_off(PORT_A,PIN2);
									
				g_startup_flag=OFF;
		}
		
 	}
}
ISR(EXIT_INT_0)
{
	g_stop_flag=STOP;
	MOTOR_shut_down();
	LED_on(PORT_A,PIN2);
	LED_off(PORT_A,PIN0);
	LED_off(PORT_A,PIN1);
	LED_off(PORT_A,PIN3);
}
ISR(EXIT_INT_1)
{
	g_motor_move=ON;
	g_stop_flag = OFF;
	LED_off(PORT_A,PIN2);
	g_startup_flag=ON;

}


