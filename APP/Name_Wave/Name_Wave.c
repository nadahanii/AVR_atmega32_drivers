/*
 * Name_Wave.c
 *
 *  Created on: Feb 19, 2023
 *      Author: dell
 */
#include "../../STD_LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include <avr/delay.h>
#include "../../HAL/LCD/LCD_Interface.h"
#include "Name_Wave.h"

void Name_In_Sinosuidal_Wave(u8* counter){
	(*counter)=1;
	LCD_GoTo(*counter,2);
	LCD_WriteChar('N');
	(*counter)++;
	LCD_GoTo(*counter,1);
	LCD_WriteChar('A');
	(*counter)+=2;
	LCD_GoTo(*counter,2);
	LCD_WriteChar('D');
	(*counter)++;
	LCD_GoTo(*counter,1);
	LCD_WriteChar('A');
	(*counter)=1;
	_delay_ms(500);
}
