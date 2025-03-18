#include QMK_KEYBOARD_H

#include "quantum.h"

#include "rgb.h"
#include "logo.h"
#include "common.h"

#include "oled.h"
#include "erikpeyronson.h"

#include "keymap_out.h"
#include "encoder_navigation.h"

// clang-format off
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [BAS] = {{QK_REPEAT_KEY, QK_ALT_REPEAT_KEY},
                    {QK_REPEAT_KEY, QK_ALT_REPEAT_KEY}},
    [SWE] = {{QK_REPEAT_KEY, QK_ALT_REPEAT_KEY},
                   {QK_REPEAT_KEY, QK_ALT_REPEAT_KEY}},
    [ETC] = {{KC_WH_D, KC_WH_U}, {KC_WH_D, KC_WH_U}},
    [NUM] = {{MY_ALT_TAB_NAV, MY_ALT_TAB_NAV_REVERSE},
                   {MY_ALT_TAB_NAV, MY_ALT_TAB_NAV_REVERSE}},
    [SYM] = {{MY_CTRL_TAB_NAV, MY_CTRL_TAB_NAV_REVERSE},
                   {MY_CTRL_TAB_NAV, MY_CTRL_TAB_NAV_REVERSE}},
    [NAV] = {{KC_WH_D, KC_WH_U}, {KC_WH_D, KC_WH_U}},
    [STC] = {{KC_NO, KC_NO}, {KC_NO, KC_NO}}};
#endif
// clang-format on

// clang-format off
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for W, twice for switch to swedish layer
    [TD_SWE] = ACTION_TAP_DANCE_LAYER_MOVE(KC_MINUS, SWE),
    [TD_BASE] = ACTION_TAP_DANCE_LAYER_MOVE(KC_NO, BAS),
    [TD_BASE_TILDE] = ACTION_TAP_DANCE_LAYER_MOVE(KC_TILD, BAS),
};

const char *layer_strings[] = {
  [BAS]  = "Bas",
  [ETC]  = "Osm",
  [SWE]  = "Swe",
  [NUM]  = "Num ",
  [SYM]  = "Sym",
  [NAV]  = "Nav",
  [STC]  = "Etc",
};

// clang-format on
void keyboard_post_init_user(void)
{
  // Customise these values to desired behaviour
  debug_enable   = false;
  debug_matrix   = false;
  debug_keyboard = false;
  debug_mouse    = false;

  my_rgb_init();
  my_oled_init(keymaps);
}


bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
  // If console is enabled, it will print the matrix position and status of each
  // key pressed
#ifdef CONSOLE_ENABLE

  uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: "
          "%u, count: %u\n\n",
      keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time,
      record->tap.interrupted, record->tap.count);

  uprintf("Character reprentation: %c \n\n", keycode_to_char(keycode, NULL));
#endif

  switch (keycode) { // This will do most of the grunt work with the keycodes.
    case ONENOTE_HAND:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT("d") "y");
      }
      break;
    case ONENOTE_ARROW:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT("d") "t");
      }
      break;

     case ONENOTE_NEXT_PEN:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT("d") "g" SS_TAP(X_RIGHT) SS_TAP(X_ENTER));
      }
      break;
    case ONENOTE_PREVIOUS_PEN:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT("d") "g" SS_TAP(X_LEFT) SS_TAP(X_ENTER));
      }
      break;

    case ONENOTE_ZOOM_IN:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT("w") "e");
      }
      break;
    case ONENOTE_ZOOM_OUT:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT("w") "w");
      }
      break;
    case ONENOTE_FULL_SCREEN:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT("d") "f");
      }
  }

      // Custom navigation
  if (!process_encoder_navigation(keycode, record)) {
      return false;
  }

  if (!my_rgb_process_record(keycode, record)) return false;
  return true;
}

static bool is_idle = false;

void housekeeping_task_user(void)
{
  static RgbMode old_rgb_mode;
  uint32_t       idle_time = last_input_activity_elapsed();

  if (!is_idle && idle_time > MY_OLED_SCREENSAVER_TIMEOUT)
    {
      old_rgb_mode = my_rgb_get_mode();
      my_rgb_set_mode(OFF);
      my_oled_screensaver(true);
      is_idle = true;
    }
  else if (is_idle && idle_time < MY_OLED_SCREENSAVER_TIMEOUT)
    {
      my_oled_screensaver(false);
      my_rgb_set_mode(old_rgb_mode);
      is_idle = false;
    }
}