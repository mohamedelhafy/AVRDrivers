/*
 * ADC.c
 *
 * Created: 1/24/2022 12:48:10 AM
 *  Author: Mohamed Elhafy
 */ 

#include "STD_Macros.h"
#include <avr/io.h>
#include <avr/interrupt.h>



/*********************************************************************************************************/
/*	Function Name        : ADC_vInit																	 */
/*	Function Returns     : void																			 */
/*	Function Arguments   : void																			 */
/*	Function Description : Initializing the ADC Basic configuration										 */
/*********************************************************************************************************/
void ADC_vInit(void)
{
	SET_BIT(ADMUX,REFS0);       // Configure VREF
	SET_BIT(ADCSRA,ADEN);      // Enable ADC     
	/* Adjust ADC Clock Set the PS to 64*/
	SET_BIT(ADCSRA,ADPS2);
	SET_BIT(ADCSRA,ADPS1);
}




/*********************************************************************************************************/
/*	Function Name        : ADC_u16Read                                                                   */
/*	Function Returns     : unsigned short pin number                                                     */
/*	Function Arguments   : unsigned char pinnumber                                                       */
/*	Function Description : Enable the ADC at the desired input                                           */
/*********************************************************************************************************/
uint_16 ADC_u16Read(uint_8 pinnumber)
{
	uint_16 returnVal;    // Define the return value 
	
	ADMUX |=pinnumber;    // Select the input to the ADC
	
	SET_BIT(ADCSRA,ADSC);  // Set Start of conversion 
	
	while(IS_BIT_CLEAR(ADCSRA,ADIF)); // Stay here till the H.W raise the I Flag after end of conversion 
	
	SET_BIT(ADCSRA,ADIF);   // Clear the I flag by write 1 at it 
	
	returnVal=(ADCL);         // Read the ADCL Reg and store it at the first 8-Bit of the returnVal 
	returnVal |=(ADCH<<8);   // Read the ADCH Reg and store it at the HSB of the returnVal 
	
	return returnVal;       // return the value that been read after conversion
}





/*********************************************************************************************************/
/*	Function Name        : ADC_vStartOfConversion                                                        */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned char pinnumber                                                       */
/*	Function Description : Enable the ADC at the desired input And Enable ADC interrupt                  */
/*********************************************************************************************************/
void ADC_vStartOfConversion(uint_8 pinnumber)
{
	/* if you use this function please make sure that you handle the result in ISR (ADC_vect) */
	ADMUX |=pinnumber;    // Select the input to the ADC
	//sei();                   // Enable the global interrupt
	SET_BIT(ADCSRA,ADIE);   // Enable ADC interrupt
	SET_BIT(ADCSRA,ADSC);  // Set Start of conversion 
}