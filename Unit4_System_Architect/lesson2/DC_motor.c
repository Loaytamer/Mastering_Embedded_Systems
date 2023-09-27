/*
 ============================================================================
 Name        : DC_motor.c
 Author      : Loay Tamer Mohamed
 Version     : v1
 Description : collisions avoiding
 ============================================================================
 */

#include "DC_motor.h"
int speed;
void (*DC_state)();
void DC_init()
{
	// initialize drivers
	printf("==== DC_motor init ====");
}
void DC_set_speed(int s)
{
	speed = s;
	DC_state = state(DC_busy);
	printf("CA ------ speed = % -----> DC\n", speed);
}
state_define(DC_busy)
{
	//state id
	DC_state_id = DC_busy;

	printf("DC_busy_state:  speed = %d\n", speed);
	DC_state = state(DC_idle);
}
state_define(DC_idle)
{
	//state id
	DC_state_id = DC_idle;
	printf("DC_idle_state:  speed = %d\n", speed);
	DC_state = state(DC_idle);
}



