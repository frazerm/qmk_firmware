#include QMK_KEYBOARD_H
#include <split_util.h>

// #ifdef PROTOCOL_LUFA
//   #include "lufa.h"
//   #include "split_util.h"
// #endif
// #ifdef SSD1306OLED
//   #include "ssd1306.h"
// #endif



#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

uint8_t is_left_hand;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3

#define LOWER  LT(_LOWER, KC_SPC)
#define RAISE  LT(_RAISE, KC_SPC)
#define ADJUST MO(_ADJUST)

#define HYPER  ALL_T(KC_ESC)
#define TILDE  LSFT(KC_BSLS)

enum custom_keycodes {
  QWERTY = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   S  |   D  |   F  |   G  |            ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|------.     |    ]  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |      |     |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * |------+------+------+------+------+------+------|      \      \-----------------------------------------'
 * | ESC  |   1  |   2  |   3  |   4  |   5  |      |       \Enter \  |RAISE |BackSP| RGUI |
 * '----------------------------------+------+------|        \      \ |      |      |      |
 *                                    |      |      |         '------''--------------------'
 *                                    '-------------'
 *
 */

[_QWERTY] = LAYOUT( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                          KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_QUOT, \
  HYPER,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                          KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,  \
  KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_NO,       KC_NO,   KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, \
  KC_LCTL, KC_LGUI, KC_LALT, KC_LCTL, KC_NO,   KC_SPC,  KC_NO,       KC_NO,   KC_SPC,  KC_NO,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, \
                                               LOWER,   KC_BSPC,     KC_BSPC, RAISE \
),

[_LOWER] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, KC_DEL,  \
  KC_BSPC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,  \
  _______, KC_LBRC, KC_LCBR, KC_LPRN, KC_UNDS, KC_EQL,                       KC_PLUS, KC_MINS, KC_RPRN, KC_RCBR, KC_RBRC, _______, \
  _______, _______, _______, _______, KC_NUHS, _______, _______,    _______, _______, TILDE, _______, _______, _______, _______,   \
  _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, KC_HOME, _______, _______, KC_END,  \
                                               _______, _______,    _______, _______ \
),

[_RAISE] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, KC_DEL,  \
  KC_BSPC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,  \
  _______, KC_LBRC, KC_LCBR, KC_LPRN, KC_UNDS, KC_EQL,                       KC_PLUS, KC_MINS, KC_RPRN, KC_RCBR, KC_RBRC, _______, \
  _______, _______, _______, _______, KC_NUHS, _______, _______,    _______, _______, TILDE, _______, _______, _______, _______,   \
  _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, KC_HOME, _______, _______, KC_END,  \
                                               _______, _______,    _______, _______ \
),

[_ADJUST] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______, \
  _______, RESET,   _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,  \
  _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______, \
                                               _______, _______,    _______, _______ \
)
};

// void matrix_init_user() {
//   is_left_hand = is_keyboard_left();
// }

// #ifdef OLED_DRIVER_ENABLE
// void oled_task_user(void) {
//     static const char PROGMEM qmk_logo[] = {
//         0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
//         0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
//         0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
//     };

//     oled_write_P(qmk_logo, false);
// }
// #endif

#ifdef OLED_DRIVER_ENABLE
void oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
      case _QWERTY:
        oled_write_P(PSTR("Default\n"), false);
        break;
      case _LOWER:
        oled_write_P(PSTR("Lower\n"), false);
        break;
      case _RAISE:
        oled_write_P(PSTR("Raise\n"), false);
        break;
      case _ADJUST:
        oled_write_P(PSTR("Adjust\n"), false);
        break;
      default:
        // Or use the write_ln shortcut over adding '\n' to the end of your string
        oled_write_ln_P(PSTR("Undefined"), false);
    }
}
#endif

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
  switch (index) {
    case 0:
      if (clockwise) {
        tap_code(KC_VOLU);
      } else {
          tap_code(KC_VOLD);
      }
      break;
    case 1:
      if (clockwise) {
        tap_code(KC_MS_WH_DOWN);
      } else {
        tap_code(KC_MS_WH_UP);
      }
      break;
    default:
      break;
  }
}
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  #ifdef CONSOLE_ENABLE
    uprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);
  #endif

  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
  }
  return true;
}
