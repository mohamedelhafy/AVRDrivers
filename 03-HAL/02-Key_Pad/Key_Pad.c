/*
 * Key_Pad.c
 *
 * Created: 1/23/2022 1:08:38 AM
 *  Author: hp
 */ 

#include "DIO.h"
#include <util/delay.h>



/*********************************************************************************************************/
/*	Function Name        : keyPad_vInit                                                                  */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned char port                                                            */
/*	Function Description : Initialize the KeyPad                                                         */
/*********************************************************************************************************/
void keyPad_vInit(uint_8 port)
{
	uint_8 i;
	DIO_vSetPortDir(port,0xf0);
	for(i=0;i<4;i++)
	{
		DIO_vSetPullUp(port,i,1);
	}
}





/*********************************************************************************************************/
/*	Function Name        : keyPad_u8Read                                                                 */
/*	Function Returns     : unsigned char                                                                 */
/*	Function Arguments   : unsigned char port                                                            */
/*	Function Description : Read the input key                                                            */
/*********************************************************************************************************/
uint_8 keyPad_u8Read(uint_8 port)
{
	uint_8 Data[4][4]={{'7','8','9','/'}
				      ,{'4','5','6','*'}
				      ,{'1','2','3','-'}
				      ,{'A','0','=','+'}},
					  i,j,Redata=0xff;
	DIO_vWritePort(port,0xf0);
	for(i=4;i<8;i++)
	{
		DIO_vWritePin(port,i,0);
		for(j=0;j<4;j++)
		{
			if (0==DIO_u8readPin(port,j))
			{
				Redata = Data[j][i-4];
				_delay_ms(250);
			}
		}
		DIO_vWritePin(port,i,1);
	}
	
	return Redata;
}