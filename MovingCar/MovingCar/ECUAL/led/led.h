/*
 * led.h
 *
 * Created: 4/3/2023 5:33:17 PM
 *  Author: Ahmed Hesham
 */ 


#ifndef LED_H_
#define LED_H_

#include "../../MCAL/dio/dio.h"

#define LED_0_PORT		PORT_A
#define LED_1_PORT		PORT_A
#define LED_2_PORT		PORT_A
#define LED_3_PORT		PORT_A
#define LED_0_PIN		0
#define LED_1_PIN		1
#define LED_2_PIN		2
#define LED_3_PIN		3

typedef enum ledErrors{
	LED_OK,
	WRONG_LED_PORT,
	WRONG_LED_PIN
	}en_ledError_t;



en_ledError_t LED_init(u8 u8_a_ledPort,u8 u8_a_ledPin);

en_ledError_t LED_on(u8 u8_a_ledPort,u8 u8_a_ledPin);

en_ledError_t LED_off(u8 u8_a_ledPort,u8 u8_a_ledPin);

en_ledError_t LED_toggle(u8 u8_a_ledPort,u8 u8_a_ledPin);


#endif /* LED_H_ */