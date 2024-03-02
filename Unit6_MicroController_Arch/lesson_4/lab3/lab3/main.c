/*
 * Author : Loay Tamer Mohamed
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#define set_bit(reg, bit_no)    reg |= (1<< bit_no) 
#define clear_bit(reg, bit_no)  reg &= ~(1<< bit_no)
#define toggle_bit(reg, bit_no) reg ^= (1<< bit_no) 
#ifndef F_CPU
#define F_CPU 8000000UL
#endif

// configure INT pins as inputs
void INT_pins()
{
	clear_bit(DDRD, 2); //INT0
	clear_bit(DDRD, 3); //INT1
	clear_bit(DDRB, 2); //INT1
}

void LEDS_pins()
{
	set_bit(DDRD, 6); // LED2
	set_bit(DDRD, 5); // lED0
	set_bit(DDRD, 7); // LED1
}

void INT_init()
{
	GICR = 0xE0;
	MCUCR = 0x05;
}
int main(void)
{
    INT_pins();
	LEDS_pins();
	INT_init();
	sei();
    while (1) ;
    
}

ISR (INT0_vect)
{
	cli();
	set_bit(PORTD,5);
	_delay_ms(10000);
	clear_bit(PORTD,5);
	sei();
}

ISR (INT1_vect)
{
	cli();
	set_bit(PORTD,7);
	_delay_ms(10000);
	clear_bit(PORTD,7);
	sei();
}

ISR (INT2_vect)
{
	cli();
	set_bit(PORTD,6);
	_delay_ms(10000);
	clear_bit(PORTD,6);
	sei();
}