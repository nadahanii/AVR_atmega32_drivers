/*
 * TIMER1_Config.h
 *
 *  Created on: Mar 24, 2023
 *      Author: dell
 */

#ifndef TIMER1_CONFIG_H_
#define TIMER1_CONFIG_H_

#define TIMER1_MODE CTC_MODE

//Prescaler options(1/8/64/256/1024)
#define TIMER1_PRESCALER 		64
#define TIMER1_CLK		 		8 //'8000000UL'unsigned long
#define TIMER1_RESOLUTION		256

#define PWM1_MODE 			 FAST_PWM_MODE
#define COMPARE_OUTPUT_MATCH INVERTING_TCCR1A

//#define TIMER0_CTC_VALUE 200
//Timer modes
#define NORMAL_MODE 			0
#define CTC_MODE 				1
#define PHASE_CORRECT_PWM_MODE  2
#define FAST_PWM_MODE 			3

//Pwm types
#define INVERTING_TCCR1A		0
#define NON_INVERTING_TCCR1A    1
#define INVERTING_TCCR1B        2
#define NON_INVERTING_TCCR1B	3
#endif /* MCAL_TIMER1_TIMER1_CONFIG_H_ */
