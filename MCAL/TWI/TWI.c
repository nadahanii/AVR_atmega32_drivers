/*
 * TWI.c
 *
 *  Created on: Apr 13, 2023
 *      Author: dell
 */
#include "../../STD_LIB/STD_TYPES.h"
#include "../../STD_LIB/BIT_MATH.h"
#include "TWI_Interface.h"
#include "TWI_Registers.h"
#include "TWI_Config.h"


void TWI_MasterInit()
{
	//Set clock to 200kHz
	 TWBR_REG = 6;

	//Enable ACK
	SET_BIT(TWCR_REG,6);

	//Enable TWI circuit
	SET_BIT(TWCR_REG,2);
}

void TWI_SlaveInit(u8 SlaveAddress)
{
	//Set slave address
	//Shifted left by one to fill the bits from 1 to 7
	TWAR_REG = SlaveAddress<<1;

	//Enable ACK
	SET_BIT(TWCR_REG,6);

	//Enable TWI circuit
	SET_BIT(TWCR_REG,2);
}

void TWI_StartCondition()
{

	//Start condition
	SET_BIT(TWCR_REG,5);
	//Clear the jobs' flag
	SET_BIT(TWCR_REG,7);

	//Wait till flag is set to make
	//sure that start condition is sent successfully
	while(GET_BIT(TWCR_REG,7)==0);

	//Check on the start condition status' existence

	//AND the register with 0xF8 to get only the most 5 bits
	//Wait till successful-start-condition status arrives
	while((TWSR_REG & 0XF8) != Successful_Start_Condition);


//	else{
//		//report error
//	}
}

void TWI_StopCondition()
{


	//Stop condition
	SET_BIT(TWCR_REG,4);
	//Clear the jobs' flag
	SET_BIT(TWCR_REG,7);

	//Wait till flag is set to make
	//sure that stop condition is sent successfully
	//while(GET_BIT(TWCR_REG,7)==0);
}


void TWI_SendSlaveAddressWithWrite(u8 SlaveAddress)
{
	//Load slave address
	//Shifted left by one to fill the bits from 1 to 7
	TWDR_REG = SlaveAddress<<1;

	//Set write operation
	CLR_BIT(TWDR_REG,0);

	//Clear the jobs' flag
	SET_BIT(TWCR_REG,7);

	//Wait till flag is set to make
	//sure that data is loaded successfully
	while(GET_BIT(TWCR_REG,7)==0);

	//AND the register with 0xF8 to get
		//only the most 5 bits
	//Wait till successful-transmission status arrives
	while((TWSR_REG & 0XF8) != Successful_Slave_Address_With_Write);
}

void TWI_SendSlaveAddressWithRead(u8 SlaveAddress)
{
	//Load slave address
	//Shifted left by one to fill the bits from 1 to 7
	TWDR_REG = SlaveAddress<<1;

	//Set read operation
	SET_BIT(TWDR_REG,0);

	//Clear the jobs' flag
	SET_BIT(TWCR_REG,7);

	//Wait till flag is set to make
	//sure that slave address is loaded successfully
	while(GET_BIT(TWCR_REG,7)==0);

	//AND the register with 0xF8 to get
		//only the most 5 bits
	//Wait till successful-reading status arrives
	while((TWSR_REG & 0XF8) != Successful_Slave_Address_With_Read);
}

void TWI_MasterWriteData(u8 Data)
{
	//Write data in TWDR
	TWDR_REG = Data;

	//Clear the jobs' flag
	SET_BIT(TWCR_REG,7);

	//Wait till flag is set to make
	//sure that data is loaded successfully
	while(GET_BIT(TWCR_REG,7)==0);

	//AND the register with 0xF8 to get
		//only the most 5 bits
	//Wait till successful-data-Transmission status arrives
	while((TWSR_REG & 0XF8) != Successful_Data_Transmission_From_Master);
}

u8 TWI_MasterReadData()
{

	//Clear the jobs' flag
	SET_BIT(TWCR_REG,7);

	//Wait till flag is set to make
	//sure that data is received in the TWDR register
	while(GET_BIT(TWCR_REG,7)==0);

	//AND the register with 0xF8 to get
		//only the most 5 bits
	//Wait till successful-data-Receiving status arrives
	while((TWSR_REG & 0XF8) != Successful_Data_Receiving_Master);

	return TWDR_REG;
}

void TWI_RepeatedStartCondition()
{
	//Start condition
	SET_BIT(TWCR_REG,5);
	//Clear the jobs' flag
	SET_BIT(TWCR_REG,7);

	//Wait till flag is set to make
	//sure that start condition is sent successfully
	while(GET_BIT(TWCR_REG,7)==0);

	//Check on the start condition status' existence

	//AND the register with 0xF8 to get only the most 5 bits
	//Wait till successful-restart-condition status arrives
	while((TWSR_REG & 0XF8) != Successful_Repeated_Start_Condition);
}

u8 TWI_ReadStatusCode()
{
	u8 StatusCode = (TWSR_REG & 0XF8);
	switch(StatusCode)
	{
	case Successful_Start_Condition:
		return Successful_Start_Condition;
		break;
	case Successful_Repeated_Start_Condition:
		return Successful_Repeated_Start_Condition;
		break;
	case Successful_Slave_Address_With_Write:
		return Successful_Slave_Address_With_Write;
		break;
	case Successful_Data_Transmission_From_Master:
		return Successful_Data_Transmission_From_Master;
		break;
	case Successful_Slave_Address_With_Read:
		return Successful_Slave_Address_With_Read;
		break;
	case Successful_Data_Receiving_Master:
		return Successful_Data_Receiving_Master;
		break;
	case Unsuccessful_Slave_Address_With_Write:
		return Unsuccessful_Slave_Address_With_Write;
		break;
	case Unsuccessful_Data_Transmission_From_Master:
		return Unsuccessful_Data_Transmission_From_Master;
		break;
	case Unsuccessful_Slave_Address_With_Read:
		return Unsuccessful_Slave_Address_With_Read;
		break;
	case Unsuccessful_Data_Receiving_Master:
		return Unsuccessful_Data_Receiving_Master;
		break;

	default:
		return Unknown_Error;
		break;
	}
}
