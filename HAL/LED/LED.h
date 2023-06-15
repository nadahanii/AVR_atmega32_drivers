/* File Description: Interfaces used to control a single LED
 * File Author: Nada Hani
 * File Version: V1.0
 * Last-Modified Date: 25 Feb. 2023
 * */
#ifndef LED_LED_H_
#define LED_LED_H_


/*
 * Function Description: Sets the Pin_ID in the passed Port_ID as an output pin to use it to control the LED.
 * Function input: 1- Port_ID (option inputs: [PORTA-PORTD])
 * 				   2- Pin_ID (option inputs: [PIN0-PIN7])
 * Function return: N/A
 * */
void LED_INIT(u8 Port_ID , u8 Pin_ID);

/*
 * Function Description: Passes a voltage to the passed Pin_ID to enable the LED.
 * Function input: 1- Port_ID (option inputs: [PORTA-PORTD])
 * 				   2- Pin_ID (option inputs: [PIN0-PIN7])
 * Function return: N/A
 * */
void LED_ON(u8 Port_ID , u8 Pin_ID);

/*
 * Function Description: Passes 0 volt to the passed Pin_ID to turn off the LED.
 * Function input: 1- Port_ID (option inputs: [PORTA-PORTD])
 * 				   2- Pin_ID (option inputs: [PIN0-PIN7])
 * Function return: N/A
 * */
void LED_OFF(u8 Port_ID , u8 Pin_ID);

/*
 * Function Description: Toggles the current passed value to the LED.
 * Function input: 1- Port_ID (option inputs: [PORTA-PORTD])
 * 				   2- Pin_ID (option inputs: [PIN0-PIN7])
 * Function return: N/A
 * */
void LED_TOG(u8 Port_ID , u8 Pin_ID);

#endif /* HAL_LED_LED_H_ */
