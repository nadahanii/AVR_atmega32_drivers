/* File Description: Interfaces used to control LCD Screen
 * File Author: Nada Hani
 * File Version: V1.0
 * Last-Modified Date: 25 Feb. 2023
 * */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_



/*
 * Values of required instructions to get the LCD prepared for showing data*/
#define LCD_Function_Set   0b00111000
#define LCD_Display_On_Off 0b00001100
#define LCD_Set_Entry_Mode 0b00000110
#define LCD_Clear          0x01

/*
 * Constant values from the LCD's data sheet to manipulate the typing cursor*/
#define LCD_Line_1		   128
#define LCD_Line_2		   191
#define Move_To_CGRAM	   64
#define Zero_ASCI		   48

/*
 * Function Description: Executes the required instructions (with the suitable delays between them),
 * 							to get the LCD prepared for showing data.
 * Function input: N/A
 * Function return: N/A
 * */
void LCD_8bit_INIT(void);

/*
 * Function Description: Transports the passed character through the data port and triggers the Enable
 * 							pin to write on LCD at its falling edge.
 * Function input: 1- data (option inputs: [A-Z]+[a-z]+
 * 								a bunch of special characters mentioned in the datasheet including [.,!?=+-#%*..etc.])
 * Function return: N/A
 * */
void LCD_WriteChar(u8 data);

/*
 * Function Description: Loops over the passed array of characters (that are predefined in the LCD's CGROM),
 * 							and transports each character through the data port and triggers the Enable
 * 							pin to write on LCD at its falling edge.
 * Function input: 1- string (option inputs: pointer to an array of characters)
 *
 * Function return: N/A
 * */
void LCD_WriteString(u8* string);

/*
 * Function Description: Moves the typing cursor to the passed coordinates on the LCD screen.
 * Function input: 1- x (option inputs: [0-16](this indicates the number of horizontal places that can be written on, in each line))
 * 				   2- y (option inputs: [1,2] (this indicates the number of vertical lines in the LCD))
 * Function return: N/A
 * */
void LCD_GoTo(u8 x,u8 y);

/*
 * Function Description:Loops over the passed array of characters (that are unique and new to the LCD's CGROM),
 * 							and transports each character to the CGRAM, then loops over them to store each one of them
 * 							in the DDRAM to be viewed.
 * Function input: 1- string (option inputs: pointer to an array of hex/binary values to the custom characters)
 *
 * Function return: N/A
 * */
void LCD_Write_Custom_Char(u8* CustomArr,u8 x,u8 y);

/*
 * Function Description: Writes integer numbers on the LCD up to the number 9999
 * Function input: 1- number (option inputs: [0-9999])
 *
 * Function return: N/A
 * */
void LCD_Write_Int_Number(u32 number);
//void LCD_WriteIntNumber(u32 number);
/*
 * Function Description: Writes float numbers on the LCD that 8 digits total (including the floating point)
 * Function input: 1- number (option inputs: [00.00-99.99] OR [0.0-9.9] OR [00.0-99.9] OR [0.00-9.99])
 *
 * Function return: N/A
 * */
void LCD_Write_Float_Number(f64 number);

/*
 * Function Description: Places the passed instruction on the data port , then triggers the Enable
 * 							pin to write on LCD at its falling edge.
 * Function input: 1- instruction (option inputs: 8 bits value OR one hex value)
 *
 * Function return: N/A
 * */
void LCD_WriteInstruction(u8 instruction);



#endif /* HAL_LCD_LCD_INTERFACE_H_ */
