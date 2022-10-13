#include <avr/io.h>
#include "../../MCAL/SPI/SPI.h"
#include "../../MCAL/DIO/DIO.h"
#include "../../MCAL/ADC/ADC.h"
#include "../../HAL/LCD/LCD.h"
int main ()
{
	u16 adc;
	u8 Temp;
	ADC_Init();
	SPI_InitMaster();
	LCD_Init();
	while (1)
	{
		adc = ADC_readChannel(0);
		Temp = adc / 2.01;
		Go_To_Row_Col(0,0);
		Display_Str("Temperature:  ");
		Integer_TO_String(Temp);
		Display_Str(" C     ");

		if(Temp >= 30 )
		{
			SPI_sendByte('1');
		}
		else if(Temp < 30)
		{
			SPI_sendByte('2');
		}
		else
		{
			SPI_sendByte('3');
		}
	}
}
