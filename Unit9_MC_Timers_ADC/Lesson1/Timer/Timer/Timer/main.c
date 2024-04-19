/*
 * Timer.c
 *
 * Created: 19/04/2024 02:26:52
 * Author : Loay
 */ 
#define F_CPU 8000000UL
#include "MCAL/Timer.h"

extern uint8_t u8_TOVNumber;

void TOIE_Callback()
{
	PORTA = ~PORTA;
}

int main(void)
{
    DDRA = 0xFF;
    sei();
    TIMER0_CALLBACK_CompareMatch_INT(TOIE_Callback);
    S_TIMER0_CONFIG config = {CTC, OCIE_ENABLE, TOIE_DISABLE, PRESCALING_CLK8};
    TIMER0_SetCompareVal(0xF0);
    TIMER0_INIT(&config);
    while (1) 
    {
    }
}

