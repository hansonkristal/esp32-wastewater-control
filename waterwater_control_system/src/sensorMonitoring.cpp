#include <Arduino.h>
#include "sensorMonitoring.h"

/*TODO: create data structure to store sensor data*/
void monitorSensors(void* parameters){
    while (true){
        Serial.println("Monitoring all sensors");
        vTaskDelay(1000/ portTICK_PERIOD_MS);
    }
}