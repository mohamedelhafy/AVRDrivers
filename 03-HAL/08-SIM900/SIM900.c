/******************************************************************************************/
/* Author  : Mohamed Farag Elhafy                                                         */
/* Date    : 3 MAR 2022                                                                   */
/* Version : V01                                                                          */
/******************************************************************************************/




/*sorry this File Have No Comments I will Come Back To Write All Comments After While */


#include <string.h>
//#include <avr/pgmspace.h>
#include "STD_Macros.h"
#include "UART.h"
#include "SIM900.h"

const char successResp[] = "OK";
const char failResp[] = "ERROR";
const char inNetResp[] = "+CREG: 0,1";
const char outNetResp[] = "+CREG: 0,2";
const char messageSendResp[] = "+CMGS: ";

char buffer[];

unsigned char getCommByte(unsigned int data);
void sendCRLF();

char *getAnswer()
{
	char cmd_buff[20];
    unsigned int c = UART_NO_DATA;
	int j=0;
	while(1)
	{
		c = UART_u8Recive();
		if (c != UART_NO_DATA)
		{
			unsigned char answerChar = getCommByte(c);
			if (answerChar == CR && j!=0)
			{
				break;
			} 
			else if (answerChar != LF && answerChar!= CR)
			{
			  cmd_buff[j] = answerChar;
			  j++;
			}
			else
			{
				// Do No Thing
			}
		}
		else
		{
			// Do No Thing
		}
	}
	return cmd_buff;	
}

void simPowerOn()
{
	DELAY_vMS(startDelay);
	SET_BIT(pwrDDR, pwrPin);
	CLR_BIT(pwrPORT, pwrPin);
	DELAY_vMS(initDelay);
	CLR_BIT(pwrDDR, pwrPin);
}

void simCommInit()
{
	UART_vInit(9600);
	DELAY_vMS(commDelay);
	UART_vSendString("AT+IPR=9600");
	sendCRLF();
	delay(commDelay);
	if (strncmp( getAnswer(), successResp, 2 ) != 0)
	{
	 //sendError
	}
}

void waitForReg()
{
	while(1)
	{
		UART_vSendString("AT+CREG?");
		sendCRLF();
		DELAY_vMS(regDelay);
		if (strncmp( getAnswer(), inNetResp, 10 ) == 0)
		{
			break;
		}	
	}
}

void simSetTextInput()
{
	UART_vSendString("AT+CMGF=1");
	sendCRLF();
	DELAY_vMS(commDelay);
	if (strncmp( getAnswer(), successResp, 2 ) != 0)
	{
	 //sendError
	}
}

void simSetPhone()
{
	UART_vSendString("AT+CMGS=\"+201110809883\"");
	sendCRLF();
	DELAY_vMS(commDelay);
}

void *searchContact(char * contact, size_t len)
{
	buffer[30] = "AT+CPBF=\"";
	buffer[30] = strncat(buffer, contact, len);
	buffer[30] = strncat(buffer, "\"", 1);
	UART_vSendString(buffer);
	sendCRLF();
	DELAY_vMS(commDelay);
	return getAnswer();
}

void simSendMessage()
{
	UART_vSendString("There is some one try to Stole your car");
	sendCRLF();
	DELAY_vMS(commDelay);
	UART_vSendString(inputEnd);
	if (strncasecmp( getAnswer(), messageSendResp, 7) != 0)
	{
	 //sendError
	}	
}

unsigned char getCommByte(unsigned int data)
{
	return (data & 0x00FF);
}

void sendCRLF()
{
	UART_vSendData(CR);
	UART_vSendData(LF);
}