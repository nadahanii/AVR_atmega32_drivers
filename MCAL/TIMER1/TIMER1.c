/*
 * TIMER1.c
 *
 *  Created on: Mar 24, 2023
 *      Author: dell
 */
#include "../../STD_LIB/STD_TYPES.h"
#include "../../STD_LIB/BIT_MATH.h"
#include "TIMER1_Interface.h"
#include "TIMER1_Registers.h"
#include "TIMER1_Config.h"

//1- Determine PWM type (fast / phase correct)
//2- Determine PWM mode (inverting/non-inverting)
void PWM1_Init()
{
#if PWM1_MODE == FAST_PWM_MODE
	CLR_BIT(TCCR1A_REG,0);
	SET_BIT(TCCR1A_REG,1);
	SET_BIT(TCCR1B_REG,3);
	SET_BIT(TCCR1B_REG,4);
#elif PWM1_MODE == PHASE_CORRECT_PWM_MODE
	CLR_BIT(TCCR1A_REG,0);
	SET_BIT(TCCR1A_REG,1);
	CLR_BIT(TCCR1B_REG,3);
	SET_BIT(TCCR1B_REG,4);
#endif

#if COMPARE_OUTPUT_MATCH == INVERTING_TCCR1A
	//pin5 portD
	SET_BIT(TCCR1A_REG,6);
	SET_BIT(TCCR1A_REG,7);
#elif COMPARE_OUTPUT_MATCH == NON_INVERTING_TCCR1A
	//pin4 portD
	CLR_BIT(TCCR1A_REG,6);
	SET_BIT(TCCR1A_REG,7);
#elif COMPARE_OUTPUT_MATCH == INVERTING_TCCR1B
	//pin5 portD
	SET_BIT(TCCR1A_REG,4);
	SET_BIT(TCCR1A_REG,5);
#elif COMPARE_OUTPUT_MATCH == NON_INVERTING_TCCR1B
	//pin4 portD
	CLR_BIT(TCCR1A_REG,4);
	SET_BIT(TCCR1A_REG,5);
#endif
}

//Set CTC register
void PWM1_SetDutyCycle(u8 DutyCycle)
{
	/*NOTES:
	 * 1-DutuCycle is divided by 100 because it is passed to the function
	 *   as a percentage not a ratio.
	 * 2- The top value differs according to the chosen mode.
	 * 	  (can be in a register as ICR1_REG or a constant value mentioned in the data sheet)
	 * */
#if PWM1_MODE == FAST_PWM_MODE
	#if COMPARE_OUTPUT_MATCH == INVERTING_TCCR1A
		OCR1A_REG = ICR1_REG * (1-(DutyCycle/100.0));
	#elif COMPARE_OUTPUT_MATCH == NON_INVERTING_TCCR1A
		OCR1A_REG = ICR1_REG * (DutyCycle/100.0);
	#elif COMPARE_OUTPUT_MATCH == INVERTING_TCCR1B
		OCR1B_REG = ICR1_REG * (1-(DutyCycle/100.0));
	#elif COMPARE_OUTPUT_MATCH == NON_INVERTING_TCCR1B
		OCR1B_REG = ICR1_REG * (DutyCycle/100.0);
	#endif

#elif PWM1_MODE == PHASE_CORRECT_PWM_MODE
	#if COMPARE_OUTPUT_MATCH == INVERTING_TCCR1A
		OCR1A_REG = ICR1_REG * (1-(DutyCycle/100.0));
	#elif COMPARE_OUTPUT_MATCH == NON_INVERTING_TCCR1A
		OCR1A_REG = ICR1_REG / (DutyCycle/100.0);
				//ICR1_REG / ((DutyCycle/100.0)+1);
	#elif COMPARE_OUTPUT_MATCH == INVERTING_TCCR1B
		OCR1B_REG = ICR1_REG * (1-(DutyCycle/100.0));
	#elif COMPARE_OUTPUT_MATCH == NON_INVERTING_TCCR1B
		OCR1B_REG = ICR1_REG / (DutyCycle/100.0);
				//ICR1_REG / ((DutyCycle/100.0)+1);
	#endif
#endif

}

//Depends on whether i can control the "TOP" value of the PWM or not.
//(Control the time after which the wave will repeat itself)
void PWM1_SetFrequency(u8 Frequency)
{
	/* NOTES:
	 *1- Timer clock is multiplied by 1000000 because it is in MEGA Hz.
	 *2- Prescaler should always be > 1 to make sure that the calculation result doesn't
	 *	 exceed the maximum value that the ICR1_REG can store.*/
	ICR1_REG = (TIMER1_CLK *1000000UL)/(TIMER1_PRESCALER*Frequency);
}


//Set prescaler
void PWM1_Start()
{
	//prescaler_64
	SET_BIT(TCCR1B_REG,0);
	SET_BIT(TCCR1B_REG,1);
	CLR_BIT(TCCR1B_REG,2);
}

//Clear prescaler
void PWM1_Stop()
{
	CLR_BIT(TCCR1B_REG,0);
	CLR_BIT(TCCR1B_REG,1);
	CLR_BIT(TCCR1B_REG,2);
}
