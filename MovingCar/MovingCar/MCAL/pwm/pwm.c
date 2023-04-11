/*
 * pwm.c
 *
 * Created: 4/7/2023 3:46:50 PM
 *  Author: Ahmed Hesham
 */ 

#include "pwm.h"

en_pwmError_t PWM_init (u8 u8_a_pwmUsed)
{
	en_pwmError_t en_a_error = PWM_OK;
	if (u8_a_pwmUsed == PWM_0)
	{
		DIO_init(PORT_B,3, OUTPUT);
		
		#if			PWM_0_MODE		==		FAST_PWM
		SET_BIT(TCCR0,WGM01); SET_BIT(TCCR0,WGM00);
		
		#elif		PWM_0_MODE		==		PHASE_CORRECT
		CLR_BIT(TCCR0,WGM01); SET_BIT(TCCR0,WGM00);
		#endif
		
		#if			PWM_0_INVERSION		==		NON_INVERTED
		SET_BIT(TCCR0,COM01); CLR_BIT(TCCR0,COM00);
		
		#elif		PWM_0_INVERSION		==		INVERTED
		SET_BIT(TCCR0,COM01); SET_BIT(TCCR0,COM00);
		#endif

		
	}
	else if (u8_a_pwmUsed == PWM_1)
	{
		
	}
	else if (u8_a_pwmUsed == PWM_2)
	{
		
	}
	else
	{
		en_a_error = PWM_WRONG_PWM_USED;
	}
	return en_a_error;
}

en_pwmError_t PWM_setDutyCycle		(u8 u8_a_pwmUsed, u8 desiredDutyCycle)
{
	en_pwmError_t en_a_error = PWM_OK;
	if (u8_a_pwmUsed == PWM_0)
	{
		if (desiredDutyCycle > 100)
		{
			en_a_error = PWM_WRONG_DUTY_CYCLE;
		}
		else
		{
				#if			PWM_0_INVERSION		==		NON_INVERTED
			
			if(desiredDutyCycle == 0)
			{
				SET_BIT(TCCR0,COM01); SET_BIT(TCCR0,COM00);
				OCR0 = (255 - ((desiredDutyCycle *256)/100));
			}
			else
			{
				SET_BIT(TCCR0,COM01); CLR_BIT(TCCR0,COM00);
				OCR0 = (((desiredDutyCycle * 256) / 100) - 1);
			}
			
			#elif		PWM_0_INVERSION		==		INVERTED
			if(desiredDutyCycle == 100)
			{
				SET_BIT(TCCR0,COM01); CLR_BIT(TCCR0,COM00);
				OCR0 = (((desiredDutyCycle * 256) / 100) - 1);
			}
			else
			{
				SET_BIT(TCCR0,COM01); SET_BIT(TCCR0,COM00);
				OCR0 = (255 - ((desiredDutyCycle *256)/100));
			}
			#endif

			
		}
	}
	else if (u8_a_pwmUsed == PWM_1)
	{
		if (desiredDutyCycle > 100)
		{
			en_a_error = PWM_WRONG_DUTY_CYCLE;
		}
		else
		{
		
		}
	}
	else if (u8_a_pwmUsed == PWM_2)
	{
		if (desiredDutyCycle >= 100)
		{
			en_a_error = PWM_WRONG_DUTY_CYCLE;
		}
		else
		{
			
		}
	}
	else
	{
		en_a_error = PWM_WRONG_PWM_USED;
	}
	return en_a_error;

}

en_pwmError_t PWM_start(u8 u8_a_pwmUsed)
{
	en_pwmError_t en_a_error = PWM_OK;
	if (u8_a_pwmUsed == PWM_0)
	{
		#if		PWM_0_PRESCALER == PRESCLNG_1
		CLR_BIT(TCCR0, CS02);	CLR_BIT(TCCR0, CS01);	SET_BIT(TCCR0, CS00);

		#elif	PWM_0_PRESCALER == PRESCLNG_8
		CLR_BIT(TCCR0, CS02);	SET_BIT(TCCR0, CS01);	CLR_BIT(TCCR0, CS00);

		#elif	PWM_0_PRESCALER == PRESCLNG_64
		CLR_BIT(TCCR0, CS02);	SET_BIT(TCCR0, CS01);	SET_BIT(TCCR0, CS00);

		#elif	PWM_0_PRESCALER == PRESCLNG_256
		SET_BIT(TCCR0, CS02);	CLR_BIT(TCCR0, CS01);	CLR_BIT(TCCR0, CS00);

		#elif	PWM_0_PRESCALER == PRESCLNG_1024
		SET_BIT(TCCR0, CS02);	CLR_BIT(TCCR0, CS01);	SET_BIT(TCCR0, CS00);

		#endif
	}
	else if (u8_a_pwmUsed == PWM_1)
	{
	}
	else if (u8_a_pwmUsed == PWM_2)
	{
	}	
	else
	{
		en_a_error = PWM_WRONG_PWM_USED;
	}
	return en_a_error;
}

en_pwmError_t PWM_stop				(u8 u8_a_pwmUsed)
{
	en_pwmError_t en_a_error = PWM_OK;
	if (u8_a_pwmUsed == PWM_0 || u8_a_pwmUsed == PWM_1 || u8_a_pwmUsed == PWM_2)
	{
		CLR_BIT(TCCR0,CS02); CLR_BIT(TCCR0,CS01);	CLR_BIT(TCCR0,CS00);
	}
	else
	{
		en_a_error = PWM_WRONG_PWM_USED;
	}
	return en_a_error;
}
