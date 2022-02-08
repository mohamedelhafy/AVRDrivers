/*
 * LCD_Config.h
 *
 * Created: 1/22/2022 4:29:56 PM
 *  Author: Mohamed Elhafy
 *
 * the basic configration of the LCD that will be Edited by the driver user
 */ 


#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

// Selecting the pins and mode My LCD conected for
#define MODE 4  // for Selecting the Mode 8 for 8-bit mode 4 For 4-bit mode and any thig else for use the Not the same port mode
#define LCDPort 'A'  // for Selecting the Port That used 
#define high_Nibble  //in case the mode=4 Please feel free to change it 
					//if you want and if you use Low Nibble of the MC Port 
				   //please remove the high_Nibble and define as low_Nibble

//used in Case that I use Pins from More than one Port 
#define notTheSamePortMode 0 // for Selecting the Mode use 8 if 8-bit mode used and 4 for 4-bit mode

#define D0Port 'A'
#define D0Pin 0

#define D1Port 'A'
#define D1Pin 1

#define D2Port 'A'
#define D2Pin 2

#define D3Port 'A'
#define D3Pin 3

#define D4Port 'A'
#define D4Pin 4

#define D5Port 'A'
#define D5Pin 5

#define D6Port 'A'
#define D6Pin 6

#define D7Port 'A'
#define D7Pin 7


// checking the basic configration of the LCD
#if ((MODE==4||MODE==8)&&(notTheSamePortMode==4||notTheSamePortMode==8))||((!(MODE==4||MODE==8))&&(!(notTheSamePortMode==4||notTheSamePortMode==8)))
	#error "please Select the mode you working on if all pins set in the same port set the mode in the Mode Macro Else Set it in the notTheSamePortMode" 
#endif

//My code Make by Default the RW pin is grounded If it not like that
//please feel free to uncomment its macro and type the pin port and number
#define ENPin 0    //for Selecting the pin number of EN pin
#define RSPin 1   //for Selecting the pin number of RS pin
//#define RWPin	 //usualy We don't use the this but this is for future use 
#define ENPort 'A'     //for Selecting the port of EN pin
#define RSPort 'A'    //for Selecting the port of EN pin
//#define RWPort       //usualy We don't use the this but this is for future use 


#endif /* LCD_CONFIG_H_ */