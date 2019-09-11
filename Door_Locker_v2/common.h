/*
 * common.h
 *
 * Created: 3/21/2015 03:45:56 ?
 *  Author: Dalia Hossam
 */

#define SET_BIT(PORT,PIN_NO) PORT=PORT|(1<<PIN_NO)
#define CLR_BIT(PORT,PIN_NO) PORT=PORT&(~(1<<PIN_NO))
//#define TOGGLE(PORT,PIN_NO) PORT=PORT^(1<<PIN_NO))
//#define GET_BIT(PORT,PIN_NO) (PORT>>PIN_NO)&0x01
