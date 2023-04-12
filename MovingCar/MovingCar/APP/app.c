/*
 * app.c
 *
 * Created: 4/3/2023 7:32:47 PM
 *  Author: Ahmed Hesham
 */ 

#include "app.h"
#define MOVING_FORWARD_TIME				6
#define STOP_0_TIME						1
#define STOP_1_TIME						1
#define MOVING_RIGHT_TIME				4
#define TURNING_TIME					2

u8 u8_g_tickNumber	=	0;
u8 u8_g_FirstEntery	=	0;
void APP_initModules(void)
{
	MOTOR_init();
	
	BUTTON_init(BUTTON_0_PORT, BUTTON_0_Pin);
	BUTTON_init(BUTTON_1_PORT, BUTTON_1_Pin);
	LED_init(LED_0_PORT, LED_0_PIN);
	LED_init(LED_1_PORT, LED_1_PIN);
	LED_init(LED_2_PORT, LED_2_PIN);
	LED_init(LED_3_PORT, LED_3_PIN);
	
	TIMER_init(TIMER_2);
	
	TIMER_setTime(TIMER_2, 500);
	
	TIMER_setCallBack(TIMER_2, APP_sysTickTask);
	
	EXTINT_Init(INT_2);
	
	EXTINT_setCallBackInt(INT_2, APP_button1Task);
	
}



void APP_superLoop (void)
{
	while (1)
	{
		u8 button0State = 0;
		BUTTON_read(BUTTON_0_PORT, BUTTON_0_Pin, &button0State);
		if (button0State)
		{	
			BUTTON_read(BUTTON_0_PORT, BUTTON_0_Pin, &button0State);
			if(button0State)
			{
				BUTTON_read(BUTTON_0_PORT, BUTTON_0_Pin, &button0State);
				TIMER_enableInterrupt(TIMER_2);
				TIMER_start(TIMER_2);
				MOTOR_start();
				while(button0State)
				{
					BUTTON_read(BUTTON_0_PORT, BUTTON_0_Pin, &button0State);
				}
								
			}
		}
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
	
	LED_on(LED_0_PORT, LED_0_PIN);
	LED_off(LED_3_PORT, LED_3_PIN);
	LED_off(LED_1_PORT, LED_1_PIN);
	LED_off(LED_2_PORT, LED_2_PIN);

	MOTOR_speed(50);
	MOTOR_start();
}


void APP_carTurnRight(void)
{
	MOTOR_setDirection(MOTOR_0, CW);
	MOTOR_setDirection(MOTOR_1, ACW);
	MOTOR_speed(60);
	MOTOR_start();
	LED_on(LED_2_PORT, LED_2_PIN);
	LED_off(LED_3_PORT, LED_3_PIN);
	LED_off(LED_1_PORT, LED_1_PIN);
	LED_off(LED_0_PORT, LED_0_PIN);
}

void APP_carMoveRight(void)
{
	MOTOR_setDirection(MOTOR_0, CW);
	MOTOR_setDirection(MOTOR_1, CW);
	MOTOR_speed(20);
	MOTOR_start();

	
	LED_on(LED_3_PORT, LED_3_PIN);
	LED_off(LED_1_PORT, LED_1_PIN);
	LED_off(LED_2_PORT, LED_2_PIN);
	LED_off(LED_0_PORT, LED_0_PIN);
}

void APP_carStop(void)
{
	MOTOR_stop();
	LED_on(LED_1_PORT, LED_1_PIN);
	LED_off(LED_3_PORT, LED_3_PIN);
	LED_off(LED_2_PORT, LED_2_PIN);
	LED_off(LED_0_PORT, LED_0_PIN);
}

void APP_sysTickTask(void)
{
	if (u8_g_FirstEntery == 0)	
	{
		u8_g_FirstEntery = 1;
		TIMER_stopInterrupt(TIMER_2);
		TIMER_delay(TIMER_2, 1000);
		TIMER_enableInterrupt(TIMER_2);
	}
		
	if (u8_g_tickNumber < MOVING_FORWARD_TIME)
	{
		u8_g_tickNumber++;
		APP_carMoveForward();
	}
	else if (u8_g_tickNumber >= STATE_0 && u8_g_tickNumber < STATE_1)
	{
		APP_carStop();
		u8_g_tickNumber++;
	}
	else if (u8_g_tickNumber >= STATE_1 && u8_g_tickNumber < STATE_2)
	{
		APP_carTurnRight();
		u8_g_tickNumber++;
	}
	else if (u8_g_tickNumber >=  STATE_2 && u8_g_tickNumber < STATE_3)
	{
		APP_carStop();
		u8_g_tickNumber++;
	}
	else if (u8_g_tickNumber >=  STATE_3 && u8_g_tickNumber < STATE_4)
	{
		u8_g_tickNumber++;
		APP_carMoveRight();
	}
	else if (u8_g_tickNumber >= STATE_4 && u8_g_tickNumber < STATE_5)
	{
		APP_carStop();
		u8_g_tickNumber++;
	}
	else if (u8_g_tickNumber >=  STATE_5 && u8_g_tickNumber < STATE_6)
	{
		APP_carTurnRight();
		u8_g_tickNumber++;
	}
	else if (u8_g_tickNumber >=  STATE_6 && u8_g_tickNumber < STATE_7)
	{
		APP_carStop();
		u8_g_tickNumber++;
		
		if (u8_g_tickNumber >= STATE_7)
		{
			u8_g_tickNumber = 0;
		}
	}


}
	
void APP_button1Task(void)
{
	u8_g_FirstEntery = 0;
	
	MOTOR_stop();
	LED_off(LED_1_PORT, LED_1_PIN);
	LED_off(LED_3_PORT, LED_3_PIN);
	LED_off(LED_2_PORT, LED_2_PIN);
	LED_off(LED_0_PORT, LED_0_PIN);
	//TIMER_stop(TIMER_2);
	TIMER_stopInterrupt(TIMER_2);
	
}