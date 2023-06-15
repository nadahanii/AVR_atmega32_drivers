/*
 * TWI_Interface.h
 *
 *  Created on: Apr 13, 2023
 *      Author: dell
 */

#ifndef TWI_INTERFACE_H_
#define TWI_INTERFACE_H_

enum TWI_StatusCodes{
	Successful_Start_Condition = 0x08,
	Successful_Repeated_Start_Condition = 0x10,
	Successful_Slave_Address_With_Write = 0x18,
	Successful_Data_Transmission_From_Master = 0x28,
	Successful_Slave_Address_With_Read = 0x40,
	Successful_Data_Receiving_Master = 0x50,

	Unsuccessful_Slave_Address_With_Write = 0x20,
	Unsuccessful_Data_Transmission_From_Master = 0x30,
	Unsuccessful_Slave_Address_With_Read = 0x48,
	Unsuccessful_Data_Receiving_Master = 0x58,

	Unknown_Error=0x00
};

void TWI_MasterInit();

void TWI_SlaveInit(u8 SlaveAddress);

void TWI_StartCondition();

void TWI_StopCondition();

void TWI_SendSlaveAddressWithWrite(u8 SlaveAddress);

void TWI_SendSlaveAddressWithRead(u8 SlaveAddress);

void TWI_MasterWriteData(u8 Data);

u8 TWI_MasterReadData();

void TWI_RepeatedStartCondition();

u8 TWI_ReadStatusCode();

#endif /* MCAL_TWI_TWI_INTERFACE_H_ */
