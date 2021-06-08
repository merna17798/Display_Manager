/*
 * TC72.h
 *
 * Created: 01/06/2021 12:17:15
 *  Author: Hadeel
 */ 


#ifndef TC72_H_
#define TC72_H_


#define TC72_MODE_CONTINUOUS    0x04
#define TC72_MODE_SHUTDOWN      0x05
#define TC72_MODE_ONESHOT       0x15

void tc72Init(void);
void tc72_Read(char * msb ,char * lsb);

#endif /* TC72_H_ */