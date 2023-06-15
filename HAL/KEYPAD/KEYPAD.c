/*
 * KEYPAD.c
 *
 *  Created on: Feb 18, 2023
 *      Author: dell
 */
#include "../../STD_LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "KEYPAD_Interface.h"
#include "KEYPAD_Config.h"
#include <avr/delay.h>

u8 SwitchValue [4][4] ={{'7','8','9','/'},
						{'4','5','6','*'},
						{'1','2','3','-'},
						{'C','0','=','+'}};

void KEYPAD_INIT(){

	DIO_SetPortDirection(KEYPAD_PORT,0xF0);

	DIO_SetPortValue(KEYPAD_PORT,0xFF);
}

u8 KEYPAD_GetKeyPressed(){
	u8 KeyPressed=0;
	u8 GetPinReading=1;

	for(u8 column=C1;column<=C4;column++){
		DIO_SetPinValue(KEYPAD_PORT,column,LOW);

		for(u8 row=R1;row<=R4;row++){
			DIO_ReadPin(KEYPAD_PORT,row,&GetPinReading);

			if(GetPinReading==LOW){
				KeyPressed = SwitchValue[row][column-C1];
				_delay_ms(20);

				while(GetPinReading==LOW){
					//to stay stuck while the same switch is still pressed
					DIO_ReadPin(KEYPAD_PORT,row,&GetPinReading);
				}
			}
		}
		//to restore its initial value
		DIO_SetPinValue(KEYPAD_PORT,column,HIGH);
	}

	return KeyPressed;
}
