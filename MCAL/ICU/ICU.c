/*
 * ICU.c
 *
 *  Created on: Mar 29, 2023
 *      Author: dell
 */
#include "../../STD_LIB/STD_TYPES.h"
#include "../../STD_LIB/BIT_MATH.h"
#include "ICU_Interface.h"
#include "ICU_Registers.h"
#include "ICU_Config.h"

#include "../GI/GI_Interface.h"

u16 period_ticks=0;
u16 C2_ticks = 0;
u16 C3_ticks = 0;
u16 C4_ticks = 0;
u16 TON = 0;
u16  TOFF = 0;

void ICU_Init()
{
	//Set trigger type to rising edge initially.
	SET_BIT(TCCR1B_REG,6);

	//Enable ICU Interrupt
	SET_BIT(TIMSK_REG,5);

	//Enable Global Interrupt
	GI_Enable();

	//Start timer by setting prescaler
	//prescaler_8
	CLR_BIT(TCCR1B_REG,0);
	SET_BIT(TCCR1B_REG,1);
	CLR_BIT(TCCR1B_REG,2);
}

void ICU_SetTrigger(u8 TriggerType)
{
	switch(TriggerType)
	{
	case RISING_EDGE:
		SET_BIT(TCCR1B_REG,6);
		break;
	case FALLING_EDGE:
		CLR_BIT(TCCR1B_REG,6);
		break;
	default:
		break;
	}
}

u16 ICU_GetValue()
{
	return ICR1_REG;
}

void ICU_DisplayPWM(u8* Frequency , u8* DutyCycle)
{
	u16 Period = period_ticks * (TIMER1_PRESCALER/TIMER1_CLK);//total period = # period ticks * Tick-Time
	*Frequency = 1/Period;
	*DutyCycle = (TON / period_ticks)*100;
}

void __vector_6(void)__attribute__((signal));
void __vector_6(void)
{
	static u8 counter =0;


	if(counter == 1){
		//Time between two rising edges
		period_ticks = ICU_GetValue();
	}
	else if(counter==2){
		C2_ticks = ICU_GetValue(); //Number of ticks at the second rising edge (beginning of a new signal)
		//Change trigger type
		ICU_SetTrigger(FALLING_EDGE);

	}
	else if(counter==3){ //falling edge interrupt
		C3_ticks = ICU_GetValue();
		TON = C3_ticks - C2_ticks;//Number of ticks till now - Number of ticks at the second rising edge(beginning of a new signal)
		//Change trigger type
		ICU_SetTrigger(RISING_EDGE);
	}
	else if(counter==4){
		C4_ticks = ICU_GetValue();
		TOFF = C4_ticks - C3_ticks;
	}
	//Ignore first interrupt
	counter++;
}
