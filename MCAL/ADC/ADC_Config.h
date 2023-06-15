/*
 * ADC_Config.h
 *
 *  Created on: Mar 10, 2023
 *      Author: dell
 */

#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

/* You can choose which voltage reference to operate on
 * from (ADC_INTERNAL_2_56_v/ADC_INTERNAL_AVCC/ADC_EXTERNAL)
 * */
#define ADC_VREF		ADC_INTERNAL_AVCC
#define ADC_ADJUST 		ADC_RIGHT
#define ADC_PRESCALER   ADC_PRESCALER_8

#define ADC_PRESCALER_2    0
#define ADC_PRESCALER_4    1
#define ADC_PRESCALER_8    2
#define ADC_PRESCALER_16   3
#define ADC_PRESCALER_32   4
#define ADC_PRESCALER_64   5
#define ADC_PRESCALER_128  6

#define ADC_RIGHT		0
#define ADC_LEFT		1




enum ADC_VREF_OPTIONS{
	ADC_INTERNAL_2_56_v,
	ADC_INTERNAL_AVCC,
	ADC_EXTERNAL
};

#endif /* MCAL_ADC_ADC_CONFIG_H_ */
