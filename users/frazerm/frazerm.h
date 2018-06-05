#ifndef FRAZERM_COMMON_H
#define FRAZERM_COMMON_H

#include "preonic.h"

enum frazerm_layers {
  _QWERTY,
  _COLEMAK,
  _DVORAK,
  _GAMING,
  _WIN_MODS,
  _LOWER,
  _RAISE,
  _ADJUST,
  _CALC,
};

enum frazerm_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  WIN_MODS,
  LOWER,
  RAISE,
  GAMING,
  CALC,
  CALC_EXIT,
  CALC_RET,
  CALC_PLS,
  CALC_MIN,
  CALC_MUL,
  CALC_DIV,
  CALC_POW
};

#endif //FRAZERM_COMMON_H