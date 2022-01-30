/*
 * I2C.c
 *
 * Created: 1/29/2022 10:19:36 PM
 *  Author: Mohamed Elhafy
 */ 


#include "I2C.h"
#include <avr/io.h>


/*********************************************************************************************************/
/*	Function Name        : I2C_vInitMaster                                                               */
/*	Function Returns     : void											                   			     */
/*	Function Arguments   : unsigned long SCL_Clock    								                     */
/*	Function Description : Initialize the I2C Communication as a Master and initialize the clock         */
/*********************************************************************************************************/
void I2C_vInitMaster(uint_32 SCL_clock)
{
	uint_16 tempClock=300,pre=1;
	
	while(tempClock>256)
	{
		tempClock=(((F_CPU/SCL_clock)-16)/(2*pre));
		pre++;
	}
	TWBR =(uint_8)tempClock;
}





/*********************************************************************************************************/
/*	Function Name        : I2C_vStartToAddress                                                           */
/*	Function Returns     : void											                   			     */
/*	Function Arguments   : unsigned char address_R_W   								                     */
/*	Function Description : send start condition the Address with read write condition                    */
/*********************************************************************************************************/
void I2C_vStartToAddress(uint_8 address_R_W)
{
	SET_BIT(TWCR,TWEN);//Set the TWI Enable Bit
	SET_BIT(TWCR,TWSTA);//raise the TWI start bit to send the Start bit in case the bus is available 
	SET_BIT(TWCR,TWEA);// enable ACK
	SET_BIT(TWCR,TWINT);//clear the interrupt flag by write one on it
	 
	while(IS_BIT_CLEAR(TWCR,TWINT)); //wait till finish and raise the interrupt flag
	
	if (STATUS_REG!=SEND_START)
	{
		/************************************************************************/
		/* check if the status not the send start status                        */
		/************************************************************************/
		I2C_vError(); // call the I2C Error handling 
	}
	
	TWDR = address_R_W; // loading the SLA+R/W in TWDR
	
	SET_BIT(TWCR,TWINT); // clear the interrupt flag to start transmiton 
	while(IS_BIT_CLEAR(TWCR,TWINT)); //wait till finish
	if ((STATUS_REG!=SEND_ADDRESS_WRITE)|((TWSR&0xf8)!=SEND_ADDRESS_READ))
	{
		/*******************************************************************************/
		/* Check the Status reg and make sure the status is send address + control bit */
		/*******************************************************************************/
		I2C_vError();
	}
}






/*********************************************************************************************************/
/*	Function Name        : I2C_vRepeatedStartToAddress                                                   */
/*	Function Returns     : void											                   			     */
/*	Function Arguments   : unsigned char address_R_W   								                     */
/*	Function Description : send repeated start condition the Address with read write condition           */
/*********************************************************************************************************/
void I2C_vRepeatedStartToAddress(uint_8 address_R_W)
{
	SET_BIT(TWCR,TWSTA);//raise the TWI start bit to send the Start bit in case the bus is available
	SET_BIT(TWCR,TWINT);//clear the interrupt flag by write one on it
	
	while(IS_BIT_CLEAR(TWCR,TWINT)); //wait till finish and raise the interrupt flag
	
	if (STATUS_REG!=REPEATED_START)
	{
		/************************************************************************/
		/* Make Sure that the repeated start sent                               */
		/************************************************************************/
		I2C_vError();
	}
}




/*********************************************************************************************************/
/*	Function Name        : I2C_vSendData                                                                 */
/*	Function Returns     : void											                   			     */
/*	Function Arguments   : unsigned char data        								                     */
/*	Function Description : send data frame                                                               */
/*********************************************************************************************************/
void I2C_vSendData(uint_8 data)
{
	TWDR=data; //loading data in TWI Data Register
	
	SET_BIT(TWCR,TWINT); //clear the interrupt flag to start sending
	
	while(IS_BIT_CLEAR(TWCR,TWINT)); //wait till finish sending
	
	if (STATUS_REG != SEND_DATA)
	{
		/************************************************************************/
		/* check if the data have been Sent                                     */
		/************************************************************************/
		I2C_vError();
	}
}



/*********************************************************************************************************/
/*	Function Name        : I2C_vStop                                                                     */
/*	Function Returns     : void											                   			     */
/*	Function Arguments   : void                      								                     */
/*	Function Description : send stop condition                                                           */
/*********************************************************************************************************/
void I2C_vStop(void)
{
	SET_BIT(TWCR,TWSTO); // raise the stop frame Enable bit 
	SET_BIT(TWCR,TWINT); // clear the interrupt flag
}





/*********************************************************************************************************/
/*	Function Name        : I2C_u8SlaveRead                                                               */
/*	Function Returns     : unsigned char								                   			     */
/*	Function Arguments   : void                      								                     */
/*	Function Description : read the TWDR                                                                 */
/*********************************************************************************************************/
uint_8 I2C_u8SlaveRead(void)
{
	uint_8 temp=DUMMY_DATA;
	SET_BIT(TWCR,TWEN);
	SET_BIT(TWCR,TWEA);
	SET_BIT(TWCR,TWINT);
	
	while(IS_BIT_CLEAR(TWCR,TWINT));
	if (STATUS_REG==RECEIVE_MY_ADDRESS_AND_WRITE)
	{
		SET_BIT(TWCR,TWINT);
		while(IS_BIT_CLEAR(TWCR,TWINT));
		if (STATUS_REG==RECEIVE_DATA_AFTER_MY_ADDRESS)
		{
			temp=TWDR;
		}
	}
	return temp;
}