/*
    Runs MQTT in an RTOS task.
    Publishes data from FreeRTOS.
*/
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include <string.h>
#include "MQTTClient.h"

void mqttTask(void *pvParameters) {
    MQTTClient client;
    MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer;

    MQTTClient_create(&client, "tcp://broker.hivemq.com:1883", "FreeRTOS_Client", MQTTCLIENT_PERSISTENCE_NONE, nullptr);
    MQTTClient_connect(client, &conn_opts);
    MQTTClient_publish(client, "iot/test", strlen("Hello from RTOS"), "Hello from RTOS", 0, 0, nullptr);

    vTaskDelete(nullptr);
}

void sensorTask(void *pvParameters) {
    while (1) {
        if (xSemaphoreTake(mutex, portMAX_DELAY)) {
            printf("Sensor Task: Reading sensor data...\n");
            xSemaphoreGive(mutex);
        }
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}

void networkTask(void *pvParameters) {
    while (1) {
        if (xSemaphoreTake(mutex, portMAX_DELAY)) {
            printf("Network Task: Sending data...\n");
            xSemaphoreGive(mutex);
        }
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}

int main() {
    mutex = xSemaphoreCreateMutex();
    xTaskCreate(mqttTask, "MQTT Task", 1024, nullptr, 1, nullptr);
    xTaskCreate(networkTask, "Network Task", 1024, nullptr, 1, nullptr);
    xTaskCreate(sensorTask, "Sensor Task", 1024, nullptr, 1, nullptr);

    vTaskStartScheduler();
    return 0;
}
