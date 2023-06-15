/*
 * RTOS_Interface.h
 *
 *  Created on: May 5, 2023
 *      Author: dell
 */

#ifndef RTOS_INTERFACE_H_
#define RTOS_INTERFACE_H_

typedef struct Task{
	u8 Priority;
	u16 Periodicity;
	u16 FirstDelay;
	 void(*PF)(void);
}TASK_TBC;



//1-init timer
//2-restart schedule in timer's callback
void RTOS_Init();

void RTOS_CreateTask(u8 Priority, u16 Periodicity, u16 FirstDelay, void(*PF)(void));

void RTOS_SchedulerStart();

#endif /* RTOS_RTOS_INTERFACE_H_ */
