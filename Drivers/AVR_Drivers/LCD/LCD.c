/*
 * Author: Loay Tamer Mohamed
 * Description: LCD.c for avr
 */

#include "LCD.h"

/**
 * @Fn        - LCD_INIT
 * @brief     - Initializes the LCD display in preparation for use.
 * @details   - This function performs the essential setup steps required by the LCD controller to function correctly.
		        It typically involves setting the display mode (e.g., 4-bit or 8-bit interface),
			    enabling display and backlight (if applicable),and configuring other initial parameters.
 * @param[in] - None 
 * @retval    - None
 */
void LCD_INIT(void){
	_delay_ms(20);
	DataDir_LCD_PORT  = 0xFF; //LCD Port is o/p
	DataDir_LCD_CTRL |= ((1<<RS) | (1<<RW) | (1<<EN)) ; // control pins is o/p
	LCD_CTRL		 &= ~((1<<RS) | (1<<RW) | (1<<EN)); // reset control pins
	_delay_ms(15);
	LCD_Clear_screen();
	#ifdef EIGHT_BIT_MODE
	LCD_write_command(LCD_FUNCTION_8BIT_2LINES);
	#endif
	
	#ifdef FOUR_BIT_MODE
	LCD_write_command(LCD_FUNCTION_4BIT_2LINES);
	LCD_write_command(0x02);
	#endif
	
	LCD_write_command(LCD_DISP_ON_CURSOR_BLINK);
	LCD_write_command(LCD_BEGIN_AT_FIRST_ROW);
	LCD_write_command(LCD_ENTRY_MODE);
}

/**
 * @Fn        - LCD_write_command
 * @brief  	  - Sends a command byte to the LCD controller.
 * @details   - Commands are used to control various aspects of the LCD's behavior, such as clearing the display,
			    setting cursor position, configuring display mode, and more.
 * @param[in] - cmd (unsigned char): The command byte to be sent to the LCD.
 * @retval    - None
 * @Note      - The LCD controller might require specific timings or control signals for sending commands.
 */
void LCD_write_command(unsigned char cmd){
	LCD_CTRL &= ~((1<<RS) | (1<<RW)); //set command and write mode 
	#ifdef EIGHT_BIT_MODE
	LCD_PORT  = cmd;
	_delay_ms(1);
	LCD_kick();
	#endif
	
	#ifdef FOUR_BIT_MODE
	LCD_PORT  = (LCD_PORT & 0X0F) | (cmd & 0XF0); // write MSBs of cmd
	LCD_kick();	
	LCD_PORT  = (LCD_PORT & 0X0F) | (cmd << 4 );  // write LSBs of cmd
	LCD_kick();
	#endif
}

/**
 * @Fn        - LCD_write_data
 * @brief     - Writes a data byte to the LCD display.
 * @details   - Data bytes represent the actual characters or symbols that appear on the display. This function sends them to the LCD for rendering.
 * @param[in] - data (unsigned char): The data byte to be written to the LCD.
 * @retval    - None
 * @Note      - Similar to `LCD_write_command`, timing requirements or control signals might be necessary.
 */
void LCD_write_data(unsigned char data){
	LCD_CTRL &= ~(1<<RW); //write mode
	LCD_CTRL |=  (1<<RS); //set data mode
	#ifdef EIGHT_BIT_MODE
	LCD_PORT  = data;
	_delay_ms(1);
	LCD_kick();
	#endif
	
	#ifdef FOUR_BIT_MODE
	LCD_PORT  = (LCD_PORT & 0X0F) | (data & 0XF0); // write MSBs of data
	LCD_kick();
	LCD_PORT  = (LCD_PORT & 0X0F) | (data << 4 );  // write LSBs of data
	LCD_kick();
	#endif
}

/**
 * @Fn        - LCD_write_string
 * @brief     - Writes a null-terminated string of characters to the LCD display.
 * @details   - This function iterates through the provided string, sending each character (data byte) to the LCD using `LCD_write_data` for efficient display.
 * @param[in] - string (char*): A pointer to a null-terminated character array containing the string to be displayed.
 * @retval    - None
 * @Note      - Ensure the string length doesn't exceed the LCD's display capacity.
 */
void LCD_write_string(char* string){
	int counter = 0;
	while (*string){
		counter++;
		LCD_write_data(*string++);
		if(counter > 16)
		{
			LCD_GOTO_XY(2, 0); //go to second line at first position
		}
		else if(counter > 32)
		{
			LCD_Clear_screen();
			LCD_GOTO_XY(1, 0); //go to first line at first position
			counter = 0;
		}
	}
}

/**
 * @Fn        - LCD_Clear_screen
 * @brief     - Clears the entire LCD display and positions the cursor at the home position (usually top-left corner).
 * @details   - This function sends the appropriate command to the LCD controller to erase all displayed content and typically resets the cursor to its default location.
 * @param[in] - None
 * @retval    - None
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
	LCD_CTRL |= (1<<EN);
	_delay_ms(50);
	LCD_CTRL &= ~(1<<EN);
}

/**
 * @Fn        - LCD_GOTO_XY
 * @brief     - Positions the cursor on the LCD display at a specified row (line) and column (position).
 * @details   - This function sends the appropriate command to the LCD controller to move the cursor to the desired location. 
				This allows for targeted character placement when writing data.
 * @param[in] - line (unsigned char): The desired row (line) number on the LCD (zero-based indexing is common).
 * @param[in] - position (unsigned char): The desired column (position) within the row (zero-based indexing is common).
 * @retval    - None
 * @Note      - The exact range
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

/**
 * @Fn     - LCD_isBusy
 * @brief  - Checks if the LCD controller is busy (processing a command or data).
 * @details This function typically reads a specific status flag or register bit from the LCD controller that indicates its busy state.
			While busy, the LCD might not be able to accept new commands or data reliably.
 * @param[in] - None
 * @retval  - (implementation-dependent):
 *   - Returns a non-zero value if the LCD is busy.
 *   - Returns zero if the LCD is not busy and ready to receive commands or data.
 * @Note   - The exact return value and busy flag interpretation depend on the LCD controller. Consult the LCD's datasheet for precise details. This function might be called before sending commands or data to ensure successful transmission.
 */
void LCD_isBusy(void);
