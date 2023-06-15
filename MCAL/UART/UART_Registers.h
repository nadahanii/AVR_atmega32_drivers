/*
 * UART_Registers.h
 *
 *  Created on: Mar 31, 2023
 *      Author: dell
 */

#ifndef UART_REGISTERS_H_
#define UART_REGISTERS_H_

#define UDR_REG   *((volatile u8*)0x2C)
#define UCSRA_REG *((volatile u8*)0x2B)
#define UCSRB_REG *((volatile u8*)0x2A)
#define UCSRC_REG *((volatile u8*)0x40)
//we don't need UBRRH_REG because the maximum baud rate
//in 8MHz clock is less than 255
#define UBRRL_REG *((volatile u8*)0x29)

#endif /* MCAL_UART_UART_REGISTERS_H_ */
