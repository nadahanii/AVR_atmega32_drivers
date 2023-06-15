/*
 * ADC.c
 *
 *  Created on: Mar 10, 2023
 *      Author: dell
 */

#include "../../STD_LIB/STD_TYPES.h"
#include "../../STD_LIB/BIT_MATH.h"
#include "ADC_Interface.h"
#include "ADC_Registers.h"
#include "ADC_Config.h"

void ADC_Init()
{
	//Determine voltage reference source and value
#if ADC_VREF == ADC_INTERNAL_2_56_v
	SET_BIT(ADMUX_REG,REFS0);
	SET_BIT(ADMUX_REG,REFS1);
#elif ADC_VREF == ADC_INTERNAL_AVCC
	SET_BIT(ADMUX_REG,REFS0);
	CLR_BIT(ADMUX_REG,REFS1);
#elif ADC_VREF == ADC_EXTERNAL
	CLR_BIT(ADMUX_REG,REFS0);
	CLR_BIT(ADMUX_REG,REFS1);
#endif

	//Determine reading direction
#if ADC_ADJUST == ADC_LEFT
	SET_BIT(ADMUX_REG,5);
#elif ADC_ADJUST == ADC_RIGHT
	CLR_BIT(ADMUX_REG,5);
#endif

	//Determine pre-scaler value
#if ADC_PRESCALER == ADC_PRESCALER_2
	CLR_BIT(ADCSRA_REG,0);
	CLR_BIT(ADCSRA_REG,1);
	CLR_BIT(ADCSRA_REG,2);
#elif ADC_PRESCALER == ADC_PRESCALER_4
	CLR_BIT(ADCSRA_REG,0);
	SET_BIT(ADCSRA_REG,1);
	CLR_BIT(ADCSRA_REG,2);
#elif ADC_PRESCALER == ADC_PRESCALER_8
	SET_BIT(ADCSRA_REG,0);
	SET_BIT(ADCSRA_REG,1);
	CLR_BIT(ADCSRA_REG,2);
#elif ADC_PRESCALER == ADC_PRESCALER_16
	CLR_BIT(ADCSRA_REG,0);
	CLR_BIT(ADCSRA_REG,1);
	SET_BIT(ADCSRA_REG,2);
#elif ADC_PRESCALER == ADC_PRESCALER_32
	SET_BIT(ADCSRA_REG,0);
	CLR_BIT(ADCSRA_REG,1);
	SET_BIT(ADCSRA_REG,2);
#elif ADC_PRESCALER == ADC_PRESCALER_64
	CLR_BIT(ADCSRA_REG,0);
	SET_BIT(ADCSRA_REG,1);
	SET_BIT(ADCSRA_REG,2);
#elif ADC_PRESCALER == ADC_PRESCALER_128
	SET_BIT(ADCSRA_REG,0);
	SET_BIT(ADCSRA_REG,1);
	SET_BIT(ADCSRA_REG,2);
#endif

	//Select auto trigger / free running mode
CLR_BIT(ADCSRA_REG,5);

	//Enable ADC circuit
SET_BIT(ADCSRA_REG,7);
}

/* NOTES
 * 1- Only first 3 pins are used to determine the input channel [0-2] from the [0-4]-valued register.
 * */
u16 ADC_READ(u8 ADC_PIN)
{
	ADCDATA_REG=0x00; //clear data register at each new reading
		//Select ADC channel
		switch(ADC_PIN){
		case ADC0:
			CLR_BIT(ADMUX_REG,0);
			CLR_BIT(ADMUX_REG,1);
			CLR_BIT(ADMUX_REG,2);
			break;
		case ADC1:
			SET_BIT(ADMUX_REG,0);
			CLR_BIT(ADMUX_REG,1);
			CLR_BIT(ADMUX_REG,2);
			break;
		case ADC2:
			CLR_BIT(ADMUX_REG,0);
			SET_BIT(ADMUX_REG,1);
			CLR_BIT(ADMUX_REG,2);
			break;
		case ADC3:
			SET_BIT(ADMUX_REG,0);
			SET_BIT(ADMUX_REG,1);
			CLR_BIT(ADMUX_REG,2);
			break;
		case ADC4:
			CLR_BIT(ADMUX_REG,0);
			CLR_BIT(ADMUX_REG,1);
			SET_BIT(ADMUX_REG,2);
			break;
		case ADC5:
			SET_BIT(ADMUX_REG,0);
			CLR_BIT(ADMUX_REG,1);
			SET_BIT(ADMUX_REG,2);
			break;
		case ADC6:
			CLR_BIT(ADMUX_REG,0);
			SET_BIT(ADMUX_REG,1);
			SET_BIT(ADMUX_REG,2);
			break;
		case ADC7:
			SET_BIT(ADMUX_REG,0);
			SET_BIT(ADMUX_REG,1);
			SET_BIT(ADMUX_REG,2);
			break;
		default:
			//report error
			break;
		}

		//Start conversion
		SET_BIT(ADCSRA_REG,6);

		//Wait till conversion is completed
		while(GET_BIT(ADCSRA_REG,4) == 0);

		//Clear ADC flag manually because we don't want to enter its ISR right now
		SET_BIT(ADCSRA_REG,4);

#if ADC_ADJUST == ADC_RIGHT
		//Read from ADC_DATA register directly.
		return ADCDATA_REG;
#elif ADC_ADJUST == ADC_LEFT
		//mathematical operations must be done first
		return ADCDATA_REG>>6;
#endif
}
