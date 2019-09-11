
/*
 * Function.c
 *
 * Created: 3/21/2015 03:45:56 ?
 *  Author: Dalia Hossam
 */

# define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "Config.h"
#include "LCD.h"
#include "Keypad.h"
#include "LED.h"
#include "Function.h"
#include "STD.h"
#include "Buzzer.h"


u8_t i;
u8_t First_Password[4];
u8_t Repeat_Password[4];

void Scan_Pass_First(void)
{
	LCD_DisplayString_XY("Plz enter a pass",0xC0,0);
	LCD_SendCommand(0x90+5);
	
	for (i=0;i<4;i++)
	{
		First_Password[i]=Key_Pressed(Get_Key());
		LCD_DisplayCharacter('*');
	}
	
	LCD_ClearScreen();
	_delay_ms(500);
	
 	for (i=0;i<4;i++)
 	{
 		UART_SendByte(First_Password[i]);
 		_delay_ms(50);
 	}
	 
	LCD_DisplayString_XY("Ur Pass Is Saved",0xc0,0);
	_delay_ms(1000);
	LCD_ClearScreen();
}

void Scan_Pass_Repeat(void)
{
	LCD_DisplayString_XY("Enter pass again",0xc0,0);
	LCD_SendCommand(0x90+5);
	
	for (i=0;i<4;i++)
	{
		Repeat_Password[i]=Key_Pressed(Get_Key());
		LCD_DisplayCharacter('*');
	}
	
	UART_SendByte(Repeat_Password[0]);
	_delay_ms(50);
	UART_SendByte(Repeat_Password[1]);
	_delay_ms(50);
	UART_SendByte(Repeat_Password[2]);
	_delay_ms(50);
	UART_SendByte(Repeat_Password[3]);
	_delay_ms(50);
		
	LCD_ClearScreen();
}

u8_t Compare_Pass(void)
{
u8_t CheckPwd;
if (First_Password[0]==Repeat_Password[0]  &&  First_Password[1]==Repeat_Password[1]  &&  First_Password[2]==Repeat_Password[2]  &&  First_Password[3]==Repeat_Password[3])
{
		CheckPwd=True;
	}
 	else
 	{
 		CheckPwd=False;
 	}
 	return CheckPwd; 	
 }
u8_t Recieve_PWD_Comp(void)
{
	u8_t Check;
	Check=UART_RecieveByte();
	_delay_ms(15);
	return Check;
}
void Correct_Pwd(void)
{
	LCD_DisplayString_XY("Right PASSWORD",0xc0,1);
	_delay_ms(1000);
	LCD_ClearScreen();
}

void Wrong_Pwd(void)
{
	LCD_DisplayString_XY("Wrong PASSWORD",0xc0,1);
	_delay_ms(1000);
	LCD_ClearScreen();
}


u8_t Option_Menu(void)
{
	u8_t X;
	LCD_DisplayString_XY("If u want to:",0x80,0);
	LCD_DisplayString_XY("1 Open door",0xc0,2);
	LCD_DisplayString_XY("2 Close door",0x90,2);
	LCD_DisplayString_XY("3 Change pass.",0xD0,2);
	X=Key_Pressed(Get_Key());
	UART_SendByte(X);
	_delay_ms(20);
	return(X);
}

void OpenDoor(void)
{
	LCD_ClearScreen();
	LCD_DisplayString_XY("DOOR OPEND",0xc0,0);
	_delay_ms(1000);
	LCD_ClearScreen();
}

void CloseDoor(void)
{
	LCD_ClearScreen();
	LCD_DisplayString_XY("DOOR CLOSED",0xc0,0);
	_delay_ms(1000);
	LCD_ClearScreen();
}
void System_error(void)
{
	LCD_ClearScreen();
	LCD_DisplayString("");	
	
	while(1)
	{
		Buzzer_ON();
		LED_YELL_ON();
		_delay_ms(100);
		Buzzer_OFF();
		LED_YELL_OFF();
		_delay_ms(100);
	}
}