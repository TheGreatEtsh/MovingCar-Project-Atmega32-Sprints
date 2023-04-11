/*
 * motor.c
 *
 * Created: 4/10/2023 1:14:31 AM
 *  Author: Ahmed Hesham
 */ 
#include "motor.h"
											/*Number, PORT0_#, PIN0_#*, PORT1_#, PIN1_#*/
st_motors_t st_arr_motors[NUMBER_OF_MOTORS] =  {{MOTOR_0, PORT_D, 2, PORT_D, 3},
												{MOTOR_1, PORT_D, 6, PORT_D, 7}
												};

void MOTOR_init				(void)
{

	for (u8 i = 0; i < NUMBER_OF_MOTORS; i++)
	{
		DIO_init(st_arr_motors[i].motorPortNumber_0, st_arr_motors[i].motorPinNumber_0, OUTPUT);
		DIO_init(st_arr_motors[i].motorPortNumber_1, st_arr_motors[i].motorPinNumber_1, OUTPUT);
	}
	TIMER_init(TIMER_0);
}


void MOTOR_setDirection		(u8 u8_a_motorNumber, u8 u8_a_direction)
{
	for (u8 i = 0; i < NUMBER_OF_MOTORS; i++) 	
	{
		if (u8_a_motorNumber == st_arr_motors[i].motorNumber)		
		{	
			switch(u8_a_direction)
			{
				case CW:
				DIO_write(st_arr_motors[i].motorPortNumber_0, st_arr_motors[i].motorPinNumber_0,HIGH);
				DIO_write(st_arr_motors[i].motorPortNumber_1, st_arr_motors[i].motorPinNumber_1,LOW);
				break;
				case ACW:
				DIO_write(st_arr_motors[i].motorPortNumber_0, st_arr_motors[i].motorPinNumber_0,LOW);
				DIO_write(st_arr_motors[i].motorPortNumber_1, st_arr_motors[i].motorPinNumber_1,HIGH);
				break;
				default:
				break;
			}
		}
	}
}


void MOTOR_speed			(u8 u8_a_speed)
{	
	TIMER_pwmGenerator(TIMER_0, u8_a_speed);
}


void MOTOR_start			(void)
{
	TIMER_start(TIMER_0);
}


void MOTOR_stop				(void)
{
	TIMER_stop(TIMER_0);
}