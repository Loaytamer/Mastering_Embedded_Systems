/*
 ============================================================================
 Name        : CA_3modules.c
 Author      : Loay Tamer Mohamed
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "CA.h"
#include "DC_motor.h"
#include "Ultrasonic.h"

void setup(void)
{
	US_init();
	DC_init();
	CA_state = state(CA_waiting);
	US_state = state(US_busy);
	DC_state = state(DC_idle);
}
int main(void) {

	volatile int d;
	setup();
	while(1)
	{
		US_state();
		CA_state();
		DC_state();
		for(d = 0; d < 1000; d++);
	}
	return 0;
}
