#include "erikpeyronson.h"

#define IS_KC_SHIFTED_SYMBOL(code) (keycode >> 8 & 0x02)

static const char PROGMEM code_to_name[60] = {' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
    'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '1', '2', '3', '4', '5', '6', '7', '8',
    '9', '0', 'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\', '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

__attribute__((weak)) const char *layer_to_string(uint8_t layer) { return layer_strings[layer]; }

uint16_t get_effective_keycode(uint8_t current_layer, keypos_t key)
{
  // Start checking from the given layer, going down to the base layer
  for (int8_t layer = current_layer; layer >= 0; layer--)
    {
      uint16_t keycode = keymap_key_to_keycode(layer, key);
      if (keycode != KC_TRNS)
        {
          return keycode; // Found a non-transparent keycode
        }
    }
  return KC_NO; // No valid key found (shouldn't happen in a properly defined keymap)
}

__attribute__((weak)) char keycode_to_char(uint16_t keycode, keypos_t keypos)
{
  if (MY_IS_QK_TAP_DANCE(keycode))
    {
      uprintf("keycode in tapdance conversion: 0x%4x \n", keycode);
      keycode = QK_MODS_GET_BASIC_KEYCODE(keycode);
      uprintf("Basic keycode: 0x%04x \n", keycode);

      switch (keycode)
        {
          case TD_CURLY_BRACKETS:
            return '}';
          case TD_SQUARE_BRACKETS:
            return ']';
          case TD_PARENTESES:
            return ')';
          case TD_LTGT:
            return '>';
          default:
            return (char)0x07;
        }
    }

  if (keycode == KC_TRANSPARENT)
    {
      keycode = get_effective_keycode(get_highest_layer(layer_state), keypos);
    }

  if (IS_QK_MOD_TAP(keycode))
    {
      println("Mod tap");
      keycode = QK_MOD_TAP_GET_TAP_KEYCODE(keycode);
    }
  if (IS_KC_SHIFTED_SYMBOL(keycode))
    {
      println("Is shifted");
      switch (QK_MODS_GET_BASIC_KEYCODE(keycode))
        {
          case 0x1E:
            return '!';
          case 0x1F:
            return '@';
          case 0x20:
            return '#';
          case 0x21:
            return '$';
          case 0x22:
            return '%';
          case 0x23:
            return '^';
          case 0x24:
            return '&';
          case 0x25:
            return '*';
          case 0x26:
            return '(';
          case 0x27:
            return ')';
          case 0x2F:
            return '{';
          case 0x30:
            return '}';
          case KC_EQUAL:
            return '+';
        }
    }


  if (IS_QK_LAYER_TAP(keycode))
    {
      println("layer tap tap");
      keycode = QK_LAYER_TAP_GET_TAP_KEYCODE(keycode);
    }

  if (IS_QK_MODS(keycode))
    {
      println("qk mods");
      keycode = QK_MODS_GET_BASIC_KEYCODE(keycode);
    }
  if (IS_QK_ONE_SHOT_MOD(keycode))
    {
      println("one shot mod");
      keycode = 0xE0 + biton(QK_ONE_SHOT_MOD_GET_MODS(keycode) & 0xF) + biton(QK_ONE_SHOT_MOD_GET_MODS(keycode) & 0x10);
    }

  if (keycode == KC_NO)
    {
      return 0x80;
    }

  switch (keycode)
    {
      case KC_KP_SLASH:
        return '/';
      case KC_KP_ASTERISK:
        return '*';
      case KC_KP_MINUS:
        return '-';
      case KC_KP_PLUS:
        return '+';
    }

    switch(keycode) {
      case KC_UP:
        return 0x18;
    case KC_DOWN:
        return 0x19;
    case KC_LEFT:
        return 0x1B;
    case KC_RIGHT:
        return 0x1A;
    case KC_PGUP:
        return 'U';
    case KC_PGDN:
        return 'D';
    case KC_HOME:
        return 'H';
    case KC_END:
        return 'E';
    case KC_INS:
        return 'I';
    }

    switch(keycode) {
      case KC_F1:
      return '1';
    case KC_F2:
      return '2';
    case KC_F3:
      return '3';
    case KC_F4:
      return '4';
    case KC_F5:
      return '5';
    case KC_F6:
      return '6';
    case KC_F7:
      return '7';
    case KC_F8:
      return '8';
    case KC_F9:
      return '9';
    case KC_F10:
      return '0';
    case KC_F11:
      return '1';
    case KC_F12:
      return '2';

    }

  if (keycode > ARRAY_SIZE(code_to_name))
    {
      return (char)0x07;
    }
  // update keylog
  return pgm_read_byte(&code_to_name[keycode]);
}

__attribute__((weak)) int8_t get_layer_with_key(uint8_t layer, const keypos_t keypos)
{
  uint16_t kc = keymap_key_to_keycode(layer, keypos);

  while (layer > 0 && (kc == KC_TRANSPARENT || IS_LAYER_OFF(layer)))
    {
      layer--;
      kc = keymap_key_to_keycode(layer, keypos);
    }

  if (kc != KC_NO && kc != KC_TRANSPARENT)
    {
      return layer;
    }

  return -1;
}

bracket_info_t brackets[] = {
    [TD_CURLY_BRACKETS]  = {KC_LEFT_BRACKET, KC_RIGHT_BRACKET, true},
    [TD_SQUARE_BRACKETS] = {KC_LEFT_BRACKET, KC_RIGHT_BRACKET, false},
    [TD_PARENTESES]      = {KC_9, KC_0, true},
    [TD_LTGT]            = {KC_COMMA, KC_DOT, true},
};
