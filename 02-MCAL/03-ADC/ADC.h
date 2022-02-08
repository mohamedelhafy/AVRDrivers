/*
 * ADC.h
 *
 * Created: 1/24/2022 12:48:28 AM
 *  Author: Mohamed Elhafy
 */ 


#ifndef ADC_H_
#define ADC_H_

#include "STD_Macros.h"


/*********************************************************************************************************/
/*	Function Name        : ADC_vInit																	 */
/*	Function Returns     : void																			 */
/*	Function Arguments   : void																			 */
/*	Function Description : Initializing the ADC Basic configuration										 */
/*********************************************************************************************************/
void ADC_vInit(void);



/*********************************************************************************************************/
/*	Function Name        : ADC_u16Read                                                                   */
/*	Function Returns     : unsigned short pin number                                                     */
/*	Function Arguments   : unsigned char pinnumber                                                       */
/*	Function Description : Enable the ADC at the desired input                                           */
/*********************************************************************************************************/
uint_16 ADC_u16Read(uint_8 pinnumber);





/*********************************************************************************************************/
/*	Function Name        : ADC_vStartOfConversion                                                        */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned char pinnumber                                                       */
/*	Function Description : Enable the ADC at the desired input And Enable ADC interrupt                  */
/*********************************************************************************************************/
void ADC_vStartOfConversion(uint_8 pinnumber);

#endif /* ADC_H_ */