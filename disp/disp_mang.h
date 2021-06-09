/*
 * disp_mang.h
 *
 *  Created on: 8 Jun 2021
 *      Author: Merna Saleh
 */

#ifndef DISP_MANG_H_
#define DISP_MANG_H_


#include "types.h"
#include<util/delay.h>
#include<avr/io.h>
#include "DIO_Lcfg.h"
#include "DIO.h"
#include "LCD_cfg.h"
#include "LCD.h"
#include "keypad.h"
#include "LCD_Lcfg.h"
typedef enum states{
	STANDBY=1,
	NORMAL=2,
	OPERATION=3,
	ERROR=4
}STATE;
void LCD_STATE(STATE Set_State);
void IDLE_Screen(u8 SET_TEMP,u8 CRT_TEMP,STATE Set_State);
u8 combine(u8 a, u8 b);
u8 KeyPad_SET_Temp(void);
void Welcome_Screen(void);

#endif /* DISP_MANG_H_ */
