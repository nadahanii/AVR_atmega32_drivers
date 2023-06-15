/*
 * SEV_SEG.c
 *
 *  Created on: Feb 11, 2023
 *      Author: dell
 */

#include "../../STD_LIB/STD_TYPES.h"
#include "avr/delay.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "SEV_SEG.h"

#define Zero 0b00111111
#define One 0b00000110
#define Two 0b01011011
#define Three 0b01001111
#define Four 0b01100110
#define Five 0b01101101
#define Six 0b01111101
#define Seven 0b00000111
#define Eight 0b01111111
#define Nine 0b01101111

void SEV_SEG_INIT(u8 Port_ID){
	DIO_SetPortDirection(Port_ID,OUTPUT_PORT);
}

void SEV_SEG_COUNT_UP(u8 Start_Num,u8 End_Num,u16 Delay,u8 Port_ID){
	if(Start_Num >=0 && End_Num <=9){
		for(u8 i=Start_Num ; i<=End_Num; i++){

			switch(i){
			case 0: DIO_SetPortValue(Port_ID,Zero);break;
			case 1: DIO_SetPortValue(Port_ID,One);break;
			case 2: DIO_SetPortValue(Port_ID,Two);break;
			case 3: DIO_SetPortValue(Port_ID,Three);break;
			case 4: DIO_SetPortValue(Port_ID,Four);break;
			case 5: DIO_SetPortValue(Port_ID,Five);break;
			case 6: DIO_SetPortValue(Port_ID,Six);break;
			case 7: DIO_SetPortValue(Port_ID,Seven);break;
			case 8: DIO_SetPortValue(Port_ID,Eight);break;
			case 9: DIO_SetPortValue(Port_ID,Nine);break;
			}
			_delay_ms(Delay);
		}
	}
}

void SEV_SEG_COUNT_DOWN(u8 Start_Num,u8 End_Num,u16 Delay,u8 Port_ID){
	if(Start_Num >=0 && End_Num <=9){
		for(u8 i=End_Num ; i>=Start_Num; i--){

			switch(i){
			case 0: DIO_SetPortValue(Port_ID,Zero);break;
			case 1: DIO_SetPortValue(Port_ID,One);break;
			case 2: DIO_SetPortValue(Port_ID,Two);break;
			case 3: DIO_SetPortValue(Port_ID,Three);break;
			case 4: DIO_SetPortValue(Port_ID,Four);break;
			case 5: DIO_SetPortValue(Port_ID,Five);break;
			case 6: DIO_SetPortValue(Port_ID,Six);break;
			case 7: DIO_SetPortValue(Port_ID,Seven);break;
			case 8: DIO_SetPortValue(Port_ID,Eight);break;
			case 9: DIO_SetPortValue(Port_ID,Nine);break;
			}
			_delay_ms(Delay);
		}
	}
}

void SEV_SEG_DISPLAY_NUM(u8 Number,u8 Port_ID){
	switch(Number){
			case 0: DIO_SetPortValue(Port_ID,Zero);break;
			case 1: DIO_SetPortValue(Port_ID,One);break;
			case 2: DIO_SetPortValue(Port_ID,Two);break;
			case 3: DIO_SetPortValue(Port_ID,Three);break;
			case 4: DIO_SetPortValue(Port_ID,Four);break;
			case 5: DIO_SetPortValue(Port_ID,Five);break;
			case 6: DIO_SetPortValue(Port_ID,Six);break;
			case 7: DIO_SetPortValue(Port_ID,Seven);break;
			case 8: DIO_SetPortValue(Port_ID,Eight);break;
			case 9: DIO_SetPortValue(Port_ID,Nine);break;
			}
}

void SEV_SEG_TOG_NUM(u8 Number,u8 Port_ID,u16 Delay){

	SEV_SEG_DISPLAY_NUM(Number,Port_ID);
	_delay_ms(Delay);
	DIO_SetPortValue(Port_ID,LOW_PORT);
	_delay_ms(Delay);
}
