/*
 * LCD.c
 *
 * Created: 1/21/2022 2:38:40 AM
 *  Author: Mohamed Elhafy
 */ 



#include "LCD.h"
#include "DIO.h"
#include <util/delay.h>

/*
void LCD_vInit(LCD_Data *Data)
{
	uint_8 i;
	for (i=0;i<Data->Mode;i++)
	{
		DIO_vSetPinDirOutput(Data->portName,Data->pins[i]);
	}
	DIO_vSetPinDirOutput(Data->RSPortName,Data->RS);
	DIO_vSetPinDirOutput(Data->ENPortName,Data->EN);
}

void LCD_vSendChar(LCD_Data *Data, uint_8 sentData)
{
	DIO_vWritePort(Data->portName,sentData);
	DIO_vWritePin(Data->RSPortName,Data->RS,1);
	
	
	DIO_vWritePin(Data->ENPortName,Data->EN,1);
	_delay_ms(2);
	DIO_vWritePin(Data->ENPortName,Data->EN,1);
	_delay_ms(2);
}*/



/*********************************************************************************************************/
/*	Function Name        : LCD_vInit                                                                     */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : void                                                                          */
/*	Function Description : initializing the basic config in of the LCD                                   */
/*********************************************************************************************************/
void LCD_vInit(void)
{
	_delay_ms(100);
	DIO_vSetPinDirOutput(RSPort,RSPin);
	DIO_vSetPinDirOutput(ENPort,ENPin);
	#if (Mode==8)
		DIO_vSetPortDir(LCDPort,0xff);
		LCD_vSendCmd(EIGHT_BITS);
	#endif
	
	#if MODE==4
		#ifdef low_Nibble
			uint_8 i;
			for (i=0;i<4;i++)
			{
				DIO_vSetPinDirOutput(LCDPort,i);
			}
			LCD_vSendCmd(RETURN_HOME);
			LCD_vSendCmd(FOUR_BITS);
		#endif
		
		#ifdef high_Nibble
			uint_8 i;
			for (i=4;i<8;i++)
			{
				DIO_vSetPinDirOutput(LCDPort,i);
			}
			LCD_vSendCmd(RETURN_HOME);
			LCD_vSendCmd(FOUR_BITS);
		#endif
	#endif
	#if notTheSamePortMode==4
		DIO_vSetPinDirOutput(D4Port,D4Port);
		DIO_vSetPinDirOutput(D5Port,D5Port);
		DIO_vSetPinDirOutput(D6Port,D6Port);
		DIO_vSetPinDirOutput(D7Port,D7Port);
		LCD_vSendCmd(RETURN_HOME);
		LCD_vSendCmd(FOUR_BITS);				
	#endif
	#if notTheSamePortMode==8
		DIO_vSetPinDirOutput(D0Port,D0Port);
		DIO_vSetPinDirOutput(D1Port,D1Port);
		DIO_vSetPinDirOutput(D2Port,D2Port);
		DIO_vSetPinDirOutput(D3Port,D3Port);
		DIO_vSetPinDirOutput(D4Port,D4Port);
		DIO_vSetPinDirOutput(D5Port,D5Port);
		DIO_vSetPinDirOutput(D6Port,D6Port);
		DIO_vSetPinDirOutput(D7Port,D7Port);
		LCD_vSendCmd(EIGHT_BITS);
	#endif
	LCD_vSendCmd(CURSOR_ON_DISPLAY_ON);
	LCD_vClearScreen();
	LCD_vSendCmd(ENTRY_MODE_SHIFT_CURSOR_RIGHT);
}




/*********************************************************************************************************/
/*	Function Name        : LCD_vEnable                                                                   */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : void                                                                          */
/*	Function Description : Send Enable signal to My LCD that make it take available data in its data pins*/
/*********************************************************************************************************/
void LCD_vEnable(void)
{
	DIO_vWritePin(ENPort,ENPin,1);
	_delay_ms(2);
	DIO_vWritePin(ENPort,ENPin,0);
	_delay_ms(2);
}





/*********************************************************************************************************/
/*	Function Name        : LCD_vSendChar                                                                 */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned char sentData                                                        */
/*	Function Description : send a char to show it in the LCD                                             */
/*********************************************************************************************************/
void LCD_vSendChar(uint_8 sentData)
{
	DIO_vWritePin(RSPort,RSPin,1);
	
	#if MODE==8
		DIO_vWritePort(LCDPort,sentData);
		LCD_vEnable();
		_delay_ms(1);
	#endif
	
	#if MODE==4
	
		#ifdef low_Nibble

			DIO_vWriteLowNibble(LCDPort,sentData>>4);
			LCD_vEnable();
			DIO_vWriteLowNibble(LCDPort,sentData);
			LCD_vEnable();
		#endif
	
		#ifdef high_Nibble
			DIO_vWriteHighNibble(LCDPort,sentData>>4);
			LCD_vEnable();
			DIO_vWriteHighNibble(LCDPort,sentData);
			LCD_vEnable();
		#endif
	#endif
	#if notTheSamePortMode==4
		DIO_vWritePin(D7Port,D7Pin,IS_BIT_SET(sentData,7));
		DIO_vWritePin(D6Port,D6Pin,IS_BIT_SET(sentData,6));
		DIO_vWritePin(D5Port,D5Pin,IS_BIT_SET(sentData,5));
		DIO_vWritePin(D4Port,D4Pin,IS_BIT_SET(sentData,4));
		LCD_vEnable();
		DIO_vWritePin(D7Port,D7Pin,IS_BIT_SET(sentData,3));
		DIO_vWritePin(D6Port,D6Pin,IS_BIT_SET(sentData,2));
		DIO_vWritePin(D5Port,D5Pin,IS_BIT_SET(sentData,1));
		DIO_vWritePin(D4Port,D4Pin,IS_BIT_SET(sentData,0));
		LCD_vEnable();
	#endif
	#if notTheSamePortMode==8
		DIO_vWritePin(D0Port,D0Pin,IS_BIT_SET(sentData,0));
		DIO_vWritePin(D1Port,D1Pin,IS_BIT_SET(sentData,1));
		DIO_vWritePin(D2Port,D2Pin,IS_BIT_SET(sentData,2));
		DIO_vWritePin(D3Port,D3Pin,IS_BIT_SET(sentData,3));
		DIO_vWritePin(D4Port,D4Pin,IS_BIT_SET(sentData,4));
		DIO_vWritePin(D5Port,D5Pin,IS_BIT_SET(sentData,5));
		DIO_vWritePin(D6Port,D6Pin,IS_BIT_SET(sentData,6));
		DIO_vWritePin(D7Port,D7Pin,IS_BIT_SET(sentData,7));
		LCD_vEnable();
	#endif
}





/*********************************************************************************************************/
/*	Function Name        : LCD_vSendCmd                                                                  */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned char cmd                                                             */
/*	Function Description : Send a command to my LCD                                                      */
/*********************************************************************************************************/
void LCD_vSendCmd(uint_8 cmd)
{
	DIO_vWritePin(RSPort,RSPin,0);
	
	#if Mode==8
		DIO_vWritePort(LCDPort,cmd);
		LCD_vEnable();
	#endif
		
	#if Mode==4
	
		#ifdef low_Nibble

			DIO_vWriteLowNibble(LCDPort,cmd>>4);
			LCD_vEnable();
			DIO_vWriteLowNibble(LCDPort,cmd);
			LCD_vEnable();
		#endif	
		
		#ifdef high_Nibble
			DIO_vWriteHighNibble(LCDPort,cmd>>4);
			LCD_vEnable();
			DIO_vWriteHighNibble(LCDPort,cmd);
			LCD_vEnable();
		#endif		
	#endif
	
	#if notTheSamePortMode==4
		DIO_vWritePin(D7Port,D7Pin,IS_BIT_SET(cmd,7));
		DIO_vWritePin(D6Port,D6Pin,IS_BIT_SET(cmd,6));
		DIO_vWritePin(D5Port,D5Pin,IS_BIT_SET(cmd,5));
		DIO_vWritePin(D4Port,D4Pin,IS_BIT_SET(cmd,4));
		LCD_vEnable();
		DIO_vWritePin(D7Port,D7Pin,IS_BIT_SET(cmd,3));
		DIO_vWritePin(D6Port,D6Pin,IS_BIT_SET(cmd,2));
		DIO_vWritePin(D5Port,D5Pin,IS_BIT_SET(cmd,1));
		DIO_vWritePin(D4Port,D4Pin,IS_BIT_SET(cmd,0));
		LCD_vEnable();
	#endif
	#if notTheSamePortMode==8
		DIO_vWritePin(D0Port,D0Pin,IS_BIT_SET(cmd,0));
		DIO_vWritePin(D1Port,D1Pin,IS_BIT_SET(cmd,1));
		DIO_vWritePin(D2Port,D2Pin,IS_BIT_SET(cmd,2));
		DIO_vWritePin(D3Port,D3Pin,IS_BIT_SET(cmd,3));
		DIO_vWritePin(D4Port,D4Pin,IS_BIT_SET(cmd,4));
		DIO_vWritePin(D5Port,D5Pin,IS_BIT_SET(cmd,5));
		DIO_vWritePin(D6Port,D6Pin,IS_BIT_SET(cmd,6));
		DIO_vWritePin(D7Port,D7Pin,IS_BIT_SET(cmd,7));
		LCD_vEnable();
	#endif
	_delay_ms(2);
}




/*********************************************************************************************************/
/*	Function Name        : LCD_vClearScreen                                                              */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : void                                                                          */
/*	Function Description : Clear the content of the screen                                               */
/*					   By Restore 0x20 in all location of the DDRAM and make the address counter be 0    */
/*********************************************************************************************************/
void LCD_vClearScreen(void)
{
	LCD_vSendCmd(0x01);
	_delay_ms(5);
}




/*********************************************************************************************************/
/*	Function Name        : LCD_vMoveCursor                                                               */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned char row unsigned char colum                                         */
/*	Function Description : set the cursor in a location by editing of the address counter                */
/*********************************************************************************************************/
void LCD_vMoveCursor(uint_8 row,uint_8 colum)
{
	
 	uint_8 Address = row==1?(0x80+colum-1):(0xc0+colum-1);
 	LCD_vSendCmd(Address);
/*
	uint_8 data;

	if (row>2||row<0||colum>16||colum<0)
	{
		data = 0x80;
	} 
	else if(row==1)
	{
		data=0x80+colum-1;
	}
	else if (row==2)
	{
		data = 0xc0+colum-1; 
	}
	LCD_vSendCmd(data);
*/
}





/*********************************************************************************************************/
/*	Function Name        : LCD_vSendString                                                               */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : pointer to unsigned char data that hold the first address of the string       */
/*	Function Description : Write that string in the screen by looping till i find the null char \0       */
/*						   and sent all it to the LCD                                                    */
/*********************************************************************************************************/
void LCD_vSendString(char *data)
{
	while(*data!='\0')
	{
		LCD_vSendChar(*data);
		data++;
	}
}






/*********************************************************************************************************/
/*	Function Name        : LCD_vSendNum                                                                  */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned long integer num                                                     */
/*	Function Description : Send the number to LCD                                                        */
/*********************************************************************************************************/
void LCD_vSendNum(sint_32 num)
{

	uint_32 temp=0;
	sint_8 loopnum=0;
	if (num<0)
	{
		LCD_vSendChar('-');
		num=(~num)+1;
	}
	while(0!=num)
	{
		temp*=10;
		temp+=(num%10);
		num/=10;
		loopnum++;
	}
	do
	{
		LCD_vSendChar((temp%10)+'0');
		temp/=10;
		loopnum--;
	}while(loopnum>0);
}