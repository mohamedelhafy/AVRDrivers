/*
 * Timers.c
 *
 * Created: 1/25/2022 12:43:47 AM
 *  Author: Mohamed Elhafy
 */ 

#include "STD_Macros.h"
#include <avr/interrupt.h>
#include "DIO.h"



/*********************************************************************************************************/
/*	Function Name        : Timer0_vInitNormal_Interrupt                                                  */
/*	Function Returns     : void											                   			     */
/*	Function Arguments   : unsigned char prescaler									                     */
/*	Function Description : Enable Timer/Counter0 in Normal Mode and start count                          */
/*						   with interrupt generated when over flow happen                                */
/*********************************************************************************************************/
void Timer0_vInitNormal_Interrupt(uint_8 prescaler)
{	
	/******************************************************************************************************/
	/*Please If you use this func. Make sure that you enable the I-Bit And handle the ISR(TIMER0_OVF_vect)*/
	/******************************************************************************************************/
	uint_8 i;
	if (prescaler>7)
	{
		prescaler=5;
	}
	/*setting the prescaler to the Timer/Counter0 Input Clock */
	for (i=0;i<3;i++)
	{
		if (IS_BIT_SET(prescaler,i))
		{
			SET_BIT(TCCR0,i);
		} 
		else
		{
			CLR_BIT(TCCR0,i);
		}
	}
	
	 /*Setting the Timer/Counter0 Mode 00 for Normal Mode */
	 CLR_BIT(TCCR0,WGM00);
	 CLR_BIT(TCCR0,WGM01);
	 /*Enable the Interrupt Mask*/
	 SET_BIT(TIMSK,TOIE0);
	 //sei();
}




/*********************************************************************************************************/
/*	Function Name        : Timer0_vInitCTC_Interrupt                                                     */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned char prescaler , unsigned char cmpVal                                */
/*	Function Description : Enable Timer/Counter0 in Clear Timer on Compare Match (CTC) Mode              */
/*						   and start count with interrupt generated when Compare Match happen            */
/*********************************************************************************************************/
void Timer0_vInitCTC_Interrupt(uint_8 prescaler, uint_8 cmpVal)
{
	/*******************************************************************************************************/
	/*Please If you use this func. Make sure that you enable the I-Bit And handle the ISR(TIMER0_COMP_vect)*/
	/*******************************************************************************************************/
	uint_8 i;
	if (prescaler>7)
	{
		prescaler=5;
	}
	/*setting the prescaler to the Timer/Counter0 Input Clock */
	for (i=0;i<3;i++)
	{
		if (IS_BIT_SET(prescaler,i))
		{
			SET_BIT(TCCR0,i);
		}
		else
		{
			CLR_BIT(TCCR0,i);
		}
	}
	
	OCR0=cmpVal;
	
	/*Setting the Timer/Counter0 Mode 10 for CTC Mode */
	CLR_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	
	//Setting the interrupt Mask
	SET_BIT(TIMSK,OCIE0);
}




/*********************************************************************************************************/
/*	Function Name        : Timer0_vGenratFastPWM                                                         */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned char prescaler , float duty                                          */
/*	Function Description : Generate PWM signal on OC0(PB3) Pin with duty cycle in Fast PWM Mode          */
/*********************************************************************************************************/
void Timer0_vGenratFastPWM(uint_8 prescaler,float_32 duty)
{
	/************************************************************************/
	/*                    Generate Fast PWM Signal In OC0                   */
	/************************************************************************/
	DIO_vSetPinDirOutput('B',4);
	uint_8 i;
	if (prescaler>7)
	{
		prescaler=5;
	}
	/*setting the prescaler to the Timer/Counter0 Input Clock */
	for (i=0;i<3;i++)
	{
		if (IS_BIT_SET(prescaler,i))
		{
			SET_BIT(TCCR0,i);
		}
		else
		{
			CLR_BIT(TCCR0,i);
		}
	}
	
	//Set the OCR0 Value that is the high time 
	OCR0=(uint_8)(duty*256);
	//Set it As clear Pin OC0 in Compare match and Work the pin in Fast PWM Mode 
	SET_BIT(TCCR0,COM01);
	CLR_BIT(TCCR0,COM00);
	/*Setting the Timer/Counter0 Mode 11 for Fast PWM Mode */
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
}





/*********************************************************************************************************/
/*	Function Name        : Timer0_vGenratPWM                                                             */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned char prescaler , float duty                                          */
/*	Function Description : Generate PWM signal in OC0(PB3) Pin with duty cycle in phase correct PWM Mode */
/*********************************************************************************************************/
void Timer0_vGenratPWM(uint_8 prescaler,float_32 duty)
{
	/************************************************************************/
	/*                   Generate PWM Signal in OC0                         */
	/************************************************************************/
	DIO_vSetPinDirOutput('B',4);
	uint_8 i;
	if (prescaler>7)
	{
		prescaler=5;
	}
	/*setting the prescaler to the Timer/Counter0 Input Clock */
	for (i=0;i<3;i++)
	{
		if (IS_BIT_SET(prescaler,i))
		{
			SET_BIT(TCCR0,i);
		}
		else
		{
			CLR_BIT(TCCR0,i);
		}
	}
	
	//Set the OCR0 Value that is the high time
	OCR0=(uint_8)(duty*510);
	
	//Set it As clear Pin OC0 in Compare match and Work the pin in Fast PWM Mode
	SET_BIT(TCCR0,COM01);
	CLR_BIT(TCCR0,COM00);
	
	/*Setting the Timer/Counter0 Mode 11 for Fast PWM Mode */
	SET_BIT(TCCR0,WGM00);
	CLR_BIT(TCCR0,WGM01);
}





/*********************************************************************************************************/
/*	Function Name        : Timer2_vSetOutPutOSC                                                          */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : void                                                                          */
/*	Function Description : Set the output OSC to timer 2 that will be on pins TOSC (1,2)                 */
/*********************************************************************************************************/
void Timer2_vSetOutPutOSC(void)
{
	/******************************************************************/
	/*Please use this func. before using any func. of timer/counter0  */
	/*        if you use external clock in TOSC pins                  */
	/******************************************************************/
	SET_BIT(ASSR,AS2);
}





/*********************************************************************************************************/
/*	Function Name        : Timer2_vInitNormal_Interrupt                                                  */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned char prescaler                                                       */
/*	Function Description : Enable Timer/Counter2 in Normal Mode and start count                          */
/*						   with interrupt generated when over flow happen                                */
/*********************************************************************************************************/
void Timer2_vInitNormal_Interrupt(uint_8 prescaler)
{
	/*Please If you use this func. Make sure that you enable the I-Bit And handle the ISR(TIMER0_OVF_vect)*/
	uint_8 i;
	if (prescaler>7)
	{
		prescaler=5;
	}
	/*setting the prescaler to the Timer/Counter2 Input Clock */
	for (i=0;i<3;i++)
	{
		if (IS_BIT_SET(prescaler,i))
		{
			SET_BIT(TCCR2,i);
		}
		else
		{
			CLR_BIT(TCCR2,i);
		}
	}
	
	/*Setting the Timer/Counter2 Mode 00 for Normal Mode */
	CLR_BIT(TCCR2,WGM20);
	CLR_BIT(TCCR2,WGM21);
	/*Enable the Interrupt Mask*/
	SET_BIT(TIMSK,TOIE2);
}





/*********************************************************************************************************/
/*	Function Name        : Timer2_vInitCTC_Interrupt                                                     */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned char prescaler , unsigned char cmpVal                                */
/*	Function Description : Enable Timer/Counter2 in Clear Timer on Compare Match (CTC) Mode              */
/*						   and start count with interrupt generated when Compare Match happen            */
/*********************************************************************************************************/
void Timer2_vInitCTC_Interrupt(uint_8 prescaler,uint_8 cmpVal)
{
	/******************************************************************/
	/*Please If you use this func. Make sure that you enable the I-Bit*/
	/*            And handle the ISR(TIMER2_COMP_vect)                */
	/******************************************************************/
	uint_8 i;
	if (prescaler>7)
	{
		prescaler=5;
	}
	/*setting the prescaler to the Timer/Counter2 Input Clock */
	for (i=0;i<3;i++)
	{
		if (IS_BIT_SET(prescaler,i))
		{
			SET_BIT(TCCR2,i);
		}
		else
		{
			CLR_BIT(TCCR2,i);
		}
	}
	
	OCR2=cmpVal;
	
	/*Setting the Timer/Counter0 Mode 10 for CTC Mode */
	CLR_BIT(TCCR2,WGM20);
	SET_BIT(TCCR2,WGM21);
	
	//Setting the interrupt Mask
	SET_BIT(TIMSK,OCIE2);
}





/*********************************************************************************************************/
/*	Function Name        : Timer2_vGenratFastPWM                                                         */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned char prescaler , unsigned char cmpVal                                */
/*	Function Description : Generate PWM signal in OC2(PD7) Pin with duty cycle in Fast PWM Mode          */
/*********************************************************************************************************/
void Timer2_vGenratFastPWM(uint_8 prescaler, float_32 duty)
{
	/************************************************************************/
	/*                    Generate Fast PWM Signal In OC2                   */
	/************************************************************************/
	//set the pin output pin 
	DIO_vSetPinDirOutput('D',7);
	uint_8 i;
	if (prescaler>7)
	{
		prescaler=5;
	}
	/*setting the prescaler to the Timer/Counter2 Input Clock */
	for (i=0;i<3;i++)
	{
		if (IS_BIT_SET(prescaler,i))
		{
			SET_BIT(TCCR2,i);
		}
		else
		{
			CLR_BIT(TCCR2,i);
		}
	}
	
	//Set the OCR2 Value that is the high time
	OCR2=(uint_8)(duty*256);
	//Set it As clear Pin OC2 in Compare match and Work the pin in Fast PWM Mode
	SET_BIT(TCCR2,COM21);
	CLR_BIT(TCCR2,COM20);
	/*Setting the Timer/Counter2 Mode 11 for Fast PWM Mode */
	SET_BIT(TCCR2,WGM20);
	SET_BIT(TCCR2,WGM21);
}





/*********************************************************************************************************/
/*	Function Name        : Timer2_vGenratPWM                                                             */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned char prescaler , float duty                                          */
/*	Function Description : Generate PWM signal in OC2(PD7) Pin with duty cycle in phase correct PWM Mode */
/*********************************************************************************************************/
void Timer2_vGenratPWM(uint_8 prescaler, float_32 duty)
{
	/************************************************************************/
	/*                      Generate PWM Signal In OC2                      */
	/************************************************************************/
	// set the pin output pin 
	DIO_vSetPinDirOutput('D',7);
	uint_8 i;
	if (prescaler>7)
	{
		prescaler=5;
	}
	/*setting the prescaler to the Timer/Counter2 Input Clock */
	for (i=0;i<3;i++)
	{
		if (IS_BIT_SET(prescaler,i))
		{
			SET_BIT(TCCR2,i);
		}
		else
		{
			CLR_BIT(TCCR2,i);
		}
	}
	
	//Set the OCR0 Value that is the high time
	OCR2=(uint_8)(duty*510);
	
	//Set it As clear Pin OC2 in Compare match and Work the pin in Fast PWM Mode
	SET_BIT(TCCR2,COM21);
	CLR_BIT(TCCR2,COM20);
	
	/*Setting the Timer/Counter2 Mode 11 for Fast PWM Mode */
	SET_BIT(TCCR2,WGM20);
	CLR_BIT(TCCR2,WGM21);
}





/*********************************************************************************************************/
/*	Function Name        : Timer1_vInitNormal_Interrupt                                                  */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned char prescaler                                                       */
/*	Function Description : Enable Timer/Counter1 in Normal Mode and start count                          */
/*						   with interrupt generated when over flow happen                                */
/*********************************************************************************************************/
void Timer1_vInitNormal_Interrupt(uint_8 prescaler)
{
	/***********************************************************************************************/
	/*if you use this func. Make sure that you Enable the I-bit And handle the ISR(TIMER1_OVF_vect)*/
	/***********************************************************************************************/
	uint_8 i;
	if (prescaler>7)
	{
		prescaler=5;
	}
	/*setting the prescaler to the Timer/Counter1 Input Clock */
	for (i=0;i<3;i++)
	{
		if (IS_BIT_SET(prescaler,i))
		{
			SET_BIT(TCCR1B,i);
		}
		else
		{
			CLR_BIT(TCCR1B,i);
		}
	}
	/*clear all WGM bits to make sure that We operate in the normal mode*/
	CLR_BIT(TCCR1A,WGM10);
	CLR_BIT(TCCR1A,WGM11);
	CLR_BIT(TCCR1B,WGM12);
	CLR_BIT(TCCR1B,WGM13);
	
	/*Set the enable bit for OVF interrupt */
	SET_BIT(TIMSK,TOIE1);
}





/*********************************************************************************************************/
/*	Function Name        : Timer1_vInitCTC_Interrupt                                                     */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned char prescaler , unsigned char cmpVal                                */
/*	Function Description : Enable Timer/Counter1 in Clear Timer on Compare Match (CTC) Mode              */
/*	  and start count with interrupt generated when Compare Match happen With OCR1A And Clear the TCNT   */
/*********************************************************************************************************/
void Timer1_vInitCTC_Interrupt(uint_8 prescaler,uint_16 cmpVal)
{
	/********************************************************************************************/
	/*if you use this func. Make sure that you Enable the I-bit And handle the ISR(TIMER1__vect)*/
	/********************************************************************************************/
	uint_8 i;
	if (prescaler>7)
	{
		prescaler=5;
	}
	/*setting the prescaler to the Timer/Counter0 Input Clock */
	for (i=0;i<3;i++)
	{
		if (IS_BIT_SET(prescaler,i))
		{
			SET_BIT(TCCR1B,i);
		}
		else
		{
			CLR_BIT(TCCR1B,i);
		}
	}
	/*Set the upper limit of TCNT*/
	OCR1A=cmpVal;
	
	/*Setup the WGM bits*/
	CLR_BIT(TCCR1A,WGM10);
	CLR_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	CLR_BIT(TCCR1B,WGM13);
	/*Enable Interrupt Mask For the Compare Match Enable */
	SET_BIT(TIMSK,OCIE1A);
}






/*********************************************************************************************************/
/*	Function Name        : Timer1_vInitCompareMatchB_Interrupt                                           */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned char prescaler , unsigned char cmpVal                                */
/*	Function Description : Enable Timer/Counter1 in Clear Timer on Compare Match (CTC) Mode              */
/* and start count with interrupt generated when Compare Match happen  With OCR1B without Clear the TCNT */
/*********************************************************************************************************/
void Timer1_vInitCompareMatchB_Interrupt(uint_8 prescaler,uint_8 cmpVal)
{
	/************************************************************************/
	/* before use this func. please make soure you Select the Mode And Make */
	/*    sure that the OCR1A is Bigger than OCR1B OR ICR1 in CTC Mode      */
	/*              And handle the ICR(TIMER1_COMPB_vect)                   */
	/************************************************************************/
	SET_BIT(TIMSK,OCIE1B);
}





/*********************************************************************************************************/
/*	Function Name        : Timer1_vGenratFastPWM_OnOC1Apin                                               */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned char prescaler , unsigned char cmpVal                                */
/*	Function Description : Generate PWM signal in OC1A(PD5) Pin with duty cycle in Fast PWM Mode         */
/*********************************************************************************************************/
void Timer1_vGenratFastPWM_OnOC1Apin(uint_8 prescaler, float_32 duty ,uint_8 mode)
{
	/************************************************************************/
	/* Generate Fast PWM signal On OC1A                                     */
	/************************************************************************/
	DIO_vSetPinDirOutput('D',5);
	uint_8 i;
	if (prescaler>7)
	{
		prescaler=5;
	}
	/*setting the prescaler to the Timer/Counter1 Input Clock */
	for (i=0;i<3;i++)
	{
		if (IS_BIT_SET(prescaler,i))
		{
			SET_BIT(TCCR1B,i);
		}
		else
		{
			CLR_BIT(TCCR1B,i);
		}
	}
	
	switch(mode)
	{
		case 8:
			SET_BIT(TCCR1A,WGM10);
			CLR_BIT(TCCR1A,WGM11);
			SET_BIT(TCCR1B,WGM12);
			CLR_BIT(TCCR1B,WGM13);
			OCR1A=(uint_16)(duty*256);
			break;
		case 9:
			CLR_BIT(TCCR1A,WGM10);
			SET_BIT(TCCR1A,WGM11);
			SET_BIT(TCCR1B,WGM12);
			CLR_BIT(TCCR1B,WGM13);
			OCR1A=(uint_16)(duty*0x1ff);
			break;
		case 10:
		default:
			SET_BIT(TCCR1A,WGM10);
			SET_BIT(TCCR1A,WGM11);
			SET_BIT(TCCR1B,WGM12);
			CLR_BIT(TCCR1B,WGM13);
			OCR1A=(uint_16)(duty*0x3ff);
			break;
	}
	
	CLR_BIT(TCCR1A,COM1A0);
	SET_BIT(TCCR1A,COM1A1);
}






/*********************************************************************************************************/
/*	Function Name        : Timer1_vGenratFastPWM_OnOC1Bpin                                               */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned char prescaler , unsigned char cmpVal                                */
/*	Function Description : Generate PWM signal in OC1A(PD4) Pin with duty cycle in Fast PWM Mode         */
/*********************************************************************************************************/
void Timer1_vGenratFastPWM_OnOC1Bpin(uint_8 prescaler, float_32 duty,uint_8 mode)
{
	DIO_vSetPinDirOutput('D',4);
	//set Prescaler
	uint_8 i;
	if (prescaler>7)
	{
		prescaler=5;
	}
	/*setting the prescaler to the Timer/Counter1 Input Clock */
	for (i=0;i<3;i++)
	{
		if (IS_BIT_SET(prescaler,i))
		{
			SET_BIT(TCCR1B,i);
		}
		else
		{
			CLR_BIT(TCCR1B,i);
		}
	}
	switch(mode)
	{
		case 8:
			SET_BIT(TCCR1A,WGM10);
			CLR_BIT(TCCR1A,WGM11);
			SET_BIT(TCCR1B,WGM12);
			CLR_BIT(TCCR1B,WGM13);
			OCR1B=(uint_16)(duty*256);
			break;
			
		case 9:
			CLR_BIT(TCCR1A,WGM10);
			SET_BIT(TCCR1A,WGM11);
			SET_BIT(TCCR1B,WGM12);
			CLR_BIT(TCCR1B,WGM13);
			OCR1B=(uint_16)(duty*0x1ff);
			break;
			
		case 10:
		default:
			SET_BIT(TCCR1A,WGM10);
			SET_BIT(TCCR1A,WGM11);
			SET_BIT(TCCR1B,WGM12);
			CLR_BIT(TCCR1B,WGM13);
			OCR1B=(uint_16)(duty*0x3ff);
			break;
	}
	
	CLR_BIT(TCCR1A,COM1B0);
	SET_BIT(TCCR1A,COM1B1);
}





/*********************************************************************************************************/
/*	Function Name        : Timer1_vGenratPWM_OnOC1Apin                                                   */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned char prescaler , float duty                                          */
/*	Function Description : Generate PWM signal in OC1A(PD5) Pin with duty cycle in phase correct PWM Mode*/
/*********************************************************************************************************/
void Timer1_vGenratPWM_OnOC1Apin(uint_8 prescaler, float_32 duty,uint_8 mode)
{
	DIO_vSetPinDirOutput('D',5);
	uint_8 i;
	if (prescaler>7)
	{
		prescaler=5;
	}
	/*setting the prescaler to the Timer/Counter1 Input Clock */
	for (i=0;i<3;i++)
	{
		if (IS_BIT_SET(prescaler,i))
		{
			SET_BIT(TCCR1B,i);
		}
		else
		{
			CLR_BIT(TCCR1B,i);
		}
	}
	
	switch(mode)
	{
		case 8:
			SET_BIT(TCCR1A,WGM10);
			CLR_BIT(TCCR1A,WGM11);
			CLR_BIT(TCCR1B,WGM12);
			CLR_BIT(TCCR1B,WGM13);
			OCR1A=(uint_16)(duty*510);
			break;
			
		case 9:
			CLR_BIT(TCCR1A,WGM10);
			SET_BIT(TCCR1A,WGM11);
			CLR_BIT(TCCR1B,WGM12);
			CLR_BIT(TCCR1B,WGM13);
			OCR1A=(uint_16)(duty*((2*0x1ff)-2));
			break;
		
		case 10:
		default:
			SET_BIT(TCCR1A,WGM10);
			SET_BIT(TCCR1A,WGM11);
			CLR_BIT(TCCR1B,WGM12);
			CLR_BIT(TCCR1B,WGM13);
			OCR1A=(uint_16)(duty*((2*0x1ff)-2));
			break;
	}
	CLR_BIT(TCCR1A,COM1A0);
	SET_BIT(TCCR1A,COM1A1);
}






/*********************************************************************************************************/
/*	Function Name        : Timer1_vGenratPWM_OnOC1Bpin                                                   */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned char prescaler , float duty                                          */
/*	Function Description : Generate PWM signal in OC1B(PD4) Pin with duty cycle in phase correct PWM Mode*/
/*********************************************************************************************************/
void Timer1_vGenratPWM_OnOC1Bpin(uint_8 prescaler, float_32 duty, uint_8 mode)
{
	DIO_vSetPinDirOutput('D',4);
	uint_8 i;
	if (prescaler>7)
	{
		prescaler=5;
	}
	/*setting the prescaler to the Timer/Counter1 Input Clock */
	for (i=0;i<3;i++)
	{
		if (IS_BIT_SET(prescaler,i))
		{
			SET_BIT(TCCR1B,i);
		}
		else
		{
			CLR_BIT(TCCR1B,i);
		}
	}
	
	switch(mode)
	{
		case 8:
			SET_BIT(TCCR1A,WGM10);
			CLR_BIT(TCCR1A,WGM11);
			CLR_BIT(TCCR1B,WGM12);
			CLR_BIT(TCCR1B,WGM13);
			OCR1B=(uint_16)(duty*510);
		break;
		
		case 9:
			CLR_BIT(TCCR1A,WGM10);
			SET_BIT(TCCR1A,WGM11);
			CLR_BIT(TCCR1B,WGM12);
			CLR_BIT(TCCR1B,WGM13);
			OCR1B=(uint_16)(duty*((2*0x1ff)-2));
		break;
		
		case 10:
		default:
			SET_BIT(TCCR1A,WGM10);
			SET_BIT(TCCR1A,WGM11);
			CLR_BIT(TCCR1B,WGM12);
			CLR_BIT(TCCR1B,WGM13);
			OCR1B=(uint_16)(duty*((2*0x1ff)-2));
		break;
	}
	CLR_BIT(TCCR1A,COM1B0);
	SET_BIT(TCCR1A,COM1B1);
}





/*********************************************************************************************************/
/*	Function Name        : watchDogTimer_vSleep_ms                                                       */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned short time                                                           */
/*	Function Description : Set the Watch dog timer enable to reset me is i dont disable it               */
/*********************************************************************************************************/
void watchDogTimer_vSleep_ms(uint_16 time)
{
	if (time<=16)
	{
		CLR_BIT(WDTCR,WDP0);
		CLR_BIT(WDTCR,WDP1);
		CLR_BIT(WDTCR,WDP2);
	} 
	else if(time<=34)
	{
		SET_BIT(WDTCR,WDP0);
		CLR_BIT(WDTCR,WDP1);
		CLR_BIT(WDTCR,WDP2);
	}
	else if (time<=65)
	{
		CLR_BIT(WDTCR,WDP0);
		SET_BIT(WDTCR,WDP1);
		CLR_BIT(WDTCR,WDP2);
	}
	else if (time<=130)
	{
		SET_BIT(WDTCR,WDP0);
		SET_BIT(WDTCR,WDP1);
		CLR_BIT(WDTCR,WDP2);
	}
	else if (time<=260)
	{
		CLR_BIT(WDTCR,WDP0);
		CLR_BIT(WDTCR,WDP1);
		SET_BIT(WDTCR,WDP2);
	}
	else if (time<=520)
	{
		SET_BIT(WDTCR,WDP0);
		CLR_BIT(WDTCR,WDP1);
		SET_BIT(WDTCR,WDP2);
	}
	else if (time<=1000)
	{
		CLR_BIT(WDTCR,WDP0);
		SET_BIT(WDTCR,WDP1);
		SET_BIT(WDTCR,WDP2);
	}
	else 
	{
		SET_BIT(WDTCR,WDP0);
		SET_BIT(WDTCR,WDP1);
		SET_BIT(WDTCR,WDP2);
	}
	
	SET_BIT(WDTCR,WDE);
}







/*********************************************************************************************************/
/*	Function Name        : watchDogTimer_vDisable                                                        */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : void                                                                          */
/*	Function Description : disable the watch dog timer                                                   */
/*********************************************************************************************************/
void watchDogTimer_vDisable(void)
{
	SET_BIT(WDTCR,WDTOE);
	CLR_BIT(WDTCR,WDE);
}








/*********************************************************************************************************/
/*	Function Name        : Timer1_vGenratFstPWM_OnOC1ApinWithOnTime                                      */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned short onTime, unsigned short all time                                */
/*	Function Description : Generate PWM signal in OC1A(PD5) Pin with duty cycle in phase correct PWM Mode*/
/*                        And clear the timer on ICR val                                                 */
/*********************************************************************************************************/
void Timer1_vGenratFstPWM_OnOC1ApinWithOnTimeInUs(uint_16 onTime,uint_16 allTime)
{
	DIO_vSetPinDirOutput('D',5);
	CLR_BIT(TCCR1B,CS10);
	SET_BIT(TCCR1B,CS11);
	CLR_BIT(TCCR1B,CS12);
	
	// Set the Wave Generation Mode
	CLR_BIT(TCCR1A,WGM10);
	SET_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);
	
	// Load the ICR value
	ICR1 = allTime;
	//set the OCR value
	OCR1A = onTime;
	// clear pin on compare match
	CLR_BIT(TCCR1A,COM1A0);
	SET_BIT(TCCR1A,COM1A1);
}





/*********************************************************************************************************/
/*	Function Name        : Timer1_vGenratFstPWM_OnOC1ApinWithOnTime                                      */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned short onTime, unsigned short all time                                */
/*	Function Description : Generate PWM signal in OC1B(PD4) Pin with duty cycle in phase correct PWM Mode*/
/*                        And clear the timer on ICR val                                                 */
/*********************************************************************************************************/
void Timer1_vGenratFastPWM_OnOC1BpinWithOnTimeInUs(uint_16 onTime,uint_16 allTime)
{
	DIO_vSetPinDirOutput('D',4);
	CLR_BIT(TCCR1B,CS10);
	SET_BIT(TCCR1B,CS11);
	CLR_BIT(TCCR1B,CS12);
	
	// Set the Wave Generation Mode
	CLR_BIT(TCCR1A,WGM10);
	SET_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);
		
	// Load the ICR value
	ICR1 = allTime;
	//set the OCR value
	OCR1B = onTime;
	// clear pin on compare match
	CLR_BIT(TCCR1A,COM1B0);
	SET_BIT(TCCR1A,COM1B1);
}