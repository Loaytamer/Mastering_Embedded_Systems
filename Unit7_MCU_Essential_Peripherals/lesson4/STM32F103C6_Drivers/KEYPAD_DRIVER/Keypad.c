/*
 * Author: Loay Tamer Mohamed
 * Description: Keypad.c
 */

#include "Keypad.h"

GPIO_pinConfig_t pinConfig;
int Keypad_row[] = {R0, R1, R2, R3};
int Keypad_col[] = {C0, C1, C2, C3};

/**
 * @Fn		  - Keypad_init
 * @brief     - Initializes the keypad for reading key presses.
 * @details   - This function likely performs the necessary setup steps to prepare the keypad for user input. It involve:
 *			     - Configuring GPIO pins connected to the keypad rows and columns (as inputs and outputs).
 *				 - Enabling any internal pull-up or pull-down resistors on the GPIO pins (if required).
 *				 - Setting up scanning logic to detect key presses (if the keypad doesn't have built-in scanning).
 * @param[in] - None 
 * @retval    - None
 * @Note      - The specific initialization steps depend on the keypad type and its connection to the microcontroller.
 */
void Keypad_init(){
	// make rows as output
	pinConfig.GPIO_pinNumber    = R0;
	pinConfig.GPIO_MODE         = GPIO_MODE_OUTPUT_PP;
	pinConfig.GPIO_Output_Speed = GPIO_MODE_10MHZ;
	MCAL_GPIO_Init(Keypad_PORT, &pinConfig);

	pinConfig.GPIO_pinNumber    = R1;
	pinConfig.GPIO_MODE         = GPIO_MODE_OUTPUT_PP;
	pinConfig.GPIO_Output_Speed = GPIO_MODE_10MHZ;
	MCAL_GPIO_Init(Keypad_PORT, &pinConfig);

	pinConfig.GPIO_pinNumber    = R2;
	pinConfig.GPIO_MODE         = GPIO_MODE_OUTPUT_PP;
	pinConfig.GPIO_Output_Speed = GPIO_MODE_10MHZ;
	MCAL_GPIO_Init(Keypad_PORT, &pinConfig);

	pinConfig.GPIO_pinNumber    = R3;
	pinConfig.GPIO_MODE         = GPIO_MODE_OUTPUT_PP;
	pinConfig.GPIO_Output_Speed = GPIO_MODE_10MHZ;
	MCAL_GPIO_Init(Keypad_PORT, &pinConfig);

	// make cols as output
	pinConfig.GPIO_pinNumber    = C0;
	pinConfig.GPIO_MODE         = GPIO_MODE_OUTPUT_PP;
	pinConfig.GPIO_Output_Speed = GPIO_MODE_10MHZ;
	MCAL_GPIO_Init(Keypad_PORT, &pinConfig);

	pinConfig.GPIO_pinNumber    = C1;
	pinConfig.GPIO_MODE         = GPIO_MODE_OUTPUT_PP;
	pinConfig.GPIO_Output_Speed = GPIO_MODE_10MHZ;
	MCAL_GPIO_Init(Keypad_PORT, &pinConfig);

	pinConfig.GPIO_pinNumber    = C2;
	pinConfig.GPIO_MODE         = GPIO_MODE_OUTPUT_PP;
	pinConfig.GPIO_Output_Speed = GPIO_MODE_10MHZ;
	MCAL_GPIO_Init(Keypad_PORT, &pinConfig);

	pinConfig.GPIO_pinNumber    = C3;
	pinConfig.GPIO_MODE         = GPIO_MODE_OUTPUT_PP;
	pinConfig.GPIO_Output_Speed = GPIO_MODE_10MHZ;
	MCAL_GPIO_Init(Keypad_PORT, &pinConfig);

	MCAL_GPIO_WritePort(Keypad_PORT, 0XFF);
}

/**
 * @Fn	     - Keypad_getKey
 * @brief    - Reads the pressed key from the keypad (if any).
 * @details	 - This function scans the keypad to identify the currently pressed key (if a key is pressed). It typically involves:
 *				 - Implementing a scanning algorithm to check each key in the keypad matrix.
 *				 - Detecting a voltage change on a row pin when a column pin is driven low (or vice versa, depending on the connection scheme).
 *				 - Decoding the row and column combination to determine the pressed key.
 * @param[in] - None
 * @retval    - (implementation-dependent):
 *				 - Returns the ASCII code of the pressed key (e.g., 'A', '1', '#') if a key is pressed.
 *				 - Returns a special value (e.g., 0, -1) to indicate no key is pressed.
 * @Note	  - The exact return value and its interpretation for "no key pressed" depend on the implementation.
 */
char Keypad_getKey(){
	int i, j;
	for(i = 0; i < 4; i++)
	{
		//set all col = 1
		MCAL_GPIO_WritePin(Keypad_PORT, Keypad_col[0], GPIO_PIN_SET);
		MCAL_GPIO_WritePin(Keypad_PORT, Keypad_col[1], GPIO_PIN_SET);
		MCAL_GPIO_WritePin(Keypad_PORT, Keypad_col[2], GPIO_PIN_SET);
		MCAL_GPIO_WritePin(Keypad_PORT, Keypad_col[3], GPIO_PIN_SET);
		MCAL_GPIO_WritePin(Keypad_PORT, Keypad_col[i], GPIO_PIN_RESET);
		for(j = 0; j < 4; j++)
		{
			if(MCAL_GPIO_ReadPin(Keypad_PORT, Keypad_row[j]) == 0) //check if the btn is pressed
			{
				while (MCAL_GPIO_ReadPin(Keypad_PORT, Keypad_row[j]) == 0); // to realise it as single press
				switch(i){
				case (0): if     (j==0) return '7';
						else if(j==1) return '4';
						else if(j==2) return '1';
						else if(j==3) return 'O';
						break;
				case (1): if     (j==0) return '8';
						else if(j==1) return '5';
						else if(j==2) return '2';
						else if(j==3) return '0';
						break;
				case (2): if     (j==0) return '9';
						else if(j==1) return '6';
						else if(j==2) return '3';
						else if(j==3) return '=';
						break;
				case (3): if     (j==0) return '/';
						else if(j==1) return '*';
						else if(j==2) return '-';
						else if(j==3) return '+';
						break;
				}
			}
		}
	}
	return 'N'; //indicates no pressed
}
