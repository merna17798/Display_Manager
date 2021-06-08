/*
 * SPI.c
 *
 * Created: 01/06/2021 12:16:13
 *  Author: Enas
 */ 

#include "SPI.h"
#include "SPI_cgf.h"
#include <avr/io.h>
#include <util/delay.h>


/*Registers definitions*/
#define PORT_REG(PORT_ID) (*((volatile  unsigned char*const)(PortBaseAddresses[PORT_ID] - PORT_REG_OFFSET)))
#define DDR_REG(PORT_ID) (*((volatile  unsigned char*const)(PortBaseAddresses[PORT_ID] - DDR_REG_OFFSET)))
#define PIN_REG(PORT_ID) (*((volatile  unsigned char*const)(PortBaseAddresses[PORT_ID] - PIN_REG_OFFSET)))

const unsigned char PortBaseAddresses[NUM_OF_PORTS] =
{	PORTA_BASE_ADDRESS,
	PORTB_BASE_ADDRESS,
	PORTC_BASE_ADDRESS,
PORTD_BASE_ADDRESS};


void masterInit(void){
 /*Set MOSI, SCK and SS Output*/
 DDR_REG(1)=(1<<MOSI)|(1<<SCK)|(1<<SS);
 DDR_REG(1)= DDR_REG(1)& ~(1<<MISO);
 /*Enable SPI Master set clock rate fck/128 data is 
 sample at falling edge*/
 SPCR=(1<<SPE)|(1<<MSTR)|(1<<SPR1)|(1<<SPR0)|(1<<CPHA);
 
}

void slaveInit(void){
	 
 DDR_REG(1)= DDR_REG(1)& (~(1<<SS));  
 DDR_REG(1)= DDR_REG(1)& (~(1<<MOSI));
 DDR_REG(1)= DDR_REG(1)| (1<<MISO);
 DDR_REG(1)= DDR_REG(1)& (~(1<<SCK));
 SPCR=(1<<SPE);

}

void masterTransmit(char spiData){
 /*Start the transmission*/
 SPDR=spiData;
 /*Wait for completion*/
 while(!(SPSR&(1<<SPIF)));
 
 
}

char masterReceive(void){
 /*Wait for the SPI buffer's full*/
 while(!(SPSR&(1<<SPIF)));
 /*return SPI Buffer*/
 return SPDR;
}

