/*
 * Author : Loay Tamer Mohamed 
 */ 

#define F_CPU 8000000UL
#include <stdint.h>
#include <util/delay.h>
// GPIO port D Registers
#define PORTD *(volatile uint8_t*)(0x32)
#define DDRD  *(volatile uint8_t*)(0x31)
#define PIND  *(volatile uint8_t*)(0x30)

void gpio_init()
{
	//configure pin 4,5,6,7 as o/p
	DDRD |= (1<<4) | (1<<5) | (1<<6) | (1<<7);
	PORTD = 0xEF;
}

int main(void)
{
    gpio_init();
    while (1) 
    {
		PORTD &= ~(1<<5); // turn on first led
		_delay_ms(1000);
		PORTD |= (1<<5);// turn off first led
		PORTD &= ~(1<<6); // turn on second led
		_delay_ms(1000);
		PORTD |= (1<<6);// turn off second led
		PORTD &= ~(1<<7); // turn on third led
		_delay_ms(1000);
		PORTD |= (1<<7);// turn off third led
		PORTD |= (1<<4); // turn on buzzer
		_delay_ms(1000);
		PORTD &= ~(1<<4);// turn off buzzer
    }
}

