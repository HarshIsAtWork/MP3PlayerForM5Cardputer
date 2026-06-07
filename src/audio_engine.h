#pragma once
#include <stdint.h>
#include <vector>

class AudioEngine {
public:
    AudioEngine();
    void begin();
    bool loadPlaylist();
    bool play(int index, uint32_t startPos = 0);
    void stop();
    void togglePause();
    void next(bool autoPlay = false);
    void prev();
    void loopTasks();
    std::vector<uint32_t> songOffsets;
    int currentIndex = 0;
    int browserIndex = 0;
    bool isPaused = false;
    bool isShuffle = false;
};

extern AudioEngine audioApp;
