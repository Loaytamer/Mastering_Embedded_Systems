/*
 ============================================================================
 Name        : alarm_monitor.c
 Author      : Loay Tamer Mohamed
 Version     : v1.0
 Description : High-Pressure-Detector
 ============================================================================
 */
#include "alarm_monitor.h"

// variables
int alarm_state = 0;
void (*alarm_monitor_state)();

state_define(alarm_ON){
	alarm_monitor_state_id = alarm_on;
	alarm_monitor_state = state(alarm_OFF);
}

state_define(alarm_OFF){
	if (alarm_state == 1)
	{
		alarm_monitor_state = state(alarm_ON);
		alarm_monitor_state();
	}
	else
	{
		alarm_monitor_state = state(alarm_OFF);
		alarm_monitor_state_id = alarm_off;
	}

		
	
}

void setAlarm(int state)
{
	alarm_state = state;
}

void alarm_monitor_init(){
	;
}
