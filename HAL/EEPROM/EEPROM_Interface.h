/*
 * EEPROM_Interface.h
 *
 *  Created on: Apr 14, 2023
 *      Author: dell
 */

#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_

void EEPROM_WriteByte(u8 Page, u8 Location, u8 Data);

u8 EEPROM_ReadByte(u8 Page, u8 Location);

#endif /* HAL_EEPROM_EEPROM_INTERFACE_H_ */
