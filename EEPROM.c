/*
 * EEPROM.c
 *
 * Created: 1/19/2022 2:38:51 AM
 *  Author: Mohamed Elhafy
 */ 

#include "STD_Macros.h"
#include <avr/io.h>



/*********************************************************************************************************/
/*	Function Name        : EEPROM_vWrite                                                                 */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned short location unsigned char data                                    */
/*	Function Description : write the data sent in that location                                          */
/*********************************************************************************************************/
void EEPROM_vWrite(uint_16 location,uint_8 data)
{
	while(IS_BIT_SET(EECR,EEWE)); // wait if there is write process happend
	/*
	// 	EEARL = (char)location;
	// 	EEARH = (char)(location>>8);
	*/
	EEAR = location;            // upload the location in the EEAR regesters 
							   //Note that the DDRA is consists of 2 Reg. EEARH and EEARL
							   
	EEDR = data;             // upload the data into EEDR DataRegister
	
	SET_BIT(EECR,EEMWE);   // Set the Master Write Enable bit in the control register EECR 
						  // the HW will back this to zero after only 4-clock cycles
						  
	SET_BIT(EECR,EEWE);	// before the EEMWE back to zero We should set the Write Enable bit EEWE
					   // in the control register EECR
}






/*********************************************************************************************************/
/*	Function Name        : EEPROM_u8Read                                                                 */
/*	Function Returns     : unsigned char                                                                 */
/*	Function Arguments   : unsigned short location                                                       */
/*	Function Description : Read the data in that location                                                */
/*********************************************************************************************************/
uint_8 EEPROM_u8Read(uint_16 location)
{
	/*
	// 	EEARL = (char)location;
	// 	EEARH = (char)(location>>8);
	*/
	EEAR = location;                          // upload the location in the EEAR regesters
											 // Note that the DDRA is consists of 2 Reg. EEARH and EEARL
	SET_BIT(EECR,EERE);                     // Set the Read Enable bit EERE in the Control register EECR
										   // the HW will bake this to zero after the read operation complete
										  // and load the target data in the EEDR
	while(IS_BIT_CLEAR(EECR,EERE));      // check if the HW complete the Read operation or not
	return EEDR;                        // Return the value of the EEDR 
}