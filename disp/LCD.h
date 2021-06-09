/*
 * LCD.h
 *
 *  Created on: June 7, 2021
 *      Author: Ghada & Toaa
 */

#ifndef LCD_H_
#define LCD_H_

#include "types.h"
#include<avr/io.h>
#include<util/delay.h>
#define DATA_BITS_MODE 4

/* Use higher 4 bits in the data port */
#if (DATA_BITS_MODE == 4)
#define LOWER_PORT_PINS
#endif

/******************** Driver information ****************/
/* this driver is meant for 16x2 character LCD and it supports 8 bit mode*/

/********************************************************/
/*******************Public Functions *******************/
/********************************************************/
/***************************************************************************************/
/* Description: Apply initialization sequence for LCD module                           */
/* Input      : Void                                                                   */
/* Output     : Void                                                                   */
/* Scope      : Public                                                                 */
/***************************************************************************************/
void LCD_vidInit(void);

void LCD_vidSendCommand(u8 u8CmdCpy);

void LCD_vidWriteData( char u8DataCpy);

void LCD_vidWriteString(const char *Str);

void LCD_vidGotoXY(u8 u8ColCpy, u8 u8RowCpy);

void LCD_vidWriteInt(s16 val);


#endif /* LCD_H_ */
