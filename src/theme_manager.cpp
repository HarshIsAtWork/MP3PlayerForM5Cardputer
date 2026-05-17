#include <Arduino.h>
#include <M5Unified.h>

#include "theme_manager.h"

uint16_t C_BG_DARK, C_BG_LIGHT, C_HEADER, C_ACCENT, C_PLAYING, C_HIGHLIGHT, C_TEXT_MAIN, C_TEXT_DIM;

const int NUM_THEME_COLORS = 8;
const int NUM_THEMES = 5;
const char* themeLabels[] = { "Gunmetal Blue", "Cyberpunk", "Retro Amber", "Hacker Green", "Custom" };
const char* themeColorLabels[] = { "BG Dark", "BG Light", "Header", "Accent", "Playing", "Highlight", "Text Main", "Text Dim" };
int g_customThemeRGB[8][3] = {
    { 16, 0, 16 },
    { 33, 36, 33 },
    { 24, 28, 24 },
    { 0, 182, 255 },
    { 0, 255, 0 },
    { 255, 0, 255 },
    { 255, 255, 255 },
    { 148, 146, 148 }
};

uint16_t rgb888To565(int r, int g, int b) {
    r = constrain(r, 0, 255);
    g = constrain(g, 0, 255);
    b = constrain(b, 0, 255);
    return ((r & 0xF8) << 8) | ((g & 0xFC) << 3) | (b >> 3);
}

void rgb565ToRgb888(uint16_t color, int& r, int& g, int& b) {
    r = ((color >> 11) & 0x1F) * 255 / 31;
    g = ((color >> 5) & 0x3F) * 255 / 63;
    b = (color & 0x1F) * 255 / 31;
}

void captureCurrentThemeToCustom() {
    uint16_t colorSlots[8] = {
        C_BG_DARK, C_BG_LIGHT, C_HEADER, C_ACCENT,
        C_PLAYING, C_HIGHLIGHT, C_TEXT_MAIN, C_TEXT_DIM
    };

    for (int i = 0; i < 8; i++) {
        rgb565ToRgb888(colorSlots[i], g_customThemeRGB[i][0], g_customThemeRGB[i][1], g_customThemeRGB[i][2]);
    }
}

void applyCustomTheme() {
    C_BG_DARK = rgb888To565(g_customThemeRGB[0][0], g_customThemeRGB[0][1], g_customThemeRGB[0][2]);
    C_BG_LIGHT = rgb888To565(g_customThemeRGB[1][0], g_customThemeRGB[1][1], g_customThemeRGB[1][2]);
    C_HEADER = rgb888To565(g_customThemeRGB[2][0], g_customThemeRGB[2][1], g_customThemeRGB[2][2]);
    C_ACCENT = rgb888To565(g_customThemeRGB[3][0], g_customThemeRGB[3][1], g_customThemeRGB[3][2]);
    C_PLAYING = rgb888To565(g_customThemeRGB[4][0], g_customThemeRGB[4][1], g_customThemeRGB[4][2]);
    C_HIGHLIGHT = rgb888To565(g_customThemeRGB[5][0], g_customThemeRGB[5][1], g_customThemeRGB[5][2]);
    C_TEXT_MAIN = rgb888To565(g_customThemeRGB[6][0], g_customThemeRGB[6][1], g_customThemeRGB[6][2]);
    C_TEXT_DIM = rgb888To565(g_customThemeRGB[7][0], g_customThemeRGB[7][1], g_customThemeRGB[7][2]);
}

void applyTheme(int index) {
    switch (index) {
        case 0:
            C_BG_DARK = 0x1002; C_BG_LIGHT = 0x2124; C_HEADER = 0x18E3;
            C_ACCENT = 0x05BF; C_PLAYING = 0x07E0; C_HIGHLIGHT = 0xF81F;
            C_TEXT_MAIN = 0xFFFF; C_TEXT_DIM = 0x9492;
            break;
        case 1:
            C_BG_DARK = 0x0803; C_BG_LIGHT = 0x1866; C_HEADER = 0xA013;
            C_ACCENT = 0x07FF; C_PLAYING = 0xFFE0; C_HIGHLIGHT = 0xF800;
            C_TEXT_MAIN = 0xFFFF; C_TEXT_DIM = 0x7BEF;
            break;
        case 2:
            C_BG_DARK = TFT_BLACK; C_BG_LIGHT = 0x2104; C_HEADER = 0x6A00;
            C_ACCENT = 0xFDA0; C_PLAYING = TFT_ORANGE; C_HIGHLIGHT = TFT_RED;
            C_TEXT_MAIN = 0xFEA0; C_TEXT_DIM = 0xA340;
            break;
        case 3:
            C_BG_DARK = 0x0000; C_BG_LIGHT = 0x0180; C_HEADER = 0x0320;
            C_ACCENT = 0x07E0; C_PLAYING = 0x07FF; C_HIGHLIGHT = TFT_WHITE;
            C_TEXT_MAIN = 0x07E0; C_TEXT_DIM = 0x03E0;
            break;
        case 4:
        default:
            applyCustomTheme();
            break;
    }
}
