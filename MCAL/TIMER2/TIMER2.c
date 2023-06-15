/*
 * TIMER2.c
 *
 *  Created on: Mar 17, 2023
 *      Author: dell
 */

#include "../../STD_LIB/STD_TYPES.h"
#include "../../STD_LIB/BIT_MATH.h"
#include "../GI/GI_Interface.h"
#include "TIMER2_Interface.h"
#include "TIMER2_Registers.h"
#include "TIMER2_Config.h"

u32 TIMER2_Num_Of_Overflows=0;
u32 TIMER2_Pre_load_Value=0;

void TIMER2_Init(void)
{
	//1- Select Timer mode (Normal/CTC/Phase Correct/PWM/Fast PWM)
#if TIMER2_MODE == NORMAL_MODE
	CLR_BIT(TCCR2_REG,3);
	CLR_BIT(TCCR2_REG,6);
#endif

	//2- Enable Timer interrupt
	SET_BIT(TIMSK_REG,0);

	//3- Enable Global interrupt
	GI_Enable();
}

void TIMER2_Start(u16 Prescaler)
{
	switch(Prescaler)
		{
		case PRESCALER_VAL_1:
			/*since 7 in binary is 111,
			so that we keep the rest of register's bits as they are.
			TCCR0_REG |= (PRESCALER_1&7);*/
			SET_BIT(TCCR2_REG,0);
			CLR_BIT(TCCR2_REG,1);
			CLR_BIT(TCCR2_REG,2);
			break;
		case PRESCALER_VAL_8:
			CLR_BIT(TCCR2_REG,0);
			SET_BIT(TCCR2_REG,1);
			CLR_BIT(TCCR2_REG,2);
			break;
		case PRESCALER_VAL_64:
			SET_BIT(TCCR2_REG,0);
			SET_BIT(TCCR2_REG,1);
			CLR_BIT(TCCR2_REG,2);
					break;
		case PRESCALER_VAL_256:
			CLR_BIT(TCCR2_REG,0);
			CLR_BIT(TCCR2_REG,1);
			SET_BIT(TCCR2_REG,2);
			break;
		case PRESCALER_VAL_1024:
			SET_BIT(TCCR2_REG,0);
			CLR_BIT(TCCR2_REG,1);
			SET_BIT(TCCR2_REG,2);
			break;
		default:
			CLR_BIT(TCCR2_REG,0);
			CLR_BIT(TCCR2_REG,1);
			CLR_BIT(TCCR2_REG,2);
			break;
		}
}
