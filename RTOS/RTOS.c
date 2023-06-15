/*
 * RTOS.c
 *
 *  Created on: May 5, 2023
 *      Author: dell
 */
#include "../STD_LIB/STD_TYPES.h"
#include "../MCAL/TIMER0/TIMER0_Interface.h"
#include "RTOS_Interface.h"
#include "RTOS_Config.h"

TASK_TBC ArrOfTasks[NumberOfTasks];

void RTOS_Init()
{
	//Set callback function of timer to restart the scheduler
	TIMER0_CallBack(&RTOS_SchedulerStart);
	//timer0 init
	TIMER0_Init();
	//timer0 start
	TIMER0_Start(PRESCALER_8);
	//set tick time
	TIMER0_SetTime(Tick_Time);
}

void RTOS_CreateTask(u8 Priority, u16 Periodicity, u16 FirstDelay, void(*PF)(void))
{
	if(Priority<NumberOfTasks){
		ArrOfTasks[Priority].FirstDelay = FirstDelay;
		ArrOfTasks[Priority].Periodicity = Periodicity;
		ArrOfTasks[Priority].PF = PF;
	}
	else{
		//report error
	}
}

void RTOS_SchedulerStart()
{
	for(u8 counter=0;counter<NumberOfTasks;counter++){
		if(ArrOfTasks[counter].FirstDelay==0){
			//call function directly
			ArrOfTasks[counter].PF();
			//update the called functions's periodicity
			ArrOfTasks[counter].FirstDelay = ArrOfTasks[counter].Periodicity-Tick_Time;
		}
		else{
			ArrOfTasks[counter].FirstDelay-=Tick_Time;
		}
	}
}
