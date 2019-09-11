/*
 * InterfacingUART.h
 *
 * Created: 3/21/2015 03:45:56 م
 *  Author: Dalia Hossam
 */

#ifndef INTERFACINGUART_H_
#define INTERFACINGUART_H_

#include "STD.h"


void UART_Init();
void UART_SendByte(s8_t Data);
s8_t UART_RecieveByte();
void UART_SendString();
void UART_RecieveString();


#endif /* INTERFACINGUART_H_ */