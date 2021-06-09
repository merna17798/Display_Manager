 /******************************************************************************
 *
 * Module: KEYPAD
 *
 * File Name: keypad.h
 *
 * Description: Header file for the Keypad driver
 *
 * Author: Merna Mohamed
 *
 *
 *******************************************************************************/
/*we violated this rule as they are hardware registers
#1461-D (MISRA-C:2004 19.4/R) C macros shall only expand to a braced initialiser, a constant, a string literal,
a parenthesised expression, a type qualifier, a storage class specifier, or a do-while-zero construct
*/

/*#include<avr/io.h>*/
#ifndef KEYPAD_H_
#define KEYPAD_H_

/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/
#include "common_macros.h"
#include "types.h"
#include<avr/io.h>
#include<util/delay.h>
/* Keypad configurations for number of rows and columns */
#define N_col 3
#define N_row 4

/* Keypad Port Configurations */
#define KEYPAD_PORT_OUT PORTA
#define KEYPAD_PORT_IN  PINA
#define KEYPAD_PORT_DIR DDRA 

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Function responsible for getting the pressed keypad key
 */
u8 KeyPad_getPressedKey(void);

#endif /* KEYPAD_H_ */
