#pragma once
#include <stdint.h>
#include <freertos/FreeRTOS.h>
#include <freertos/semphr.h>
#include <freertos/queue.h>

typedef enum {
    CMD_PLAY,
    CMD_PAUSE,
    CMD_RESUME,
    CMD_STOP,
    CMD_NEXT,
    CMD_PREV,
    CMD_SEEK,
    CMD_VOLUME,
    CMD_SET_LOOP,
    CMD_TOGGLE_SHUFFLE,
    CMD_RELOAD_PLAYLIST,
} AudioCommand_t;

typedef struct {
    AudioCommand_t cmd;
    int iParam;
    uint32_t uParam;
} AudioCommandMsg_t;

typedef enum {
    EVT_TRACK_CHANGED,
    EVT_PLAYBACK_STATE,
    EVT_BATTERY_UPDATE,
    EVT_FFT_READY,
    EVT_NETWORK_STATUS,
    EVT_SCAN_DONE,
} UIEventType_t;

typedef struct {
    UIEventType_t type;
    int iParam;
    uint32_t uParam;
} UIEvent_t;

extern QueueHandle_t audioCommandQueue; // depth 8
extern QueueHandle_t uiEventQueue;      // depth 16
extern SemaphoreHandle_t sdMutex;
extern SemaphoreHandle_t fftMutex;
extern SemaphoreHandle_t fftResultMutex;

// Task entrypoints
void AudioTask(void* pv);
void FFTTask(void* pv);
void UITask(void* pv);
void SystemTask(void* pv);
