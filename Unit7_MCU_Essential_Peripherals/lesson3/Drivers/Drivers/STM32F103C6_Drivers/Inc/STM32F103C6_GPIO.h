/*
 * STM32F103C6_GPIO.h
 * Author: Loay Tamer Mohamed
 */

#ifndef INC_STM32F103C6_GPIO_H_
#define INC_STM32F103C6_GPIO_H_

//===== Includes =====
#include "STM32F103x6.h"

//===== config structure =====
typedef struct{
	uint16_t GPIO_pinNumber;   //specify the GPIO pins to be configured
							   //this parameter must be set based on @ref GPIO_PINS_Define
	uint8_t  GPIO_MODE;		   //specify the operating mode for the selected pins
	 	 	 	 	 	 	   //this parameter must be set based on @ref GPIO_MODE_Define
	uint8_t  GPIO_Output_Speed;//specify the speed for the selected pins
		 	 	 	 	 	   //this parameter must be set based on @ref GPIO_MODE_Speed_Define
}GPIO_pinConfig_t;

/*========== Macros Configuration Reference ==========*/

//@ref GPIO_PINS_State
#define GPIO_PIN_SET			1
#define GPIO_PIN_RESET			0

//@ref GPIO_Return_Lock
#define GPIO_Return_Lock_OK		1
#define GPIO_Return_Lock_ERROR	0

//@ref GPIO_PINS_Define
#define GPIO_PIN_0			((uint16_t)0x0001)  //Pin 0    selected
#define GPIO_PIN_1			((uint16_t)0x0002)  //Pin 1    selected
#define GPIO_PIN_2			((uint16_t)0x0004)  //Pin 2    selected
#define GPIO_PIN_3			((uint16_t)0x0008)  //Pin 3    selected
#define GPIO_PIN_4			((uint16_t)0x0010)  //Pin 4    selected
#define GPIO_PIN_5			((uint16_t)0x0020)  //Pin 5    selected
#define GPIO_PIN_6			((uint16_t)0x0040)  //Pin 6    selected
#define GPIO_PIN_7			((uint16_t)0x0080)  //Pin 7    selected
#define GPIO_PIN_8			((uint16_t)0x0100)  //Pin 8    selected
#define GPIO_PIN_9			((uint16_t)0x0200)  //Pin 9    selected
#define GPIO_PIN_10			((uint16_t)0x0400)  //Pin 10   selected
#define GPIO_PIN_11			((uint16_t)0x0800)  //Pin 11   selected
#define GPIO_PIN_12			((uint16_t)0x1000)  //Pin 12   selected
#define GPIO_PIN_13			((uint16_t)0x2000)  //Pin 13   selected
#define GPIO_PIN_14			((uint16_t)0x4000)  //Pin 14   selected
#define GPIO_PIN_15			((uint16_t)0x8000)  //Pin 15   selected
#define GPIO_PIN_All		((uint16_t)0xFFFF)  //All PINS selected

#define GPIO_PIN_MASK		(0x0000FFFFu)  		//Pin Mask

//@ref GPIO_PINS_MODE_Define
#define GPIO_MODE_ANALOG		0x00000000u		// Analog mode
#define GPIO_MODE_INPUT_FLO		0x00000001u		//Floating input (reset state)
#define GPIO_MODE_INPUT_PU		0x00000002u		//Input with pull-up
#define GPIO_MODE_INPUT_PD		0x00000003u		//Input with pull-down
#define GPIO_MODE_INPUT_AF		0x00000004u		//Alternate function Input
#define GPIO_MODE_OUTPUT_PP		0x00000005u		//General purpose output push-pull
#define GPIO_MODE_OUTPUT_OD		0x00000006u		//General purpose output Open-drain
#define GPIO_MODE_OUTPUT_AF_PP	0x00000007u		//Alternate function output Push-pull
#define GPIO_MODE_OUTPUT_AF_OD	0x00000008u		//Alternate function output Open-drain


//@ref GPIO_MODE_Speed_Define
#define GPIO_MODE_10MHZ			0x00000001u		//Output mode, max speed 10 MHz.
#define GPIO_MODE_2MHZ			0x00000002u		//Output mode, max speed 2 MHz.
#define GPIO_MODE_50MHZ			0x00000003u		//Output mode, max speed 50 MHz.

/*========== APIs supported by "MCAL GPIO DRIVER" ==========*/
void MCAL_GPIO_Init  (GPIO_t* GPIOx, GPIO_pinConfig_t* pinConfig);
void MCAL_GPIO_DeInit(GPIO_t* GPIOx);

//Read APIs
uint8_t MCAL_GPIO_ReadPin(GPIO_t* GPIOx, uint16_t pinNumber);
uint16_t MCAL_GPIO_ReadPort(GPIO_t* GPIOx);

//Write APIs
void MCAL_GPIO_WritePin(GPIO_t* GPIOx, uint16_t pinNumber, uint8_t value);
void MCAL_GPIO_WritePort(GPIO_t* GPIOx,uint16_t value); //value uint16 because we have 16 pin in port

void MCAL_GPIO_TogglePin(GPIO_t* GPIOx, uint16_t pinNumber);
uint8_t MCAL_GPIO_LockPin(GPIO_t* GPIOx, uint16_t pinNumber);
#endif /* INC_STM32F103C6_GPIO_H_ */
