/*
 * TC72.c
 *
 * Created: 01/06/2021 12:15:41
 *  Author: Hadeel
 */ 

#include "TC72.h"
#include "SPI.h"
#include "TC72_cfg.h"

#include <util/delay.h>




void tc72Init(void){
	 masterInit();
	 PORT_REG|=(1<<ENABLE_PIN);
	 /*Select Control Register*/
	 masterTransmit(TC72_CONTROL_WRITE_REG);
	 /*Select Continuous temperature Conversion*/
	 masterTransmit(TC72_MODE_CONTINUOUS);
	 PORT_REG &=~(1<<ENABLE_PIN);
	 _delay_ms(150);
 
}


void tc72_Read(char * msb ,char * lsb){
	PORT_REG|=(1<<ENABLE_PIN);
  /*Read the MSB*/
  masterTransmit(TC72_MSB_REG);
  /*Issue one more clock frame to force data out*/
  masterTransmit(TC72_CONTROL_READ_REG);
  PORT_REG &=~(1<<ENABLE_PIN);
  _delay_ms(1);
  *msb=masterReceive();
  PORT_REG |=(1<<ENABLE_PIN);
  /*Read The LSB*/
  masterTransmit(TC72_LSB_REG);
  /*Issue one more clock frame to force data out*/
  masterTransmit(TC72_CONTROL_READ_REG);
  PORT_REG &=~(1<<ENABLE_PIN); 
  _delay_ms(1);
  *lsb=masterReceive();
}

