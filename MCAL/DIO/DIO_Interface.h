/* File Description: Interfaces used to control DIO Peripheral
 * File Author: Nada Hani
 * File Version: V1.0
 * Last-Modified Date: 25 Feb. 2023
 * */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

enum DIO_ErrorState{
	DIO_OK,
	DIO_PinOutOfRange,
	DIO_PortOutOfRange,
	DIO_ValueIncorrect,
	DIO_DirectionIncorrect,
	DIO_NOTOK
};

// Constants that will be further used to control ports and pins in the DIO
#define OUTPUT 1
#define INPUT 0

#define OUTPUT_PORT 0xFF
#define INPUT_PORT 0x00

#define HIGH   1
#define LOW   0

#define HIGH_PORT 0xFF
#define LOW_PORT 0x00

#define PIN0   0
#define PIN1   1
#define PIN2   2
#define PIN3   3
#define PIN4   4
#define PIN5   5
#define PIN6   6
#define PIN7   7

#define PORTA  0
#define PORTB  1
#define PORTC  2
#define PORTD  3

/*
 * Function Description: Sets all DIO ports' directions and pins' values to the ones mentioned
 * 							in the config file.
 * Function input: N/A
 * Function return: N/A
 * */
void DIO_INIT(void);

/*
 * Function Description: Sets direction of the pin passed in Pin_ID to the value passed in Pin_Dir.
 *
 * Function input: 1- Port_ID (option inputs: [PORTA-PORTD])
 * 				   2- Pin_ID (option inputs: [PIN0-PIN7])
 * 				   3- Pin_Dir (option inputs: [INPUT,OUTPUT]
 *
 * Function return: u8 (the current DIO state, a value from the DIO_ErrorState enum)
 * */
u8 DIO_SetPinDirection(u8 Port_ID , u8 Pin_ID , u8 Pin_Dir);

/*
 * Function Description: Sets the pin passed in Pin_ID to the value passed in Pin_Val.
 *
 * Function input: 1- Port_ID (option inputs: [PORTA-PORTD])
 * 				   2- Pin_ID (option inputs: [PIN0-PIN7])
 * 				   3- Pin_Dir (option inputs: [HIGH,LOW]
 *
 * Function return: u8 (the current DIO state, a value from the DIO_ErrorState enum)
 * */
u8 DIO_SetPinValue(u8 Port_ID , u8 Pin_ID , u8 Pin_Val);

/*
 * Function Description: Reads the pin passed in Pin_ID and places its value in the PinReading variable.
 *
 * Function input: 1- Port_ID (option inputs: [PORTA-PORTD])
 * 				   2- Pin_ID (option inputs: [PIN0-PIN7])
 * 				   3- PinReading (option inputs: pointer to an u8 variable)
 *
 * Function return: u8 (the current DIO state, a value from the DIO_ErrorState enum)
 * */
u8 DIO_ReadPin(u8 Port_ID , u8 Pin_ID,u8* PinReading);

/*
 * Function Description: Toggles the current value in the pin passed in Pin_ID.
 *
 * Function input: 1- Port_ID (option inputs: [PORTA-PORTD])
 * 				   2- Pin_ID (option inputs: [PIN0-PIN7])
 *
 * Function return: u8 (the current DIO state, a value from the DIO_ErrorState enum)
 * */
u8 DIO_TogglePin(u8 Port_ID , u8 Pin_ID);

/*
 * Function Description: Sets the direction of the port passed in Port_ID to the value passed in Port_Dir.
 *
 * Function input: 1- Port_ID (option inputs: [PORTA-PORTD])
 * 				   2- Port_Dir (option inputs: [INPUT_PORT,OUTPUT_PORT])
 *
 * Function return: u8 (the current DIO state, a value from the DIO_ErrorState enum)
 * */
u8 DIO_SetPortDirection(u8 Port_ID  , u8 Port_Dir);

/*
 * Function Description: Sets the port passed in Port_ID to the value passed in Port_Val.
 *
 * Function input: 1- Port_ID (option inputs: [PORTA-PORTD])
 * 				   2- Port_Val (option inputs: [HIGH_PORT,LOW_PORT,u8 value to save in the port])
 *
 * Function return: u8 (the current DIO state, a value from the DIO_ErrorState enum)
 * */
u8 DIO_SetPortValue(u8 Port_ID , u8 Port_Val);

/*
 * Function Description: Reads the port passed in Port_ID and places its value in the PortReading variable.
 *
 * Function input: 1- Port_ID (option inputs: [PORTA-PORTD])
 * 				   2- PortReading (option inputs: pointer to an u8 variable)
 *
 * Function return: u8 (the current DIO state, a value from the DIO_ErrorState enum)
 * */
u8 DIO_ReadPort(u8 Port_ID,u8* PortReading);

/*
 * Function Description: Toggles the current value in the port passed in Port_ID.
 *
 * Function input: 1- Port_ID (option inputs: [PORTA-PORTD])
 *
 * Function return: u8 (the current DIO state, a value from the DIO_ErrorState enum)
 * */
u8 DIO_TogglePort(u8 Port_ID);

#endif /* DIO_INTERFACE_H_ */
