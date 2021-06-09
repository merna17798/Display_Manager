 /******************************************************************************
 *
 * Module: Common - Macros
 *
 * File Name: Common_Macros.h
 *
 * Description: Commonly used Macros
 *
 * Author: Toqa&Ghada
 * Edited by: Merna Saleh
 *
 *******************************************************************************/
/*we violated this rule as we prefer using macros
 * #1428-D (MISRA-C:2004 19.7/A) A function should be used in preference to a function-like macro
 * we also violate this rule as when trying to solve it with putting parentheses we got that err
 * err:#41 expected an identifier
 * #1430-D (MISRA-C:2004 19.10/R) In the definition of a function-like macro
	each instance of a parameter shall be enclosed in parentheses
	unless it is used as the operand of # or ##.
	The compiler cannot determine if the parameter "REG" is used as an operand of # or ##.
 * */
#ifndef COMMON_MACROS
#define COMMON_MACROS

/* Set a certain bit in any register */
#define SET_BIT(REG,BIT) (REG|=(1<<BIT))

/* Clear a certain bit in any register */
#define CLEAR_BIT(REG,BIT) (REG&=(~(1<<BIT)))

#define SET_VALUE_REG(REG,MASK,VALUE)                       REG=(((REG)&(MASK))|VALUE)

/* Toggle a certain bit in any register */
#define TOGGLE_BIT(REG,BIT) (REG^=(1<<BIT))

/* Rotate right the register value with specific number of rotates */
#define ROR(REG,num) ( REG= (REG>>num) | (REG<<(8-num)) )

/* Rotate left the register value with specific number of rotates */
#define ROL(REG,num) ( REG= (REG<<num) | (REG>>(8-num)) )

/* Check if a specific bit is set in any register and return true if yes */
#define BIT_IS_SET(REG,BIT) ( REG & (1<<BIT) )

/* Check if a specific bit is cleared in any register and return true if yes */
#define BIT_IS_CLEAR(REG,BIT) ( !(REG & (1<<BIT)) )
#endif
