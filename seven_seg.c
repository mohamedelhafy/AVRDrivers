/*
 * seven_seg.c
 *
 * Created: 1/17/2022 9:53:29 PM
 *  Author: Mohamed Elhafy
 */ 

#include "DIO.h"

#ifndef CC
#ifndef CA

#warning "please desfine the type of you 7 Seg As CA for Common Anode and CC as Common Cathod I Make it common cathod for you if it not working pleas kindly make a macro as a CA "
#define CC

#endif
#endif




/*********************************************************************************************************/
/*	Function Name        : sevenSeg_vInit                                                                */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned char port                                                            */
/*	Function Description : initializing of the 7-Seg                                                     */
/*********************************************************************************************************/
void sevenSeg_vInit(uint_8 port)
{
	DIO_vSetPortDir(port,0xff);
}






/*********************************************************************************************************/
/*	Function Name        : sevenSeg_vWrite                                                               */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned char port and unsigned char val                                      */
/*	Function Description : write that val in the 7-seg                                                   */
/*********************************************************************************************************/
void sevenSeg_vWrite(uint_8 port,uint_8 val)
{
	uint_8 arr[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x47,0x7f,0x6f}; // the value of the numbers 
	
	#if defined CC
	DIO_vWritePort(port,arr[val]);
	#elif defined CA
	DIO_vWritePort(port,~(arr[val]));
	#endif
}