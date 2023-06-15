/*
 * TIMER2_Registers.h
 *
 *  Created on: Mar 17, 2023
 *      Author: dell
 */

#ifndef TIMER2_REGISTERS_H_
#define TIMER2_REGISTERS_H_


#define TCNT2_REG *((volatile u8*)0x44)
#define OCR2_REG *((volatile u8*)0x43)
#define TCCR2_REG *((volatile u8*)0x45)
#define TIMSK_REG *((volatile u8*)0x59)
#define TIFR_REG *((volatile u8*)0x58)


#endif /* MCAL_TIMER2_TIMER2_REGISTERS_H_ */
