/*
 * Author: Loay Tamer Mohamed
 * Description: Keypad.h for avr
 */


#ifndef KEYPAD_H_
#define KEYPAD_H_
#define F_CPU 1000000UL

//===== Includes =====
#include <avr/io.h>
#include <util/delay.h>

/*========== Macros Configuration Reference ==========*/

//@ref Keypad Pins
#define R0 0
#define R1 1
#define R2 2
#define R3 3
#define C0 4
#define C1 5
#define C2 6
#define C3 7

#define Keypad_PORT		PORTD
#define Keypad_DataDir  DDRD
#define keypadPIN	    PIND

/*========== APIs supported by "KEYPAD DRIVER" ==========*/
void Keypad_init();
char Keypad_getKey();


#endif /* KEYPAD_H_ */