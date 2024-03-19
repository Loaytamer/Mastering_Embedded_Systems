/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Loay Tamer Mohamed
 * @brief          : Main program body
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include "STM32F103C6_GPIO.h"

//clk configuration
void clk_init()
{
	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();
}

// GPIO configurations
void gpio_init()
{
	GPIO_pinConfig_t pinConfig;
	// mode of pin A1
	pinConfig.GPIO_pinNumber 	 = GPIO_PIN_1;
	pinConfig.GPIO_MODE	  		 = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(GPIOA, &pinConfig);

	// mode of pin A13
	pinConfig.GPIO_pinNumber 	 = GPIO_PIN_13;
	pinConfig.GPIO_MODE	  	 	 = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(GPIOA, &pinConfig);

	// mode of pin B1
	pinConfig.GPIO_pinNumber 	 = GPIO_PIN_1;
	pinConfig.GPIO_MODE	  	 	 = GPIO_MODE_OUTPUT_PP;
	pinConfig.GPIO_Output_Speed  = GPIO_MODE_10MHZ;
	MCAL_GPIO_Init(GPIOB, &pinConfig);

	// mode of pin B13
	pinConfig.GPIO_pinNumber 	 = GPIO_PIN_13;
	pinConfig.GPIO_MODE	  	 	 = GPIO_MODE_OUTPUT_PP;
	pinConfig.GPIO_Output_Speed  = GPIO_MODE_10MHZ;
	MCAL_GPIO_Init(GPIOB, &pinConfig);
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
		if(MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) == 0) // btn(PIN A1) pressed
		{
			MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN_1);
			while(MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) == 0); //single press
		}
		if(MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_13) == 1) // btn(PIN A13) pressed
		{
			//multipress
			MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN_13);
		}
		custom_delay(1);
	}
}

