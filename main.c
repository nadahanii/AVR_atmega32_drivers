/*
 * main.c
 *
 *  Created on: Feb 11, 2023
 *      Author: Nada Hani
 */

#include <avr/delay.h>
#include "STD_LIB/STD_TYPES.h"
#include "STD_LIB/BIT_MATH.h"
#include "MCAL/DIO/DIO_Interface.h"
#include "HAL/LED/LED.h"
#include "HAL/LCD/LCD_Interface.h"
#include "HAL/KEYPAD/KEYPAD_Interface.h"
#include "HAL/DC_MOTOR/DC_MOTOR_Interface.h"
#include "MCAL/GI/GI_Interface.h"
#include "MCAL/EXT_INT/EXT_INT_Interface.h"
#include "MCAL/ADC/ADC_Interface.h"
#include "HAL/TEMP_SENSOR/TEMP_SENSOR_Interface.h"
#include "HAL/LDR/LDR_Interface.h"
#include "MCAL/TIMER0/TIMER0_Interface.h"
#include "MCAL/ICU/ICU_Interface.h"
#include "MCAL/WDT/WDT_Interface.h"
#include "MCAL/UART/UART_Interface.h"
#include "MCAL/SPI/SPI_Interface.h"
#include "MCAL/TWI/TWI_Interface.h"
#include "HAL/EEPROM/EEPROM_Interface.h"
#include "RTOS/RTOS_Interface.h"



void Temperature_Reading_Handler(void);
void LDR_Reading_Handler(void);
void App1(void);

u8 counter=0;

void main(void){
	DIO_INIT();
	//External interrupt configuration
	GI_Enable();
	EXT_INT_Enable(EXT_INT2);
	EXT_INT_SenseControl(EXT_INT2,FallingEdge);
	EXT_INT2_Callback(&App1);

	LCD_8bit_INIT();
	KEYPAD_INIT();

	ADC_Init();

	//Mode 1
	LCD_WriteInstruction(LCD_Clear);
	LCD_GoTo(0,1);



	while(1){

		Temperature_Reading_Handler();
		LDR_Reading_Handler();
	}



}











void App1(void){
	u8 keyPressed=0;
	u8 enteredPassword=0;
	LCD_WriteInstruction(LCD_Clear);
	LCD_GoTo(0,1);
	LCD_WriteString("1-Password: ");
	LCD_GoTo(1,2);
	LCD_WriteString("2-Login: ");
	_delay_ms(20);
	keyPressed = KEYPAD_GetKeyPressed();
	LCD_GoTo(1,2);
	while(keyPressed!='='){
	keyPressed = KEYPAD_GetKeyPressed();
	if(keyPressed!=0){
		switch(keyPressed){
		case '1':

			LCD_WriteInstruction(LCD_Clear);
			LCD_GoTo(0,1);
			LCD_WriteString("Enter your pass: ");
			LCD_GoTo(1,2);
			enteredPassword = KEYPAD_GetKeyPressed();
			LCD_WriteChar(enteredPassword);
			break;
		}
	}
	}


}

void Temperature_Reading_Handler(void)
{
	LCD_GoTo(0,1);
	LCD_WriteString("Temp:");
	u16 tempReading =TEMP_SENSOR_Reading(ADC6);
	//u8 temp8Reading = ((u8)(((u32)tempReading * 500UL) / 256UL));
	LCD_GoTo(1,5);
	LCD_Write_Int_Number(tempReading);

	LCD_GoTo(1,9);
	LCD_WriteString(" Fan:");
	LCD_GoTo(1,15);

	if(tempReading>=(u16)25){
		LCD_WriteString("ON");
	}
	else{
		LCD_WriteString("OFF");
	}
	LCD_WriteString("   ");
}

void LDR_Reading_Handler(void)
{
	LCD_GoTo(1,2);
	LCD_WriteString("LDR: ");
	u8 LDRRead = LDR_Intensity_Level(ADC7);
	u8 LDRVal = 0;
	switch(LDRRead){
	case LEVEL_1:
		DIO_SetPinValue(PORTB,PIN0,LOW);
		DIO_SetPinValue(PORTA,PIN5,LOW);
		DIO_SetPinValue(PORTA,PIN4,LOW);
		DIO_SetPinValue(PORTA,PIN3,LOW);
		LDRVal=LEVEL_1;
		break;
	case LEVEL_2:
		DIO_SetPinValue(PORTB,PIN0,HIGH);
		DIO_SetPinValue(PORTA,PIN5,LOW);
		DIO_SetPinValue(PORTA,PIN4,LOW);
		DIO_SetPinValue(PORTA,PIN3,LOW);
		LDRVal=LEVEL_2;
		break;
	case LEVEL_3:
		DIO_SetPinValue(PORTB,PIN0,HIGH);
		DIO_SetPinValue(PORTA,PIN5,HIGH);
		DIO_SetPinValue(PORTA,PIN4,LOW);
		DIO_SetPinValue(PORTA,PIN3,LOW);
		LDRVal=LEVEL_3;
		break;
	case LEVEL_4:
		DIO_SetPinValue(PORTB,PIN0,HIGH);
		DIO_SetPinValue(PORTA,PIN5,HIGH);
		DIO_SetPinValue(PORTA,PIN4,HIGH);
		DIO_SetPinValue(PORTA,PIN3,LOW);
		LDRVal=LEVEL_4;
		break;
	case LEVEL_5:
		DIO_SetPinValue(PORTB,PIN0,HIGH);
		DIO_SetPinValue(PORTA,PIN5,HIGH);
		DIO_SetPinValue(PORTA,PIN4,HIGH);
		DIO_SetPinValue(PORTA,PIN3,HIGH);
		LDRVal=LEVEL_5;
		break;
	default:
		DIO_SetPinValue(PORTB,PIN0,LOW);
		DIO_SetPinValue(PORTA,PIN5,LOW);
		DIO_SetPinValue(PORTA,PIN4,LOW);
		DIO_SetPinValue(PORTA,PIN3,LOW);
		LDRVal=0;
		break;
	}
	LCD_Write_Int_Number(LDRVal);
	LCD_WriteString(" Lights ");
}




