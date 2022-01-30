/*
 * I2C.h
 *
 * Created: 1/29/2022 10:19:54 PM
 *  Author: Mohamed Elhafy
 */ 


#ifndef I2C_H_
#define I2C_H_

#include "STD_Macros.h"

#define STATUS_REG (TWSR&0xf8)


#define SEND_START 0x08 //send start bit status

#define REPEATED_START 0x10

#define SEND_ADDRESS_WRITE 0x18


#define SEND_DATA 0x28

#define SEND_ADDRESS_READ 0x40

#define RECEIVE_MY_ADDRESS_AND_WRITE 0x60

#define RECEIVE_DATA_AFTER_MY_ADDRESS 0x80



/*********************************************************************************************************/
/*	Function Name        : I2C_vInitMaster                                                               */
/*	Function Returns     : void											                   			     */
/*	Function Arguments   : unsigned long SCL_Clock    								                     */
/*	Function Description : Initialize the I2C Communication as a Master and initialize the clock         */
/*********************************************************************************************************/
void I2C_vInitMaster(uint_32 SCL_clock);




//void I2C_vSetAddress(uint_8 address);



/*********************************************************************************************************/
/*	Function Name        : I2C_vStartToAddress                                                           */
/*	Function Returns     : void											                   			     */
/*	Function Arguments   : unsigned char address_R_W   								                     */
/*	Function Description : send start condition the Address with read write condition                    */
/*********************************************************************************************************/
void I2C_vStartToAddress(uint_8 address_R_W);




/*********************************************************************************************************/
/*	Function Name        : I2C_vRepeatedStartToAddress                                                   */
/*	Function Returns     : void											                   			     */
/*	Function Arguments   : unsigned char address_R_W   								                     */
/*	Function Description : send repeated start condition the Address with read write condition           */
/*********************************************************************************************************/
void I2C_vRepeatedStartToAddress(uint_8 address_R_W);



/*********************************************************************************************************/
/*	Function Name        : I2C_vSendData                                                                 */
/*	Function Returns     : void											                   			     */
/*	Function Arguments   : unsigned char data        								                     */
/*	Function Description : send data frame                                                               */
/*********************************************************************************************************/
void I2C_vSendData(uint_8 data);


/*********************************************************************************************************/
/*	Function Name        : I2C_vStop                                                                     */
/*	Function Returns     : void											                   			     */
/*	Function Arguments   : void                      								                     */
/*	Function Description : send stop condition                                                           */
/*********************************************************************************************************/
void I2C_vStop(void);



/*********************************************************************************************************/
/*	Function Name        : I2C_u8SlaveRead                                                               */
/*	Function Returns     : unsigned char								                   			     */
/*	Function Arguments   : void                      								                     */
/*	Function Description : read the TWDR                                                                 */
/*********************************************************************************************************/
uint_8 I2C_u8SlaveRead(void);


void I2C_vError();



#endif /* I2C_H_ */