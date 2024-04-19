/*
 * Timer.c
 *
 * Created: 19/04/2024 02:27:59
 *  Author: Loay
 */ /*
 * timer.c
 *
 * Created: 19/04/2024 00:55:59
 *  Author: Loay
 */ 

/*========== Includes ==========*/
#include "Timer.h"

/*========== General  Variables ==========*/
ptr_voidFunVoid_t callBack_OVF;
ptr_voidFunVoid_t callBack_CM;
uint8_t TOV_Number;
S_TIMER0_CONFIG* TIMER0_Configuration;

/*========== APIs  Implementation ==========*/
E_STATUS_t TIMER0_INIT(S_TIMER0_CONFIG* TIMCONFIG){
	E_STATUS_t Retval = E_NOK;
	if(NULL_PTR == TIMCONFIG){
		Retval = E_NOK;
	}else{
		TIMER0_Configuration = TIMCONFIG;
		
		if((TIMER0_Configuration->mode == NORMAL) || (TIMER0_Configuration->mode == PWM) || (TIMER0_Configuration->mode == CTC) || (TIMER0_Configuration->mode == FAST_PWM)){
			TCCR0 |= TIMER0_Configuration->mode;
			Retval = E_OK;
		}else{
			Retval = E_NOK;
		}
		if((TIMER0_Configuration->clk >= NO_CLK_SRC) && (TIMER0_Configuration->clk <= EXT_CLK_RISING)){
			TCCR0 |= TIMER0_Configuration->clk;
			Retval = E_OK;
		}else{
			Retval = E_NOK;
		}
		if((TIMER0_Configuration->ocmINT == OCIE_DISABLE) || (TIMER0_Configuration->ocmINT == OCIE_ENABLE) ){
			TIMSK |= TIMER0_Configuration->ocmINT;
			Retval = E_OK;
		}else{
			Retval = E_NOK;
		}
		if((TIMER0_Configuration->tofINT == TOIE_ENABLE) || (TIMER0_Configuration->tofINT == TOIE_DISABLE)){
			TIMSK |= TIMER0_Configuration->tofINT;
			Retval = E_OK;
		}else{
		Retval = E_NOK;
		}
	}
	return Retval;
}
		

E_STATUS_t TIMER0_STOP(){
	E_STATUS_t Retval = E_NOK;
	TIMSK |= NO_CLK_SRC;
	return Retval;
}

E_STATUS_t TIMER0_GetCompareVal(ptr_uint8_t ticksNumber){
	E_STATUS_t Retval = E_NOK;
	*(ticksNumber) = OCR0;
	return Retval;
}
E_STATUS_t TIMER0_SetCompareVal(uint8_t ticksNumber){
	E_STATUS_t Retval = E_NOK;
	OCR0 = ticksNumber;
	return Retval;
}

E_STATUS_t TIMER0_GetCounterVal(ptr_uint8_t ticksNumber){
	E_STATUS_t Retval = E_NOK;
	*ticksNumber = TCNT0;
	return Retval;
}
E_STATUS_t TIMER0_SetCounterVal(uint8_t ticksNumber){
	E_STATUS_t Retval = E_NOK;
	TCNT0  = ticksNumber;
	return Retval;
}

E_STATUS_t TIMER0_GetOverflowVal(ptr_uint8_t ticksNumber){
	E_STATUS_t Retval = E_NOK;
	*ticksNumber  = TOV_Number;
	return Retval;
}
E_STATUS_t TIMER0_SetOverflowVal(uint8_t ticksNumber){
	E_STATUS_t Retval = E_NOK;
	TOV_Number  = ticksNumber;
	return Retval;
}

void TIMER0_CALLBACK_Overflow_INT(ptr_voidFunVoid_t callback){
	callBack_OVF = callback;
}
void TIMER0_CALLBACK_CompareMatch_INT(ptr_voidFunVoid_t callback){
	callBack_CM = callback;
}

ISR(TIMER0_COMP_vect)
{
	callBack_CM();
}

ISR(TIMER0_OVF_vect)
{
	TOV_Number++;
	callBack_OVF();
}
