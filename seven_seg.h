/*
 * seven_seg.h
 *
 * Created: 1/17/2022 9:53:52 PM
 *  Author: Mohamed Elhafy
 */ 


#ifndef SEVEN_SEG_H_
#define SEVEN_SEG_H_

#include "STD_Macros.h"




/*********************************************************************************************************/
/*	Function Name        : sevenSeg_vInit                                                                */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned char port                                                            */
/*	Function Description : initializing of the 7-Seg                                                     */
/*********************************************************************************************************/
void sevenSeg_vInit(uint_8 port);






/*********************************************************************************************************/
/*	Function Name        : sevenSeg_vWrite                                                               */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned char port and unsigned char val                                      */
/*	Function Description : write that val in the 7-seg                                                   */
/*********************************************************************************************************/
void sevenSeg_vWrite(uint_8 port,uint_8 val);


#endif /* SEVEN_SEG_H_ */