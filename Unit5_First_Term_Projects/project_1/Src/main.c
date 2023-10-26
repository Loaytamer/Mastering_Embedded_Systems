/*
 ============================================================================
 Name        : main.c
 Author      : Loay Tamer Mohamed
 Version     : v1.0
 Description : High-Pressure-Detector
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "driver.h"
#include "pressure_sensor.h"
#include "alarm_monitor.h"
#include "pressure_controller.h"

void setup()
{
	pSensor_state = state(pSensor_reading);
	alarm_monitor_state = state(alarm_OFF);
	pController_state = state(pressure_detection);
}

int main (){
	GPIO_INITIALIZATION();
	setup();
	while (1)
	{
		pSensor_state();
		setPressureVal(getPressureVal());
		pController_state();
		alarm_monitor_state();
		if (alarm_monitor_state_id == alarm_on)
		{
			Set_Alarm_actuator(1);
			Delay(1000); //assume that 1000 = 60sec
			
		}
		else
		{
			Set_Alarm_actuator(0);
			Delay(100);
		}

	}

}
