/*
 * SPI.c
 *
 *  Created on: Apr 1, 2023
 *      Author: dell
 */
#include "../../STD_LIB/STD_TYPES.h"
#include "../../STD_LIB/BIT_MATH.h"
#include "SPI_Interface.h"
#include "SPI_Config.h"
#include "SPI_Registers.h"
#include "../DIO/DIO_Interface.h"

void SPI_Master_Init()
{
	//0-Pins initialization
	DIO_SetPinDirection(PORTB,PIN5,OUTPUT); //MOSI
	DIO_SetPinDirection(PORTB,PIN6,INPUT); //MISO
	DIO_SetPinDirection(PORTB,PIN7,OUTPUT); //SCK
	//Slave select can be any DIO pin

	//1-Determine data order (LSB/MSB)
#if SPI_DATA_ORDER == SPI_DATA_LSB
	SET_BIT(SPCR_REG,5);
#elif SPI_DATA_ORDER == SPI_DATA_MSB
	CLR_BIT(SPCR_REG,5);
#endif

	//2-Determine clock shape
	CLR_BIT(SPCR_REG,3);
	SET_BIT(SPCR_REG,2);

	//3-Determine mode (Master)
	SET_BIT(SPCR_REG,4);

	//4-Enable SPI Interrupt
	SET_BIT(SPCR_REG,7);

	//5-Enable SPI Circuit
	SET_BIT(SPCR_REG,6);

	//6-Determine clock prescaler
	SET_BIT(SPCR_REG,0);
	CLR_BIT(SPCR_REG,1);
}

void SPI_Slave_Init()
{
	//0-Pins initialization
	DIO_SetPinDirection(PORTB,PIN4,INPUT); //SS
	DIO_SetPinDirection(PORTB,PIN5,INPUT); //MOSI
	DIO_SetPinDirection(PORTB,PIN6,OUTPUT); //MISO
	DIO_SetPinDirection(PORTB,PIN7,INPUT); //SCK

	//1-Determine data order (LSB/MSB)
#if SPI_DATA_ORDER == SPI_DATA_LSB
	SET_BIT(SPCR_REG,5);
#elif SPI_DATA_ORDER == SPI_DATA_MSB
	CLR_BIT(SPCR_REG,5);
#endif

	//2-Determine clock shape
	//Both master and slave have the same clock shape
	//because this protocol supports full duplex data transmission
	CLR_BIT(SPCR_REG,3);
	SET_BIT(SPCR_REG,2);

	//3-Determine mode (Slave)
	CLR_BIT(SPCR_REG,4);

	//4-Enable SPI Interrupt
	SET_BIT(SPCR_REG,7);

	//5-Enable SPI Circuit
	SET_BIT(SPCR_REG,6);

	//6-Determine clock prescaler
	SET_BIT(SPCR_REG,0);
	CLR_BIT(SPCR_REG,1);
}

u8 SPI_TRANCEIVER(u8 Data)
{
#if SPI_MODE == MASTER
	//To transmit data effectively ,put SS pin to low
	//when in master mode.
	DIO_SetPinValue(PORTB,PIN4,LOW);

	//Sent data
	SPDR_REG = Data;

	//Waiting till transmission complete.(flag ==1)
	while(GET_BIT(SPSR_REG,7)==0);
	DIO_SetPinValue(PORTB,PIN4,HIGH);//SS pin


	//Clearing interrupt flag to make sure it is
	//ready for next transmission.
	SET_BIT(SPSR_REG,7);

	//Both transmission and receiving are completed
	//,so return received data.
	return SPDR_REG;
#elif SPI_MODE == SLAVE

	//Sent data
	SPDR_REG = Data;

	//Waiting till transmission complete.(flag ==1)
	while(GET_BIT(SPSR_REG,7)==0);

	//Clearing interrupt flag to make sure it is
	//ready for next transmission.
	SET_BIT(SPSR_REG,7);

	//Both transmission and receiving are completed
	//,so return received data.
	return SPDR_REG;
#endif
}
