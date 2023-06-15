/* File Description: Interfaces used to control Stepper Motor
 * File Author: Nada Hani
 * File Version: V1.0
 * Last-Modified Date: 25 Feb. 2023
 * */

#ifndef STEPPER_MOTOR_INTERFACE_H_
#define STEPPER_MOTOR_INTERFACE_H_




#define Full_Step 0
#define Half_Step 1

/*
 * Function Description: Sets the stepper port's direction as output.
 * Function input: N/A
 * Function return: N/A
 * */
void STEPPER_INIT();

/*
 * Function Description: Rotates the stepper motor in a clockwise direction,
 * 							by taking full step at a time.(moving from quarter to another)
 * Function input: N/A
 * Function return: N/A
 * */
void STEPPER_ClockWise_FullStep();

/*
 * Function Description: Rotates the stepper motor in an anti-clockwise direction,
 * 							by taking full step at a time.(moving from quarter to another)
 * Function input: N/A
 * Function return: N/A
 * */
void STEPPER_AntiClockWise_FullStep();

/*
 * Function Description: Rotates the stepper motor in a clockwise direction,
 * 							by taking half step at a time. (4 main directions and another 4 between each two adjacent directions)
 * Function input: N/A
 * Function return: N/A
 * */

void STEPPER_ClockWise_HalfStep();

/*
 * Function Description: Rotates the stepper motor in an anti-clockwise direction,
 * 							by taking half step at a time. (4 main directions and another 4 between each two adjacent directions)
 * Function input: N/A
 * Function return: N/A
 * */
void STEPPER_AntiClockWise_HalfStep();

/*
 * Function Description: Stops the stepper motor from rotating
 * Function input: N/A
 * Function return: N/A
 * */
void STEPPER_Stop();

/*
 * Function Description: Makes the stepper motor rotates (by a half step OR full step),
 * 							 according to the number of steps passed in Step_Num
 * Function input: 1- Step_Num (option inputs: [1-4](Full_Step) OR [1-8](Half_Step))
 * 				   2- Step_Style (option inputs: [Full_Step](Full_Step) OR [Half_Step](Half_Step))
 * Function return: N/A
 * */

void STEPPER_STEP(u8 Step_Num,u8 Step_Style);

/*
 * Function Description: Makes the stepper motor rotates (by a half step OR full step),
 * 							 till the number of the step passed in Step_Num.
 * Function input: 1- Step_Num (option inputs: [1-4](Full_Step) OR [1-8](Half_Step))
 * 				   2- Step_Style (option inputs: [Full_Step](Full_Step) OR [Half_Step](Half_Step))
 * Function return: N/A
 * */
void STEPPER_GoToSTEP(u8 Step_Num,u8 Step_Style);

#endif /* HAL_STEPPER_MOTOR_STEPPER_MOTOR_INTERFACE_H_ */
