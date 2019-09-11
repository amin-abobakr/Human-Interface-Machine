/*
 * Buzzer.c
 *
 * Created: 3/21/2015 03:45:56 ?
 *  Author: Dalia Hossam
 */

#include <avr/io.h>
#include "Buzzer_Config.h"
#include "Buzzer.h"
#include "common.h"

void Buzzer_Init(void)
{
	SET_BIT(BUZZER_DDR,BUZZER_PIN_NO);
}
void Buzzer_ON(void)
{
	SET_BIT(BUZZER_PORT,BUZZER_PIN_NO);
}
void Buzzer_OFF(void)
{
	CLR_BIT(BUZZER_PORT,BUZZER_PIN_NO);
}