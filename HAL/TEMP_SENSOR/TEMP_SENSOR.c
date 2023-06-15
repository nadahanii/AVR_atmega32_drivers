/*
 * TEMP_SENSOR.c
 *
 *  Created on: Mar 17, 2023
 *      Author: dell
 */

#include "../../STD_LIB/STD_TYPES.h"
#include "../../MCAL/ADC/ADC_Interface.h"
#include "TEMP_SENSOR_Interface.h"

u16 TEMP_SENSOR_Reading(u8 ADC_CHANNEL)
{
	u16 ADC_Reading = ADC_READ(ADC_CHANNEL); //[0-1024]
	//return ADC_Reading;
//	f32 temperature = ((u32)(ADC_Reading*150))/1024.0;
//	u16 Temp = (u16)(temperature+17);
	//*********** original code *************
	f32 volt = ((u32)(ADC_Reading*5000))/1024.0;
	u16 Temp = volt/10.0;
	return Temp;
	//***************************************
			//((u16)(((u32)ADC_Reading * 512UL) / 1024UL));

}
