/*
 ============================================================================
 Name        : state.h
 Author      : Loay Tamer Mohamed
 Version     : v1
 Description : collisions avoiding
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#ifndef STATE_H_
#define STATE_H_

#define state_define(_stateFunc_) void ST_##_stateFunc_()
#define state(_stateFunc_)         ST_##_stateFunc_



void US_set_distance(int d);
void DC_set_speed(int s);
#endif

