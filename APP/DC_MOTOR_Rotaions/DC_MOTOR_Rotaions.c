/*
 * DC_MOTOR_Rotaions.c
 *
 *  Created on: Feb 25, 2023
 *      Author: dell
 */

#include <avr/delay.h>
#include "../../STD_LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../HAL/DC_MOTOR/DC_MOTOR_Interface.h"
#include "../../HAL/LCD/LCD_Interface.h"
#include "DC_MOTOR_Rotaions.h"


void DC_MOTOR_RotaionsWithLabels(){

	u8 ClockwiseString[] = "Clockwise";
	u8 AntiClockwiseString[] = "Anti-Clockwise";

	LCD_WriteInstruction(LCD_Clear);
	LCD_WriteString(ClockwiseString);
	MOTOR_ClockWise();
	_delay_ms(3000);

	LCD_WriteInstruction(LCD_Clear);
	LCD_WriteString(AntiClockwiseString);
	MOTOR_AntiClockWise();
	_delay_ms(3000);


}
