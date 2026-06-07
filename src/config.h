#pragma once
#include <Preferences.h>
#include <stdint.h>

struct Settings {
    int brightness = 100;
    int themeIndex = 0;
    int visMode = 0;
    int timeoutIndex = 0;
    bool resumePlay = true;
    int spkRateIndex = 4;
    int lastIndex = 0;
    uint32_t lastPos = 0;
    int powerSaverMode = 0;
    int seek = 5;
    char currentFolder[128];
};

class ConfigManager {
public:
    static Settings userSettings;
    static void begin();
    static void load();
    static void save(uint32_t currentPos = 0, int currentIndex = 0);
};
