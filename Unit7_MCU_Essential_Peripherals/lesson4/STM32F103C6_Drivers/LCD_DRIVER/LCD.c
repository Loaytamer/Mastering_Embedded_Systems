/*
 * Author: Loay Tamer Mohamed
 * Description: LCD.c for avr
 */

#include "LCD.h"

GPIO_pinConfig_t pinConfig;

void custom_delay(int x)
{
	uint8_t i,j;
	for(i = 0; i < x; i++)
		for(j = 0; j < 255; j++);
}

/**
 * @Fn        - LCD_INIT
 * @brief��   - Initializes the LCD display in preparation for use.
 * @details   - This function performs the essential setup steps required by the LCD controller to function correctly.
		        It typically involves setting the display mode (e.g., 4-bit or 8-bit interface),
			    enabling display and backlight (if applicable),and configuring other initial parameters.
 * @param[in] - None 
 * @retval    - None
 */
void LCD_INIT(void){
	custom_delay(20);
	//LCD Port is o/p
	pinConfig.GPIO_pinNumber    = GPIO_PIN_0;
	pinConfig.GPIO_MODE         = GPIO_MODE_OUTPUT_PP;
	pinConfig.GPIO_Output_Speed = GPIO_MODE_10MHZ;
	MCAL_GPIO_Init(LCD_PORT, &pinConfig);

	pinConfig.GPIO_pinNumber    = GPIO_PIN_1;
	pinConfig.GPIO_MODE         = GPIO_MODE_OUTPUT_PP;
	pinConfig.GPIO_Output_Speed = GPIO_MODE_10MHZ;
	MCAL_GPIO_Init(LCD_PORT, &pinConfig);

	pinConfig.GPIO_pinNumber    = GPIO_PIN_2;
	pinConfig.GPIO_MODE         = GPIO_MODE_OUTPUT_PP;
	pinConfig.GPIO_Output_Speed = GPIO_MODE_10MHZ;
	MCAL_GPIO_Init(LCD_PORT, &pinConfig);

	pinConfig.GPIO_pinNumber    = GPIO_PIN_3;
	pinConfig.GPIO_MODE         = GPIO_MODE_OUTPUT_PP;
	pinConfig.GPIO_Output_Speed = GPIO_MODE_10MHZ;
	MCAL_GPIO_Init(LCD_PORT, &pinConfig);

	pinConfig.GPIO_pinNumber    = GPIO_PIN_4;
	pinConfig.GPIO_MODE         = GPIO_MODE_OUTPUT_PP;
	pinConfig.GPIO_Output_Speed = GPIO_MODE_10MHZ;
	MCAL_GPIO_Init(LCD_PORT, &pinConfig);

	pinConfig.GPIO_pinNumber    = GPIO_PIN_5;
	pinConfig.GPIO_MODE         = GPIO_MODE_OUTPUT_PP;
	pinConfig.GPIO_Output_Speed = GPIO_MODE_10MHZ;
	MCAL_GPIO_Init(LCD_PORT, &pinConfig);

	pinConfig.GPIO_pinNumber    = GPIO_PIN_6;
	pinConfig.GPIO_MODE         = GPIO_MODE_OUTPUT_PP;
	pinConfig.GPIO_Output_Speed = GPIO_MODE_10MHZ;
	MCAL_GPIO_Init(LCD_PORT, &pinConfig);

	pinConfig.GPIO_pinNumber    = GPIO_PIN_7;
	pinConfig.GPIO_MODE         = GPIO_MODE_OUTPUT_PP;
	pinConfig.GPIO_Output_Speed = GPIO_MODE_10MHZ;
	MCAL_GPIO_Init(LCD_PORT, &pinConfig);

	pinConfig.GPIO_pinNumber    = RS;
	pinConfig.GPIO_MODE         = GPIO_MODE_OUTPUT_PP;
	pinConfig.GPIO_Output_Speed = GPIO_MODE_10MHZ;
	MCAL_GPIO_Init(LCD_CTRL, &pinConfig);
	pinConfig.GPIO_pinNumber    = RW;
	pinConfig.GPIO_MODE         = GPIO_MODE_OUTPUT_PP;
	pinConfig.GPIO_Output_Speed = GPIO_MODE_10MHZ;
	MCAL_GPIO_Init(LCD_CTRL, &pinConfig);

	pinConfig.GPIO_pinNumber    = EN;
	pinConfig.GPIO_MODE         = GPIO_MODE_OUTPUT_PP;
	pinConfig.GPIO_Output_Speed = GPIO_MODE_10MHZ;
	MCAL_GPIO_Init(LCD_CTRL, &pinConfig);

	// reset control pins
	MCAL_GPIO_WritePin(LCD_CTRL, RS, GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(LCD_CTRL, RW, GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(LCD_CTRL, EN, GPIO_PIN_RESET);

	custom_delay(15);
	LCD_Clear_screen();
	#ifdef EIGHT_BIT_MODE
	LCD_write_command(LCD_FUNCTION_8BIT_2LINES);
	#endif

	/*#ifdef FOUR_BIT_MODE
	LCD_write_command(LCD_FUNCTION_4BIT_2LINES);
	LCD_write_command(0x02);
	#endif*/

	LCD_write_command(LCD_DISP_ON_CURSOR_BLINK);
	LCD_write_command(LCD_BEGIN_AT_FIRST_ROW);
	LCD_write_command(LCD_ENTRY_MODE);
}

/**
 * @Fn        - LCD_write_command
 * @brief	  - Sends a command byte to the LCD controller.
 * @details   - Commands are used to control various aspects of the LCD's behavior, such as clearing the display,
			    setting cursor position, configuring display mode, and more.
 * @param[in] - cmd (unsigned char): The command byte to be sent to the LCD.
 * @retval    - None
 * @Note	  - The LCD controller might require specific timings or control signals for sending commands.
 */
void LCD_write_command(unsigned char cmd){
	//set command and write mode
	MCAL_GPIO_WritePin(LCD_CTRL, RS, GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(LCD_CTRL, RW, GPIO_PIN_RESET);
	#ifdef EIGHT_BIT_MODE
	MCAL_GPIO_WritePort(LCD_PORT, cmd);
	custom_delay(1);
	LCD_kick();
	#endif

	/*#ifdef FOUR_BIT_MODE
		LCD_PORT  = (LCD_PORT & 0X0F) | (cmd & 0XF0); // write MSBs of cmd
		LCD_kick();
		LCD_PORT  = (LCD_PORT & 0X0F) | (cmd << 4 );  // write LSBs of cmd
		LCD_kick();
	#endif*/
}

/**
 * @Fn	      - LCD_write_data
 * @brief     - Writes a data byte to the LCD display.
 * @details   - Data bytes represent the actual characters or symbols that appear on the display. This function sends them to the LCD for rendering.
 * @param[in] - data (unsigned char): The data byte to be written to the LCD.
 * @retval    - None
 * @Note���   - Similar to `LCD_write_command`, timing requirements or control signals might be necessary.
 */
void LCD_write_data(unsigned char data){
	#ifdef EIGHT_BIT_MODE
	MCAL_GPIO_WritePort(LCD_PORT, data);
	#endif
	MCAL_GPIO_WritePin(LCD_CTRL, RW, GPIO_PIN_RESET); //write mode
	MCAL_GPIO_WritePin(LCD_CTRL, RS, GPIO_PIN_SET); //set data mode
	custom_delay(1);
	LCD_kick();
	/*#ifdef FOUR_BIT_MODE
		LCD_PORT  = (LCD_PORT & 0X0F) | (data & 0XF0); // write MSBs of data
		LCD_kick();
		LCD_PORT  = (LCD_PORT & 0X0F) | (data << 4 );  // write LSBs of data
		LCD_kick();
	#endif*/
}

/**
 * @Fn	      - LCD_write_string
 * @brief     - Writes a null-terminated string of characters to the LCD display.
 * @details   - This function iterates through the provided string, sending each character (data byte) to the LCD using `LCD_write_data` for efficient display.
 * @param[in] - string (char*): A pointer to a null-terminated character array containing the string to be displayed.
 * @retval    - None
 * @Note      - Ensure the string length doesn't exceed the LCD's display capacity.
 */
void LCD_write_string(char* string){
	int counter = 0;
	while (*string){
		counter++;
		LCD_write_data(*string++);
		if(counter == 16)
		{
			LCD_GOTO_XY(2, counter-16); //go to second line at first position
		}
		else if(counter == 32)
		{
			LCD_Clear_screen();
			counter = 0;
			LCD_GOTO_XY(1, counter); //go to first line at first position

		}
	}
}

/**
 * @Fn        - LCD_Clear_screen
 * @brief��   - Clears the entire LCD display and positions the cursor at the home position (usually top-left corner).
 * @details   - This function sends the appropriate command to the LCD controller to erase all displayed content and typically resets the cursor to its default location.
 * @param[in] - None
 * @retval    - None
 */
void LCD_Clear_screen(void){
	LCD_write_command(LCD_CLEAR_SCREEN);
}

/**
 * @Fn		  - LCD_LCD_kick
 * @brief	  - Enables the LCD to receive commands or data for a specified duration.
 * @details	  - This function is likely used to provide a brief window for the LCD controller to accept commands or data.
				It typically involves:
 *				 1. Setting an LCD control signal EN to indicate a command or data transfer.
 *				 2. Introducing a short delay to allow the LCD controller to prepare for the transfer.
 *				 3. (Optional) Clearing the control signal(s) to disable further commands or data until the next `LCD_kick` or a separate enabling mechanism is used.
 * @param[in] - None 
 * @retval    - None
 * @Note      - The specific control signals and timing requirements depend on the LCD controller. 
 */
void LCD_kick(void){
	MCAL_GPIO_WritePin(LCD_CTRL, EN, GPIO_PIN_SET);
	custom_delay(50);
	MCAL_GPIO_WritePin(LCD_CTRL, EN, GPIO_PIN_RESET);
}

/**
 * @Fn	      - LCD_GOTO_XY
 * @brief     - Positions the cursor on the LCD display at a specified row (line) and column (position).
 * @details   - This function sends the appropriate command to the LCD controller to move the cursor to the desired location. 
				This allows for targeted character placement when writing data.
 * @param[in] - line (unsigned char): The desired row (line) number on the LCD (zero-based indexing is common).
 * @param[in] - position (unsigned char): The desired column (position) within the row (zero-based indexing is common).
 * @retval    - None
 * @Note      - The exact range
 */
void LCD_GOTO_XY(unsigned char line, unsigned char position){
	//Ensure that position is in allowed range
	if (position < 16 && position >= 0){
		if(line == 1)
			LCD_write_command(LCD_BEGIN_AT_FIRST_ROW + position);
		else if(line == 2)
			LCD_write_command(LCD_BEGIN_AT_SECOND_ROW + position);
	}
}


