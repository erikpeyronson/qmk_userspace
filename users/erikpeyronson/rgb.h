#pragma once

#include "common.h"

typedef enum _RgbMode
{

#ifdef MY_RGB_EACH_KEY_ENABLED
  EACH_KEY = 0,
#endif
#ifdef MY_RGB_THUMBS_HINT_ENABLED
  THUMBS_HINT,
#endif
  THUMBS_SOLID,
  OFF
} RgbMode;

typedef struct _my_state_t
{
  RgbMode rgb_mode;
} my_state_t;

#ifdef RGB_MATRIX_ENABLE
void    my_rgb_init(void);
void    my_rgb_set_mode(RgbMode mode);
RgbMode my_rgb_get_mode(void);
void    my_rgb_next_mode(void);
void    my_rgb_sync_state(uint8_t in_buflen, const void *in_data, uint8_t out_buflen, void *out_data);
bool    my_rgb_process_record(uint16_t keycode, keyrecord_t *record);

#else
void    my_rgb_init(void) {}
void    my_rgb_set_mode(RgbMode mode) {}
RgbMode my_rgb_get_mode(void) { return OFF; }
void    my_rgb_next_mode(void) {}
void    my_rgb_sync_state(uint8_t in_buflen, const void *in_data, uint8_t out_buflen, void *out_data) {}
bool    my_rgb_process_record(uint16_t keycode, keyrecord_t *record) { return true; }
#endif