/*
 * WDT_Interface.h
 *
 *  Created on: Mar 29, 2023
 *      Author: dell
 */

#ifndef WDT_INTERFACE_H_
#define WDT_INTERFACE_H_

enum WDT_PRESCALER{
	TimeOut_16_3_ms,
	TimeOut_32_5_ms,
	TimeOut_65_ms,
	TimeOut_130_ms,
	TimeOut_260_ms,
	TimeOut_520_ms,
	TimeOut_1_Sec,
	TimeOut_2_1_Sec

};

void WDT_Start();

void WDT_Clear();

void WDT_SetTimeOut(u8 Prescaler);

#endif /* MCAL_WDT_WDT_INTERFACE_H_ */
