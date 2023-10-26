/*
 ============================================================================
 Name        : pressure_sensor.h
 Author      : Loay Tamer Mohamed
 Version     : v1.0
 Description : High-Pressure-Detector
 ============================================================================
 */
#include "state.h"
#ifndef PRESSURE_SENSOR_H_
#define PRESSURE_SENSOR_H_

enum{
	pSensor_reading,
}pSensor_state_id;

state_define(pSensor_reading);

void pressure_sensor_init();
extern void(*pSensor_state)();

#endif /* PRESSURE_SENSOR_H_ */
