/*
 ============================================================================
 Name        : Ultrasonic.h
 Author      : Loay Tamer Mohamed
 Version     : v1
 Description : collisions avoiding
 ============================================================================
*/

#ifndef US_H_
#define US_H_
#include "state.h"
enum{
	US_busy,
}US_state_id;

void US_init();
state_define(US_busy);
int generate_random(int l, int r, int count);
extern void (*US_state)();

#endif /* CA_H_ */
