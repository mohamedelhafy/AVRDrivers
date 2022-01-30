/*
 * Key_pad.h
 *
 * Created: 1/23/2022 1:08:56 AM
 *  Author: hp
 */ 


#ifndef KEY_PAD_H_
#define KEY_PAD_H_

#include "STD_Macros.h"



/*********************************************************************************************************/
/*	Function Name        : keyPad_vInit                                                                  */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned char port                                                            */
/*	Function Description : Initialize the KeyPad                                                         */
/*********************************************************************************************************/
void keyPad_vInit(uint_8 port);




/*********************************************************************************************************/
/*	Function Name        : keyPad_u8Read                                                                 */
/*	Function Returns     : unsigned char                                                                 */
/*	Function Arguments   : unsigned char port                                                            */
/*	Function Description : Read the input key                                                            */
/*********************************************************************************************************/
uint_8 keyPad_u8Read(uint_8 port);


#endif /* KEY_PAD_H_ */