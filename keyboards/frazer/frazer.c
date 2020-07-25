#include QMK_KEYBOARD_H

#define KLGT LED_FLAG_KEYLIGHT;

led_config_t g_led_config = {
    {
        { 38, 37, 36, 35, 34, 33 },
        { 39, 40, 41, 42, 43, 44 },
        { 50, 49, 48, 47, 46, 45 },
        { 51, 52, 53, 54, 55, 56 },
        { 65, 64, 63, 62, 61, 58 },
        { NO_LED, NO_LED, 60, 59, 57, NO_LED },

        { 5, 4, 3, 2, 1, 0 },
        { 6, 7, 8, 9, 10, 11 },
        { 17, 16, 15, 14, 13, 12 },
        { 18, 19, 20, 21, 22, 23 },
        { 32, 31, 30, 29, 28, 25 },
        { NO_LED, NO_LED, 27, 26, 24, NO_LED },
    },
    {
        { 206,  9 },  { 189,  9 },  { 172,  9 },  { 155,  9 },  { 137,  9 },  { 120,  9 },
        { 120,  18 }, { 137,  18 }, { 155,  18 }, { 172,  18 }, { 189,  18 }, { 206,  18 },
        { 206,  27 }, { 189,  27 }, { 172,  27 }, { 155,  27 }, { 137,  27 }, { 120,  27 }, 
        { 120,  36 }, { 137,  36 }, { 155,  36 }, { 172,  36 }, { 189,  36 }, { 206,  36 },
        { 206,  45 }, { 189,  45 }, { 172,  45 }, { 155,  45 }, { 137,  45 }, { 120,  45 }, 
        { 120,  54 }, { 137,  54 }, { 155,  54 },

        { 120,  9 },  { 137,  9 },  { 155,  9 },  { 172,  9 },  { 189,  9 },  { 206,  9 },
        { 120,  18 }, { 137,  18 }, { 155,  18 }, { 172,  18 }, { 189,  18 }, { 206,  18 },
        { 120,  27 }, { 137,  27 }, { 155,  27 }, { 172,  27 }, { 189,  27 }, { 206,  27 },
        { 120,  36 }, { 137,  36 }, { 155,  36 }, { 172,  36 }, { 189,  36 }, { 206,  36 },
        { 120,  45 }, { 137,  45 }, { 155,  45 }, { 172,  45 }, { 189,  45 }, { 206,  45 },
        { 120,  54 }, { 137,  54 }, { 155,  54 },
    },
    {
        4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4
    }
};