/*
 * LM32.h
 *
 * Created: 1/24/2022 3:56:35 AM
 *  Author: Mohamed Elhafy
 */ 


#ifndef LM32_H_
#define LM32_H_

#include "STD_Macros.h"

/*
	Function Name        : LM35_u8TempRead
	Function Returns     : Float
	Function Arguments   : unsigned char pinnumber 
	Function Description : Reading the tmp 
*/
float_32 LM35_u8TempRead(uint_8 pinnumber);

float_32 LM35_u8TempReadWithNeg(uint_8 pinnumber);

#endif /* LM32_H_ */