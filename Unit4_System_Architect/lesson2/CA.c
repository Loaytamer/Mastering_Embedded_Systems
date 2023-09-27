/*
 ============================================================================
 Name        : CA.c
 Author      : Loay Tamer Mohamed
 Version     : v1
 Description : collisions avoiding
 ============================================================================
 */
#include "CA.h"

//variable
int CA_speed  = 0;
int CA_distance  = 0;
int threshold = 50;

void (*CA_state)();

void US_set_distance(int d)
{
	CA_distance = d;
	(CA_distance <= threshold)? (CA_state = state(CA_waiting)): (CA_state = state(CA_driving));
	printf("US ------ distance = % -----> CA\n", CA_distance);
}
state_define(CA_waiting)
{
	//state id
	CA_state_id = CA_waiting;
	// Action
	CA_speed = 0;
	// get distance from ultrasonic
	DC_set_speed(CA_speed);
}

state_define(CA_driving)
{
	//state id
	CA_state_id = CA_driving;
	printf("Driving state : distance = %d   speed = %d", CA_distance, CA_speed);
	// Action
	CA_speed = 30;
	DC_set_speed(CA_speed);
}
