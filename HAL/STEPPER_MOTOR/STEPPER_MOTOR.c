/*
 * STEPPER_MOTOR.c
 *
 *  Created on: Feb 25, 2023
 *      Author: dell
 */

#include <avr/delay.h>
#include "../../STD_LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "STEPPER_MOTOR_Interface.h"
#include "STEPPER_MOTOR_Config.h"


void STEPPER_INIT()
{
	DIO_SetPortDirection(STEPPER_PORT,0x0F);
	/*DIO_SetPinDirection(STEPPER_PORT,COIL_1,OUTPUT);
	DIO_SetPinDirection(STEPPER_PORT,COIL_2,OUTPUT);
	DIO_SetPinDirection(STEPPER_PORT,COIL_3,OUTPUT);
	DIO_SetPinDirection(STEPPER_PORT,COIL_4,OUTPUT);*/
}

void STEPPER_Stop()
{
	DIO_SetPinValue(STEPPER_PORT,COIL_1,LOW);
	DIO_SetPinValue(STEPPER_PORT,COIL_2,LOW);
	DIO_SetPinValue(STEPPER_PORT,COIL_3,LOW);
	DIO_SetPinValue(STEPPER_PORT,COIL_4,LOW);
}

void STEPPER_STEP(u8 Step_Num,u8 Step_Style)
{
	if(Step_Style==Full_Step){
		switch(Step_Num){
		case 1:
			//coil 1
			DIO_SetPortValue(STEPPER_PORT,0x01);
			break;
		case 2:
			//coil 2
			DIO_SetPortValue(STEPPER_PORT,0x02);
			break;
		case 3:
			//coil 3
		    DIO_SetPortValue(STEPPER_PORT,0x04);
			break;
		case 4:
			//coil 4
			DIO_SetPortValue(STEPPER_PORT,0x08);
			_delay_ms(5);
			//coil 1
			DIO_SetPortValue(STEPPER_PORT,0x01);
			break;
		default:
			//report error
			break;

		}
	}

	else if(Step_Style==Half_Step){
		switch(Step_Num){
			case 1:
				//coil 1
				DIO_SetPortValue(STEPPER_PORT,0x01);

				break;
			case 2:
				//coil 1 & 2
				DIO_SetPortValue(STEPPER_PORT,0x03);

				break;

			case 3:
				//coil 2
				DIO_SetPortValue(STEPPER_PORT,0x02);

				break;
			case 4:
				//coil 2 & 3
				DIO_SetPortValue(STEPPER_PORT,0x06);


				break;
			case 5:
				//coil 3
				DIO_SetPortValue(STEPPER_PORT,0x04);
				break;
			case 6:
				//coil 3 & 4
				DIO_SetPortValue(STEPPER_PORT,0x0C);
				break;

			case 7:
				//coil 4
				DIO_SetPortValue(STEPPER_PORT,0x08);
				break;
			case 8:
				//set coil 4 and 1
				DIO_SetPortValue(STEPPER_PORT,0x09);
				break;
			default:
				//report error
				break;

			}
	}

}

void STEPPER_ClockWise_FullStep()
{
	for(u8 i=1;i<=4;i++){
		STEPPER_STEP(i,Full_Step);
		_delay_ms(5);
	}

}

void STEPPER_AntiClockWise_FullStep()
{
	for(u8 i=4;i>=1;i--){
		STEPPER_STEP(i,Full_Step);
		_delay_ms(5);
	}
}

void STEPPER_ClockWise_HalfStep()
{
	for(u8 i=1;i<=8;i++){
		STEPPER_STEP(i,Half_Step);
		_delay_ms(5);
	}
}

void STEPPER_AntiClockWise_HalfStep()
{
	for(u8 i=8;i>=1;i--){
		STEPPER_STEP(i,Half_Step);
		_delay_ms(5);
	}
}

void STEPPER_GoToSTEP(u8 Step_Num,u8 Step_Style)
{
	for(u8 i=1;i<=Step_Num;i++){
		_delay_ms(5);
		STEPPER_STEP(i,Step_Style);
	}
}
