/*
 * DIO.h
 *
 *  Created on: June 7, 2021
 *      Author: Ghada & Toaa
 */


#ifndef DIO_H_
#define DIO_H_

/* IO Pins Function */
void DIO_SetPinValue(u8 u8PortIdCopy , u8 u8PinIdCopy, u8 u8PinValCopy);

u8 DIO_GetPinValue(u8 u8PortIdCopy, u8 u8PinIdCopy);

void DIO_SetPinDirection(u8 u8PortIdCopy, u8 u8PinIdCopy, u8 u8PinDirCopy);

/* IO Ports Functions */
void DIO_SetPortDirection(u8 u8PortId, u8 u8PortDir);

void DIO_SetPortValue(u8 u8PortId, u8 u8PortVal);
void DIO_SetPortValue_AND (u8 u8PortId, u8 u8PortVal,u8 mask);
#endif /* DIO_H_ */
