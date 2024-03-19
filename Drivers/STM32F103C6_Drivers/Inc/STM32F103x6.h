/*
 * STM32F103x6.h
 * Author: Loay Tamer Mohamed
 */

#ifndef INC_STM32F103X6_H_
#define INC_STM32F103X6_H_

/*========== Includes ==========*/
#include "stdlib.h"
#include "stdint.h"

/*========== Base addresses for Memory ==========*/
#define FLASH_Memory_Base				0x08000000UL
#define System_Memory_Base				0x1FFFF000UL
#define SRAM_Base						0x20000000UL

#define Peripherals_Base				0x40000000UL
#define Cortex_M3_Internal_Peripherals	0xE0000000UL

/*========== Base addresses for AHB Peripherals ==========*/
//RCC
#define RCC_BASE						(Peripherals_Base + 0x00021000)

/*========== Base addresses for ABP2 Peripherals ==========*/

//GPIO
//A,B fully included in LQFP package
#define GPIOA_BASE 						(Peripherals_Base + 0x00010800)
#define GPIOB_BASE 						(Peripherals_Base + 0x00010C00)

//C,D parital included in LQFP package
#define GPIOC_BASE 						(Peripherals_Base + 0x00011000)
#define GPIOD_BASE 						(Peripherals_Base + 0x00011400)

//E,F,G not included in LQFP package
#define GPIOE_BASE 						(Peripherals_Base + 0x00011800)
#define GPIOF_BASE 						(Peripherals_Base + 0x00011C00)
#define GPIOG_BASE 						(Peripherals_Base + 0x00012000)

//EXTI
#define EXTI_BASE 						(Peripherals_Base + 0x00010400)

//AFIO
#define AFIO_BASE 						(Peripherals_Base + 0x00010000)

/*========== Base addresses for ABP1 Peripherals ==========*/

/*========== Peripheral Registers:RCC ==========*/
typedef struct{
	volatile uint32_t CR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t APB1RSTR;
	volatile uint32_t AHBENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t APB1ENR;
	volatile uint32_t CSR;
	volatile uint32_t AHBSTR;
	volatile uint32_t CFGR2;
}RCC_t;
/*========== Peripheral Registers:GPIO ==========*/
typedef struct{
	volatile uint32_t CRL;
	volatile uint32_t CRH;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t BRR;
	volatile uint32_t LCKR;
}GPIO_t;

/*========== Peripheral Registers:AFIO ==========*/
typedef struct{
	volatile uint32_t EVCR;
	volatile uint32_t MAPR;
	volatile uint32_t EXTICR1;
	volatile uint32_t EXTICR2;
	volatile uint32_t EXTICR3;
	volatile uint32_t EXTICR4;
	volatile uint32_t RESERVED;
	volatile uint32_t MAPR2;
}AFIO_t;

/*========== Peripheral Registers:EXTI ==========*/
typedef struct{
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;
}EXTI_t;

/*========== Peripheral Instances:GPIO ==========*/
#define GPIOA	((GPIO_t*)(GPIOA_BASE))
#define GPIOB	((GPIO_t*)(GPIOB_BASE))
#define GPIOC	((GPIO_t*)(GPIOC_BASE))
#define GPIOD	((GPIO_t*)(GPIOD_BASE))
#define GPIOE	((GPIO_t*)(GPIOE_BASE))
#define GPIOF	((GPIO_t*)(GPIOF_BASE))
#define GPIOG	((GPIO_t*)(GPIOG_BASE))

/*========== Peripheral Instances:AFIO ==========*/
#define AFIO	((AFIO_t*)(AFIO_BASE))

/*========== Peripheral Instances:AFIO ==========*/
#define EXTI	((EXTI_t*)(AFIO_BASE))

/*========== Peripheral Instances:RCC ==========*/
#define RCC	((RCC_t*)(RCC_BASE))

/*========== Clock Enable Macros ==========*/
#define RCC_GPIOA_CLK_EN()		(RCC->APB2ENR |= (1<<2))
#define RCC_GPIOB_CLK_EN()		(RCC->APB2ENR |= (1<<3))
#define RCC_GPIOC_CLK_EN()		(RCC->APB2ENR |= (1<<4))
#define RCC_GPIOD_CLK_EN()		(RCC->APB2ENR |= (1<<5))
#define RCC_GPIOE_CLK_EN()		(RCC->APB2ENR |= (1<<6))

#define RCC_AFIO_CLK_EN()		(RCC->APB2ENR |= (1<<0))
#endif /* INC_STM32F103X6_H_ */
