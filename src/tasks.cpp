#include "tasks.h"
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <Arduino.h>

QueueHandle_t audioCommandQueue = nullptr;
QueueHandle_t uiEventQueue = nullptr;
SemaphoreHandle_t sdMutex = nullptr;
SemaphoreHandle_t fftMutex = nullptr;
SemaphoreHandle_t fftResultMutex = nullptr;

void create_ipc_objects() {
    if (!audioCommandQueue) audioCommandQueue = xQueueCreate(8, sizeof(AudioCommandMsg_t));
    if (!uiEventQueue) uiEventQueue = xQueueCreate(16, sizeof(UIEvent_t));
    if (!sdMutex) sdMutex = xSemaphoreCreateMutex();
    if (!fftMutex) fftMutex = xSemaphoreCreateMutex();
    if (!fftResultMutex) fftResultMutex = xSemaphoreCreateMutex();
}

void AudioTask(void* pv) {
    create_ipc_objects();
    for (;;) {
        // Audio real-time processing placeholder
        vTaskDelay(pdMS_TO_TICKS(10));
    }
}

void FFTTask(void* pv) {
    create_ipc_objects();
    for (;;) {
        // FFT processing placeholder
        vTaskDelay(pdMS_TO_TICKS(40));
    }
}

void UITask(void* pv) {
    create_ipc_objects();
    for (;;) {
        // UI polling and render placeholder
        vTaskDelay(pdMS_TO_TICKS(33));
    }
}

void SystemTask(void* pv) {
    create_ipc_objects();
    for (;;) {
        // System periodic tasks
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}
