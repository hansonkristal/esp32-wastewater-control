#ifndef TANKCONTROL_H
#define TANKCONTROL_H

#include <Arduino.h>


// Replace these with actual Atlas Scientific addresses
#define DOSING_PUMP_ADDRESS_1 0x38
#define DOSING_PUMP_ADDRESS_2 0x39
#define PH_SENSOR_ADDRESS_1   0x63
#define PH_SENSOR_ADDRESS_2   0x64

// Liquid Level Sensor (LLS) Pins
#define LLS_LOW_PIN       2  // Tank 1 low level sensor pin
#define LLS_HIGH_PIN      3  // Tank 1 high level sensor pin
#define LLS_LOW_PIN_02    4  // Tank 2 low level sensor pin
#define LLS_HIGH_PIN_02   5  // Tank 2 high level sensor pin


float phSensorReadTank01();
void doseAcidTank01();
void controlTank01(void* parameters);
void controlPH01(void* parameters);
void controlLLS01(void* parameters);

float phSensorReadTank02();
void doseAcidTank02();
void controlTank02(void* parameters);
void controlPH02(void* parameters);
void controlLLS02(void* parameters);

#endif // TANKCONTROL_H
