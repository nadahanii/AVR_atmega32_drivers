/*
 * TIMER0_Interface.h
 *
 *  Created on: Mar 17, 2023
 *      Author: dell
 */

#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_

enum TIMER0_PRESCALERS{
	PRESCALER_1=1,
	PRESCALER_8,
	PRESCALER_64,
	PRESCALER_256,
	PRESCALER_1024
};

enum TIMER0_OC0_PIN_VALUES{
	CLEAR,SET,TOGGLE
};

//1-Choose timer mode
//2-Enable interrupts
void TIMER0_Init(void);

//Desired Time must be passed in milliseconds
void TIMER0_SetTime(u32 DesiredTime);

//Timer zero's interrupt ISR callback
void TIMER0_CallBack(void (*PF)(void));

void TIMER0_Start(u16 Prescaler);

void TIMER0_Stop();

//Values (clear/set/toggle)
void TIMER0_Set_OC0_Pin(u8 Pin_Value);

void TIMER0_Set_CTC(u8 CTC_Value);

#endif /* MCAL_TIMER0_TIMER0_INTERFACE_H_ */
