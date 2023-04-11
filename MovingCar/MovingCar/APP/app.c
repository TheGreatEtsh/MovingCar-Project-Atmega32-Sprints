/*
 * app.c
 *
 * Created: 4/3/2023 7:32:47 PM
 *  Author: Ahmed Hesham
 */ 

#include "app.h"

void APP_initModules(void)
{
	MOTOR_init();
	MOTOR_start();
	BUTTON_init(BUTTON_0_PORT, BUTTON_0_Pin);
	APP_carMoveForward();
	
}



void APP_superLoop (void)
{
	while (1)
	{
		APP_testingMotors();
	}
}

void APP_testingMotors(void)
{
	u8 button0State = 0;
	BUTTON_read(BUTTON_0_PORT, BUTTON_0_Pin, &button0State);
	if (button0State)
	{
		//_delay_ms(60);
		BUTTON_read(BUTTON_0_PORT, BUTTON_0_Pin, &button0State);
		if(button0State)
		{
			BUTTON_read(BUTTON_0_PORT, BUTTON_0_Pin, &button0State);
			APP_carTurnRight();
			while(button0State)
			{
				BUTTON_read(BUTTON_0_PORT, BUTTON_0_Pin, &button0State);
			}
			APP_carMoveForward();
			
		}
	}
}

void APP_carMoveForward(void)
{
	MOTOR_setDirection(MOTOR_0, CW);
	MOTOR_setDirection(MOTOR_1, CW);

	MOTOR_speed(50);
	MOTOR_start();
}


void APP_carTurnRight(void)
{
	MOTOR_setDirection(MOTOR_0, CW);
	MOTOR_setDirection(MOTOR_1, ACW);
	MOTOR_speed(100);
	MOTOR_start();
}
