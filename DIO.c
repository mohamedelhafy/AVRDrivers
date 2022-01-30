/*
 * DIO.c
 *
 * Created: 1/16/2022 2:22:51 PM
 * Author: Mohamed Elhafy
 */ 
#include "STD_Macros.h"
#include <avr/io.h>



/*********************************************************************************************************/
/*	Function Name        : DIO_vSetPinDirInput                                                           */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned char portname , unsigned char pin number                             */
/*	Function Description : set the direction of pin as a input pin                                       */
/*********************************************************************************************************/
void DIO_vSetPinDirInput (uint_8 port , uint_8 pin_number)
{
	/*
	* Access the DDRx register and clear the bit that targeted the pin_number
	*/
	switch (port)
	{
		case 'A':
		case 'a':
			CLR_BIT(DDRA,pin_number);
			break;
			
		case 'B':
		case 'b':
			CLR_BIT(DDRB,pin_number);
			break;
		
		case 'C':
		case 'c':
			CLR_BIT(DDRC,pin_number);
			break;
		
		case 'D':
		case 'd':
			CLR_BIT(DDRD,pin_number);
			break;
	}
}





/*********************************************************************************************************/
/*	Function Name        : DIO_vSetPinDirOutput                                                          */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned char portname , unsigned char pin number                             */
/*	Function Description : set the direction of pin as a output pin                                      */
/*********************************************************************************************************/
void DIO_vSetPinDirOutput (uint_8 port , uint_8 pin_number)
{
	/*
	 * Access the DDRx register and Set the bit that targeted the pin_number
	 */
	switch (port)
	{
		case 'A':
		case 'a':
			SET_BIT(DDRA,pin_number);
			break;
		
		case 'B':
		case 'b':
			SET_BIT(DDRB,pin_number);
			break;
		
		case 'C':
		case 'c':
			SET_BIT(DDRC,pin_number);
			break;
		
		case 'D':
		case 'd':
			SET_BIT(DDRD,pin_number);
			break;
	}
}





/*********************************************************************************************************/
/*	Function Name        : DIO_vWritePin                                                                  */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned char portname,unsigned char pinnumber,unsigned char outputvalue      */
/*	Function Description : Set the value of the given pin in the given port                              */
/*							(outputvalue 0 = low : 1 = high)                                             */
/*********************************************************************************************************/
void DIO_vWritePin(uint_8 port, uint_8 pin, uint_8 val)
{
	/*
	 * Access the PORTx Register and write in the pin's bit the val
	 */
	switch (port)
	{
		case 'A':
		case 'a':
			if (val)
			{
				SET_BIT(PORTA,pin);
			}
			else
			{
				CLR_BIT(PORTA,pin);	
			}
			break;
		
		case 'B':
		case 'b':
			if (val)
			{
				SET_BIT(PORTB,pin);
			}
			else
			{
				CLR_BIT(PORTB,pin);
			}
			break;
		
		case 'C':
		case 'c':
			if (val)
			{
				SET_BIT(PORTC,pin);
			}
			else
			{
				CLR_BIT(PORTC,pin);
			}
			break;
		
		case 'D':
		case 'd':
			if (val)
			{
				SET_BIT(PORTD,pin);
			}
			else
			{
				CLR_BIT(PORTD,pin);
			}
			break;
	}
}




/*********************************************************************************************************/
/*	Function Name        : DIO_u8readPin                                                                 */
/*	Function Returns     : unsigned char                                                                 */
/*	Function Arguments   : unsigned char portname,unsigned char pinnumber                                */
/*	Function Description : Returns 1 if the value of the given pin is high and zero if the value is low  */
/*********************************************************************************************************/
uint_8 DIO_u8readPin(uint_8 port, uint_8 pin_number)
{
	/*
	 * Access the PINx register and return the Pin_number's Pin in it
	 */
	uint_8 val=0;
	
	switch(port)
	{
		
		case 'A':
		case 'a':
			val=READ_BIT(PINA,pin_number);
			break;
			
		case 'B':
		case 'b':
			val=READ_BIT(PINB,pin_number);
			break;
		
		case 'C':
		case 'c':
			val=READ_BIT(PINC,pin_number);
			break;
		
		case 'D':
		case 'd':
			val=READ_BIT(PIND,pin_number);
			break;
	}
	
	return val;
}





/*********************************************************************************************************/
/*	Function Name        : DIO_vTogglePin                                                                */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned char portname,unsigned char pinnumber                                */
/*	Function Description : Reverse the value of the given pin in the given port.                         */
/*********************************************************************************************************/
void DIO_vTogglePin(uint_8 port, uint_8 pin_number)
{
	/*
	 * Access the PORTx register and Toggle the pin_number's bit
	 */
	switch(port)
	{
		case 'A':
		case 'a':
			TOG_BIT(PORTA,pin_number);
			break;
			
		case 'B':
		case 'b':
			TOG_BIT(PORTB,pin_number);
			break;
		
		case 'C':
		case 'c':
			TOG_BIT(PORTC,pin_number);
			break;
		
		case 'D':
		case 'd':
			TOG_BIT(PORTD,pin_number);
			break;
	}
}






/*********************************************************************************************************/
/*	Function Name        : DIO_vSetPortDir                                                               */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned char portname,unsigned char direction                                */
/*	Function Description : set the direction of whole port .                                             */
/*********************************************************************************************************/
void DIO_vSetPortDir(uint_8 port, uint_8 dir)
{
	/*
	 * Access the DDRx register and set it as a dir 
	 */
	switch(port)
	{
		case 'A':
		case 'a':
			DDRA = dir;
			break;
		
		case 'B':
		case 'b':
			DDRB = dir;
			break;
		
		case 'C':
		case 'c':
			DDRC = dir;
			break;
		
		case 'D':
		case 'd':
			DDRD = dir;
			break;
	}
}





/*********************************************************************************************************/
/*	Function Name        : DIO_vWritePort                                                                */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned char portname,unsigned char portvalue                                */
/*	Function Description : Write the value to all port pins.                                             */
/*********************************************************************************************************/
void DIO_vWritePort(uint_8 port , uint_8 val)
{
	/*
	 * Access the PORTx register and write the val in it
	 */
	switch(port)
	{
		case 'A':
		case 'a':
			PORTA = val;
			break;
			
		case 'B':
		case 'b':
			PORTB = val;
			break;
		
		case 'C':
		case 'c':
			PORTC = val;
			break;
		
		case 'D':
		case 'd':
			PORTD = val;
			break;
	}
}





/*********************************************************************************************************/
/*	Function Name        : DIO_u8reaPort                                                                 */
/*	Function Returns     : unsigned char                                                                 */
/*	Function Arguments   : unsigned char portname                                                        */
/*	Function Description : read the value of the port .                                                  */
/*********************************************************************************************************/
uint_8 DIO_u8readPort(uint_8 port)
{
	/*
	 * Access the PINx register and return its value
	 */
	uint_8 val=0;
	
	switch(port)
	{
		case 'A':
		case 'a':
			val = PINA;
			break;
		
		case 'B':
		case 'b':
			val = PINB;
			break;
		
		case 'C':
		case 'c':
			val = PINC;
			break;
		
		case 'D':
		case 'd':
			val = PIND;
			break;
	}
	
	return val;
}






/*********************************************************************************************************/
/*	Function Name        : DIO_vTogglePort                                                               */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned char portname                                                        */
/*	Function Description : toggle the value of the port .                                                */
/*********************************************************************************************************/
void DIO_vTogglePort(uint_8 port)
{
	/*
	 * Access the PORTx register and Toggle All its contant
	 */
	switch(port)
	{
		case 'A':
		case 'a':
			PORTA = ~PORTA;
			break;
		
		case 'B':
		case 'b':
			PORTB = ~PORTB;
			break;
		
		case 'C':
		case 'c':
			PORTC = ~PORTC;
			break;
		
		case 'D':
		case 'd':
			PORTD = ~PORTD;
			break;
	}
}







/*********************************************************************************************************/
/*	Function Name        : DIO_vSetPullUp                                                                */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned char port unsigned char pinnumber unsigned char enable               */
/*	Function Description : enabling or disable the internal pull up to a specific pin                    */
/*********************************************************************************************************/
void DIO_vSetPullUp(uint_8 port, uint_8 pinnumber, uint_8 enable)
{
	/*
	 * Access the PORTx register and set or Clear the pinnumber's bit in it
	 * acording to the Enabale value
	 */
	switch(port)
	{
		case 'A':
		case 'a':
			if (enable)
			{
				SET_BIT(PORTA,pinnumber);
			}
			else
			{
				CLR_BIT(PORTA,pinnumber);
			}
			break;
		
		case 'B':
		case 'b':
			if (enable)
			{
				SET_BIT(PORTB,pinnumber);
			}
			else
			{
				CLR_BIT(PORTB,pinnumber);
			}
			break;
		
		case 'C':
		case 'c':
			if (enable)
			{
				SET_BIT(PORTC,pinnumber);
			}
			else
			{
				CLR_BIT(PORTC,pinnumber);
			}
			break;
		
		case 'D':
		case 'd':
			if (enable)
			{
				SET_BIT(PORTD,pinnumber);
			}
			else
			{
				CLR_BIT(PORTD,pinnumber);
			}
			break;
	}
}






/*********************************************************************************************************/
/*	Function Name        : DIO_vWritLowNibble                                                            */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned char port unsigned char val                                          */
/*	Function Description : Write the first 4-bit of the val in the lowest nibble of the port sent        */
/*********************************************************************************************************/
void DIO_vWriteLowNibble(uint_8 port,uint_8 val)
{
	/*
	 * Access the PORTx register and write in the lowest nibble (first 4-bit) in it 
	 * the first 4-bit in the val
	 */
	uint_8 i;
	for (i=0;i<4;i++)
	{
		DIO_vWritePin(port,i,val&1);
		val>>=1;
	}
}





/*********************************************************************************************************/
/*	Function Name        : DIO_vWritHighNibble                                                           */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned char port unsigned char val                                          */
/*	Function Description : Write the first 4-bit of the val in the highest nibble of the port sent       */
/*********************************************************************************************************/
void DIO_vWriteHighNibble(uint_8 port,uint_8 val)
{
	/*
	 * Access the PORTx register and write in the highest nibble (last 4-bit) in it 
	 * the first 4-bit in the val
	 */
	uint_8 i;
	for (i=4;i<8;i++)
	{
			DIO_vWritePin(port,i,val&1);
			val>>=1;
	}
}