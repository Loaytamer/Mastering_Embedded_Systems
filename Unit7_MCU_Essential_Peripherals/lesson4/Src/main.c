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


#include "LCD.h"
#include "STM32F103C6_EXTI.h"

uint8_t IRQ_FLAG;

void wait(uint32_t time)
{
	uint32_t i , j;

	for( i=0 ; i<time ; i++)
		for(j=0 ; j<255 ; j++);
}

//clk configuration
void clk_init()
{
	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();
	RCC_AFIO_CLK_EN();
}

void EXTI_CallBack(void){
	IRQ_FLAG = 1;
	LCD_Clear_screen();
	LCD_write_string("IRQ EXTI9 is happend.");
	wait(500);

}


int main(void)
{

	clk_init();
	LCD_INIT();
	LCD_Clear_screen();
	EXTI_PinConfig_t EXTI_CFG;
	EXTI_CFG.EXTI_PIN = EXTI9PB9;
	EXTI_CFG.Trigger_Case = EXTI_Trigger_Rising;
	EXTI_CFG.P_IRQ_CallBack = EXTI_CallBack;
	EXTI_CFG.IRQ_EN =EXTI_IRQ_Enable;
	MCAL_EXTI_Init(&EXTI_CFG);
	IRQ_FLAG = 1;
	while(1)
	{
//		if(IRQ_FLAG == 1)
//		{
//			LCD_Clear_screen();
//			IRQ_FLAG = 0;
//		}
		wait(500);
		LCD_Clear_screen();
		LCD_write_string("LCD Ready");
	}
}

