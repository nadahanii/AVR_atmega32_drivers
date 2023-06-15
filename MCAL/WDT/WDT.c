/*
 * WDT.c
 *
 *  Created on: Mar 29, 2023
 *      Author: dell
 */
#include "../../STD_LIB/STD_TYPES.h"
#include"../../STD_LIB/BIT_MATH.h"
#include "WDT_Interface.h"
#include "WDT_Registers.h"


void WDT_Start()
{
	SET_BIT(WDTCR_REG,3);
}

void WDT_Clear()
{
	//Set bits 3 & 4 at the same time
	//WDTCR_REG = (1<<4) | (1<<3);
	//WDTCR_REG = 0x00;
	//Clear bit 3
	//CLR_BIT(WDTCR_REG,3);
	asm("WDR");
}

void WDT_SetTimeOut(u8 Prescaler)
{
	switch(Prescaler)
	{
	case TimeOut_16_3_ms:
		CLR_BIT(WDTCR_REG,0);
		CLR_BIT(WDTCR_REG,1);
		CLR_BIT(WDTCR_REG,2);
		break;
	case TimeOut_32_5_ms:
		SET_BIT(WDTCR_REG,0);
		CLR_BIT(WDTCR_REG,1);
		CLR_BIT(WDTCR_REG,2);
		break;
	case TimeOut_65_ms:
		CLR_BIT(WDTCR_REG,0);
		SET_BIT(WDTCR_REG,1);
		CLR_BIT(WDTCR_REG,2);
		break;
	case TimeOut_130_ms:
		SET_BIT(WDTCR_REG,0);
		SET_BIT(WDTCR_REG,1);
		CLR_BIT(WDTCR_REG,2);
		break;
	case TimeOut_260_ms:
		CLR_BIT(WDTCR_REG,0);
		CLR_BIT(WDTCR_REG,1);
		SET_BIT(WDTCR_REG,2);
		break;
	case TimeOut_520_ms:
		SET_BIT(WDTCR_REG,0);
		CLR_BIT(WDTCR_REG,1);
		SET_BIT(WDTCR_REG,2);
		break;
	case TimeOut_1_Sec:
		CLR_BIT(WDTCR_REG,0);
		SET_BIT(WDTCR_REG,1);
		SET_BIT(WDTCR_REG,2);
		break;
	case TimeOut_2_1_Sec:
		SET_BIT(WDTCR_REG,0);
		SET_BIT(WDTCR_REG,1);
		SET_BIT(WDTCR_REG,2);
		break;
	default:
		break;
	}
}
