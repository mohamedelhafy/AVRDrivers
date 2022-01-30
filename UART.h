/*
 * USART.h
 *
 * Created: 1/28/2022 1:10:42 AM
 *  Author: Mohamed Elhafy
 */ 


#ifndef USART_H_
#define USART_H_


/*********************************************************************************************************/
/*	Function Name        : UART_vInit                                                                    */
/*	Function Returns     : void											                   			     */
/*	Function Arguments   : unsigned long baudRate									                     */
/*	Function Description : Enable the UART And Set the useful data in the frame 8-bit                    */
/*********************************************************************************************************/
void UART_vInit(uint_32 baudRate);



/*********************************************************************************************************/
/*	Function Name        : UART_vSendData                                                                */
/*	Function Returns     : void											                   			     */
/*	Function Arguments   : unsigned char Data       								                     */
/*	Function Description : Send one byte by the UART                                                     */
/*********************************************************************************************************/
void UART_vSendData(uint_8 Data);




/*********************************************************************************************************/
/*	Function Name        : UART_u8Recive                                                                 */
/*	Function Returns     : unsigned char								                   			     */
/*	Function Arguments   : void														                     */
/*	Function Description : read the UDR receiver buffer                                                  */
/*********************************************************************************************************/
uint_8 UART_u8Recive(void);




/*********************************************************************************************************/
/*	Function Name        : UART_vSendString                                                              */
/*	Function Returns     : void											                   			     */
/*	Function Arguments   : pointer to unsigned char data							                     */
/*	Function Description : Sending string by using UART                                                  */
/*********************************************************************************************************/
void UART_vSendString(uint_8 *data);


#endif /* USART_H_ */