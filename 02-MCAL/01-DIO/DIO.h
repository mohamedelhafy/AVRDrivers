/*
 * DIO.h
 *
 * Created: 1/16/2022 2:23:30 PM
 * Author: Mohamed Elhafy
 *
 * proto typing of the DIO functions 
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "STD_Macros.h"




/*********************************************************************************************************/
/*	Function Name        : DIO_vSetPinDirInput                                                           */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned char portname , unsigned char pin number                             */
/*	Function Description : set the direction of pin as a input pin                                       */
/*********************************************************************************************************/
void DIO_vSetPinDirInput (uint_8 port , uint_8 pin_number);





/*********************************************************************************************************/
/*	Function Name        : DIO_vSetPinDirOutput                                                          */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned char portname , unsigned char pin number                             */
/*	Function Description : set the direction of pin as a output pin                                      */
/*********************************************************************************************************/
void DIO_vSetPinDirOutput (uint_8 port , uint_8 pin_number);





/*********************************************************************************************************/
/*	Function Name        : DIO_vWritePin                                                                  */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned char portname,unsigned char pinnumber,unsigned char outputvalue      */
/*	Function Description : Set the value of the given pin in the given port                              */
/*							(outputvalue 0 = low : 1 = high)                                             */
/*********************************************************************************************************/
void DIO_vWritePin(uint_8 port, uint_8 pin, uint_8 val);






/*********************************************************************************************************/
/*	Function Name        : DIO_u8readPin                                                                 */
/*	Function Returns     : unsigned char                                                                 */
/*	Function Arguments   : unsigned char portname,unsigned char pinnumber                                */
/*	Function Description : Returns 1 if the value of the given pin is high and zero if the value is low  */
/*********************************************************************************************************/
uint_8 DIO_u8readPin(uint_8 port, uint_8 pin_number);





/*********************************************************************************************************/
/*	Function Name        : DIO_vTogglepin                                                                */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned char portname,unsigned char pinnumber                                */
/*	Function Description : Reverse the value of the given pin in the given port.                         */
/*********************************************************************************************************/
void DIO_vTogglePin(uint_8 port, uint_8 pin_number);





/*********************************************************************************************************/
/*	Function Name        : DIO_vSetPortDir                                                               */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned char portname,unsigned char direction                                */
/*	Function Description : set the direction of whole port .                                             */
/*********************************************************************************************************/
void DIO_vSetPortDir(uint_8 port, uint_8 dir);





/*********************************************************************************************************/
/*	Function Name        : DIO_vWritePort                                                                */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned char portname,unsigned char portvalue                                */
/*	Function Description : Write the value to all port pins.                                             */
/*********************************************************************************************************/
void DIO_vWritePort(uint_8 port , uint_8 val);





/*********************************************************************************************************/
/*	Function Name        : DIO_u8reaPort                                                                 */
/*	Function Returns     : unsigned char                                                                 */
/*	Function Arguments   : unsigned char portname                                                        */
/*	Function Description : read the value of the port .                                                  */
/*********************************************************************************************************/
uint_8 DIO_u8readPort(uint_8 port);






/*********************************************************************************************************/
/*	Function Name        : DIO_vTogglePort                                                               */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned char portname                                                        */
/*	Function Description : toggle the value of the port .                                                */
/*********************************************************************************************************/
void DIO_vTogglePort(uint_8 port);






/*********************************************************************************************************/
/*	Function Name        : DIO_vSetPullUp                                                                */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned char port unsigned char pinnumber unsigned char enable               */
/*	Function Description : enabling or disable the internal pull up to a specific pin                    */
/*********************************************************************************************************/
void DIO_vSetPullUp(uint_8 port, uint_8 pinnumber, uint_8 enable);






/*********************************************************************************************************/
/*	Function Name        : DIO_vWritLowNibble                                                            */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned char port unsigned char val                                          */
/*	Function Description : Write the first 4-bit of the val in the lowest nibble of the port sent        */
/*********************************************************************************************************/
void DIO_vWriteLowNibble(uint_8 port,uint_8 val);





/*********************************************************************************************************/
/*	Function Name        : DIO_vWritHighNibble                                                           */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned char port unsigned char val                                          */
/*	Function Description : Write the first 4-bit of the val in the highest nibble of the port sent       */
/*********************************************************************************************************/
void DIO_vWriteHighNibble(uint_8 port,uint_8 val);


#endif /* DIO_H_ */