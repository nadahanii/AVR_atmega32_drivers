/*
 * TIMER0_Config.h
 *
 *  Created on: Mar 17, 2023
 *      Author: dell
 */

#ifndef TIMER0_CONFIG_H_
#define TIMER0_CONFIG_H_

#define TIMER0_MODE CTC_MODE

//Prescaler options(1/8/64/256/1024)
#define TIMER0_PRESCALER PRESCALER_1
#define TIMER0_CLK		 8 //since the passed desired time is in milliseconds
//'8000000UL'unsigned long
#define TIMER0_RESOLUTION		 256

//#define TIMER0_CTC_VALUE 200

#define NORMAL_MODE 			0
#define CTC_MODE 				1
#define PHASE_CORRECT_PWM_MODE  2
#define FAST_PWM_MODE 			3


#endif /* MCAL_TIMER0_TIMER0_CONFIG_H_ */
