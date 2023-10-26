/*
 ============================================================================
 Name        : alarm_monitor.h
 Author      : Loay Tamer Mohamed
 Version     : v1.0
 Description : High-Pressure-Detector
 ============================================================================
 */
#include "state.h"
#ifndef ALARM_MONITOR_H_
#define ALARM_MONITOR_H_

enum{
	alarm_on,
	alarm_off,
}alarm_monitor_state_id;


state_define(alarm_ON);
state_define(alarm_OFF);

void alarm_monitor_init();
extern void (*alarm_monitor_state)();

#endif /* PRESSURE_SENSOR_H_ */
