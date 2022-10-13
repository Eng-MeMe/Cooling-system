#include "SPI.h"

/****************************************************************************************************/
/*****************************************Function Definition****************************************/

void SPI_InitMaster (void)				// Function to initialize the master
{
	/*
	 * SS >> o/p pin
	 * MOSI >> o/p pin
	 * MISO >> i/p pin
	 * SCLK >> o/p pin
	 */
	DDRB |= (1<<4);
	DDRB |= (1<<5);
	DDRB &= (~(1<<6));
	DDRB |= (1<<7);

	SPCR = (1 <<SPE) | (1<<MSTR); 		//Enable SPI + Enable Master + SPI clock = F_CPU / 4
}

void SPI_InitSlave (void)
{
	/*
	 * SS >> i/p pin
	 * MOSI >> i/p pin
	 * MISO >> o/p pin
	 * SCLK >> i/p pin
	 */

	DDRB &= (~(1<<4));
	DDRB &= (~(1<<5));
	DDRB |= (1<<6);
	DDRB &= (~(1<<7));

	SPCR = (1 <<SPE); 					//Enable SPI + Enable Slave + SPI clock = F_CPU / 4
}

void SPI_sendByte (u8 data)				// Function to send data byte
{
	SPDR = data;						// Set data at SPI data register
	while (BIT_IS_CLEAR(SPSR,SPIF));	//Polling SPI flag = 1
}

u8 SPI_receiveByte (void)				// Function to receive data byte
{
	while (BIT_IS_CLEAR(SPSR,SPIF));	//Polling SPI flag = 1
	return SPDR; 						//return the received data from SPI data register
}

void SPI_sendString (const u8 *str)		// Function to send string
{
	u8 i = 0;
	while (str[i] != '\0')
	{
		SPI_sendByte(str[i]);
		i++;
	}
}

void SPI_receiveString (u8 *str)		// Function to receive string
{
	u8 i = 0;
	str[i] = SPI_receiveByte();
	while (str[i] != "#")
	{
		i++;
		str[i] = SPI_receiveByte();
	}
	str[i] = '\0';
}

