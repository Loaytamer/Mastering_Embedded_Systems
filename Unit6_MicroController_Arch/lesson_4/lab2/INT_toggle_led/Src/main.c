/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

/*
 ******************************************************************************
 * @file           : main.c
 * @author         : Loay Tamer Mohamed
 * @brief          : STM32F103C6_INT_lab
 ******************************************************************************
 */
#include <stdint.h>


//clock control
#define RCC_BASE   	0x40021000
#define RCC_APB2ENR *(volatile uint32_t *)(RCC_BASE   + 0x18)

//GPIOA
#define GPIOA_BASE 	0x40010800
#define GPIOA_CRH 	*(volatile uint32_t *)(GPIOA_BASE + 0x04)
#define GPIOA_ODR 	*(volatile uint32_t *)(GPIOA_BASE + 0x0C)
#define GPIOA_CRL 	*(volatile uint32_t *)(GPIOA_BASE + 0x00)

//EXTI
#define EXTI_BASE 0x40010400
#define EXTI_IMR  *(volatile uint32_t *)(EXTI_BASE + 0x00)
#define EXTI_RTSR *(volatile uint32_t *)(EXTI_BASE + 0x08)
#define EXTI_PR   *(volatile uint32_t *)(EXTI_BASE + 0x14)

// AFIO
#define AFIO_BASE 0x40010000
#define AFIO_EXTICR1 *(volatile uint32_t *)(AFIO_BASE + 0x08)

#define NVIC_ISER0 *(volatile uint32_t *)(0xE000E100)

void clk_init()
{
	RCC_APB2ENR |= (1<<2);
	RCC_APB2ENR |= (1<<0);
}

void GPIO_init()
{
	GPIOA_CRH	&= 0xFF0FFFFF;
	GPIOA_CRH	|= 0x00200000;
	//configure pin 0 as input
	GPIOA_CRL |= (1<<2);
}

void EXTI_init()
{
	// EXTI 0 configuration
	AFIO_EXTICR1 = 0;
	// Rising trigger enabled for line 0
	EXTI_RTSR |= (1<<0);
	//  Interrupt request from Line 0 is not masked
	EXTI_IMR |= (1<<0);

}
int main(void)
{
	clk_init();
	GPIO_init();

	EXTI_init();
	NVIC_ISER0 |= (1<<6);
	while(1);
	return 0;
}

void EXTI0_IRQHandler()
{
	//toggle pin 13 PORTA
	GPIOA_ODR ^= (1<<13);

	//clear pending reg
	EXTI_PR |= (1<<0);
}
