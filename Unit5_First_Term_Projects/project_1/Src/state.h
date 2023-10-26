/*
 ============================================================================
 Name        : state.h
 Author      : Loay Tamer Mohamed
 Version     : v1.0
 Description : High-Pressure-Detector
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#ifndef STATE_H_
#define STATE_H_

#define state_define(_stateFunc_) void ST_##_stateFunc_()
#define state(_stateFunc_)        ST_##_stateFunc_

void setPressureVal(int pressure_Val);
void setAlarm(int state);
int return_pVal();
#endif /* STATE_H_ */
