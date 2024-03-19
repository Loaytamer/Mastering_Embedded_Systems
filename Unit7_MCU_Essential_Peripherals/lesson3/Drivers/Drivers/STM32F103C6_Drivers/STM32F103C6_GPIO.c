/*
 * STM32F103C6_GPIO.c
 * Author: Loay Tamer Mohamed
 */

#include "STM32F103C6_GPIO.h"


uint8_t CRLH_Postion(uint16_t pinNumber){
	switch(pinNumber){
	case GPIO_PIN_0:
		return 0;
		break;
	case GPIO_PIN_1:
		return 4;
		break;
	case GPIO_PIN_2:
		return 8;
		break;
	case GPIO_PIN_3:
		return 12;
		break;
	case GPIO_PIN_4:
		return 16;
		break;
	case GPIO_PIN_5:
		return 20;
		break;
	case GPIO_PIN_6:
		return 24;
		break;
	case GPIO_PIN_7:
		return 28;
		break;
	case GPIO_PIN_8:
		return 0;
		break;
	case GPIO_PIN_9:
		return 4;
		break;
	case GPIO_PIN_10:
		return 8;
		break;
	case GPIO_PIN_11:
		return 12;
		break;
	case GPIO_PIN_12:
		return 16;
		break;
	case GPIO_PIN_13:
		return 20;
		break;
	case GPIO_PIN_14:
		return 24;
		break;
	case GPIO_PIN_15:
		return 28;
		break;
	return 0;
	}
}

	/**================================================================
	 *@Fn        - MCAL_GPIO_Init
	 *@brief     - Initializes a GPIO pin with the specified configuration.
	 *@param[in] - GPIOx: Pointer to GPIO peripheral (where x can be A to D).
	 *             pinConfig: Pointer to structure containing pin configuration settings.
	 *@retval    - None
	 *@Note      - in LQFP package A,B fully included..  C,D parital included.. E,F,G not included..
   ================================================================
	 */
	void MCAL_GPIO_Init  (GPIO_t* GPIOx, GPIO_pinConfig_t* pinConfig){
		// select between CRL or CRH, if pin 0->7 choose CRL else: Choose CRH
		volatile uint32_t *configReg = (pinConfig->GPIO_pinNumber < GPIO_PIN_8)? &(GPIOx->CRL):&(GPIOx->CRH);
		// clear CNF[1:0] MODE[1:0]
		*(configReg) &= ~(0xF << CRLH_Postion(pinConfig->GPIO_pinNumber));
		//pin_config to store CNF[1:0] MODE[1:0] for selected pin
		uint8_t pin_config = 0;
		// if output mode
		if(pinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_PP || pinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_OD|| pinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_AF_PP || pinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_AF_OD){
			pin_config = ((((pinConfig->GPIO_MODE-5) << 2) | (pinConfig->GPIO_Output_Speed)) & 0x0F);
		}
		// if input mode
		// Mode 00: input mode (reset state)
		else{
			if(pinConfig->GPIO_MODE == GPIO_MODE_ANALOG || pinConfig->GPIO_MODE == GPIO_MODE_INPUT_FLO)
			{
				pin_config = (pinConfig->GPIO_MODE << 2);
			}
			else if(pinConfig->GPIO_MODE == GPIO_MODE_INPUT_AF)
			{
				pin_config =  (GPIO_MODE_INPUT_FLO << 2);
			}
			else{//GPIO_MODE_PU or GPIO_MODE_PD
				pin_config = (GPIO_MODE_INPUT_PU <<2);
				if (pinConfig->GPIO_MODE == GPIO_MODE_INPUT_PU)
				{
					GPIOx->ODR |= pinConfig->GPIO_pinNumber;
				}
				else if (pinConfig->GPIO_MODE == GPIO_MODE_INPUT_PD)
				{
					GPIOx->ODR &= ~(pinConfig->GPIO_pinNumber);
				}
			}

		}
		//write on CRL or CRH
		*(configReg) |= (pin_config << CRLH_Postion(pinConfig->GPIO_pinNumber));
	}

	/**================================================================
	 *@Fn        - MCAL_GPIO_DeInit
	 *@brief     - Reset GPIO pins.
	 *@param[in] - GPIOx: Pointer to GPIO peripheral (where x can be A to D).
	 *@retval    - None
	 *@Note      -
   ================================================================
	 */
	void MCAL_GPIO_DeInit(GPIO_t* GPIOx){
		//Set and cleared by software.
		//0: No effect
		//1: Reset I/O port
		if (GPIOx == GPIOA)
		{
			RCC->APB2RSTR |=  (1 << 2);
			RCC->APB2RSTR &= ~(1 << 2);
		}
		else if (GPIOx == GPIOB)
		{
			RCC->APB2RSTR |=  (1 << 3);
			RCC->APB2RSTR &= ~(1 << 3);
		}
		else if (GPIOx == GPIOC)
		{
			RCC->APB2RSTR |=  (1 << 4);
			RCC->APB2RSTR &= ~(1 << 4);
		}
		else if (GPIOx == GPIOD)
		{
			RCC->APB2RSTR |=  (1 << 5);
			RCC->APB2RSTR &= ~(1 << 5);
		}
		else if (GPIOx == GPIOE)
		{
			RCC->APB2RSTR |=  (1 << 6);
			RCC->APB2RSTR &= ~(1 << 6);
		}
	}

	//Read APIs

	/**================================================================
	 *@Fn        - MCAL_GPIO_ReadPin
	 *@brief     - Reads the specified GPIO pin.
	 *@param[in] - GPIOx: Pointer to GPIO peripheral (where x can be A to D).
	 *             pinNumber: GPIO pin number to be read mentioned @ref GPIO_PINS_Define.
	 *@retval    - 0 or 1 depending on the pin state.
	 *@Note      -
   ================================================================
	 */
	uint8_t MCAL_GPIO_ReadPin(GPIO_t* GPIOx, uint16_t pinNumber){
		uint8_t bitStatus;
		if((GPIOx->IDR & pinNumber) != 0)
		{
			bitStatus = GPIO_PIN_SET;
		}
		else
		{
			bitStatus = GPIO_PIN_RESET;
		}
		return bitStatus;
	}

	/**================================================================
	 *@Fn        - MCAL_GPIO_ReadPort
	 *@brief     - Reads the entire GPIO port.
	 *@param[in] - GPIOx: Pointer to GPIO peripheral (where x can be A to D).
	 *@retval    - 16-bit value representing the state of all pins in the port.
	 *@Note      -
   ================================================================
	 */
	uint16_t MCAL_GPIO_ReadPort(GPIO_t* GPIOx){
		return (uint16_t)(GPIOx->IDR);
	}

	//Write APIs

	/**================================================================
	 *@Fn        - MCAL_GPIO_WritePin
	 *@brief     - Writes a value to the specified GPIO pin.
	 *@param[in] - GPIOx: Pointer to GPIO peripheral (where x can be A to D).
	 *             pinNumber: GPIO pin number to be written mentioned @ref GPIO_PINS_Define.
	 *             value: Value to be written to the pin (0 or 1).
	 *@retval    - None
	 *@Note      -
   ================================================================
	 */
	void MCAL_GPIO_WritePin(GPIO_t* GPIOx, uint16_t pinNumber, uint8_t value){
		if(value == GPIO_PIN_RESET){
			GPIOx->ODR &= ~(pinNumber);
		}
		else{
			GPIOx->ODR |=  (pinNumber);
		}

	}

	/**================================================================
	 *@Fn        - MCAL_GPIO_WritePort
	 *@brief     - Writes a 16-bit value to the entire GPIO port.
	 *@param[in] - GPIOx: Pointer to GPIO peripheral (where x can be A to D).
	 *             value: 16-bit value to be written to the port.
	 *@retval    - None
	 *@Note      - The value parameter corresponds to the states of all pins in the port.
   ================================================================
	 */
	void MCAL_GPIO_WritePort(GPIO_t* GPIOx,uint16_t value){ //value uint16 because we have 16 pin in port
		GPIOx->ODR = (uint16_t)value;
	}

	/**================================================================
	 *@Fn        - MCAL_GPIO_TogglePin
	 *@brief     - Toggles the specified GPIO pin.
	 *@param[in] - GPIOx: Pointer to GPIO peripheral (where x can be A to D).
	 *             pinNumber: GPIO pin number to be toggled mentioned @ref GPIO_PINS_Define.
	 *@retval    - None
	 *@Note      -
   ================================================================
	 */
	void MCAL_GPIO_TogglePin(GPIO_t* GPIOx, uint16_t pinNumber){
		GPIOx->ODR ^= pinNumber;
	}

	/**================================================================
	 *@Fn        - MCAL_GPIO_LockPin
	 *@brief     - Locks the configuration of the specified GPIO pin.
	 *@param[in] - GPIOx: Pointer to GPIO peripheral (where x can be A to D).
	 *             pinNumber: GPIO pin number to be locked mentioned @ref GPIO_PINS_Define.
	 *@retval    - 0 if pin cannot be locked, 1 if pin is successfully locked.
	 *@Note      - Once locked, the pin's configuration cannot be modified until the next reset.
   ================================================================
	 */
	uint8_t MCAL_GPIO_LockPin(GPIO_t* GPIOx, uint16_t pinNumber){
		// Bit 16 LCKK[16]: Lock key
		volatile uint32_t tmp = 1 << 16;
		//LCKy: Port x Lock bit y (y= 0 .. 15)
		tmp |= pinNumber;

		//Write 1
		GPIOx->LCKR = tmp;
		//Write 0
		GPIOx->LCKR = pinNumber;
		//Write 1
		GPIOx->LCKR = tmp;
		//Read 0
		tmp = GPIOx->LCKR;
		//Read 1 (this read is optional but confirms that the lock is active)
		if (GPIOx->LCKR & (1<<16))
		{
			return GPIO_Return_Lock_OK;
		}

		else
		{
			return GPIO_Return_Lock_ERROR;
		}

	}
