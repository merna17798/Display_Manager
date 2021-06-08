/*
 * TC72_cfg.h
 *
 * Created: 01/06/2021 12:17:37
 *  Author: Hadeel
 */ 


#ifndef TC72_CFG_H_
#define TC72_CFG_H_

#define PORTA_BASE_ADDRESS ((unsigned char)0x3B)
#define PORTB_BASE_ADDRESS ((unsigned char)0x38)
#define PORTC_BASE_ADDRESS ((unsigned char)0x35)
#define PORTD_BASE_ADDRESS ((unsigned char)0x32)

#define PORT_REG_OFFSET ((unsigned char)0)
#define DDR_REG_OFFSET ((unsigned char)1)
#define PIN_REG_OFFSET ((unsigned char)2)

#define PORT_REG (*((volatile  unsigned char*const)(PORTB_BASE_ADDRESS - PORT_REG_OFFSET)))
#define DDR_REG (*((volatile  unsigned char*const)(PORTB_BASE_ADDRESS - DDR_REG_OFFSET)))
#define PIN_REG (*((volatile  unsigned char*const)(PORTB_BASE_ADDRESS - PIN_REG_OFFSET)))

#define ENABLE_PIN 4
#define    TC72_CONTROL_READ_REG    0x00
#define    TC72_CONTROL_WRITE_REG   0x80
#define    TC72_ID_REG              0x03
#define    TC72_MSB_REG             0x02
#define    TC72_LSB_REG             0x01



#endif /* TC72_CFG_H_ */