/*
 * ICU_Registers.h
 *
 *  Created on: Mar 29, 2023
 *      Author: dell
 */

#ifndef ICU_REGISTERS_H_
#define ICU_REGISTERS_H_

#define TCCR1A_REG *((volatile u8*)0x4F)
#define TCCR1B_REG *((volatile u8*)0x4E)
//points at low but it's 16 bits, so points at both low and high
#define TCNT1_REG *((volatile u16*)0x4C)
#define OCR1A_REG *((volatile u16*)0x4A)
#define OCR1B_REG *((volatile u16*)0x48)
#define ICR1_REG  *((volatile u16*)0x46)

#define TIMSK_REG *((volatile u8*)0x59)
#define TIFR_REG *((volatile u8*)0x58)

#endif /* MCAL_ICU_ICU_REGISTERS_H_ */
