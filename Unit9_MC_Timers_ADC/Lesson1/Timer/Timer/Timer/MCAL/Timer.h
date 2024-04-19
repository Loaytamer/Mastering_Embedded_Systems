/*
 * Timer.h
 *
 * Created: 19/04/2024 00:55:43
 *  Author: Loay
 */ 


#ifndef TIMER_H_
#define TIMER_H_

/*========== Includes ==========*/
#include <avr/io.h>
#include <avr/interrupt.h>
#include "../infrastructure/Types.h"
#include "../infrastructure/Utils.h"

/*========== Enums ==========*/
typedef enum{
	NORMAL	 = 0x00,
	PWM      = 0x40,
	CTC		 = 0x08,
	FAST_PWM = 0x48,
}TIMER0_MODE_t;

typedef enum
{
	OCIE_DISABLE = 0x00,
	OCIE_ENABLE = 0x02
}OCMIE0_t;

typedef enum
{
	TOIE_DISABLE = 0x00,
	TOIE_ENABLE = 0x01
}TOVFIE0_t;

typedef enum
{
	NO_CLK_SRC,
	NO_PRESCALING,
	PRESCALING_CLK8,
	PRESCALING_CLK64,
	PRESCALING_CLK256,
	PRESCALING_CLK1024,
	EXT_CLK_FALLING,
	EXT_CLK_RISING,
}TIMER0_CLOCK_t;

/*========== Structures ==========*/
typedef struct{
	TIMER0_MODE_t   mode;
	OCMIE0_t	    ocmINT;
	TOVFIE0_t       tofINT;
	TIMER0_CLOCK_t  clk;
}S_TIMER0_CONFIG;

/*========== APIs ==========*/
E_STATUS_t TIMER0_INIT(S_TIMER0_CONFIG* TIMCONFIG);
E_STATUS_t TIMER0_STOP();

E_STATUS_t TIMER0_GetCompareVal(ptr_uint8_t ticksNumber);
E_STATUS_t TIMER0_SetCompareVal(uint8_t ticksNumber);

E_STATUS_t TIMER0_GetCounterVal(ptr_uint8_t ticksNumber);
E_STATUS_t TIMER0_SetCounterVal(uint8_t ticksNumber);

E_STATUS_t TIMER0_GetOverflowVal(ptr_uint8_t ticksNumber);
E_STATUS_t TIMER0_SetOverflowVal(uint8_t ticksNumber);

void TIMER0_CALLBACK_Overflow_INT(ptr_voidFunVoid_t callback);
void TIMER0_CALLBACK_CompareMatch_INT(ptr_voidFunVoid_t callback);

#endif /* TIMER_H_ */