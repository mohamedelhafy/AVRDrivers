/*
 * LEDs.c
 *
 * Created: 1/17/2022 1:23:33 AM
 *  Author: Mohamed Elhafy
 */ 

#include "DIO.h"




/*********************************************************************************************************/
/*	Function Name        : LED_vInit                                                                     */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned char port unsigned char pinnumber                                    */
/*	Function Description : initializing the LED by make the pin that connect to output                   */
/*********************************************************************************************************/
void LED_vInit(uint_8 port, uint_8 pinnumber)
{
	DIO_vSetPinDirOutput(port,pinnumber); 
}





/*********************************************************************************************************/
/*	Function Name        : LED_vTurnOn                                                                   */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned char port and unsigned char pinnumber                                */
/*	Function Description : turn the LED on By set the pin to high                                        */
/*********************************************************************************************************/
void LED_vTurnOn(uint_8 port, uint_8 pinnumber)
{
	DIO_vWritePin(port,pinnumber,1);
}





/*********************************************************************************************************/
/*	Function Name        : LED_vTurnOff                                                                  */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned char port unsigned char pinnumber                                    */
/*	Function Description : turn the LED on By set the pin to high                                        */
/*********************************************************************************************************/
void LED_vTurnOff(uint_8 port, uint_8 pinnumber)
{
	DIO_vWritePin(port,pinnumber,0);
}





/*********************************************************************************************************/
/*	Function Name        : LED_vToggle                                                                   */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned char port unsigned char pinnumber                                    */
/*	Function Description : toggle the LED                                                                */
/*********************************************************************************************************/
void LED_vToggle(uint_8 port, uint_8 pinnumber)
{
	DIO_vTogglePin(port,pinnumber);
}





/*********************************************************************************************************/
/*	Function Name        : LED_u8readState                                                               */
/*	Function Returns     : unsigned char                                                                 */
/*	Function Arguments   : unsigned char port unsigned char pinnumber                                    */
/*	Function Description : read the value of the led is it on or not                                     */
/*********************************************************************************************************/
uint_8 LED_u8readState(uint_8 port, uint_8 pinnumber)
{
	return DIO_u8readPin(port,pinnumber);
}

