/*
 * LDR_Interface.h
 *
 *  Created on: Mar 17, 2023
 *      Author: dell
 */

#ifndef LDR_INTERFACE_H_
#define LDR_INTERFACE_H_

enum LDR_LEVELS{
	LEVEL_1,LEVEL_2,LEVEL_3,LEVEL_4,LEVEL_5,INVALID
};

u16 LDR_Reading(u8 ADC_CHAN);

u8 LDR_Intensity_Level(u8 ADC_CHAN);



#endif /* HAL_LDR_LDR_INTERFACE_H_ */
