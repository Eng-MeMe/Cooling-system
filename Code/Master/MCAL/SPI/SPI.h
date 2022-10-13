#ifndef MCAL_SPI_SPI_H_
#define MCAL_SPI_SPI_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/delay.h>
#include "../DIO/DIO.h"
#include "../../UTLIS/Common_Macros.h"
#include "../../UTLIS/Std_Types.h"

/***************************************************************************************************/
/****************************************Function Prototypes****************************************/

void SPI_InitMaster (void);				// Function to initialize the master
void SPI_InitSlave (void);
void SPI_sendByte (u8 data);			// Function to send data byte
u8 SPI_receiveByte (void);				// Function to receive data byte
void SPI_sendString (const u8 *str);	// Function to send string
void SPI_receiveString (u8 *str);		// Function to receive string

#endif /* MCAL_SPI_SPI_H_ */
