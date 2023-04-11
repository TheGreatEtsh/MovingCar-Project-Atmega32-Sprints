/*
 * pwm.h
 *
 * Created: 4/7/2023 3:47:05 PM
 *  Author: Ahmed Hesham
 */ 


#ifndef PWM_H_
#define PWM_H_

#include "../registers.h"
#include "../../SERVICE/bit_math.h"
#include "../interrupts.h"
#include "../dio/dio.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
// TIMER NUMBERS
#define PWM_0									0
#define PWM_1									1
#define PWM_2									2



// TIMER WAVEFORM TYPES
#define FAST_PWM								0
#define PHASE_CORRECT							1

// PRESCALER OPTIONS
#define NO_CLK									0
#define PRESCLNG_1								1
#define PRESCLNG_8								8
#define PRESCLNG_64								64
#define PRESCLNG_256							256
#define PRESCLNG_1024							1024
#define XCK_FLNG_EDGE							10
#define XCK_RSNG_EDGE							15

// INVERSION MODES
#define NON_INVERTED							1
#define INVERTED								2
/******************************************_CONFIGURATIONS_***************************************/
/******************************************_PWM_MODE_USED_****************************************/

#define PWM_0_MODE								FAST_PWM
#define PWM_1_MODE
#define PWM_2_MODE								FAST_PWM
/*****************************************_PRESCALER_USED_***************************************/
#define PWM_0_PRESCALER							PRESCLNG_256
#define PWM_1_PRESCALER							PRESCLNG_256
#define PWM_2_PRESCALER							PRESCLNG_256

/**************************************_CLOCK_FREQUENCY_USED_************************************/
#define XTAL_FREQ								16

/**************************************_INVERSION_MODE_USED_************************************/
#define PWM_0_INVERSION							NON_INVERTED
#define PWM_1_INVERSION							NON_INVERTED
#define PWM_2_INVERSION							NON_INVERTED

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum pwmError{
	PWM_OK,
	PWM_WRONG_PWM_USED,
	PWM_WRONG_DUTY_CYCLE
	}en_pwmError_t;


en_pwmError_t PWM_init				(u8 u8_a_pwmUsed);
en_pwmError_t PWM_setDutyCycle		(u8 u8_a_pwmUsed, u8 desiredDutyCycle);
en_pwmError_t PWM_start				(u8 u8_a_pwmUsed);
en_pwmError_t PWM_stop				(u8 u8_a_pwmUsed);



#endif /* PWM_H_ */