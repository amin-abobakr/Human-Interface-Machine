/*
 * InterfacingUART.c
 *
 * Created: 3/21/2015 03:45:56 م
 *  Author: Dalia Hossam
 */

#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>
#include "Interfacing_UART.h"
#include "common.h"



void UART_Init()
{
	CLR_BIT(UCSRA,U2X);
	
	UBRRL=12;
	
	SET_BIT(UCSRB,TXEN);
	SET_BIT(UCSRB,RXEN);
	CLR_BIT(UCSRB,UCSZ2);
	
	SET_BIT(UCSRC,URSEL);
	CLR_BIT(UCSRC,UPM0);
	CLR_BIT(UCSRC,UPM1);
	CLR_BIT(UCSRC,USBS);
	SET_BIT(UCSRC,UCSZ1);
	SET_BIT(UCSRC,UCSZ0);
		
}


void UART_SendByte(s8_t Data)
{
	while(!(UCSRA & (1<<UDRE)));
	UDR=Data;
	_delay_ms(10);
}

s8_t UART_RecieveByte()
{
	s8_t temp;
	while(!(UCSRA & (1<<RXC)));
	temp = UDR;
	return temp;
}