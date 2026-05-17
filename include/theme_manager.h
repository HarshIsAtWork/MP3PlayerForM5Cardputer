#pragma once

#include <Arduino.h>

extern uint16_t C_BG_DARK;
extern uint16_t C_BG_LIGHT;
extern uint16_t C_HEADER;
extern uint16_t C_ACCENT;
extern uint16_t C_PLAYING;
extern uint16_t C_HIGHLIGHT;
extern uint16_t C_TEXT_MAIN;
extern uint16_t C_TEXT_DIM;

extern const int NUM_THEME_COLORS;
extern const int NUM_THEMES;
extern const char* themeLabels[];
extern const char* themeColorLabels[];
extern int g_customThemeRGB[8][3];

uint16_t rgb888To565(int r, int g, int b);
void rgb565ToRgb888(uint16_t color, int& r, int& g, int& b);
void captureCurrentThemeToCustom();
void applyCustomTheme();
void applyTheme(int index);
