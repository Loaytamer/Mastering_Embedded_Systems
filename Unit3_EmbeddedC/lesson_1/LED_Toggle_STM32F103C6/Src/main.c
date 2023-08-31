/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Loay Tamer Mohamed
 * @brief          : STM32F103C6_Led_Toggle
 ******************************************************************************
 */
#include <stdint.h>
typedef volatile unsigned int vuint32_t;

//Addresses
#define RCC_BASE   	0x40021000
#define GPIOA_BASE 	0x40010800
#define RCC_APB2ENR *(volatile uint32_t *)(RCC_BASE   + 0x18)
#define GPIOA_CRH 	*(volatile uint32_t *)(GPIOA_BASE + 0x04)
#define GPIOA_ODR 	*(volatile uint32_t *)(GPIOA_BASE + 0x0C)

typedef union
{
	vuint32_t All_fields;
	struct{
		vuint32_t reserved : 13;
		vuint32_t PIN13	   : 1;
	}PIN;
}GPIOA_ODR_t;

volatile GPIOA_ODR_t* ODR = (volatile GPIOA_ODR_t*)(GPIOA_BASE + 0x0C);
int main(void)
{
	RCC_APB2ENR |= (1<<2);
	GPIOA_CRH	&= 0xFF0FFFFF;
	GPIOA_CRH	|= 0x00200000;
	while(1)
	{
		ODR->PIN.PIN13 = 1;
		for(int i = 0; i < 10000; i++);//delay
		ODR->PIN.PIN13 = 0;
		for(int i = 0; i < 5000; i++);//delay
	}
	return 0;
}
