/*
 * Keypad.c
 *
 * Created: 3/14/2015 5:52:58 PM
 *  Author: Dalia Hossam
 */

#define F_CPU 1000000UL
#include <util/delay.h>
#include "keyPad.h"
#include "KeyPad_Config.h"



u8_t Get_Key()
{
	//keypad connected on PORTA
	//connect coloumns on PINS from (PD0-PD3),make these PINS as o/p pins
	//connect rows on PINS from(PD4-PD7),make these PINS as i/p pins with HIGH Impedance
	u8_t row_count = 0;//counter of rows
	u8_t col_count = 0;//counter of coloums
	KEYPAD_DDR &= (~0x0f);
	KEYPAD_PORT = 0xf0; // Activate PULL-UP resistance on PINS(PD4-PD7)
	while(1)
	{
		for(col_count = 0;col_count < MAXCOL;col_count++)
		{
			KEYPAD_DDR = 1<<col_count;
			for(row_count = 0;row_count < MAXROW;row_count++)
			{
				if(!(KEYPAD_PIN & (1<<row_count + 4) ) )
				{
					while(! (KEYPAD_PIN & (1<<row_count + 4) ) ); //get only one number per press
					return ((row_count*4)+col_count+1);
				}
			}
		}
	}
}

u8_t Key_Pressed(u8_t value)
{
	u8_t key=0;
	switch(value)
	{
		case 1:key = '7';
		break;
		case 2:key = '4';
		break;
		case 3:key = '1';
		break;
		case 4:key = 'c';
		break;
		case 5:key = '8';
		break;
		case 6:key = '5';
		break;
		case 7:key = '2';
		break;
		case 8:key = '0';
		break;
		case 9:key = '9';
		break;
		case 10:key = '6';
		break;
		case 11:key = '3';
		break;
		case 12:key = '=';
		break;
		case 13:key = '%';
		break;
		case 14:key = '*';
		break;
		case 15:key = '-';
		break;
		case 16:key = '+';
		break;
	}
	return key;
}