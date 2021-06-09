/*
 * LCD_cfg.h
 *
 *  Created on: June 7, 2021
 *      Author: Ghada & Toaa
 *      Edited by: Merna Saleh
 */
/*we violated this rule as they are hardware registers
#1461-D (MISRA-C:2004 19.4/R) C macros shall only expand to a braced initialiser, a constant, a string literal,
a parenthesised expression, a type qualifier, a storage class specifier, or a do-while-zero construct
*/
#ifndef LCD_CFG_H_
#define LCD_CFG_H_

#include "DIO.h"
#include "DIO_priv.h"
#include "DIO_Lcfg.h"
/************************************************************************/
/********************* PORT/PINs configurations for LCD *****************/
/************************************************************************/

/* Description: LCD DATA port configuration */
/* Range      : DIO_u8PORTA ~ DIO_u8PORTD */
#define LCD_DATA_PORT        DIO_u8PORTD

/* Description: LCD Control port configuration */
/* Range      : DIO_u8PORTA ~ DIO_u8PORTD */
#define LCD_CONTROL_PORT	 DIO_u8PORTD

/*Description: LCD RS pin */
/* Range     : DIO_u8PIN0 ~ DIO_u8PIN7 */
#define LCD_RS_PIN			 DIO_u8PIN4

/*Description: LCD RW pin */
/* Range     : DIO_u8PIN0 ~ DIO_u8PIN7 */
#define LCD_RW_PIN		   	 DIO_u8PIN5

/*Description: LCD E pin */
/* Range     : DIO_u8PIN0 ~ DIO_u8PIN7 */
#define LCD_E_PIN			 DIO_u8PIN6

#endif /* LCD_CFG_H_ */
