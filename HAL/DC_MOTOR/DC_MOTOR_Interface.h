/* File Description: Interfaces used to control DC Motor
 * File Author: Nada Hani
 * File Version: V1.0
 * Last-Modified Date: 25 Feb. 2023
 * */

#ifndef DC_MOTOR_INTERFACE_H_
#define DC_MOTOR_INTERFACE_H_

//Possible motor states that could happen
enum MOTOR_STATE {
	MOTOR_OK,
	MOTOR_NOTOK,
	MOTOR_SC, //short circuit
	MOTOR_OC //open circuit
};

/*
 * Function Description: Sets the pins connected to the motor as output pins to control the voltage they provide.
 * Function input: N/A
 * Function return: u8 (the current motor state, a value from the MOTOR_STATE enum)
 * */
u8 MOTOR_INIT();

/*
 * Function Description: Provides high voltage on the first pin and low voltage on the second,
 * 							to enable rotation in clockwise direction.
 * Function input: N/A
 * Function return: u8 (the current motor state, a value from the MOTOR_STATE enum)
 * */
u8 MOTOR_ClockWise();

/*
 * Function Description: Provides high voltage on the second pin and low voltage on the first,
 * 							to enable rotation in anti-clockwise direction.
 * Function input: N/A
 * Function return: u8 (the current motor state, a value from the MOTOR_STATE enum)
 * */
u8 MOTOR_AntiClockWise();

/*
 * Function Description: Provides low voltage on both pins to stop motor rotation.
 * Function input: N/A
 * Function return: u8 (the current motor state, a value from the MOTOR_STATE enum)
 * */
u8 MOTOR_Stop();

#endif /* HAL_DC_MOTOR_DC_MOTOR_INTERFACE_H_ */
