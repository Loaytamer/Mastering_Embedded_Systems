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
#include "Keypad.h"

#define ZERO 0x01
#define ONE 0x79
#define TWO 0x24
#define THREE 0x30
#define FOUR 0x4C
#define FIVE 0x12
#define SIX 0x02
#define SEVEN 0x19
#define EIGHT 0x00
#define NINE 0x10
//clk configuration
void clk_init()
{
	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();
}

void GPIO_init() {

	GPIO_pinConfig_t PinCfg;

	//PA1 input HighZ Floating input (reset state)
//	PinCfg.GPIO_PinNumber = GPIO_PIN_1;
//	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
//	MCAL_GPIO_Init(GPIOA, &PinCfg);

//PB1 (output PUSH pull Mode)
//01: Output mode, max speed 10 MHz.
//CNF 00: General purpose output push-pull
	PinCfg.GPIO_pinNumber = GPIO_PIN_9;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_MODE_10MHZ;
	MCAL_GPIO_Init(GPIOB, &PinCfg);

	PinCfg.GPIO_pinNumber = GPIO_PIN_10;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_MODE_10MHZ;
	MCAL_GPIO_Init(GPIOB, &PinCfg);

	PinCfg.GPIO_pinNumber = GPIO_PIN_11;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_MODE_10MHZ;
	MCAL_GPIO_Init(GPIOB, &PinCfg);

	PinCfg.GPIO_pinNumber = GPIO_PIN_12;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_MODE_10MHZ;
	MCAL_GPIO_Init(GPIOB, &PinCfg);

	PinCfg.GPIO_pinNumber = GPIO_PIN_13;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_MODE_10MHZ;
	MCAL_GPIO_Init(GPIOB, &PinCfg);

	//============================

	//PA13 input HighZ Floating input (reset state)
	PinCfg.GPIO_pinNumber = GPIO_PIN_14;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_MODE_10MHZ;
	MCAL_GPIO_Init(GPIOB, &PinCfg);

	//PB13 (output PUSH pull Mode)
	PinCfg.GPIO_pinNumber = GPIO_PIN_15;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_MODE_10MHZ;
	MCAL_GPIO_Init(GPIOB, &PinCfg);

}

int main(void)
{

	clk_init();
	LCD_INIT();
	GPIO_init();
	char key_pressed;
	unsigned char LCD_DISPLAY [11] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
	unsigned char DISPLAY [11] = {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, ZERO};
	for (unsigned char i = 0; i < 11; i++) {
		LCD_write_data(LCD_DISPLAY[i]);
		MCAL_GPIO_WritePort(GPIOB, DISPLAY[i] << 9); /* write data on to the LED port */
		custom_delay(100);
		/* wait for 1 second */
	}
	LCD_Clear_screen();
	Keypad_init();
	LCD_write_string("Keypad is ready");
	custom_delay(30);
	LCD_Clear_screen();
	while(1)
	{
		key_pressed = Keypad_getKey();
		switch (key_pressed) {
		case 'N':
			break;
		case 'O':
			LCD_Clear_screen();
			break;
		default:
			LCD_write_data(key_pressed);
			break;
		}
	}
}

