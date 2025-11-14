#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void taskFirst(void *p) {
    int count = 0;
    for (;;) {
        printf("hello task1: count %d\n", count++);
        vTaskDelay(500 / portTICK_PERIOD_MS);
        if (count > 10) {
            vTaskDelete(NULL);  
        }
    }
}

void taskSecond(void *p) {
    int count = 0;
    for (;;) {
        printf("hello task2: count %d\n", count++);
        vTaskDelay(500 / portTICK_PERIOD_MS);
        if (count > 10) {
            vTaskDelete(NULL); 
        }
    }
}

void taskThird(void *p) {
    int count = 0;
    for (;;) {
        printf("hello task3: count %d\n", count++);
        vTaskDelay(500 / portTICK_PERIOD_MS);
        if (count > 10) {
            vTaskDelete(NULL);  
        }
    }
}

void app_main(void) {
    xTaskCreate(taskFirst,  "Task1", 2048, NULL, 1, NULL);
    xTaskCreate(taskSecond, "Task2", 2048, NULL, 2, NULL);
    xTaskCreate(taskThird,  "Task3", 2048, NULL, 3, NULL);
}