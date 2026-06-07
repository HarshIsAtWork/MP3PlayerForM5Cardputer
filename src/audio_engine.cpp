#include "audio_engine.h"
#include <Arduino.h>

AudioEngine audioApp;

AudioEngine::AudioEngine() {}

void AudioEngine::begin() {
    // Placeholder: real audio init will be added in Phase 2
}

bool AudioEngine::loadPlaylist() {
    // Minimal stub: no playlist loaded yet
    songOffsets.clear();
    return false;
}

bool AudioEngine::play(int index, uint32_t startPos) {
    // Stub: pretend play succeeded only if playlist non-empty
    if (songOffsets.empty()) return false;
    currentIndex = index;
    isPaused = false;
    return true;
}

void AudioEngine::stop() {
    // Stub
    isPaused = true;
}

void AudioEngine::togglePause() {
    isPaused = !isPaused;
}

void AudioEngine::next(bool autoPlay) {
    if (songOffsets.empty()) return;
    if (isShuffle) currentIndex = random(0, songOffsets.size());
    else currentIndex = (currentIndex + 1) % songOffsets.size();
}

void AudioEngine::prev() {
    if (songOffsets.empty()) return;
    currentIndex = (currentIndex - 1 + songOffsets.size()) % songOffsets.size();
}

void AudioEngine::loopTasks() {
    // Placeholder for decoder loop; real implementation will be on AudioTask
}
