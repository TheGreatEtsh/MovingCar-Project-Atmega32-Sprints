/*
 * motor.h
 *
 * Created: 4/10/2023 1:14:05 AM
 *  Author: Ahmed Hesham
 */ 


#ifndef MOTOR_H_
#define MOTOR_H_

#include "../../MCAL/dio/dio.h"
#include "../../MCAL/timer/timer.h"

#define NUMBER_OF_MOTORS	2
#define MOTOR_0				0
#define MOTOR_1				1


#define CW					0
#define ACW					1

typedef struct motors{
	u8 motorNumber;
	u8 motorPortNumber_0;
	u8 motorPinNumber_0;
	u8 motorPortNumber_1;
	u8 motorPinNumber_1;
	}st_motors_t;

void MOTOR_init				(void);
void MOTOR_setDirection		(u8 u8_a_motorNumber, u8 u8_a_direction);
void MOTOR_speed			(u8 u8_a_speed);
void MOTOR_start			(void);
void MOTOR_stop				(void);

#endif /* MOTOR_H_ */