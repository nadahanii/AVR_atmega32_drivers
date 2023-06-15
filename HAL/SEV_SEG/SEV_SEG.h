/* File Description: Interfaces used to control Seven Segment HW
 * File Author: Nada Hani
 * File Version: V1.0
 * Last-Modified Date: 25 Feb. 2023
 * */

#ifndef SEV_SEG_H_
#define SEV_SEG_H_


/*
 * Function Description: Sets the passed port as an output port to send data through it.
 * Function input: Port_ID (option inputs: [PORTA-PORTD])
 * Function return: N/A
 * */
void SEV_SEG_INIT(u8 Port_ID);

void SEV_SEG_COUNT_UP(u8 Start_Num,u8 End_Num,u16 Delay,u8 Port_ID);

void SEV_SEG_COUNT_DOWN(u8 Start_Num,u8 End_Num,u16 Delay,u8 Port_ID);

void SEV_SEG_DISPLAY_NUM(u8 Number,u8 Port_ID);

void SEV_SEG_TOG_NUM(u8 Number,u8 Port_ID,u16 Delay);


#endif /* HAL_SEV_SEG_SEV_SEG_H_ */
