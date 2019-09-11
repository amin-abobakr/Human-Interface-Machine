/*
 * LED.c
 *
 * Created: 3/14/2015 5:52:58 PM
 *  Author: Dalia Hossam
 */ 

#include <avr/io.h>
#include "LED_Config.h"
#include "LED.h"
#include "common.h"

void LED_Init(void)
{
	SET_BIT(LED_DDR,LED_RED_PIN_NO);
	SET_BIT(LED_DDR,LED_YELL_PIN_NO);
	SET_BIT(LED_DDR,LED_GREEN_PIN_NO);
}
void LED_RED_ON(void)
{
	SET_BIT(LED_PORT,LED_RED_PIN_NO);
}
void LED_RED_OFF(void)
{
	CLR_BIT(LED_PORT,LED_RED_PIN_NO);
}
void LED_YELL_ON(void)
{
	SET_BIT(LED_PORT,LED_YELL_PIN_NO);
}
void LED_YELL_OFF(void)
{
	CLR_BIT(LED_PORT,LED_YELL_PIN_NO);
}
void LED_GREEN_ON(void)
{
	SET_BIT(LED_PORT,LED_GREEN_PIN_NO);
}
void LED_GREEN_OFF(void)
{
	CLR_BIT(LED_PORT,LED_GREEN_PIN_NO);
}