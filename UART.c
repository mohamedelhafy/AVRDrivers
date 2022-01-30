/*
 * USART.c
 *
 * Created: 1/28/2022 1:10:21 AM
 *  Author: Mohamed Elhafy
 */ 

#include "STD_Macros.h"
#include <util/delay.h>
#include <avr/io.h>



/*********************************************************************************************************/
/*	Function Name        : UART_vInit                                                                    */
/*	Function Returns     : void											                   			     */
/*	Function Arguments   : unsigned long baudRate									                     */
/*	Function Description : Enable the UART And Set the useful data in the frame 8-bit                    */
/*********************************************************************************************************/
void UART_vInit(uint_32 baudRate)
{
	/************************************************************************/
	/*                        initialize the UART                           */
	/************************************************************************/
	//choose the baud rate 
	uint_16 UBRRVal=(F_CPU/(16*baudRate))-1;
	UBRRH = (uint_8)(UBRRVal>>8);
	UBRRL = (uint_8)UBRRVal;
	
	//Enable UART Sender & Receiver
	SET_BIT(UCSRB,RXEN);
	SET_BIT(UCSRB,TXEN);
	//choose the number of useful data bits make it as 8 bit
	UCSRC = (1<<UCSZ0)|(1<<UCSZ1)|(1<<URSEL);
}



/*********************************************************************************************************/
/*	Function Name        : UART_vSendData                                                                */
/*	Function Returns     : void											                   			     */
/*	Function Arguments   : unsigned char Data       								                     */
/*	Function Description : Send one byte by the UART                                                     */
/*********************************************************************************************************/
void UART_vSendData(uint_8 Data)
{
	/************************************************************************/
	/*                    Sending Data by the UART                          */
	/************************************************************************/
	//wait till the the UDR transmit buffer to be Empty
	while(IS_BIT_CLEAR(UCSRA,UDRE));
	//put data in the buffer
	UDR = Data;
}





/*********************************************************************************************************/
/*	Function Name        : UART_u8Recive                                                                 */
/*	Function Returns     : unsigned char								                   			     */
/*	Function Arguments   : void														                     */
/*	Function Description : read the UDR receiver buffer                                                  */
/*********************************************************************************************************/
uint_8 UART_u8Recive(void)
{
	/************************************************************************/
	/*                    Receive Data from the UART                        */
	/************************************************************************/
	//wait for UDR receive buffer filled with data
	while(IS_BIT_CLEAR(UCSRA,RXC));
	//return the received data
	return UDR;
}




/*********************************************************************************************************/
/*	Function Name        : UART_vSendString                                                              */
/*	Function Returns     : void											                   			     */
/*	Function Arguments   : pointer to unsigned char data							                     */
/*	Function Description : Sending string by using UART                                                  */
/*********************************************************************************************************/
void UART_vSendString(uint_8 *data)
{
	/************************************************************************/
	/*                    Sending String by the UART                        */
	/************************************************************************/
	while(*data !='\0')
	{
		UART_vSendData(*data);
		data++;
		_delay_ms(100);
	}
}