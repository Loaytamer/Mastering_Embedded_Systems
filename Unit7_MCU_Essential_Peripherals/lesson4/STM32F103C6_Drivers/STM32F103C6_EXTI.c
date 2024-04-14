/*
 * STM32F103C6_EXTI.c
 * Author: Loay Tamer Mohamed
 */

#include "STM32F103C6_EXTI.h"

/*========== Generic Macros ==========*/
#define AFIO_GPIO_EXTI_Mapping(x)	(	(x == GPIOA)? 0 : \
										(x == GPIOB)? 1 : \
										(x == GPIOC)? 2 : \
										(x == GPIOD)? 3 : 0 )

/*========== Generic Macros ==========*/
void(*GP_IRQ_CallBack[15])(void);


/*========== Generic Functions ==========*/
void Enable_NVIC(uint16_t IRQ){
	switch(IRQ){
	case 0:
		NVIC_IRQ6_EXTI0_Enable();
		break;
	case 1:
		NVIC_IRQ7_EXTI1_Enable();
		break;
	case 2:
		NVIC_IRQ8_EXTI2_Enable();
		break;
	case 3:
		NVIC_IRQ9_EXTI3_Enable();
		break;
	case 4:
		NVIC_IRQ10_EXTI4_Enable();
		break;
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
		NVIC_IRQ23_EXTI5_9_Enable();
		break;
	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
		NVIC_IRQ40_EXTI10_15_Enable();
		break;
	}
}

void Disable_NVIC(uint16_t IRQ){
	switch(IRQ){
	case 0:
		NVIC_IRQ6_EXTI0_Disable();
		break;
	case 1:
		NVIC_IRQ7_EXTI1_Disable();
		break;
	case 2:
		NVIC_IRQ8_EXTI2_Disable();
		break;
	case 3:
		NVIC_IRQ9_EXTI3_Disable();
		break;
	case 4:
		NVIC_IRQ10_EXTI4_Disable();
		break;
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
		NVIC_IRQ23_EXTI5_9_Disable();
		break;
	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
		NVIC_IRQ40_EXTI10_15_Disable();
		break;
	}
}

void Update_EXTI(EXTI_PinConfig_t* EXTI_Config){
	// 1- configure GPIO to be AF => floating input
	GPIO_pinConfig_t PinCfg;
	PinCfg.GPIO_pinNumber = EXTI_Config->EXTI_PIN.GPIO_PIN;
	PinCfg.GPIO_MODE	  = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(EXTI_Config->EXTI_PIN.GPIO_port, &PinCfg);

	// 2- update AFIO to route between EXTI line with Port A,B,C,D
	uint8_t AFIO_EXTICR_index, AFIO_EXTICR_position;
	AFIO_EXTICR_index    = ((EXTI_Config->EXTI_PIN.EXTI_InputLineNumber) / 4);
	AFIO_EXTICR_position = (((EXTI_Config->EXTI_PIN.EXTI_InputLineNumber) % 4) * 4);

	// clear 4 bits
	AFIO->EXTICR[AFIO_EXTICR_index] &= ~(0xF << AFIO_EXTICR_position);

	AFIO->EXTICR[AFIO_EXTICR_index] |=  ((AFIO_GPIO_EXTI_Mapping(EXTI_Config->EXTI_PIN.GPIO_port) & (0xF))<< AFIO_EXTICR_position);

	// 3- configure Trigger case
	EXTI->RTSR &= ~(1 << EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
	EXTI->FTSR &= ~(1 << EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
	if(EXTI_Config->Trigger_Case == EXTI_Trigger_Rising){
		EXTI->RTSR |=  (1 << EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
	}else if(EXTI_Config->Trigger_Case == EXTI_Trigger_Falling){
		EXTI->FTSR |=  (1 << EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
	}else if(EXTI_Config->Trigger_Case == EXTI_Trigger_AnyChange){
		EXTI->RTSR |= (1 << EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
		EXTI->FTSR |= (1 << EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
	}


	// 4- Update IRQ Handling CallBack
	GP_IRQ_CallBack[EXTI_Config->EXTI_PIN.EXTI_InputLineNumber] = EXTI_Config->P_IRQ_CallBack;

	// 5- Enable/Disable IRQ & NVIC
	if(EXTI_Config->IRQ_EN == EXTI_IRQ_Enable){
		EXTI->IMR |= (1 << EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
		Enable_NVIC(EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
	}else{
		EXTI->IMR &= ~(1 << EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
		Disable_NVIC(EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
	}
}

/*******************************************************************************
 * @Fn         - MCAL_EXTI_Init
 * @brief      - Initializes an external interrupt (EXTI) pin with the specified configuration.
 * @param[in]  - EXTI_Config: Pointer to a structure containing EXTI pin configuration settings.
 * @retval     - None
 * @Note       - This function configures the EXTI subsystem to handle external interrupts on the specified pin.
 *               The configuration details are provided in the EXTI_PinConfig_t structure.
 *               It's mandatory to Enable RCC clock for AFIO and the corresponding GPIO.
 *******************************************************************************/
void MCAL_EXTI_Init(EXTI_PinConfig_t* EXTI_Config){
	Update_EXTI(EXTI_Config);
}

/*******************************************************************************
 * @Fn         - MCAL_EXTI_DeInit
 * @brief      - De-initializes the EXTI subsystem, disabling all external interrupts.
 * @param[in]  - None
 * @retval     - None
 * @Note       - This function resets the EXTI registers to its default state, effectively
 *               disabling all external interrupts that were previously configured and NVIC corresponding IRQ mask.
 *               Use this function when you no longer need to use external interrupts
 *               to avoid unintended behavior.
 *******************************************************************************/
void MCAL_EXTI_DeInit(void){
	//EXTI Registers
	EXTI->IMR   = 0x00000000;
	EXTI->EMR   = 0x00000000;
	EXTI->RTSR  = 0x00000000;
	EXTI->FTSR  = 0x00000000;
	EXTI->SWIER = 0x00000000;
	//EXTI_PR cleared by writing a ‘1’ into the bit
	EXTI->PR	= 0xFFFFFFFF;

	//Disable EXTI IRQ from NVIC
	NVIC_IRQ6_EXTI0_Disable();
	NVIC_IRQ7_EXTI1_Disable();
	NVIC_IRQ8_EXTI2_Disable();
	NVIC_IRQ9_EXTI3_Disable();
	NVIC_IRQ10_EXTI4_Disable();
	NVIC_IRQ23_EXTI5_9_Disable();
	NVIC_IRQ40_EXTI10_15_Disable();

}

/*******************************************************************************
 * @Fn         - MCAL_EXTI_Update
 * @brief      - Updates the configuration of an already initialized EXTI pin.
 * @param[in]  - EXTI_Config: Pointer to a structure containing the new EXTI pin configuration settings.
 * @retval     - None
 * @Note       - This function allows you to modify the configuration of an EXTI pin that has already been initialized with MCAL_EXTI_Init.
 *               The changes take effect immediately after this function call.
 *               Ensure that the EXTI_Config pointer points to a valid configuration structure.
 *******************************************************************************/
void MCAL_EXTI_Update(EXTI_PinConfig_t* EXTI_Config){
	Update_EXTI(EXTI_Config);
}

/*========== ISRs ==========*/
void EXTI0_IRQHandler(void){
	EXTI->PR |= (1 << 0);
	GP_IRQ_CallBack[0]();
}

void EXTI1_IRQHandler(void){
	EXTI->PR |= (1 << 1);
	GP_IRQ_CallBack[1]();
}

void EXTI2_IRQHandler(void){
	EXTI->PR |= (1 << 2);
	GP_IRQ_CallBack[2]();
}

void EXTI3_IRQHandler(void){
	EXTI->PR |= (1 << 3);
	GP_IRQ_CallBack[3]();
}

void EXTI4_IRQHandler(void){
	EXTI->PR |= (1 << 4);
	GP_IRQ_CallBack[4]();
}

void EXTI9_5_IRQHandler(void){
	if(EXTI->PR & (1<<5)) {EXTI->PR |= (1<<5); GP_IRQ_CallBack[5]();}
	if(EXTI->PR & (1<<6)) {EXTI->PR |= (1<<6); GP_IRQ_CallBack[6]();}
	if(EXTI->PR & (1<<7)) {EXTI->PR |= (1<<7); GP_IRQ_CallBack[7]();}
	if(EXTI->PR & (1<<8)) {EXTI->PR |= (1<<8); GP_IRQ_CallBack[8]();}
	if(EXTI->PR & (1<<9)) {EXTI->PR |= (1<<9); GP_IRQ_CallBack[9]();}
}

void EXTI15_10_IRQHandler(void){
	if(EXTI->PR & (1<<10)) {EXTI->PR |= (1<<10); GP_IRQ_CallBack[10]();}
	if(EXTI->PR & (1<<11)) {EXTI->PR |= (1<<11); GP_IRQ_CallBack[11]();}
	if(EXTI->PR & (1<<12)) {EXTI->PR |= (1<<12); GP_IRQ_CallBack[12]();}
	if(EXTI->PR & (1<<13)) {EXTI->PR |= (1<<13); GP_IRQ_CallBack[13]();}
	if(EXTI->PR & (1<<14)) {EXTI->PR |= (1<<14); GP_IRQ_CallBack[14]();}
	if(EXTI->PR & (1<<15)) {EXTI->PR |= (1<<15); GP_IRQ_CallBack[15]();}
}
