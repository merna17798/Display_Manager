/*
 * disp_mang.c
 *
 *  Created on: 8 Jun 2021
 *      Author: Merna Saleh
 */
#include "disp_mang.h"
void LCD_STATE(STATE Set_State){
	if(Set_State==NORMAL){
		LCD_vidGotoXY((u8)6,(u8)1);
		LCD_vidWriteString("NORMAL");
	}
	else if(Set_State==OPERATION){
		LCD_vidGotoXY((u8)6,(u8)1);
		LCD_vidWriteString("OPERATION");
	}
	else if(Set_State==STANDBY){
		LCD_vidGotoXY((u8)6,(u8)1);
		LCD_vidWriteString("STANDBY");
	}
	else{
		LCD_vidGotoXY((u8)6,(u8)1);
		LCD_vidWriteString("ERROR");
	}

}
void IDLE_Screen(u8 SET_TEMP,u8 CRT_TEMP,STATE Set_State){
	LCD_vidGotoXY((u8)0,(u8)0);
	LCD_vidWriteString("SET:");
	LCD_vidGotoXY((u8)4,(u8)0);
	LCD_vidWriteInt((s16)SET_TEMP);
	LCD_vidGotoXY((u8)10,(u8)0);
	LCD_vidWriteString("CRT:00");
	LCD_vidGotoXY((u8)14,(u8)0);
	LCD_vidWriteInt((s16)CRT_TEMP);
	LCD_vidGotoXY((u8)0,(u8)1);
	LCD_vidWriteString("STATE:");

	LCD_STATE(Set_State);
}


u8 combine(u8 a, u8 b) {
   u8 times = 1;
   u8 result=0;
   while (times <= b){
      times = (times) * ((u8)10);
   }
   result=(a*times) + b;
   return result;
}
u8 KeyPad_SET_Temp(void){
	u8 one,ten,st_TEMP=0;
	one=KeyPad_getPressedKey();
	LCD_vidGotoXY((u8)4,(u8)0);
	LCD_vidWriteInt((s16)one);

	ten=KeyPad_getPressedKey();
	LCD_vidGotoXY((u8)5,(u8)0);
	LCD_vidWriteInt((s16)ten);
	st_TEMP=combine(one,ten);
	return st_TEMP;
}
void Welcome_Screen(void){
    u8 right,out_loop,left;

	for(out_loop=(u8)0;out_loop<(u8)3;out_loop++){
		for( right=(u8)0;right<(u8)8;right++){
			LCD_vidGotoXY((u8)right,(u8)0);
			LCD_vidWriteString("WELCOME");
			_delay_ms(100);
			LCD_vidSendCommand((u8)CLEAR_COMMAND);
		}
		for(left=(u8)8;left>(u8)0;left--){
			LCD_vidGotoXY((u8)left,(u8)0);
			LCD_vidWriteString("WELCOME");
			_delay_ms(100);
			LCD_vidSendCommand((u8)CLEAR_COMMAND);
		}
	}
}

void main(void)

{
	/*u8 ind=0;*/
	LCD_vidInit();
	u8 ST_TEMP=0;
	Welcome_Screen();
	LCD_vidSendCommand((u8)CLEAR_COMMAND);
	IDLE_Screen((u8)25,(u8)00,(STATE)STANDBY);

	ST_TEMP=KeyPad_SET_Temp();

	_delay_ms(2000);
	/*ind=KeyPad_getPressedKey();*/
	/*
	if(i==(u8)'#'){
		LCD_vidSendCommand((u8)CLEAR_COMMAND);
		IDLE_Screen((u8)ST_TEMP,(u8)00,OPERATION);
	}
	*/

}

