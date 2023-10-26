/*
 ============================================================================
 Name        : pressure_controller.c
 Author      : Loay Tamer Mohamed
 Version     : v1.0
 Description : High-Pressure-Detector
 ============================================================================
 */

#include "pressure_controller.h"

//variables
int threshold = 20;
int pc_pVal = 0;
void (*pController_state)();



state_define(pressure_detection){
	pressure_controller_state_id = pressure_detection;
	pc_pVal = return_pVal();
	(pc_pVal >= threshold)? setAlarm(1): setAlarm(0);
	pController_state = state(pressure_detection);
}
