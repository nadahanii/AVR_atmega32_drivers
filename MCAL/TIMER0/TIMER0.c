/*
 * TIMER0.c
 *
 *  Created on: Mar 17, 2023
 *      Author: dell
 */

#include "../../STD_LIB/STD_TYPES.h"
#include "../../STD_LIB/BIT_MATH.h"
#include "../GI/GI_Interface.h"
#include "TIMER0_Interface.h"
#include "TIMER0_Registers.h"
#include "TIMER0_Config.h"

u32 TIMER0_Num_Of_Overflows=0;
u32 TIMER0_Pre_load_Value=0;
void (*TIMER0_CALL_BACK_PF)(void);

void TIMER0_Init(void)
{
	//1- Select Timer mode
	// (Normal/CTC/Phase Correct PWM/Fast PWM)
#if TIMER0_MODE == NORMAL_MODE
	CLR_BIT(TCCR0_REG,3);
	CLR_BIT(TCCR0_REG,6);
#elif TIMER0_MODE == CTC_MODE
	CLR_BIT(TCCR0_REG,3);
	SET_BIT(TCCR0_REG,6);
#endif

#if TIMER0_MODE == NORMAL_MODE
	//2- Enable Timer interrupt for overflow
	SET_BIT(TIMSK_REG,0);
#elif TIMER0_MODE == CTC_MODE
	//2- Enable Timer interrupt for CTC
	SET_BIT(TIMSK_REG,1);
#endif

	//3- Enable Global interrupt
	GI_Enable();
}

void TIMER0_Start(u16 Prescaler)
{
	switch(Prescaler)
	{
	/*******TRIAL************
	 * since 7 in binary is 111,
	so that we keep the rest of register's bits as they are.
	TCCR0_REG &= ~(PRESCALER_1&7);*/
	case PRESCALER_1: //001

		SET_BIT(TCCR0_REG,0);
		CLR_BIT(TCCR0_REG,1);
		CLR_BIT(TCCR0_REG,2);
		break;
	case PRESCALER_8: //010
		CLR_BIT(TCCR0_REG,0);
		SET_BIT(TCCR0_REG,1);
		CLR_BIT(TCCR0_REG,2);
		break;
	case PRESCALER_64: //011
		SET_BIT(TCCR0_REG,0);
		SET_BIT(TCCR0_REG,1);
		CLR_BIT(TCCR0_REG,2);
				break;
	case PRESCALER_256: //100
		CLR_BIT(TCCR0_REG,0);
		CLR_BIT(TCCR0_REG,1);
		SET_BIT(TCCR0_REG,2);
		break;
	case PRESCALER_1024: //101
		SET_BIT(TCCR0_REG,0);
		CLR_BIT(TCCR0_REG,1);
		SET_BIT(TCCR0_REG,2);
		break;
	default: //Stop timer
		CLR_BIT(TCCR0_REG,0);
		CLR_BIT(TCCR0_REG,1);
		CLR_BIT(TCCR0_REG,2);
		break;
	}
}

void TIMER0_Stop()
{
	CLR_BIT(TCCR0_REG,0);
	CLR_BIT(TCCR0_REG,1);
	CLR_BIT(TCCR0_REG,2);
}

//Desired Time must be passed in milliseconds
void TIMER0_SetTime(u32 DesiredTime)
{
	//(DesiredTime*1000) to convert milliseconds to microseconds
	DesiredTime*=1000;
	//Calculate timer frequency
	f32 TIMER0_FREQ = (f32)TIMER0_CLK / TIMER0_PRESCALER;

	//Calculate Tick Time
	//OR 1/TIMER0_FREQ
	f32 TIMER0_TICK_TIME = (f32)TIMER0_PRESCALER/TIMER0_CLK;

#if TIMER0_MODE == NORMAL_MODE
	//Number of ticks to reach an overflow
	u32 NUM_Of_Ticks = TIMER0_RESOLUTION;
	//Overflow Time
	f64 TIMER0_OVF_TIME =  NUM_Of_Ticks * TIMER0_TICK_TIME;

	//Number of Ticks needed to reach desired time

	u32 NUM_Of_Total_Ticks = DesiredTime / TIMER0_TICK_TIME;

	//Number of overflows
	TIMER0_Num_Of_Overflows = DesiredTime / TIMER0_OVF_TIME;

	//Pre-load value

	if(DesiredTime%(u32)TIMER0_OVF_TIME != 0) //A remainder exists, so we need to determine preload value
	{
		f32 Remainder = (DesiredTime%(u32)TIMER0_OVF_TIME)/(u32)TIMER0_OVF_TIME;
		TIMER0_Pre_load_Value = TIMER0_RESOLUTION - (TIMER0_RESOLUTION * Remainder);
		TCNT0_REG = TIMER0_Pre_load_Value;
		TIMER0_Num_Of_Overflows++;
	}

#elif TIMER0_MODE == CTC_MODE
	u8 CTC_Value = 255;

	//Number of ticks
	u32 NUM_Of_Ticks = CTC_Value;

	//Overflow Time
	f64 TIMER0_OVF_TIME =  NUM_Of_Ticks * TIMER0_TICK_TIME;


	//Number of Ticks needed to reach desired time

	u32 NUM_Of_Total_Ticks = DesiredTime / TIMER0_TICK_TIME;

	//Number of overflows
	TIMER0_Num_Of_Overflows = DesiredTime / TIMER0_OVF_TIME;

	//Customize CTC_Value to avoid using preload value
	while(DesiredTime%(u32)TIMER0_OVF_TIME != 0) //A remainder exists, so we need to determine preload value
	{
		CTC_Value--;
		//Number of ticks
		 NUM_Of_Ticks = CTC_Value;

		//Overflow Time
		 TIMER0_OVF_TIME =  NUM_Of_Ticks * TIMER0_TICK_TIME;
	}
	//load CTC_VALUE to OCR0_REG
	OCR0_REG = CTC_Value;
#endif





}

void TIMER0_Set_OC0_Pin(u8 Pin_Value)
{
	switch(Pin_Value)
	{
	case TOGGLE:
		CLR_BIT(TCCR0_REG,4);
		SET_BIT(TCCR0_REG,5);
		break;
	case SET:
		SET_BIT(TCCR0_REG,4);
		SET_BIT(TCCR0_REG,5);
		break;
	case CLEAR:
		SET_BIT(TCCR0_REG,4);
		CLR_BIT(TCCR0_REG,5);
		break;
	default:
		CLR_BIT(TCCR0_REG,4);
		CLR_BIT(TCCR0_REG,5);
		break;
	}
}

void TIMER0_Set_CTC(u8 CTC_Value)
{
	OCR0_REG = CTC_Value;
}


void TIMER0_CallBack(void (*PF)(void))
{
	TIMER0_CALL_BACK_PF = PF;
}
void __vector_11(void)__attribute__((signal));
void __vector_11(void)
{
	static u32 counter = 0;
	counter++;
	if(counter == TIMER0_Num_Of_Overflows){
		//action
		TIMER0_CALL_BACK_PF();
		counter =0;
		TCNT0_REG = TIMER0_Pre_load_Value;
		counter++;

	}
}

void __vector_10(void)__attribute__((signal));
void __vector_10(void)
{
	static u32 counter = 0;
	counter++;
	if(counter == TIMER0_Num_Of_Overflows){
		//action
		TIMER0_CALL_BACK_PF();
		counter =0;
		//TCNT0_REG = TIMER0_Pre_load_Value;
		//counter++;

	}
}
