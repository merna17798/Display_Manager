/*
 * LCD.c
 *
 *  Created on: June 7, 2021
 *      Author: Ghada & Toaa
 *      Edited by: Merna Saleh
 */
/***********************Header file Inclusion******************************/

#define F_CPU 12000000
#include "types.h"
/*#include<util/delay.h>*/
/*#include<avr/io.h>*/
#include "DIO.h"
#include "DIO_priv.h"
#include "DIO_Lcfg.h"
#include "LCD.h"
#include "LCD_cfg.h"
#include "LCD_Lcfg.h"

void LCD_vidInit(void)
{



	#if (DATA_BITS_MODE == 4)
		#ifdef UPPER_PORT_PINS
			DIO_SetPortDirection(LCD_DATA_PORT,0xF0);

		#else
			DIO_SetPortDirection(LCD_DATA_PORT,0x0F);
			DIO_SetPinDirection(LCD_CONTROL_PORT, LCD_E_PIN, DIO_u8OUTPUT);
			DIO_SetPinDirection(LCD_CONTROL_PORT, LCD_RS_PIN, DIO_u8OUTPUT);
			DIO_SetPinDirection(LCD_CONTROL_PORT, LCD_RW_PIN, DIO_u8OUTPUT);
		#endif
		LCD_vidSendCommand(FOUR_BITS_DATA_MODE); /* initialize LCD in 4-bit mode */
		LCD_vidSendCommand(TWO_LINE_LCD_Four_BIT_MODE); /* use 2-line lcd + 4-bit Data Mode + 5*7 dot display Mode */
	#elif (DATA_BITS_MODE == 8)
		DIO_SetPortDirection(LCD_DATA_PORT,0xFF);
		LCD_vidSendCommand(TWO_LINE_LCD_Eight_BIT_MODE); /* use 2-line lcd + 8-bit Data Mode + 5*7 dot display Mode */
	#endif

	LCD_vidSendCommand(CURSOR_OFF); /* cursor off */
	LCD_vidSendCommand(CLEAR_COMMAND); /* clear LCD at the beginning */
}

void LCD_vidSendCommand(u8 u8CmdCpy)
{
	/* Reset RS pin */
	DIO_SetPinValue(LCD_CONTROL_PORT, LCD_RS_PIN, DIO_u8LOW);
	/* Reset R/W pin*/
	DIO_SetPinValue(LCD_CONTROL_PORT, LCD_RW_PIN, DIO_u8LOW);
	_delay_ms(1); /* delay for processing Tas = 50ns */
	/* Set E to HIGH  */
	DIO_SetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, DIO_u8HIGH);
	_delay_ms(1); /* delay for processing Tas = 50ns */
	#if (DATA_BITS_MODE == 4)
		/* out the highest 4 bits of the required command to the data bus D4 --> D7 */
	#ifdef UPPER_PORT_PINS
		DIO_SetPortValue_AND(LCD_DATA_PORT,0x0F,(u8CmdCpy & 0xF0));
	#else
		DIO_SetPortValue_AND(LCD_DATA_PORT,0xF0,((u8CmdCpy & 0xF0) >> 4));
	#endif

	_delay_ms(1); /* delay for processing Tdsw = 100ns */
	DIO_SetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, DIO_u8LOW); /* disable LCD E=0 */
	_delay_ms(1); /* delay for processing Th = 13ns */
	DIO_SetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, DIO_u8HIGH); /* Enable LCD E=1 */
	_delay_ms(1); /* delay for processing Tpw - Tdws = 190ns */

	/* out the lowest 4 bits of the required command to the data bus D4 --> D7 */
	#ifdef UPPER_PORT_PINS
		DIO_SetPortValue_AND(LCD_DATA_PORT,0x0F,((u8CmdCpy & 0x0F) >> 4));
	#else
		DIO_SetPortValue_AND(LCD_DATA_PORT,0xF0,(u8CmdCpy & 0x0F));
	#endif

	_delay_ms(1); /* delay for processing Tdsw = 100ns */
	DIO_SetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, DIO_u8LOW); /* disable LCD E=0 */
	_delay_ms(1); /* delay for processing Th = 13ns */
	#elif (DATA_BITS_MODE == 8)
		DIO_SetPortValue(LCD_DATA_PORT,u8CmdCpy); /* out the required command to the data bus D0 --> D7 */
		_delay_ms(1); /* delay for processing Tdsw = 100ns */
		DIO_SetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, DIO_u8LOW); /* disable LCD E=0 */
		_delay_ms(1); /* delay for processing Th = 13ns */
	#endif

}
void LCD_vidWriteData(char u8DataCpy)
{
	DIO_SetPinValue(LCD_CONTROL_PORT, LCD_RS_PIN, DIO_u8HIGH); /* Data Mode RS=1 */
	DIO_SetPinValue(LCD_CONTROL_PORT, LCD_RW_PIN, DIO_u8LOW); /* write data to LCD so RW=0 */
	_delay_ms(1); /* delay for processing Tas = 50ns */
	DIO_SetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, DIO_u8HIGH); /* Enable LCD E=1 */
	_delay_ms(1); /* delay for processing Tpw - Tdws = 190ns */
	#if (DATA_BITS_MODE == 4)
		/* out the highest 4 bits of the required command to the data bus D4 --> D7 */
	#ifdef UPPER_PORT_PINS
		DIO_SetPortValue_AND(LCD_DATA_PORT,0x0F,(u8DataCpy & 0xF0));
	#else
		DIO_SetPortValue_AND(LCD_DATA_PORT,0xF0,((u8DataCpy & 0xF0) >> 4));
	#endif
	_delay_ms(1); /* delay for processing Tdsw = 100ns */
	DIO_SetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, DIO_u8LOW); /* disable LCD E=0 */
	_delay_ms(1); /* delay for processing Th = 13ns */
	DIO_SetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, DIO_u8HIGH); /* Enable LCD E=1 */
	_delay_ms(1); /* delay for processing Tpw - Tdws = 190ns */

	/* out the lowest 4 bits of the required data to the data bus D4 --> D7 */
	#ifdef UPPER_PORT_PINS
		DIO_SetPortValue_AND(LCD_DATA_PORT,0x0F,((u8DataCpy & 0x0F) >> 4));
	#else
		DIO_SetPortValue_AND(LCD_DATA_PORT,0xF0,(u8DataCpy & 0x0F));
	#endif

	_delay_ms(1); /* delay for processing Tdsw = 100ns */
	DIO_SetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, DIO_u8LOW);/* disable LCD E=0 */
	_delay_ms(1); /* delay for processing Th = 13ns */
	#elif (DATA_BITS_MODE == 8)
		DIO_SetPortValue(LCD_DATA_PORT,u8DataCpy); /* out the required command to the data bus D0 --> D7 */
		_delay_ms(1); /* delay for processing Tdsw = 100ns */
		DIO_SetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, DIO_u8LOW); /* disable LCD E=0 */
		_delay_ms(1); /* delay for processing Th = 13ns */
	#endif


}

void LCD_vidWriteString(const char *Str)
{
	u8 i = 0;
	while(Str[i] != '\0')
	{
		LCD_vidWriteData(Str[i]);
		i++;
	}
}




void LCD_vidGotoXY(u8 u8ColCpy, u8 u8RowCpy)
{
	u8 Address;

	/* first of all calculate the required address */
	switch(u8RowCpy)
	{
		case 0:
				Address=u8ColCpy;
				break;
		case 1:
				Address=u8ColCpy+0x40;
				break;
		case 2:
				Address=u8ColCpy+0x10;
				break;
		case 3:
				Address=u8ColCpy+0x50;
				break;
	}
	/* to write to a specific address in the LCD
	 * we need to apply the corresponding command 0b10000000+Address */
	LCD_vidSendCommand(Address | SET_CURSOR_LOCATION);
}


void LCD_vidWriteInt(s16 val)
{
	   char buff[16]; /* String to hold the ascii result */
	   itoa(val,buff,10); /* 10 for decimal */
	   LCD_vidWriteString(buff);
}




