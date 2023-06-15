/*
 * UART_Interface.h
 *
 *  Created on: Mar 31, 2023
 *      Author: dell
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

//1- Enable Sender and Transmitter circuits
//2- Determine baud rate
//3- Determine whether to use parity check, and its type if enabled
//4- Determine stop bit size
//5- Synchronous or Asynchronous
void UART_Init();

//Wait till UDR register is empty, then put Data in it
void UART_Transmit(u8 Data);

//Read from UDR register if Rx flag is high
u8 UART_Receive();

#endif /* MCAL_UART_UART_INTERFACE_H_ */
