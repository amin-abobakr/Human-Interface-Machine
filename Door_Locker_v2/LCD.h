/*
 * LCD.h
 *
 * Created: 3/14/2015 5:52:58 PM
 *  Author: Dalia Hossam
 */


#ifndef LCD_H_
#define LCD_H_

#include "STD.h"

#define MODE_8_BIT 0x38
#define DISPLAYON_CURSORON 0x0E
#define ROW1 0x80
#define ROW2 0xc0
#define ROW3 0x90
#define ROW4 0xD0

void LCD_Init(void);
void LCD_ClearScreen(void);
void LCD_DisplayCharacter(u8_t data);
void LCD_SendCommand(u8_t command);
void LCD_DisplayString(u8_t *data);
void LCD_DisplayString_XY(u8_t *data,u8_t row,u8_t coloum);
void LCD_IntgerToString(s16_t data);



#endif /* LCD_H_ */
