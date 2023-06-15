/*
 * ADC_Registers.h
 *
 *  Created on: Mar 10, 2023
 *      Author: dell
 */

#ifndef ADC_REGISTERS_H_
#define ADC_REGISTERS_H_

#define ADMUX_REG   *((volatile u8*)0x27)
#define ADCSRA_REG 	    *((volatile u8*)0x26)
//to point at both 0x24 and 0x25 together
#define ADCDATA_REG *((volatile u16*)0x24)
#define ADCL_REG 	*((volatile u8*)0x24)
#define ADCH_REG 	*((volatile u8*)0x25)

#define REFS1	7
#define REFS0	6
/*REFS1,REFS0 => 7,6*/
#endif /* ADC_REGISTERS_H_ */
