/*
 * Timers.h
 *
 * Created: 1/25/2022 12:44:18 AM
 *  Author: Mohamed Elhafy
 */ 


#ifndef TIMERS_H_
#define TIMERS_H_


#include "STD_Macros.h"

/*********************************************************************************************************/
/*	Function Name        : Timer0_vInitNormal_Interrupt                                                  */
/*	Function Returns     : void											                   			     */
/*	Function Arguments   : unsigned char prescaler									                     */
/*	Function Description : Enable Timer/Counter0 in Normal Mode and start count                          */
/*						   with interrupt generated when over flow happen                                */
/*********************************************************************************************************/
void Timer0_vInitNormal_Interrupt(uint_8 prescaler);



/*********************************************************************************************************/
/*	Function Name        : Timer0_vInitCTC_Interrupt                                                     */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned char prescaler , unsigned char cmpVal                                */
/*	Function Description : Enable Timer/Counter0 in Clear Timer on Compare Match (CTC) Mode              */
/*						   and start count with interrupt generated when Compare Match happen            */
/*********************************************************************************************************/
void Timer0_vInitCTC_Interrupt(uint_8 prescaler, uint_8 cmpVal);



/*********************************************************************************************************/
/*	Function Name        : Timer0_vGenratFastPWM                                                         */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned char prescaler , float duty                                          */
/*	Function Description : Generate PWM signal on OC0(PB3) Pin with duty cycle in Fast PWM Mode          */
/*********************************************************************************************************/
void Timer0_vGenratFastPWM(uint_8 prescaler,float_32 duty);




/*********************************************************************************************************/
/*	Function Name        : Timer0_vGenratPWM                                                             */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned char prescaler , float duty                                          */
/*	Function Description : Generate PWM signal in OC0(PB3) Pin with duty cycle in phase correct PWM Mode */
/*********************************************************************************************************/
void Timer0_vGenratPWM(uint_8 prescaler,float_32 duty);



/*********************************************************************************************************/
/*	Function Name        : Timer2_vSetOutPutOSC                                                          */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : void                                                                          */
/*	Function Description : Set the output OSC to timer 2 that will be on pins TOSC (1,2)                 */
/*********************************************************************************************************/
void Timer2_vSetOutPutOSC(void);




/*********************************************************************************************************/
/*	Function Name        : Timer2_vInitNormal_Interrupt                                                  */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned char prescaler                                                       */
/*	Function Description : Enable Timer/Counter2 in Normal Mode and start count                          */
/*						   with interrupt generated when over flow happen                                */
/*********************************************************************************************************/
void Timer2_vInitNormal_Interrupt(uint_8 prescaler);




/*********************************************************************************************************/
/*	Function Name        : Timer2_vInitCTC_Interrupt                                                     */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned char prescaler , unsigned char cmpVal                                */
/*	Function Description : Enable Timer/Counter2 in Clear Timer on Compare Match (CTC) Mode              */
/*						   and start count with interrupt generated when Compare Match happen            */
/*********************************************************************************************************/
void Timer2_vInitCTC_Interrupt(uint_8 prescaler,uint_8 cmpVal);




/*********************************************************************************************************/
/*	Function Name        : Timer2_vGenratFastPWM                                                         */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned char prescaler , unsigned char cmpVal                                */
/*	Function Description : Generate PWM signal in OC2(PD7) Pin with duty cycle in Fast PWM Mode          */
/*********************************************************************************************************/
void Timer2_vGenratFastPWM(uint_8 prescaler, float_32 duty);




/*********************************************************************************************************/
/*	Function Name        : Timer2_vGenratPWM                                                             */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned char prescaler , float duty                                          */
/*	Function Description : Generate PWM signal in OC2(PD7) Pin with duty cycle in phase correct PWM Mode */
/*********************************************************************************************************/
void Timer2_vGenratPWM(uint_8 prescaler, float_32 duty);




/*********************************************************************************************************/
/*	Function Name        : Timer1_vInitNormal_Interrupt                                                  */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned char prescaler                                                       */
/*	Function Description : Enable Timer/Counter1 in Normal Mode and start count                          */
/*						   with interrupt generated when over flow happen                                */
/*********************************************************************************************************/
void Timer1_vInitNormal_Interrupt(uint_8 prescaler);




/*********************************************************************************************************/
/*	Function Name        : Timer1_vInitCTC_Interrupt                                                     */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned char prescaler , unsigned char cmpVal                                */
/*	Function Description : Enable Timer/Counter1 in Clear Timer on Compare Match (CTC) Mode              */
/*	  and start count with interrupt generated when Compare Match happen With OCR1A And Clear the TCNT   */
/*********************************************************************************************************/
void Timer1_vInitCTC_Interrupt(uint_8 prescaler,uint_16 cmpVal);




/*********************************************************************************************************/
/*	Function Name        : Timer1_vInitCompareMatchB_Interrupt                                           */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned char prescaler , unsigned char cmpVal                                */
/*	Function Description : Enable Timer/Counter1 in Clear Timer on Compare Match (CTC) Mode              */
/* and start count with interrupt generated when Compare Match happen  With OCR1B without Clear the TCNT */
/*********************************************************************************************************/
void Timer1_vInitCompareMatchB_Interrupt(uint_8 prescaler,uint_16 cmpVal);




/*********************************************************************************************************/
/*	Function Name        : Timer1_vGenratFastPWM_OnOC1Apin                                               */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned char prescaler , unsigned char cmpVal                                */
/*	Function Description : Generate PWM signal in OC1A(PD5) Pin with duty cycle in Fast PWM Mode         */
/*********************************************************************************************************/
void Timer1_vGenratFastPWM_OnOC1Apin(uint_8 prescaler, float_32 duty,uint_8 mode);




/*********************************************************************************************************/
/*	Function Name        : Timer1_vGenratFastPWM_OnOC1Bpin                                               */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned char prescaler , unsigned char cmpVal                                */
/*	Function Description : Generate PWM signal in OC1A(PD4) Pin with duty cycle in Fast PWM Mode         */
/*********************************************************************************************************/
void Timer1_vGenratFastPWM_OnOC1Bpin(uint_8 prescaler, float_32 duty,uint_8 mode);




/*********************************************************************************************************/
/*	Function Name        : Timer1_vGenratPWM_OnOC1Apin                                                   */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned char prescaler , float duty                                          */
/*	Function Description : Generate PWM signal in OC1A(PD5) Pin with duty cycle in phase correct PWM Mode*/
/*********************************************************************************************************/
void Timer1_vGenratPWM_OnOC1Apin(uint_8 prescaler, float_32 duty,uint_8 mode);





/*********************************************************************************************************/
/*	Function Name        : Timer1_vGenratPWM_OnOC1Bpin                                                   */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned char prescaler , float duty                                          */
/*	Function Description : Generate PWM signal in OC1B(PD4) Pin with duty cycle in phase correct PWM Mode*/
/*********************************************************************************************************/
void Timer1_vGenratPWM_OnOC1Bpin(uint_8 prescaler, float_32 duty,uint_8 mode);





/*********************************************************************************************************/
/*	Function Name        : watchDogTimer_vSleep_ms                                                       */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned short time                                                           */
/*	Function Description : Set the Watch dog timer enable to reset me is i dont disable it               */
/*********************************************************************************************************/
void watchDogTimer_vSleep_ms(uint_16 time);





/*********************************************************************************************************/
/*	Function Name        : watchDogTimer_vDisable                                                        */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : void                                                                          */
/*	Function Description : disable the watch dog timer                                                   */
/*********************************************************************************************************/
void watchDogTimer_vDisable(void);



/*********************************************************************************************************/
/*	Function Name        : Timer1_vGenratFstPWM_OnOC1ApinWithOnTime                                      */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned short onTime, unsigned short all time                                */
/*	Function Description : Generate PWM signal in OC1A(PD5) Pin with duty cycle in phase correct PWM Mode*/ 
/*                        And clear the timer on ICR val                                                 */
/*********************************************************************************************************/
void Timer1_vGenratFstPWM_OnOC1ApinWithOnTimeInUs(uint_16 onTime,uint_16 allTime);



/*********************************************************************************************************/
/*	Function Name        : Timer1_vGenratFstPWM_OnOC1ApinWithOnTime                                      */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned short onTime, unsigned short all time                                */
/*	Function Description : Generate PWM signal in OC1B(PD4) Pin with duty cycle in phase correct PWM Mode*/
/*                        And clear the timer on ICR val                                                 */
/*********************************************************************************************************/
void Timer1_vGenratFastPWM_OnOC1BpinWithOnTimeInUs(uint_16 onTime,uint_16 allTime);


//ICU and the Rest of timer1 implemintation 
#endif /* TIMERS_H_ */