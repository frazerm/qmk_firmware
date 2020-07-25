#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x3060
#define DEVICE_VER      0x0001
#define MANUFACTURER    Frazer McIntosh
#define PRODUCT         Cool keyboard
#define DESCRIPTION     A split keyboard for Frazer

#define USE_SERIAL

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 12
#define MATRIX_COLS 6

// wiring of each half
#define MATRIX_ROW_PINS { C6, D7, E6, B4, B5, D4 }
#define MATRIX_COL_PINS { F6, F7, B1, B3, B2, B6 }

#define ENCODERS_PAD_A { F4 }
#define ENCODERS_PAD_B { F5 }

/* Set 0 if debouncing isn't needed */
// #define DEBOUNCE 5

/* serial.c configuration for split keyboard */
#define SOFT_SERIAL_PIN D2

#define RGBLIGHT_SPLIT

/* ws2812 RGB LED */
#define RGB_DI_PIN D3

/* Number of LEDs */
#define DRIVER_LED_TOTAL 66

#define RGBLED_SPLIT { 33, 33 }