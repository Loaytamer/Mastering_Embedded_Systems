/*
 ============================================================================
 Name        : Ultrasonic.c
 Author      : Loay Tamer Mohamed
 Version     : v1
 Description : collisions avoiding
 ============================================================================
 */

#include "Ultrasonic.h"
int distance = 0;
void (*US_state)();
void US_init()
{
	// initialize drivers
	printf("==== Ultrasonic init ====");
}
int generate_random(int l, int r, int count)
{
	int i;
	for(i = 0; i < count; i++)
	{
		int rand_num = (rand()%(r-l-1))+1;
		return rand_num;
	}
}
state_define(US_busy)
{
	//state id
	US_state_id = US_busy;

	// get distance from ultrasonic
	distance = generate_random(45, 55, 1);
	printf("US_busy_state:  distance = %d\n", distance);
	US_set_distance(distance);
	US_state = state(US_busy);
}

