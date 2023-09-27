/*
 ============================================================================
 Name        : Ultrasonic.h
 Author      : Loay Tamer Mohamed
 Version     : v1
 Description : collisions avoiding
 ============================================================================
*/
#include "state.h"
#ifndef CA_H_
#define CA_H_

enum{
	CA_waiting,
	CA_driving,
}CA_state_id;

state_define(CA_waiting);
state_define(CA_driving);
extern void (*CA_state)();

#endif /* CA_H_ */
