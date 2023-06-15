/*
 * LED.c
 *
 *  Created on: Feb 11, 2023
 *      Author: dell
 */

#include "../../STD_LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "LED.h"

void LED_INIT(u8 Port_ID , u8 Pin_ID){
	DIO_SetPinDirection(Port_ID,Pin_ID,OUTPUT);
}

void LED_ON(u8 Port_ID , u8 Pin_ID){

	DIO_SetPinValue(Port_ID,Pin_ID,HIGH);
}

void LED_OFF(u8 Port_ID , u8 Pin_ID){
	DIO_SetPinValue(Port_ID,Pin_ID,LOW);
}

void LED_TOG(u8 Port_ID , u8 Pin_ID){
	DIO_TogglePin(Port_ID,Pin_ID);
}
