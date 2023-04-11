/*
 * app.h
 *
 * Created: 4/3/2023 7:32:34 PM
 *  Author: Ahmed Hesham
 */ 


#ifndef APP_H_
#define APP_H_

#define F_CPU 16000000ul

#include "../ECUAL/motor/motor.h"
#include "../ECUAL/led/led.h"
#include "../ECUAL/button/button.h"

void APP_initModules(void);
void APP_superLoop (void);
void APP_carMoveForward(void);
void APP_carTurnRight(void);
void APP_testingMotors(void);
#endif /* APP_H_ */