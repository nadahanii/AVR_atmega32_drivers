/* File Description: Interfaces used to control Keypad
 * File Author: Nada Hani
 * File Version: V1.0
 * Last-Modified Date: 25 Feb. 2023
 * */

#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_

/*
 * Function Description: Sets rows pins (first 4) as input and columns pins (last 4) as output.
 * 							Makes rows pins internally pulled up and columns pins are set to high.
 * Function input: N/A
 * Function return: N/A
 * */
void KEYPAD_INIT();

/*
 * Function Description: Sets a single column's pin value to low then reads all rows to find an intersection between
 * 							the current row and current column, then returns the value corresponding to the read key
 * 							, after that returns the column value to high (its initial value).
 * Function input: N/A
 * Function return: u8 (the value corresponding to the pressed key)
 * */
u8 KEYPAD_GetKeyPressed ();
#endif /* HAL_KEYPAD_KEYPAD_INTERFACE_H_ */
