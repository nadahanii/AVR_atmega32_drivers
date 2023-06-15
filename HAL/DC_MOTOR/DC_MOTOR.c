/*
 * DC_MOTOR.c
 *
 *  Created on: Feb 25, 2023
 *      Author: dell
 */

#include "../../STD_LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "DC_MOTOR_Interface.h"
#include "DC_MOTOR_Config.h"

//if we have more than one motor, ports and pins can be passed as parameters to initialize
u8 MOTOR_INIT()
{
	DIO_SetPinDirection(MOTOR_PORT,MOTOR_PHASE_ONE,OUTPUT);
	DIO_SetPinDirection(MOTOR_PORT,MOTOR_PHASE_Two,OUTPUT);
	return MOTOR_OK;
}

u8 MOTOR_ClockWise()
{
	u8 MOTOR_Flag = 0;

	DIO_SetPinValue(MOTOR_PORT,MOTOR_PHASE_ONE,HIGH);
	DIO_SetPinValue(MOTOR_PORT,MOTOR_PHASE_Two,LOW);
	MOTOR_Flag =1;

	if(MOTOR_Flag == 0){
		return MOTOR_NOTOK;
	}
	else{
		return MOTOR_OK;
	}
}

u8 MOTOR_AntiClockWise()
{
	u8 MOTOR_Flag = 0;

	DIO_SetPinValue(MOTOR_PORT,MOTOR_PHASE_ONE,LOW);
	DIO_SetPinValue(MOTOR_PORT,MOTOR_PHASE_Two,HIGH);
	MOTOR_Flag =1;

	if(MOTOR_Flag == 0){
		return MOTOR_NOTOK;
	}
	else{
		return MOTOR_OK;
	}
}

u8 MOTOR_Stop()
{
	u8 MOTOR_Flag = 0;

	DIO_SetPinValue(MOTOR_PORT,MOTOR_PHASE_ONE,LOW);
	DIO_SetPinValue(MOTOR_PORT,MOTOR_PHASE_Two,LOW);
	MOTOR_Flag =1;

	if(MOTOR_Flag == 0){
		return MOTOR_NOTOK;
	}
	else{
		return MOTOR_OK;
	}
}
