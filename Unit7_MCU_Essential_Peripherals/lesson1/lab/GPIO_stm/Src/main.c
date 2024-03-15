/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Loay Tamer Mohamed
 * @brief          : configure GPIO in stm32f103c6 (BluePill)
 ******************************************************************************
 **/
#include <stdint.h>
#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

// RCC registers
#define RCC_BASE 0x40021000
#define RCC_APB2ENR *(volatile uint32_t*)(RCC_BASE + 0x18)
#define IOPAEN 2
#define IOPBEN 3

//GPIOA registers
#define GPIOA_BASE 0x40010800
#define GPIOA_CRL  *(volatile uint32_t*)(GPIOA_BASE + 0x00)
#define GPIOA_CRH  *(volatile uint32_t*)(GPIOA_BASE + 0x04)
#define GPIOA_IDR  *(volatile uint32_t*)(GPIOA_BASE + 0x08)

//GPIOB registers
#define GPIOB_BASE 0x40010c00
#define GPIOB_CRL  *(volatile uint32_t*)(GPIOB_BASE + 0x00)
#define GPIOB_CRH  *(volatile uint32_t*)(GPIOB_BASE + 0x04)
#define GPIOB_ODR  *(volatile uint32_t*)(GPIOB_BASE + 0x0C)

//clk configuration
void clk_init()
{
	RCC_APB2ENR |= (1 << IOPAEN) | (1 << IOPBEN);
}

// GPIO configurations
void gpio_init()
{
	GPIOA_CRL = 0x0;
	GPIOA_CRH = 0x0;
	GPIOB_CRL = 0x0;
	GPIOB_CRH = 0x0;
	// mode of pin A1
	GPIOA_CRL &= ~(0b11 << 4); // pin A1 as i/p
	GPIOA_CRL |= (1 << 6);     // floating i/p

	// mode of pin A13
	GPIOA_CRH &= ~(0b11 << 20); // pin A13 as i/p
	GPIOA_CRH |= (1 << 22);     // floating i/p

	// mode of pin B1
	GPIOB_CRL |= (1 << 4);      // pin B1 as o/p
	GPIOB_CRL &= ~(0b11 << 6);  // push-pull

	// mode of pin B1
	GPIOB_CRH |= (1 << 20);     // pin B13 as o/p
	GPIOB_CRH &= ~(0b11 << 22); // push-pull
}

void custom_delay(int x)
{
	uint8_t i,j;
	for(i = 0; i < x; i++)
		for(j = 0; j < 255; j++);
}
int main(void)
{
	clk_init();
	gpio_init();

	while(1)
	{
		if(((GPIOA_IDR & (1<<1)) >> 1) == 0) // btn(PIN A1) pressed
		{
			GPIOB_ODR ^= (1 << 1); //toggle pin B1
			while((((GPIOA_IDR & (1<<1)) >> 1) == 0)); //single press
		}
		if(((GPIOA_IDR & (1<<13)) >> 13) == 1) // btn(PIN A13) pressed
		{
			//multipress
			GPIOB_ODR ^= (1 << 13); //toggle pin B13
		}
		custom_delay(1);
	}
}
