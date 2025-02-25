#include <Arduino.h>
#include "tankControl.h"
/* Using core 1 of ESP32 */
#if CONFIG_FREERTOS_UNICORE
static const BaseType_t app_cpu = 0;
#else
static const BaseType_t app_cpu = 1;
#endif

/*task handles for child tasks*/
TaskHandle_t pH01Control_handle = NULL;
TaskHandle_t LLS01Control_handle = NULL;
TaskHandle_t monitorSensors_handle = NULL;

void controlTank01(void* parameters){
    xTaskCreatePinnedToCore(controlPH01, "pH01 Control", 2048, NULL, 1, &pH01Control_handle, app_cpu)
    xTaskCreatePinnedToCore (controlLLS01, "LLS01 Control", 2048, NULL, 1, &LLS01Control_handle, app_cpu);
    
    
    while (true){
        Serial.println("Tank 1 control loop");
        /*Configure Delay between sensor readings*/
        vTaskDelay(2000/ portTICK_PERIOD_MS);
    }
}
void controlPH01(void* parameters){
  while (true){
    //Read the pH from pH01 sensor
    float pHValue = phSensorRead();
    if (pHValue > 7){
      doseAcid();
    }
    else if (pHValue < 6){
      sendAlert("Tank 1 pH reading is %.2f\n",pHValue);
    }
  }
}

void controlLLS01(void* parameters){
    while (true){
        Serial.println("Controlling water level");
        vTaskDelay(1000/ portTICK_PERIOD_MS);
    }
}
