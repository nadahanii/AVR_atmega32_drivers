/*
 * TIMER2_Interface.h
 *
 *  Created on: Mar 17, 2023
 *      Author: dell
 */

#ifndef TIMER2_INTERFACE_H_
#define TIMER2_INTERFACE_H_

enum TIMER2_PRESCALERS{
	PRESCALER_VAL_1=1,
	PRESCALER_VAL_8,
	PRESCALER_VAL_64,
	PRESCALER_VAL_256,
	PRESCALER_VAL_1024
};

//1-Choose timer mode
//2-Enable interrupts
void TIMER2_Init(void);

void TIMER2_SetTime(u32 DesiredTime);

//Timer's interrupt ISR
void TIMER2_CallBack(void (*PF)(void));

void TIMER2_Start(u16 Prescaler);

void TIMER2_Stop();

#endif /* MCAL_TIMER2_TIMER2_INTERFACE_H_ */
