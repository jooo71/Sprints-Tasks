/*
 * motors.h
 *
 *  Created on: Aug 19, 2023
 *      Author: PC
 */

#ifndef ECUAL_MOTORS_MOTORS_H_
#define ECUAL_MOTORS_MOTORS_H_

void motor_init(uint8_t PinNum);
void motor_start(uint8_t PinNum, uint8_t percentege);
void motor_stop(uint8_t PinNum);
void motor_degree(uint8_t PinNum,uint8_t degree );

#endif /* ECUAL_MOTORS_MOTORS_H_ */
