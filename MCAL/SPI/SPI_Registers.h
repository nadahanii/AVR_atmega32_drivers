/*
 * SPI_Registers.h
 *
 *  Created on: Apr 1, 2023
 *      Author: dell
 */

#ifndef SPI_REGISTERS_H_
#define SPI_REGISTERS_H_

#define SPDR_REG *((volatile u8*)0x2F)
#define SPSR_REG *((volatile u8*)0x2E)
#define SPCR_REG *((volatile u8*)0x2D)

#endif /* MCAL_SPI_SPI_REGISTERS_H_ */
