#include <Arduino.h>
#include <M5Unified.h>
#include "config.h"
#include "tasks.h"
#include "audio_engine.h"
#include "playlist.h"
#include "ui_manager.h"

void setup() {
    auto cfg = M5.config();
    M5.begin(cfg);

    ConfigManager::begin();
    ConfigManager::load();

    audioApp.begin();
    playlist.begin();
    UIManager::begin(ConfigManager::userSettings.themeIndex);

    xTaskCreatePinnedToCore(AudioTask, "AudioTask", 8192, NULL, 22, NULL, 1);
    xTaskCreatePinnedToCore(FFTTask, "FFTTask", 4096, NULL, 5, NULL, 1);
    xTaskCreatePinnedToCore(UITask, "UITask", 8192, NULL, 10, NULL, 0);
    xTaskCreatePinnedToCore(SystemTask, "SystemTask", 4096, NULL, 3, NULL, 0);
}

void loop() {
    vTaskDelay(pdMS_TO_TICKS(1000));
}
