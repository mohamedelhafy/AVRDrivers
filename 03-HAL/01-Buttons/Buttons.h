/*
 * Buttons.h
 *
 * Created: 1/17/2022 3:20:15 AM
 *  Author: Mohamed Elhafy
 */ 


#ifndef BUTTONS_H_
#define BUTTONS_H_

#include "STD_Macros.h"




/*********************************************************************************************************/
/*	Function Name        : Button_vInit                                                                  */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned char port unsigned char pinnumber                                    */
/*	Function Description : Set the pin as input                                                          */
/*********************************************************************************************************/
void Button_vInit(uint_8 port, uint_8 pinnumber);





/*********************************************************************************************************/
/*	Function Name        : Button_u8read                                                                 */
/*	Function Returns     : unsigned char                                                                 */
/*	Function Arguments   : unsigned char port unsigned char pinnumber                                    */
/*	Function Description : access the Pin register and read the bit value of the this pin                */
/*********************************************************************************************************/
uint_8 Button_u8read(uint_8 port, uint_8 pinnumber);





/*********************************************************************************************************/
/*	Function Name        : Button_vSetPullUp                                                             */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned char port unsigned char pinnumber                                    */
/*	Function Description : enable internal pull up of the pin                                            */
/*********************************************************************************************************/
void Button_vSetPullUp(uint_8 port, uint_8 pinnumber, uint_8 enable);

#endif /* BUTTONS_H_ */