/*
 ============================================================================
 Name        : pressure_controller.h
 Author      : Loay Tamer Mohamed
 Version     : v1.0
 Description : High-Pressure-Detector
 ============================================================================
 */
#include "state.h"

#ifndef PRESSURE_CONTROLLER_H_
#define PRESSURE_CONTROLLER_H_

enum {
	pressure_detection,
}pressure_controller_state_id;

state_define(pressure_detection);
extern void (*pController_state)();

#endif /* PRESSURE_SENSOR_H_ */
