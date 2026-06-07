#include "config.h"
#include <Preferences.h>

Settings ConfigManager::userSettings;

void ConfigManager::begin() {
    // Placeholder for any init work (NVS, etc.)
}

void ConfigManager::load() {
    // Minimal load: keep defaults for now
}

void ConfigManager::save(uint32_t currentPos, int currentIndex) {
    // Minimal save: no-op for now
}
