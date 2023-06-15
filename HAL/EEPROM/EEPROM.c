/*
 * EEPROM.c
 *
 *  Created on: Apr 14, 2023
 *      Author: dell
 */

#include "../../STD_LIB/STD_TYPES.h"
#include "../../STD_LIB/BIT_MATH.h"
#include "EEPROM_Interface.h"
#include "EEPROM_Config.h"
#include "../../MCAL/TWI/TWI_Interface.h"


void EEPROM_WriteByte(u8 Page, u8 Location, u8 Data)
{
	//Start condition
	TWI_StartCondition();

	//Send slave address with write
	/*
	 * OR the fixed address with the A2 value after shifting A2 left by 2,
	 * the OR the result with the page number after ANDing page number with 3 to make
	 * 	sure that only first 2 bits are used.*/

	u8 SlaveAddress = (EEPROM_FIXED_ADDRESS | (EEPROM_A2_VALUE<<2)) | (Page&3);
	TWI_SendSlaveAddressWithWrite(SlaveAddress);

	//Send location to write on
	TWI_MasterWriteData(Location);
	//Write data
	TWI_MasterWriteData(Data);
	//Stop condition
	TWI_StopCondition();
}

u8 EEPROM_ReadByte(u8 Page, u8 Location)
{
	u8 Data=0;
	u8 SlaveAddress = (EEPROM_FIXED_ADDRESS | (EEPROM_A2_VALUE<<2)) | (Page&3);

	//Start condition
	TWI_StartCondition();

	//Write slave address with write
	TWI_SendSlaveAddressWithWrite(SlaveAddress);
	//Send location to write on (access)
	TWI_MasterWriteData(Location);
	//Repeat start condition to read
	TWI_StartCondition();
	//Send slave address with read
	TWI_SendSlaveAddressWithRead(SlaveAddress);
	//Send location to read from
	TWI_MasterWriteData(Location);
	//Receive data
	Data = TWI_MasterReadData();
	//Stop condition
	TWI_StopCondition();

	return Data;
}
