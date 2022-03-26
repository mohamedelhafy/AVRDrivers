/******************************************************************************************/
/* Author  : Mohamed Farag Elhafy                                                         */
/* Date    : 3 MAR 2022                                                                   */
/* Version : V01                                                                          */
/******************************************************************************************/




/*sorry this File Have No Comments I will Come Back To Write All Comments After While */

#ifndef SIM900_H
#define SIM900_H




#define startDelay 3000
#define initDelay 3000
#define uartDelay 600
#define commDelay 500
#define regDelay 3000
#define inputEnd 0x1A

#define CR 0x0D
#define LF 0x0A

#define UART_BAUD_RATE      9600  

#define pwrPORT PORTC
#define pwrDDR DDRC
#define pwrPin 6 

void simInit();

void simCommInit();

void simSetTextInput();

void simSetPhone();

void simSendMessage();



#endif // SIM900_H
