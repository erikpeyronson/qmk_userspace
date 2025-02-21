#include "common.h"

static bool ctrl_enabled = false;
static bool alt_enabled = false;

void start_ctrl_timer(void) {
  if (!ctrl_enabled) {
    register_code(KC_LCTL);
    ctrl_enabled = true;
  }
}

void stop_ctrl_timer(void) {
  if (ctrl_enabled) {
    unregister_code(KC_LCTL);
    ctrl_enabled = false;
  }
}

void start_alt_timer(void) {
  if (!alt_enabled) {
    register_code(KC_LALT);
    alt_enabled = true;
  }
}

void stop_alt_timer(void) {
  if (alt_enabled) {
    unregister_code(KC_LALT);
    alt_enabled = false;
  }
}

bool process_encoder_navigation(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
    case MY_CTRL_TAB_NAV:
      if (record->event.pressed) {
        start_ctrl_timer();
        tap_code(KC_TAB);
      }
      return false;
    case MY_CTRL_TAB_NAV_REVERSE:
      if (record->event.pressed) {
        uprintf("control tab reverse\n");
        start_ctrl_timer();
        tap_code16(S(KC_TAB));
      }
      return false;
    case MY_ALT_TAB_NAV:
      if (record->event.pressed) {
        start_alt_timer();
        tap_code(KC_TAB);
      }
      return false;
    case MY_ALT_TAB_NAV_REVERSE:
      if (record->event.pressed) {
        start_alt_timer();
        tap_code16(S(KC_TAB));
      }
      return false;
  }

  stop_ctrl_timer();
  stop_alt_timer();
  return true;
}
