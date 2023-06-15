/*
 * EXT_INT_Registers.h
 *
 *  Created on: Mar 4, 2023
 *      Author: dell
 */

#ifndef EXT_INT_REGISTERS_H_
#define EXT_INT_REGISTERS_H_

#define GICR_REG *((volatile u8*) 0x5B)
#define MCUCR_REG *((volatile u8*) 0x55)
#define GIFR_REG *((volatile u8*) 0x5A)
#define MCUCSR_REG *((volatile u8*) 0x54)

enum GICR_REG_BITS{
	IVCE,
	IVSEL,
	INT2 = 5,
	INT0 = 6,
	INT1 = 7
};

enum MCUCR_REG_BITS{
	ISC00,
	ISC01,
	ISC10,
	ISC11,
	SM0,
	SM1,
	SM2,
	SE
};

enum GIFR_REG_BITS{
	INTF2 = 5,
	INTF0 = 6,
	INTF1 = 7
};

#define ISC2 6

#endif /* MCAL_EXT_INT_EXT_INT_REGISTERS_H_ */
