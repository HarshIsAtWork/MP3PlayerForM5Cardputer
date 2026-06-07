#pragma once
#include <stdint.h>
#include <string>

class PlaylistManager {
public:
    PlaylistManager();
    void begin();
    bool load(const char* path = nullptr);
    const char* getSongPath(int idx);
};

extern PlaylistManager playlist;
