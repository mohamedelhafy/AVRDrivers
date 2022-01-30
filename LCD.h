/*
 * LCD.h
 *
 * Created: 1/21/2022 2:38:57 AM
 *  Author: Mohamed Elhafy
 * 
 * the prototyping of the LCD function and macros for basic commands 
 */ 


#ifndef LCD_H_
#define LCD_H_

//Commands in Use
#define CLR_SCREEN 0x01                      // if i send this cmd will Clear All My Screen

#define RETURN_HOME 0x02                    // if i send this cmd will Return the Cursor to original pos And it can be 0x03

#define ENTRY_MODE_SHIFT_CURSOR_LEFT 0x04               // if i send this cmd Will Make My LCD decrease the Address pointer by it self
// that Mean the cursor will move to the next place In the left of the char

#define ENTRY_MODE_SHIFT_DISPLAY_LEFT 0x05           //this shift the all screen lift every Char i write

#define ENTRY_MODE_SHIFT_CURSOR_RIGHT 0x06            // if i send this cmd Will Make My LCD Increase the Address pointer by it self
// that Mean the cursor will move to the next place in the right of the char

#define ENTRY_MODE_SHIFT_DISPLAY_RIGHT 0x07       //this shift the all screen lift every Char i write

#define CURSOR_OFF_DISPLAY_OFF 0x08         // if i send this cmd will Make My Screen Light OFF And Remove the cursor
#define CURSOR_ON_DISPLAY_OFF 0x0A         // if i send this cmd will Make My Screen Light OFF And show the cursor
#define CURSOR_OFF_DISPLAY_ON 0x0C        // if i send this cmd will Make My Screen Light On And remove the cursor
#define CURSOR_ON_DISPLAY_ON 0x0E        // if i send this cmd will Make My Screen Light On And show the cursor
#define CURSOR_BLINKING_DISBLAY_ON 0x0F // if i send this cmd will Make My Screen Light On And the cursor is Blanking


#define FOUR_BITS 0x28                 //if i send this cmd My LCD understands that My Mode is Four Bit
#define EIGHT_BITS 0x38                //if i send this cmd My LCD understands that My Mode is Eight Bit


#include "STD_Macros.h"

#include "LCD_Config.h"




/*********************************************************************************************************/
/*	Function Name        : LCD_vInit                                                                     */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : void                                                                          */
/*	Function Description : initializing the basic config in of the LCD                                   */
/*********************************************************************************************************/
void LCD_vInit(void);





/*********************************************************************************************************/
/*	Function Name        : LCD_vSendChar                                                                 */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned char sentData                                                        */
/*	Function Description : send a char to show it in the LCD                                             */
/*********************************************************************************************************/
void LCD_vSendChar(uint_8 sentData);




/*********************************************************************************************************/
/*	Function Name        : LCD_vSendString                                                               */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : pointer to unsigned char data that hold the first address of the string       */
/*	Function Description : Write that string in the screen by looping till i find the null char \0       */
/*						   and sent all it to the LCD                                                    */
/*********************************************************************************************************/
void LCD_vSendString(char *data);





/*********************************************************************************************************/
/*	Function Name        : LCD_vClearScreen                                                              */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : void                                                                          */
/*	Function Description : Clear the content of the screen                                               */
/*					   By Restore 0x20 in all location of the DDRAM and make the address counter be 0    */
/*********************************************************************************************************/
void LCD_vClearScreen(void);





/*********************************************************************************************************/
/*	Function Name        : LCD_vMoveCursor                                                               */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned char row unsigned char colum                                         */
/*	Function Description : set the cursor in a location by editing of the address counter                */
/*********************************************************************************************************/
void LCD_vMoveCursor(uint_8 row,uint_8 colum);





/*********************************************************************************************************/
/*	Function Name        : LCD_vSendCmd                                                                  */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned char cmd                                                             */
/*	Function Description : Send a command to my LCD                                                      */
/*********************************************************************************************************/
void LCD_vSendCmd(uint_8 cmd);





/*********************************************************************************************************/
/*	Function Name        : LCD_vSendNum                                                                  */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned long integer num                                                     */
/*	Function Description : Send the number to LCD                                                        */
/*********************************************************************************************************/
void LCD_vSendNum(sint_32 num);






/*********************************************************************************************************/
/*	Function Name        : LCD_vEnable                                                                   */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : void                                                                          */
/*	Function Description : Send Enable signal to My LCD that make it take available data in its data pins*/
/*********************************************************************************************************/
void LCD_vEnable(void);

#endif /* LCD_H_ */