/*
 * SPI.h
 *
 * Created: 1/28/2022 10:50:42 PM
 *  Author: Mohamed Elhafy
 */ 


#ifndef SPI_H_
#define SPI_H_

#include "STD_Macros.h"




/*********************************************************************************************************/
/*	Function Name        : SPI_vInitMaster                                                               */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : void                                                                          */
/*	Function Description : Set the SPI As a Master and Enable it                                         */
/*********************************************************************************************************/
void SPI_vInitMaster(void);




/*********************************************************************************************************/
/*	Function Name        : SPI_vInitSlave                                                                */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : void                                                                          */
/*	Function Description : Set the SPI As a Slave and Enable it                                          */
/*********************************************************************************************************/
void SPI_vInitSlave(void);




/*********************************************************************************************************/
/*	Function Name        : SPI_vMasterSendChar                                                           */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned char                                                                 */
/*	Function Description : Send a char with SPI                                                          */
/*********************************************************************************************************/
void SPI_vMasterSendChar(uint_8 SSport ,uint_8 SSpin ,uint_8 data);






/*********************************************************************************************************/
/*	Function Name        : SPI_vSlaveSendChar                                                            */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned char                                                                 */
/*	Function Description : Send a char with SPI                                                          */
/*********************************************************************************************************/
void SPI_vSlaveSendChar(uint_8 data);






/*********************************************************************************************************/
/*	Function Name        : SPI_u8MasterReceiveChar                                                       */
/*	Function Returns     : unsigned char                                                                 */
/*	Function Arguments   : void                                                                          */
/*	Function Description : Receive a char with SPI                                                       */
/*********************************************************************************************************/
uint_8 SPI_u8MasterReceiveChar(void);






/*********************************************************************************************************/
/*	Function Name        : SPI_u8SlaveReceiveChar                                                        */
/*	Function Returns     : unsigned char                                                                 */
/*	Function Arguments   : void                                                                          */
/*	Function Description : Receive a char with SPI                                                       */
/*********************************************************************************************************/
uint_8 SPI_u8SlaveReceiveChar(void);






/*********************************************************************************************************/
/*	Function Name        : SPI_u8MasterReceiveString                                                     */
/*	Function Returns     : unsigned char                                                                 */
/*	Function Arguments   : void                                                                          */
/*	Function Description : Receive a char with SPI                                                       */
/*********************************************************************************************************/
void SPI_vMasterSendString(uint_8 SSPort ,uint_8 SSPin ,uint_8 *data);

#endif /* SPI_H_ */