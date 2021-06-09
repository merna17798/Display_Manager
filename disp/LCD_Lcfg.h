/*
 * LCD_cfg.h
 *
 *  Created on: June 7, 2021
 *      Author: Ghada & Toaa
 *      Editd by: Merna Saleh
 */

#ifndef LCD_INT_H_
#define LCD_INT_H_

/********************************************************/
/*******************Public Definitions*******************/
/********************************************************/
/*Comment!: LCD control commands*/


#define LCD_WRITECGRAMADD       0x40

#define CLEAR_COMMAND 0x01
#define FOUR_BITS_DATA_MODE 0x02
#define TWO_LINE_LCD_Four_BIT_MODE 0x28
#define TWO_LINE_LCD_Eight_BIT_MODE 0x38
#define CURSOR_OFF 0x0C
#define CURSOR_ON 0x0E
#define SET_CURSOR_LOCATION 0x80

#endif /* LCD_INT_H_ */
