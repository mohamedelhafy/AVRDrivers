/*
 * SPI.c
 *
 * Created: 1/28/2022 10:50:25 PM
 *  Author: Mohamed Elhafy
 */ 

#include "DIO.h"
#include <avr/io.h>




/*********************************************************************************************************/
/*	Function Name        : SPI_vInitMaster                                                               */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : void                                                                          */
/*	Function Description : Set the SPI As a Master and Enable it                                         */
/*********************************************************************************************************/
void SPI_vInitMaster(void)
{
	//Set the SS/MOSI/SCK as output and MISO as input for master mood 
	DIO_vSetPinDirOutput('B',4);
	DIO_vSetPinDirOutput('B',5);
	DIO_vSetPinDirInput('B',6);
	DIO_vSetPinDirOutput('B',7);
	
	//Enable master mood
	SET_BIT(SPCR,MSTR);
	
	//Set the clock as focs/16
	SET_BIT(SPCR,SPR0);
	
	//Enable SPI
	SET_BIT(SPCR,SPE);
	
	//set the SS pin high 
	DIO_vWritePin('B',4,1);
}





/*********************************************************************************************************/
/*	Function Name        : SPI_vInitSlave                                                                */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : void                                                                          */
/*	Function Description : Set the SPI As a Slave and Enable it                                          */
/*********************************************************************************************************/
void SPI_vInitSlave(void)
{
	//set the SS/MOSI/SCK as input and MISO as output for Slave mood
	DIO_vSetPinDirInput('B',4);
	DIO_vSetPinDirInput('B',5);
	DIO_vSetPinDirOutput('B',6);
	DIO_vSetPinDirInput('B',7);
	
	//Clear the MSTR bit
	CLR_BIT(SPCR,MSTR);
	
	//Enable SPE bit
	SET_BIT(SPCR,SPE);
}





/*********************************************************************************************************/
/*	Function Name        : SPI_vSendChar                                                               */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned char                                                                 */
/*	Function Description : Send a char with SPI                                                          */
/*********************************************************************************************************/
void SPI_vMasterSendChar(uint_8 SSport ,uint_8 SSpin ,uint_8 data)
{
	//Clear the SS Pin 
	DIO_vWritePin(SSport,SSpin,0);
	
	//put data in SPDR
	SPDR = data;
	
	// wait untill the Data is transmitted 
	while(IS_BIT_CLEAR(SPCR,SPIF));
	
	//Access the SPDR
	data=SPDR;
}






/*********************************************************************************************************/
/*	Function Name        : SPI_vSlaveSendChar                                                            */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned char                                                                 */
/*	Function Description : Send a char with SPI                                                          */
/*********************************************************************************************************/
void SPI_vSlaveSendChar(uint_8 data)
{
	//wait till the buffer be free
	while(IS_BIT_CLEAR(SPDR,SPIF));
	//load the char in SPDR
	SPDR=data;
}






/*********************************************************************************************************/
/*	Function Name        : SPI_u8ReceiveChar                                                             */
/*	Function Returns     : unsigned char                                                                 */
/*	Function Arguments   : void                                                                          */
/*	Function Description : Receive a char with SPI                                                       */
/*********************************************************************************************************/
uint_8 SPI_u8MasterReceiveChar(uint_8 SSPort, uint_8 SSPin)
{
	//Clear the SS Pin
	DIO_vWritePin(SSPort,SSPin,0);
	
	//load Dumy data in SPDR
	SPDR = DUMMY_DATA;
	
	// wait untill the Data is transmitted
	while(IS_BIT_CLEAR(SPCR,SPIF));
	
	//Access the SPDR
	return SPDR;
}






/*********************************************************************************************************/
/*	Function Name        : SPI_u8SlaveReceiveChar                                                        */
/*	Function Returns     : unsigned char                                                                 */
/*	Function Arguments   : void                                                                          */
/*	Function Description : Receive a char with SPI                                                       */
/*********************************************************************************************************/
uint_8 SPI_u8SlaveReceiveChar(void)
{
	//wait till the buffer be free
	while(IS_BIT_CLEAR(SPDR,SPIF));
	//load the char in SPDR
	return SPDR;
}






/*********************************************************************************************************/
/*	Function Name        : SPI_u8ReceiveString                                                           */
/*	Function Returns     : unsigned char                                                                 */
/*	Function Arguments   : void                                                                          */
/*	Function Description : Receive a char with SPI                                                       */
/*********************************************************************************************************/
void SPI_vMasterSendString(uint_8 SSPort ,uint_8 SSPin ,uint_8 *data)
{
	while(*data!='\0')
	{
		SPI_vMasterSendChar(SSPort,SSPin,*data);
		_delay_ms(300);
		data++;
	}
}