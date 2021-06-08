/*
 * SPI.h
 *
 * Created: 01/06/2021 12:17:54
 *  Author: Enas
 */ 


#ifndef SPI_H_
#define SPI_H_
#define F_CPU 4000000UL
void masterInit(void);
void slaveInit(void);
void masterTransmit(char spiData);
char masterReceive(void);

#endif /* SPI_H_ */
