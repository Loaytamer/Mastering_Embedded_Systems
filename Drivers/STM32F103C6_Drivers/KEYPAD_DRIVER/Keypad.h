/*
 * Author: Loay Tamer Mohamed
 * Description: Keypad.h for avr
 */


#ifndef KEYPAD_H_
#define KEYPAD_H_
//#define F_CPU 1000000UL

//===== Includes =====
#include "stm32f103x6.h"
#include "STM32F103C6_GPIO.h"

/*========== Macros Configuration Reference ==========*/

//@ref Keypad Pins
#define R0 GPIO_PIN_0
#define R1 GPIO_PIN_1
#define R2 GPIO_PIN_3
#define R3 GPIO_PIN_4
#define C0 GPIO_PIN_5
#define C1 GPIO_PIN_6
#define C2 GPIO_PIN_7
#define C3 GPIO_PIN_8

#define Keypad_PORT		GPIOB

/*========== APIs supported by "KEYPAD DRIVER" ==========*/
void Keypad_init();
char Keypad_getKey();


#endif /* KEYPAD_H_ */
