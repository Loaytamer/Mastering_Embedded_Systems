/*
 ============================================================================
 Name        : pressure_sensor.c
 Author      : Loay Tamer Mohamed
 Version     : v1.0
 Description : High-Pressure-Detector
 ============================================================================
 */

#include "pressure_sensor.h"

// variables
int pVal = 0;
int sensor_timer = 0;
void(*pSensor_state)();

state_define(pSensor_reading){
	pSensor_state_id = pSensor_reading;
	sensor_timer = 100;
	pSensor_state = state(pSensor_reading);
	sensor_timer = 0;
}

void setPressureVal(int pressure_Val)
{
	pVal = pressure_Val;
}

int return_pVal()
{
	return pVal;
}
void pressure_sensor_init(){
	;
}
