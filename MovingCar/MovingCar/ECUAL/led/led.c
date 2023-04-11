/*
 * led.c
 *
 * Created: 4/3/2023 5:33:07 PM
 *  Author: Ahmed Hesham
 */ 

#include "led.h"


en_ledError_t LED_init(u8 u8_a_ledPort,u8 u8_a_ledPin)
{
	en_ledError_t en_a_error = LED_OK;
	if (u8_a_ledPort > PORT_D)
	{
		en_a_error = WRONG_LED_PORT;
	}
	else if (u8_a_ledPin > 7)
	{
		en_a_error = WRONG_LED_PIN;
	}
	else
	{
		DIO_init(u8_a_ledPort, u8_a_ledPin, OUTPUT);
		en_a_error = LED_OK;
	}
	
	return en_a_error;
}

en_ledError_t LED_on(u8 u8_a_ledPort,u8 u8_a_ledPin)
{
	en_ledError_t en_a_error = LED_OK;
	if (u8_a_ledPort > PORT_D)
	{
		en_a_error = WRONG_LED_PORT;
	}
	else if (u8_a_ledPin > 7)
	{
		en_a_error = WRONG_LED_PIN;
	}
	else
	{
		DIO_write(u8_a_ledPort,u8_a_ledPin, HIGH);
		en_a_error = LED_OK;
	}
	
	return en_a_error;
}

en_ledError_t LED_off(u8 u8_a_ledPort,u8 u8_a_ledPin)
{
	en_ledError_t en_a_error = LED_OK;
	if (u8_a_ledPort > PORT_D)
	{
		en_a_error = WRONG_LED_PORT;
	}
	else if (u8_a_ledPin > 7)
	{
		en_a_error = WRONG_LED_PIN;
	}
	else
	{
		DIO_write(u8_a_ledPort,u8_a_ledPin, LOW);
		en_a_error = LED_OK;
	}
	
	return en_a_error;
}
en_ledError_t LED_toggle(u8 u8_a_ledPort,u8 u8_a_ledPin)
{
	en_ledError_t en_a_error = LED_OK;
	if (u8_a_ledPort > PORT_D)
	{
		en_a_error = WRONG_LED_PORT;
	}
	else if (u8_a_ledPin > 7)
	{
		en_a_error = WRONG_LED_PIN;
	}
	else
	{
		DIO_toggle(u8_a_ledPort, u8_a_ledPin);
		en_a_error = LED_OK;
	}
	
	return en_a_error;
}
