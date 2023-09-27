/*
 ============================================================================
 Name        : DC_motor.h
 Author      : Loay Tamer Mohamed
 Version     : v1
 Description : collisions avoiding
 ============================================================================
*/
#include "state.h"
#ifndef DC_H_
#define DC_H_

enum{
	DC_busy,
	DC_idle,
}DC_state_id;

void DC_init();
state_define(DC_busy);
state_define(DC_idle);
extern void (*DC_state)();

#endif /* CA_H_ */
