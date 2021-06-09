/*
 * DIO_priv.h
 *
 *  Created on: June 7, 2021
 *      Author: Ghada & Toaa
 */
/*we violated this rule as they are hardware registers
#1461-D (MISRA-C:2004 19.4/R) C macros shall only expand to a braced initialiser, a constant, a string literal,
a parenthesised expression, a type qualifier, a storage class specifier, or a do-while-zero construct
*/
#ifndef DIO_PRIV_H_
#define DIO_PRIV_H_

/* Group A REGisters */
#define DIO_u8PORTA_REG  *((volatile u8*)0x3B)
#define DIO_u8DDRA_REG   *((volatile u8*)0x3A)
#define DIO_u8PINA_REG   *((volatile u8*)0x39)

/* Group B REGisters */
#define DIO_u8PORTB_REG  *((volatile u8*)0x38)
#define DIO_u8DDRB_REG   *((volatile u8*)0x37)
#define DIO_u8PINB_REG   *((volatile u8*)0x36)

/* Group C REGisters */
#define DIO_u8PORTC_REG  *((volatile u8*)0x35)
#define DIO_u8DDRC_REG   *((volatile u8*)0x34)
#define DIO_u8PINC_REG   *((volatile u8*)0x33)

/* Group D REGisters */
#define DIO_u8PORTD_REG  *((volatile u8*)0x32)
#define DIO_u8DDRD_REG   *((volatile u8*)0x31)
#define DIO_u8PIND_REG   *((volatile u8*)0x30)

#endif /* DIO_PRIV_H_ */
