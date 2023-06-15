/*
 * SPI_Interface.h
 *
 *  Created on: Apr 1, 2023
 *      Author: dell
 */

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

//1-Determine data order (from LSB / MSB)
//2-Determine clock shape (polarity & phase)
//3-Select prescaler
//4-Select mode (slave/master)
void SPI_Master_Init();

void SPI_Slave_Init();

//Transmits and receives data at the same time
u8 SPI_TRANCEIVER(u8 Data);

#endif /* MCAL_SPI_SPI_INTERFACE_H_ */
