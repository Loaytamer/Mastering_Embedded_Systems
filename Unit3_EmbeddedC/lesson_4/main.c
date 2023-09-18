/*
 ******************************************************************************
 * @file           : main.c
 * @author         : Loay Tamer Mohamed
 * @brief          : TivaC_Led_Toggle
 ******************************************************************************
 */
#include <stdint.h>
typedef volatile unsigned int vuint32_t;

//Registers
#define SYSCTL_RCGC2_R 		*(volatile vuint32_t *)(0x400FE108)
#define GPIOA_PORTF_DIR_R	*(volatile vuint32_t *)(0x40025400)
#define GPIOA_PORTF_DEN_R	*(volatile vuint32_t *)(0x4002551C)
#define GPIOA_PORTF_DATA_R	*(volatile vuint32_t *)(0x400253FC)

int main(void)
{
	volatile unsigned int i;
	SYSCTL_RCGC2_R = 0x20;
	for(i = 0; i < 5000; i++);//delay
	GPIOA_PORTF_DIR_R |= 1<<3;
	GPIOA_PORTF_DEN_R |= 1<<3;
	while(1)
	{
		
		GPIOA_PORTF_DATA_R |= 1<<3;
		for(i = 0; i < 100000; i++);//delay
		GPIOA_PORTF_DATA_R &= ~(1<<3);
		for(i = 0; i < 100000; i++);//delay
	}
	return 0;
}
