#ifdef OLED_ENABLE
#include "quantum.h"

#include "string.h"

#include "oled_driver.h"
#include "print.h"

#include "common.h"
#include "erikpeyronson.h"

#ifdef MY_RENDER_LOGO_ENABLED
#include "logo.h"
#endif

#include <ctype.h>

#define OLED_CHARS_PER_LINE 6

#ifdef MY_OLED_RENDER_KEYMAP_ENABLED
static char keymap_chars[6][3][5];
#endif

void           my_oled_init(const uint16_t keymaps[6][MATRIX_ROWS][MATRIX_COLS])
{
#ifdef MY_OLED_RENDER_KEYMAP_ENABLED
  uint8_t no_cols   = 5;
  uint8_t first_col = 1;

  uint8_t no_rows = 3;
  uint8_t first_row;

  uint8_t invert_offset;

  if (is_keyboard_master())
    {
      first_row     = 0;
      invert_offset = 0;
    }
  else
    {
      first_row     = 4;
      invert_offset = 6;
    }

  for (uint8_t layer = 0; layer < 6; ++layer)
    {
      for (size_t row = first_row; row < first_row + no_rows; row++)
        {
          for (size_t col = first_col; col < first_col + no_cols; col++)
            {
              keypos_t keypos = {col, row};
              uint16_t kc     = keymap_key_to_keycode(layer, keypos);

              // Mirror the index of the character for the right half so that the code rendering
              // can be used for both
              char *char_to_set;
              if (is_keyboard_master())
                {
                  char_to_set = &keymap_chars[layer][row - first_row][col - first_col];
                }
              else
                {
                  char_to_set = &keymap_chars[layer][row - first_row][invert_offset - col - first_col];
                }
              *char_to_set = keycode_to_char(kc, NULL);
            }
        }
    }
#endif
}

#ifdef MY_OLED_RENDER_KEYMAP_ENABLED
static void my_oled_render_keylog(void)
{
  uint8_t current_layer = get_highest_layer(layer_state);

  uint8_t rows = 3;
  uint8_t cols = 5;
  oled_write_P(PSTR("-----"), false);
  for (size_t i = 0; i < rows; i++)
    {
      for (size_t k = 0; k < cols; k++)
        {
          oled_write_char(keymap_chars[current_layer][i][k], false);
        }
      oled_advance_page(true);
    }
}
#endif

oled_rotation_t oled_init_user(oled_rotation_t rotation)
{
  rotation = OLED_ROTATION_270;
  return rotation;
}

static void my_oled_write_captalized(const char *str, bool invert)
{
  for (uint8_t i = 0; i < strlen(str); ++i)
    {
      oled_write_char(toupper(str[i]), false);
    }
}

static void my_oled_render_selection(const char *str, bool is_active, bool is_oneshot_active)
{
  (void)is_oneshot_active;
  bool write_capitalized = false;
  if (is_oneshot_active)
    {
      oled_write_char('-', false);
    }
  else if (is_active)
    {
      oled_write_char('*', false);
    }
  else
    {
      oled_write_char(' ', false);
    }

  if (write_capitalized)
    {
      my_oled_write_captalized(str, false);
    }
  else
    {
      oled_write(str, false);
    }

  if (strlen(str) < 4)
    {
      oled_advance_page(false);
    }
}

static void my_oled_render_layers(void)
{
  // uint8_t current_layer = get_highest_layer(layer_state);

  oled_write_P(PSTR("-----"), false);
  oled_write_P(PSTR("LAYER"), false);
  oled_write_P(PSTR("-----"), false);
  uint8_t osl_state = get_oneshot_layer();
  for (layer_t layer = LAYER_BASE; layer < LAYER_END; ++layer)
    {
      const bool should_oneshot = (layer != LAYER_BASE) && (osl_state == layer);
      my_oled_render_selection(layer_to_string(layer), (layer_state_is(layer)), (should_oneshot));
    }
}

static void my_oled_render_locks(void)
{
  led_t led_config = host_keyboard_led_state();

  oled_write_P(PSTR("-----"), false);
  oled_write_P(PSTR("LOCKS"), false);
  oled_write_P(PSTR("-----"), false);
  my_oled_render_selection("Word", is_caps_word_on(), false);
  my_oled_render_selection("Caps", led_config.caps_lock, false);
  my_oled_render_selection("Scrl", led_config.num_lock, false);
  my_oled_render_selection("Num", led_config.num_lock, false);
  oled_write_P(PSTR("-----"), false);
  oled_write_P(PSTR("MODS "), false);
  oled_write_P(PSTR("-----"), false);
  uint8_t mod_state = get_mods();
  uint8_t osm_state  = get_oneshot_mods();
  // clang-format off
  my_oled_render_selection( "Ctrl", (mod_state & MOD_BIT(KC_LEFT_CTRL)),  osm_state & MOD_MASK_CTRL);
  my_oled_render_selection( "Shif", (mod_state & MOD_BIT(KC_LEFT_SHIFT)), osm_state & MOD_MASK_SHIFT);
  my_oled_render_selection( "Alt",  (mod_state & MOD_BIT(KC_LEFT_ALT)),   osm_state & MOD_MASK_ALT);
  my_oled_render_selection( "Win",  (mod_state & MOD_BIT(KC_LEFT_GUI)),   osm_state & MOD_MASK_GUI);
  // clang-format on
}

void my_oled_render_info(void)
{

  oled_advance_page(false);
  if (is_keyboard_master())
    {
      my_oled_render_locks();
    }
  else
    {
      oled_advance_page(false);
      my_oled_render_layers();
    }

  oled_advance_page(false);
#ifdef MY_OLED_RENDER_KEYMAP_ENABLED
  my_oled_render_keylog();
#endif
}


#ifdef MY_RENDER_LOGO_ENABLED
static uint8_t brigtness = 0;
static bool screen_saver_on = false;

static void my_oled_render_logo(void)
{
  oled_write_raw_P(raw_logo, sizeof(raw_logo));
  oled_scroll_left();
}

void my_oled_screensaver(bool turn_on)
{
  if (!screen_saver_on && turn_on)
    {
      oled_clear();
      brigtness = oled_get_brightness();
      oled_set_brightness(OLED_SCREENSAVER_BRIGHTNESS);
      oled_scroll_set_speed(4);
      oled_scroll_left();
      screen_saver_on = true;
    }
  else if (screen_saver_on && !turn_on)
    {
      oled_clear();

      oled_scroll_off();
      screen_saver_on = false;
      oled_set_brightness(brigtness);
    }
}


bool oled_task_user(void)
{
  if (!screen_saver_on)
    {
      my_oled_render_info();
    }
  else
    {
      my_oled_render_logo();
    }

  return false;
}
#else

void my_oled_screensaver(bool turn_on) {}

bool oled_task_user(void)
{
      my_oled_render_info();
      return false;
}
#endif

#endif