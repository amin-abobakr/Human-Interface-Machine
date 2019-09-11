/*
 * Function.h
 *
 * Created: 3/21/2015 03:45:56 ?
 *  Author: Dalia Hossam
 */


#ifndef FUNCTION_H_
#define FUNCTION_H_

#include "STD.h"
#define NEW_PWD_1 81
#define REPEAT_PWD_1 82
#define Start_Compare_1 83
#define RIGHT_PASSWORD_1 84
#define WRONG_PASSWORD_1 85
#define OPTION_MENU_1 86
#define CHANGE_PWD_1 87
#define OPEN_DOOR_1 88
#define CLOSE_DOOR_1 89
#define SYSTEM_ERROR 90
#define PASSWORD_EXIST 105
#define PASSWORD_NOT_EXIST 106

typedef enum 

{
	NEW_PWD=0,
	REPEAT_PWD,
	OPTION_MENU,
	OPEN_DOOR,
	CLOSE_DOOR,
	CHANGE_PWD,
	SYSTEM_LOCK
}SystemState;
SystemState SystemStatevar;

#define True 1
#define False 0


void Scan_Pass_First(void);
void Scan_Pass_Repeat(void);
u8_t Recieve_PWD_Comp(void);
u8_t Option_Menu(void);
void OpenDoor(void);
void CloseDoor(void);
void Correct_Pwd(void);
void Wrong_Pwd(void);
void System_error(void);

#endif /* FUNCTION_H_ */