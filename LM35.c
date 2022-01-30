/*
 * LM35.c
 *
 * Created: 1/24/2022 3:56:52 AM
 *  Author: Mohamed Elhafy
 */ 

#include "STD_Macros.h" 
#include "ADC.h"

float_32 LM35_u8TempRead(uint_8 pinnumber)
{
	ADC_vInit();
	float_32 temp ;
	temp = (5.0/1024)*ADC_u16Read(pinnumber);
	temp/=10e-3;
	return temp ;
}

float_32 LM35_u8TempReadWithNeg(uint_8 pinnumber)
{
	ADC_vInit();
	float_32 temp ;
	temp = (5.0/1024)*ADC_u16Read(pinnumber);
	temp/=10e-3;
	temp-=55;
	return temp ;
}