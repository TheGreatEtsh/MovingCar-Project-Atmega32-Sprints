/*
 * app.h
 *
 * Created: 4/3/2023 7:32:34 PM
 *  Author: Ahmed Hesham
 */ 


#ifndef APP_H_
#define APP_H_

#define F_CPU 16000000ul
#define MOVING_FORWARD_TIME				6
#define STOP_0_TIME						1
#define STOP_1_TIME						1
#define MOVING_RIGHT_TIME				4
#define STATE_0							MOVING_FORWARD_TIME 
#define STATE_1							(STOP_0_TIME + MOVING_FORWARD_TIME)
#define STATE_2							(STOP_0_TIME + MOVING_FORWARD_TIME )
#define STATE_3							(STOP_0_TIME + MOVING_FORWARD_TIME  + STOP_1_TIME)
#define STATE_4							(STOP_0_TIME + MOVING_FORWARD_TIME + STOP_1_TIME + MOVING_RIGHT_TIME)
#define STATE_5							(STOP_0_TIME + MOVING_FORWARD_TIME + STOP_1_TIME + MOVING_RIGHT_TIME +STOP_0_TIME)
#define STATE_6							(STOP_0_TIME + MOVING_FORWARD_TIME + STOP_1_TIME + MOVING_RIGHT_TIME + STOP_0_TIME)
#define STATE_7							(STOP_0_TIME + MOVING_FORWARD_TIME + STOP_1_TIME + MOVING_RIGHT_TIME + STOP_0_TIME + STOP_1_TIME)

#define DISTANCE_BETWEEN_WHEELS			178.0
#define DUTY_CYCLE_USED					41
#define WHEEL_DIAMETER					67.0
#define MAX_SPEED						65.0
#define PI								3.14

#include "../ECUAL/motor/motor.h"
#include "../ECUAL/led/led.h"
#include "../ECUAL/button/button.h"
#include "../MCAL/extint/extint.h"

void APP_initModules(void);
void APP_superLoop (void);
void APP_carMoveForward(void);
void APP_carTurnRight(void);
void APP_testingMotors(void);
void APP_sysTickTask(void);
void APP_carMoveRight(void);
void APP_carStop(void);
void APP_button1Task(void);

#endif /* APP_H_ */