/*
 * WDOG.c
 *
 * Created: 18/04/2024 21:57:49
 * Author : Loay
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

#define SET_BIT(PORT, BIT)			PORT |= (1<< BIT)
#define RESET_BIT(PORT, BIT)		PORT &= ~(1<<BIT)
#define TOG_BIT(PORT, BIT)			PORT ^= (1<<BIT)
#define GET_BIT(PORT, BIT)			PORT & (1<<BIT)

#define LED_DDR  DDRD
#define LED_PORT PORTD
#define LED_PIN	 0

void WDT_ON(){
	SET_BIT(WDTCR, WDE);
	SET_BIT(WDTCR, WDP1);
	SET_BIT(WDTCR, WDP2);
}

void WDT_OFF(){
	SET_BIT(WDTCR, WDE);
	SET_BIT(WDTCR, WDTOE);
	WDTCR =0x00;
}

int main(void)
{
    SET_BIT(LED_DDR, LED_PIN);
	_delay_ms(200);
    while (1) 
    {
		WDT_ON();
		TOG_BIT(LED_PORT,LED_PIN);
		_delay_ms(1000);
		WDT_OFF();
    }
}

