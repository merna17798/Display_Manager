/*
 * disp_mang_cfg.h
 *
 *  Created on: 8 Jun 2021
 *      Author: pc
 */

#ifndef DISP_MANG_CFG_H_
#define DISP_MANG_CFG_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

/* Set a certain bit in any register */
#define SET_BIT(REG,BIT) (REG|=(1<<BIT))

/* Clear a certain bit in any register */
#define CLEAR_BIT(REG,BIT) (REG&=(~(1<<BIT)))

/* Toggle a certain bit in any register */
#define TOGGLE_BIT(REG,BIT) (REG^=(1<<BIT))

/* Check if a specific bit is set in any register and return true if yes */
#define BIT_IS_SET(REG,BIT) ( REG & (1<<BIT) )

/* Check if a specific bit is cleared in any register and return true if yes */
#define BIT_IS_CLEAR(REG,BIT) ( !(REG & (1<<BIT)) )
typedef unsigned char uint8;



#endif /* DISP_MANG_CFG_H_ */
