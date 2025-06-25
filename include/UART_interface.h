/*
 * UART_interface.h
 *
 *  Created on: Mar 21, 2025
 *      Author: Mostafa Mohamed
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

void UART1_Peripheral_init();
void UART1_Dis_RX_Interrupt(void);
void UART1_En_RX_Interrupt(void);
void UART1_Send_Data(u8_t Data);
u8_t UART1_Recieve_Data();
void UART_Call_Back_Function_USART1(void (*ptr)(void));
void UART1_ReceiveLine(char *buffer);
void UART1_Clear_Overrun_Error(void);
u8_t UART1_Is_Overrun_Error(void);

#endif /* UART_INTERFACE_H_ */
