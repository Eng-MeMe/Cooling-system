#include <avr/io.h>
#include "../../MCAL/DIO/DIO.h"
#include "../../MCAL/UART/UART.h"
int main()
{
	SPI_InitSlave();
	Set_PinDir(PORT_C,Pin_0,OUTPUT);
	Set_PinDir(PORT_C,Pin_1,OUTPUT);
	while(1)
	{

		if(SPI_receiveByte() == '1')
		{
			Set_PinLevel(PORT_C,Pin_0,HIGH);
			Set_PinLevel(PORT_C,Pin_1,LOW);
		}
		else if(SPI_receiveByte() == '2')
		{
			Set_PinLevel(PORT_C,Pin_0,LOW);
			Set_PinLevel(PORT_C,Pin_1,HIGH);
		}
		else
		{
			Set_PinLevel(PORT_C,Pin_0,LOW);
			Set_PinLevel(PORT_C,Pin_1,LOW);
		}
	}
}
