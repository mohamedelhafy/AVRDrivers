/*
 * EEPROM.h
 *
 * Created: 1/19/2022 2:39:11 AM
 *  Author: Mohamed Elhafy
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

#include "STD_Macros.h"





/*********************************************************************************************************/
/*	Function Name        : EEPROM_vWrite                                                                 */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned short location unsigned char data                                    */
/*	Function Description : write the data sent in that location                                          */
/*********************************************************************************************************/
void EEPROM_vWrite(uint_16 location,uint_8 data);






/*********************************************************************************************************/
/*	Function Name        : EEPROM_u8Read                                                                 */
/*	Function Returns     : unsigned char                                                                 */
/*	Function Arguments   : unsigned short location                                                       */
/*	Function Description : Read the data in that location                                                */
/*********************************************************************************************************/
uint_8 EEPROM_u8Read(uint_16 location);

#endif /* EEPROM_H_ */