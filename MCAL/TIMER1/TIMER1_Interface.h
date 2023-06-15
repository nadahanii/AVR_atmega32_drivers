/*
 * TIMER1_Interface.h
 *
 *  Created on: Mar 24, 2023
 *      Author: dell
 */

#ifndef TIMER1_INTERFACE_H_
#define TIMER1_INTERFACE_H_

//1- Determine PWM type (fast / phase correct)
//2- Determine PWM mode (inverting/non-inverting)
void PWM1_Init();


//Set CTC register
void PWM1_SetDutyCycle(u8 DutyCycle);

//Depends on whether i can control the "TOP" value of the PWM or not.
//(Control the time after which the wave will repeat itself)
void PWM1_SetFrequency(u8 Frequency);


//Set prescaler
void PWM1_Start();

//Clear prescaler
void PWM1_Stop();



#endif /* MCAL_TIMER1_TIMER1_INTERFACE_H_ */
