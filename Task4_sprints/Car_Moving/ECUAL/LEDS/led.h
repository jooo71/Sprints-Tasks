/*
 * led.h
 *
 *  Created on: Aug 19, 2023
 *      Author: PC
 */

#ifndef ECUAL_LEDS_LED_H_
#define ECUAL_LEDS_LED_H_

void led_init(uint8_t PinNum,uint8_t PinMode);
void ledon(uint8_t PinNum);
void ledoff(uint8_t PinNum);

#endif /* ECUAL_LEDS_LED_H_ */
