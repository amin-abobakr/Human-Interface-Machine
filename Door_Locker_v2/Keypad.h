/*
 * Keypad.h
 *
 * Created: 3/14/2015 5:52:58 PM
 *  Author: Dalia Hossam
 */

#ifndef KEYPAD_H_    // if KEYPAD_H_ no defined
#define KEYPAD_H_    // define KEYPAD_H_
#include <avr/io.h>
#include "STD.h"
#include "common.h"

#define MAXCOL 4
#define MAXROW 4

u8_t Get_Key();
u8_t Key_Pressed(u8_t value);

#endif          