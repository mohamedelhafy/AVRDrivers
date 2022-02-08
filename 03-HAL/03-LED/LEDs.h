/*
 * LEDs.h
 *
 * Created: 1/17/2022 1:23:56 AM
 *  Author: Mohamed Elhafy
 * 
 * prototyping of the LEDs functions 
 */ 


#ifndef LEDS_H_
#define LEDS_H_

#include "STD_Macros.h"




/*********************************************************************************************************/
/*	Function Name        : LED_vInit                                                                     */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned char port unsigned char pinnumber                                    */
/*	Function Description : initializing the LED by make the pin that connect to output                   */
/*********************************************************************************************************/
void LED_vInit(uint_8 port, uint_8 pinnumber);





/*********************************************************************************************************/
/*	Function Name        : LED_vTurnOn                                                                   */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned char port and unsigned char pinnumber                                */
/*	Function Description : turn the LED on By set the pin to high                                        */
/*********************************************************************************************************/
void LED_vTurnOn(uint_8 port, uint_8 pinnumber);





/*********************************************************************************************************/
/*	Function Name        : LED_vTurnOff                                                                  */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned char port unsigned char pinnumber                                    */
/*	Function Description : turn the LED on By set the pin to high                                        */
/*********************************************************************************************************/
void LED_vTurnOff(uint_8 port, uint_8 pinnumber);





/*********************************************************************************************************/
/*	Function Name        : LED_vToggle                                                                   */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned char port unsigned char pinnumber                                    */
/*	Function Description : toggle the LED                                                                */
/*********************************************************************************************************/
void LED_vToggle(uint_8 port, uint_8 pinnumber);





/*********************************************************************************************************/
/*	Function Name        : LED_u8readState                                                               */
/*	Function Returns     : unsigned char                                                                 */
/*	Function Arguments   : unsigned char port unsigned char pinnumber                                    */
/*	Function Description : read the value of the led is it on or not                                     */
/*********************************************************************************************************/
uint_8 LED_u8readState(uint_8 port, uint_8 pinnumber);


#endif /* LEDS_H_ */