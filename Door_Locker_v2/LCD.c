/*
 * LCD.c
 *
 * Created: 3/14/2015 5:52:58 PM
 *  Author: Dalia Hossam
 */

# define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "STD.h"
#include "common.h"
#include "Config.h"
#include "LCD.h"
#include "LCD_Config.h"


void LCD_Enable(void)
{
	SET_BIT(LCD_C_PORT,LCD_E_PIN_NO);
	CLR_BIT(LCD_C_PORT,LCD_E_PIN_NO);
}

void LCD_SendCommand(u8_t command)
{
	LCD_D_PORT= command;
	CLR_BIT(LCD_C_PORT,LCD_RS_PIN_NO);
	LCD_Enable();
	_delay_ms(5);
}
void LCD_ClearScreen(void)
{
	LCD_SendCommand(1);
}
void LCD_Init(void)
{
	LCD_D_DDR=0xFF;
	LCD_C_DDR=0x07;
	CLR_BIT(LCD_C_PORT,LCD_RW_PIN_NO);
	CLR_BIT(LCD_C_PORT,LCD_RS_PIN_NO);
	LCD_ClearScreen();
	LCD_SendCommand(MODE_8_BIT);
	LCD_SendCommand(DISPLAYON_CURSORON);
}
void LCD_DisplayCharacter(u8_t data)
{
	LCD_D_PORT= data;
	SET_BIT(LCD_C_PORT,LCD_RS_PIN_NO);
	LCD_Enable();
	_delay_ms(5);
}
void LCD_DisplayString(u8_t data[])
{
	u8_t i=0;
	while (data[i]!='\0')
	{
		LCD_DisplayCharacter(data[i]);
		i++;
	}
}
 void LCD_DisplayString_XY(u8_t *data,u8_t row,u8_t coloum)
{

	    LCD_SendCommand(row+coloum);
		_delay_ms(5);
		LCD_DisplayString(data);

}


