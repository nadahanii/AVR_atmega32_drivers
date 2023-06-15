/*
 * TIMER2_Config.h
 *
 *  Created on: Mar 17, 2023
 *      Author: dell
 */

#ifndef TIMER2_CONFIG_H_
#define TIMER2_CONFIG_H_

#define TIMER2_MODE NORMAL_MODE

//Prescaler options(1/8/64/256/1024)
#define TIMER2_PRESCALER PRESCALER_2
#define TIMER2_CLK		 8000000UL //unsigned long
#define RESOLUTION		 256


#define NORMAL_MODE 0
#define CTC_MODE 1
#define PHASE_CORRECT_PWM_MODE 2
#define FAST_PWM_MODE 3

#endif /* MCAL_TIMER2_TIMER2_CONFIG_H_ */
