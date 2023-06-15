/*
 * LCD.c
 *
 *  Created on: Feb 17, 2023
 *      Author: dell
 */

#include "../../STD_LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "LCD_Interface.h"
#include "LCD_Config.h"
#include <avr/delay.h>


void LCD_8bit_INIT(void){
	DIO_INIT();
	_delay_ms(35);
	LCD_WriteInstruction(LCD_Function_Set);
	_delay_ms(1);
	LCD_WriteInstruction(LCD_Display_On_Off);
	_delay_ms(1);
	LCD_WriteInstruction(LCD_Clear);
	_delay_ms(10);
	LCD_WriteInstruction(LCD_Set_Entry_Mode);
	_delay_ms(1);
}

void LCD_WriteChar(u8 data){
	//set RS pin to low to select data
	DIO_SetPinValue(Control_Port,RS,HIGH);

	//set RW pin to low to write
	DIO_SetPinValue(Control_Port,RW,LOW);

	//load character on data port
	DIO_SetPortValue(Data_Port,data);

	//set Enable in writing mode at falling edge
	DIO_SetPinValue(Control_Port,E,HIGH);
	_delay_ms(1);
	DIO_SetPinValue(Control_Port,E,LOW);
	_delay_ms(5);
}

void LCD_WriteString(u8* string){
	u8 iteration=0;
	while(string[iteration]!='\0'){
		LCD_WriteChar(string[iteration++]);
	}
}

void LCD_GoTo(u8 x,u8 y){
	if(x>=0 && x<=16 ){
		switch(y){
		case 1:
			LCD_WriteInstruction(LCD_Line_1+x);
			break;
		case 2:
			LCD_WriteInstruction(LCD_Line_2+x);
			break;
		default:
			break;
		}

	}
}

void LCD_Write_Custom_Char(u8* CustomArr,u8 x,u8 y){
	//we moved from DDRAM to CGRAM by the AC
	LCD_WriteInstruction(Move_To_CGRAM);

	for(u8 i=0;i<16;i++){
		LCD_WriteChar(CustomArr[i]);
	}
	//move from CGRAM to DDRAM
	//LCD_WriteInstruction(LCD_Line_1);
	LCD_GoTo(x,y);
	LCD_WriteChar(0);
	/*for(u8 i=0;i<8;i++){
		LCD_WriteChar(i);
		_delay_ms(10);
	}*/

}
/*void LCD_WriteIntNumber(f64 number)
{

}*/

//can write up to 9999
void LCD_Write_Int_Number(u32 number){
	if((u32)number<=(u32)9){
		LCD_WriteChar(Zero_ASCI+number);
	}
	else if((u32)number<=(u32)99){
		u8 TenthValue = number/10;
		LCD_WriteChar(Zero_ASCI+TenthValue);
		u8 UnitValue = number%10;
		LCD_WriteChar(Zero_ASCI+UnitValue);
	}
	else if((u32)number<=(u32)999){
		u8 HundredthValue = number/100;
		LCD_WriteChar(Zero_ASCI+HundredthValue);
		u8 First2Digits = number/10;
		u8 TenthValue = First2Digits%10;
		LCD_WriteChar(Zero_ASCI+TenthValue);
		u8 UnitValue = number%10;
		LCD_WriteChar(Zero_ASCI+UnitValue);

	}
	else if((u32)number<=(u32)9999){
		u8 ThousandValue = number/1000;
		LCD_WriteChar(Zero_ASCI+ThousandValue);

		u8 First2Digits = number/100;
		u8 HundredthValue = First2Digits%10;
		LCD_WriteChar(Zero_ASCI+HundredthValue);

		u16 First3Digits = number/10;
		u8 TenthValue =(u8) (First3Digits%10);
		LCD_WriteChar(Zero_ASCI+TenthValue);

		u8 UnitsValue = number%10;
		LCD_WriteChar(Zero_ASCI+UnitsValue);

	}

}

//can write up to 2 decimals and 5 positions after the floating point
void LCD_Write_Float_Number(f64 number){
	s8 i=0,j=0;
	u32 x=number;
	u8 base_NUM[10]={0};
	f64 y=0;
	if (number<0)
	{
		number*=-1;
		x=number;
		LCD_WriteChar('-');
	}
	y=(((number+1.0)-x)*10000000);
	while(x !=0)
	{
		base_NUM[i++] = x % 10;
		x/=10;
	}
	u8 k=i--;
	while(i>=0)
	{
		LCD_WriteChar(base_NUM[i--]+48);
	}
	u8 F_NUM[10]={0};
	i=0;
	u32 z=y;
	LCD_WriteChar('.');
	while(z !=0)
	{
		F_NUM[i++] = z % 10;
		z/=10;
	}
	i-=2;
	for(j=0;j<10;j++)
	{
		if(F_NUM[j]==0)
		{
			F_NUM[j]='k';
		}
		else
		{
			break;
		}
	}
	while(F_NUM[i]!='k'&& k!=7)
	{
		LCD_WriteChar(F_NUM[i--]+48);
		k++;
	}

	//separate decimal part
	/*u16 DecValue =  Number;
	LCD_Write_Int_Number((u32)DecValue);

	//convert floating to a bigger decimal for easier parsing
	u32 IntValue =(u32) (Number *100); //e.g. 27.8 => 2780

	u8 SecondAfterDot = IntValue%10; //last digit
	u32 FirstThreeDigits = IntValue/10; //decimal part + first digit after floating point
	u8 FirstAfterDot = FirstThreeDigits%10;

	LCD_WriteChar('.');
	LCD_Write_Int_Number((u32)FirstAfterDot);
	LCD_Write_Int_Number((u32)SecondAfterDot);*/

}

void LCD_WriteInstruction(u8 instruction){

	//set RS pin to low to select an instruction
	DIO_SetPinValue(Control_Port,RS,LOW);

	//set RW pin to low to write
	DIO_SetPinValue(Control_Port,RW,LOW);

	//load instruction on data port
	DIO_SetPortValue(Data_Port,instruction);

	//set Enable in writing mode at falling edge
	DIO_SetPinValue(Control_Port,E,HIGH);
	_delay_ms(1);
	DIO_SetPinValue(Control_Port,E,LOW);
	_delay_ms(5);


}
