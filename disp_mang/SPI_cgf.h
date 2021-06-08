/*
 * SPI_cgf.h
 *
 * Created: 01/06/2021 14:35:12
 *  Author: Enas
 */ 


#ifndef SPI_CGF_H_
#define SPI_CGF_H_

#define PORTA_BASE_ADDRESS ((unsigned char)0x3B)
#define PORTB_BASE_ADDRESS ((unsigned char)0x38)
#define PORTC_BASE_ADDRESS ((unsigned char)0x35)
#define PORTD_BASE_ADDRESS ((unsigned char)0x32)

#define PORT_REG_OFFSET ((unsigned char)0)
#define DDR_REG_OFFSET ((unsigned char)1)
#define PIN_REG_OFFSET ((unsigned char)2)

#define NUM_OF_PORTS ((unsigned char)4)

 
#define MOSI  7
#define MISO  6
#define SCK 5
#define SS 4


#endif /* SPI_CGF_H_ */
