#pragma once

#include "quantum.h"

typedef enum
{
  BAS = 0,
  SWE,
  ETC,
  STC,
  NUM,
  SYM,
  NAV,
  // Not an actual layer, used to end loop conditions and has to be last
  LAYER_END
} layer_t;

enum
{
  MY_CYCLE_RGB_MODE = MY_RGB_KEYCODE_OFFSET
};

// Tap Dance definitions
enum
{
  TD_CURLY_BRACKETS = 0,
  TD_SQUARE_BRACKETS,
  TD_PARENTESES,
  TD_LTGT,
  TD_SWE,
  TD_BASE,
  TD_BASE_TILDE
};

#define MY_LT(layer, kc) LT(layer, kc)