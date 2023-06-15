/*
 * ICU_Interface.h
 *
 *  Created on: Mar 29, 2023
 *      Author: dell
 */

#ifndef ICU_INTERFACE_H_
#define ICU_INTERFACE_H_

#define RISING_EDGE 0
#define FALLING_EDGE 1


void ICU_Init();

//Rising edge / Falling edge
void ICU_SetTrigger(u8 TriggerType);

//Gets the value in the ICR1 Register
u16 ICU_GetValue();

void ICU_DisplayPWM(u8* Frequency , u8* DutyCycle);



#endif /* MCAL_ICU_ICU_INTERFACE_H_ */
