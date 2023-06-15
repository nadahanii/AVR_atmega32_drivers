/*
 * LDR.c
 *
 *  Created on: Mar 17, 2023
 *      Author: dell
 */
#include "../../STD_LIB/STD_TYPES.h"
#include "LDR_Interface.h"

#include "../../MCAL/ADC/ADC_Interface.h"

u16 LDR_Reading(u8 ADC_CHAN)
{
	u16 ADC_Reading = ADC_READ(ADC_CHAN);
	u16 volt = ((u32)ADC_Reading * 5000)/1023;
	return volt;
}

u8 LDR_Intensity_Level(u8 ADC_CHAN)
{
	u16 LDR_Reading_value = LDR_Reading(ADC_CHAN);
	if(LDR_Reading_value>=0 && LDR_Reading_value<= 1000){
		return LEVEL_1;
	}
	else if(LDR_Reading_value> 1000 && LDR_Reading_value<= 2000){
		return LEVEL_2;
	}
	else if(LDR_Reading_value> 2000 && LDR_Reading_value<= 3000){
		return LEVEL_3;
	}
	else if(LDR_Reading_value> 3000 && LDR_Reading_value<= 4000){
		return LEVEL_4;
	}
	else if(LDR_Reading_value> 4000 && LDR_Reading_value<= 5000){
		return LEVEL_5;
	}
	else{
		return INVALID;
	}


}

