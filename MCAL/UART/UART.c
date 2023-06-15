/*
 * UART.c
 *
 *  Created on: Mar 31, 2023
 *      Author: dell
 */
#include "../../STD_LIB/STD_TYPES.h"
#include "../../STD_LIB/BIT_MATH.h"
#include "UART_Interface.h"
#include "UART_Registers.h"
#include "UART_Config.h"

void UART_Init()
{
	//Select UCSRC register instead of UBRRH
	SET_BIT(UCSRC_REG,7);

	//1-Select stop bit(1/2)
	SET_BIT(UCSRC_REG,3);//2 bits

	//2-Select parity check
	//disabled
	CLR_BIT(UCSRC_REG,4);
	CLR_BIT(UCSRC_REG,5);

	//3-Determine character size (8 bits)
	SET_BIT(UCSRC_REG,1);
	SET_BIT(UCSRC_REG,2);
	CLR_BIT(UCSRB_REG,2);

	//4-Select mode (Synchronous/Asynchronous)
	CLR_BIT(UCSRC_REG,6); //Asynchronous

	//5-Determine baud rate (9600)
	UBRRL_REG = 51;

	//6-Enable Tx circuit (Transmitting)
	SET_BIT(UCSRB_REG,3);

	//7-Enable Rx circuit (Receiving)
	SET_BIT(UCSRB_REG,4);


}


void UART_Transmit(u8 Data)
{
	//1-Wait till UDR register is empty
	while(GET_BIT(UCSRA_REG,5) == 0);

	//2-If empty, put data in UDR register
	UDR_REG = Data;

	//3-Wait till transmitting is complete (Transmit compete flag is 1)
	while(GET_BIT(UCSRA_REG,6)==0);
}

u8 UART_Receive()
{
	//1-Wait till receiving is completed
	while(GET_BIT(UCSRA_REG,7)==0){
		//put time out then break and report error after
		//break;
	}

	//2-If completed, return data in UDR register
	return UDR_REG;
}
