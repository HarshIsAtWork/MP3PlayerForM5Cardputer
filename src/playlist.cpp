#include "playlist.h"
#include <Arduino.h>

PlaylistManager playlist;

PlaylistManager::PlaylistManager() {}

void PlaylistManager::begin() {
    // placeholder
}

bool PlaylistManager::load(const char* path) {
    (void)path;
    // stub: no playlist available
    return false;
}

const char* PlaylistManager::getSongPath(int idx) {
    (void)idx;
    return "";
}
