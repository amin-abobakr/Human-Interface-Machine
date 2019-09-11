/*
 * Door_Locker_v2.c
 *
 * Created: 3/14/2015 5:52:58 PM
 *  Author: Dalia Hossam
 */ 

//====================================================//
//====================Includes========================//
//====================================================//

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
#include "Interfacing_UART.h"
//====================================================//

//====================================================//
//==================Main Function=====================//
//====================================================//
int main(void)
{
	
//====================================================//
//====================Variables=======================//
//====================================================//
	u8_t count_wrong=0;
	u8_t Check_Pwd;
	u8_t Choice=0;
	SystemStatevar=NEW_PWD;
	u8_t Check_Pass_Existance;
//====================================================//


//====================================================//
//==================Initialization====================//
//====================================================//
	UART_Init();
	LCD_Init();
	LED_Init();
	Buzzer_Init();
//====================================================//
	

//====================================================//
//==================While Loop========================//
//====================================================//	
    
	Check_Pass_Existance=UART_RecieveByte();
	if (Check_Pass_Existance==PASSWORD_EXIST)
	{
		SystemStatevar=REPEAT_PWD;
	}
	else
	{
		SystemStatevar=NEW_PWD;
	}
	
	while(1)
    {
        switch (SystemStatevar)
        {
//=============== New Password Case ===================//
case NEW_PWD:
		UART_SendByte(NEW_PWD_1);
		Scan_Pass_First();
		SystemStatevar=REPEAT_PWD;
		break;
//============ Repeating Password Case ===============//
case REPEAT_PWD:
		UART_SendByte(REPEAT_PWD_1);
		Scan_Pass_Repeat();
		UART_SendByte(Start_Compare_1);
		
		Check_Pwd=Recieve_PWD_Comp();
		
		      if (Check_Pwd==RIGHT_PASSWORD_1)
		      {
				  count_wrong=0;
				  Correct_Pwd();
				  SystemStatevar=OPTION_MENU;
		      } 
		      else if (Check_Pwd==WRONG_PASSWORD_1)
		      {
				  count_wrong++;
				  if (count_wrong==3)
				  {
					  System_error();
				  }
				  Wrong_Pwd();
				  SystemStatevar=REPEAT_PWD;
		      }
			break;
//================= Option Menu Case ==================//
		case OPTION_MENU:
		UART_SendByte(OPTION_MENU_1);
		      Choice=Option_Menu();
			  if (Choice=='1')
			  {
				  _delay_ms(10);
				  UART_SendByte('1');
				  SystemStatevar=OPEN_DOOR;
			  }
			  else if (Choice=='2')
			  {
				  _delay_ms(10);
				  UART_SendByte('2');
				  SystemStatevar=CLOSE_DOOR;
			  } 
			  else if (Choice=='3')
			  {
				  SystemStatevar=CHANGE_PWD;
			  } 
			  else 
			  {
				  LCD_ClearScreen();
				  LCD_DisplayString_XY("wrong choice",0xc0,0);
				  _delay_ms(1000);
				  LCD_ClearScreen(); 
				  SystemStatevar=OPTION_MENU;
			  }
			 break;
//================== Open Door Case ===================//
		case OPEN_DOOR:
			UART_SendByte(OPEN_DOOR_1);
			OpenDoor();	  
			SystemStatevar=REPEAT_PWD;
			break;
//================== Close Door Case ==================//			 
		case CLOSE_DOOR:
			UART_SendByte(CLOSE_DOOR_1);
			CloseDoor();
			SystemStatevar=REPEAT_PWD;
			break;
//================= System Lock Case =================//
		case SYSTEM_LOCK:
		    System_error();
			LED_RED_OFF();
			LED_GREEN_OFF();
			break;
//============= Changing Password Case  ==============//
		case CHANGE_PWD:
		UART_SendByte(CHANGE_PWD_1);
		   LCD_ClearScreen();
		   _delay_ms(500);
		   Scan_Pass_Repeat();
		   Check_Pwd=UART_RecieveByte();
		   if (Check_Pwd==RIGHT_PASSWORD_1)
		   {
			   Correct_Pwd();
			   SystemStatevar=NEW_PWD;
		   }
		   else
		   {
			   count_wrong++;
			   Wrong_Pwd();
			   if (count_wrong==3)
			   {
				   System_error();
			   }
			   
			   LCD_DisplayString_XY("Enter pass again",0xc0,0);
			   _delay_ms(1000);
			   LCD_ClearScreen();
		   }
		  break;
			  }
        }
			  }
//====================================================//
//=================End Of Main Function===============//
//====================================================//