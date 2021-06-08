/*
 * disp_mang.c
 *
 *  Created on: 8 Jun 2021
 *      Author: pc
 */

#include "lcd.h"
#include "keypad.h"
char a[10]="WELCOME";
char c;
int input=0;
void IDLE_Screen(void);
int main(){

	LCD_init(); /* initialize LCD */
	LCD_displayString("WELCOME");
	for(int i=0;i<3;i++){
		LCD_sendCommand(0x1C);
		LCD_sendCommand(0x18);
	}
	LCD_clearScreen();
	IDLE_Screen();
	input = KeyPad_getPressedKey();
//	_delay_ms(50);
	if(input=='#'){
		LCD_displayStringRowColumn(1,6,"OPERATION");
	}




	return 0;
}

void IDLE_Screen(void){
	LCD_displayStringRowColumn(0,0,"SET:25");
	LCD_displayStringRowColumn(0,10,"CRT:00");
	LCD_displayStringRowColumn(1,0,"STATE:STANDBY");
}
