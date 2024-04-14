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

/*========== Base addresses for Cortex M3 Internal Peripherals ==========*/
//NVIC register map
#define NVIC_Base						(Cortex_M3_Internal_Peripherals+0x0000E100)
#define NVIC_ISER0						*(volatile uint32_t *)(NVIC_Base + 0x0)
#define NVIC_ISER1						*(volatile uint32_t *)(NVIC_Base + 0x4)
#define NVIC_ISER2						*(volatile uint32_t *)(NVIC_Base + 0x8)
#define NVIC_ICER0						*(volatile uint32_t *)(NVIC_Base + 0x80)
#define NVIC_ICER1						*(volatile uint32_t *)(NVIC_Base + 0x84)
#define NVIC_ICER2						*(volatile uint32_t *)(NVIC_Base + 0x88)



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
	volatile uint32_t EXTICR[4];
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

/*========== Peripheral Instances:EXTI ==========*/
#define EXTI	((EXTI_t*)(EXTI_BASE))

/*========== Peripheral Instances:RCC ==========*/
#define RCC		((RCC_t*)(RCC_BASE))

/*========== Clock Enable Macros ==========*/
#define RCC_GPIOA_CLK_EN()		(RCC->APB2ENR |= (1<<2))
#define RCC_GPIOB_CLK_EN()		(RCC->APB2ENR |= (1<<3))
#define RCC_GPIOC_CLK_EN()		(RCC->APB2ENR |= (1<<4))
#define RCC_GPIOD_CLK_EN()		(RCC->APB2ENR |= (1<<5))
#define RCC_GPIOE_CLK_EN()		(RCC->APB2ENR |= (1<<6))

#define RCC_AFIO_CLK_EN()		(RCC->APB2ENR |= (1<<0))

/*========== IVT : EXTI ==========*/
#define EXTI0_IRQ		6
#define EXTI1_IRQ		7
#define EXTI2_IRQ		8
#define EXTI3_IRQ		9
#define EXTI4_IRQ		10
#define EXTI5_IRQ		23
#define EXTI6_IRQ		23
#define EXTI7_IRQ		23
#define EXTI8_IRQ		23
#define EXTI9_IRQ		23
#define EXTI10_IRQ		40
#define EXTI11_IRQ		40
#define EXTI12_IRQ		40
#define EXTI13_IRQ		40
#define EXTI14_IRQ		40
#define EXTI15_IRQ		40

/*========== NVIC Enable/Disable Macros ==========*/
//Enable
#define NVIC_IRQ6_EXTI0_Enable()			(NVIC_ISER0 |= 1 << EXTI0_IRQ)
#define NVIC_IRQ7_EXTI1_Enable()			(NVIC_ISER0 |= 1 << EXTI1_IRQ)
#define NVIC_IRQ8_EXTI2_Enable()			(NVIC_ISER0 |= 1 << EXTI2_IRQ)
#define NVIC_IRQ9_EXTI3_Enable()			(NVIC_ISER0 |= 1 << EXTI3_IRQ)
#define NVIC_IRQ10_EXTI4_Enable()			(NVIC_ISER0 |= 1 << EXTI4_IRQ)
#define NVIC_IRQ23_EXTI5_9_Enable()			(NVIC_ISER0 |= 1 << EXTI5_IRQ)
#define NVIC_IRQ40_EXTI10_15_Enable()	 	(NVIC_ISER1 |= 1 << 8) //NVIC_ISER1 cover INT from 32-63, to en IRQ40=> 40-32=8

//Disable
#define NVIC_IRQ6_EXTI0_Disable()			(NVIC_ICER0 |= 1 << EXTI0_IRQ)
#define NVIC_IRQ7_EXTI1_Disable()			(NVIC_ICER0 |= 1 << EXTI1_IRQ)
#define NVIC_IRQ8_EXTI2_Disable()			(NVIC_ICER0 |= 1 << EXTI2_IRQ)
#define NVIC_IRQ9_EXTI3_Disable()			(NVIC_ICER0 |= 1 << EXTI3_IRQ)
#define NVIC_IRQ10_EXTI4_Disable()			(NVIC_ICER0 |= 1 << EXTI4_IRQ)
#define NVIC_IRQ23_EXTI5_9_Disable()		(NVIC_ICER0 |= 1 << EXTI5_IRQ)
#define NVIC_IRQ40_EXTI10_15_Disable()		(NVIC_ICER1 |= 1 << 8) //NVIC_ICER1 cover INT from 32-63, to en IRQ40=> 40-32=8


//delay
void custom_delay(int x);
#endif /* INC_STM32F103X6_H_ */
