#pragma once

#include QMK_KEYBOARD_H
#include "erikpeyronson.h"

#define MY_CAPS_WORD QK_CAPS_WORD_TOGGLE

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BAS] = LAYOUT_split_3x6_5(
        /********************************************************************************************************************************************************************************************************/
        KC_TAB,          KC_Q,            KC_W,            KC_E,            KC_R,            KC_T,           /**/        KC_Y,            KC_U,            KC_I,            KC_O,            KC_P,            KC_MINS,
        LGUI_T(KC_ESC),  KC_A,            LALT_T(KC_S),    LSFT_T(KC_D),    LCTL_T(KC_F),    KC_G,           /**/        KC_H,            RCTL_T(KC_J),    RSFT_T(KC_K),    LALT_T(KC_L),    KC_SCLN,         RGUI_T(KC_QUOT),
        MO(ETC),         KC_Z,            KC_X,            KC_C,            KC_V,            KC_B,           /**/        KC_N,            KC_M,            KC_COMM,         KC_DOT,          KC_SLSH,         QK_REP,
        /********************************************************************************************************************************************************************************************************/
                         KC_NO,           LT(NAV,KC_BSPC), LT(SYM,KC_BSPC), LT(NUM,KC_DEL),  MO(ETC),        /**/        MO(ETC),         LT(NUM, KC_ENT), LT(SYM,KC_SPC),  LT(NAV, KC_SPC), KC_NO
        /********************************************************************************************************************************************************************************************************/
    ),

    [SWE] = LAYOUT_split_3x6_5(
        /********************************************************************************************************************************************************************************************************/
        KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,        /**/        KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         RALT(KC_W),
        KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,        /**/        KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         RALT(KC_P),      RALT(KC_Q),
        MO(STC),         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,        /**/        KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,
        /********************************************************************************************************************************************************************************************************/
                         KC_NO,           KC_TRNS,         KC_TRNS,         KC_TRNS,         MO(ETC),        /**/        MO(ETC),         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_NO
        /********************************************************************************************************************************************************************************************************/
    ),

    [ETC] = LAYOUT_split_3x6_5(
        /********************************************************************************************************************************************************************************************************/
        TG(SWE),         KC_NO,           KC_NO,           KC_NO,           KC_NO,           KC_NO,          /**/        KC_NO,            KC_NO,          KC_INSERT,       KC_NO,            KC_NO,          RALT(KC_W),
        KC_CAPS,         KC_NO,           KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_NO,          /**/        KC_NO,            KC_TRNS,        KC_TRNS,         KC_TRNS,          RALT(KC_P),     RALT(KC_Q),
        KC_NO,           KC_NO,           KC_NO,           KC_NO,           KC_NO,           QK_BOOT,        /**/        KC_NO,            KC_NO,          KC_NO,           KC_NO,            KC_NO,          KC_NO,
        /********************************************************************************************************************************************************************************************************/
                         KC_NO,           TG(NAV),         TG(SYM),         TG(NUM),         MO(ETC),        /**/        MO(ETC),          TG(NUM),        TG(SYM),         TG(NAV),          KC_NO
        /********************************************************************************************************************************************************************************************************/
    ),

    [STC] = LAYOUT_split_3x6_5(
        /********************************************************************************************************************************************************************************************************/
        TG(1),           DF(0),           KC_NO,            KC_NO,          KC_NO,           KC_NO,          /**/        KC_NO,            KC_NO,          KC_INSERT,       KC_NO,            KC_NO,          KC_MINS,
        KC_CAPS,         KC_NO,           KC_TRNS,          KC_TRNS,        KC_TRNS,         KC_NO,          /**/        KC_NO,            KC_TRNS,        KC_TRNS,         KC_TRNS,          KC_SCLN,        KC_QUOT,
        KC_NO,           KC_NO,           KC_NO,            KC_NO,          KC_NO,           QK_BOOT,        /**/        KC_NO,            KC_NO,          KC_NO,           KC_NO,            KC_NO,          KC_NO,
        /********************************************************************************************************************************************************************************************************/
                         KC_NO,           TG(NAV),          TG(SYM),        TG(NUM),         MO(ETC),        /**/        MO(ETC),          TG(NUM),        TG(SYM),         TG(NAV),          KC_NO
        /********************************************************************************************************************************************************************************************************/
    ),
    [NUM] = LAYOUT_split_3x6_5(
        /********************************************************************************************************************************************************************************************************/
        KC_GRV,          KC_1,            KC_2,             KC_3,           KC_4,            KC_5,           /**/        KC_6,              KC_7,           KC_8,           KC_9,             KC_0,           KC_EQL,
        KC_TRNS,         KC_NO,           KC_TRNS,          KC_TRNS,        KC_TRNS,         KC_NO,          /**/        KC_MINS,           RCTL_T(KC_4),   RSFT_T(KC_5),   LALT_T(KC_6),     KC_PAST,        RGUI_T(KC_BSLS),
        KC_NO,           KC_NO,           KC_NO,            KC_NO,          KC_NO,           KC_NO,          /**/        KC_PLUS,           KC_1,           KC_2,           KC_3,             KC_SLSH,        LT(ETC,KC_DOT),
        /********************************************************************************************************************************************************************************************************/
                         KC_NO,           KC_TRNS,          KC_TRNS,        KC_TRNS,         MO(ETC),        /**/        MO(ETC),           KC_TRNS,        KC_TRNS,        KC_0,             KC_NO
        /********************************************************************************************************************************************************************************************************/
    ),
    [SYM] = LAYOUT_split_3x6_5(
        /********************************************************************************************************************************************************************************************************/
        KC_GRV,       KC_EXLM,            KC_AT,            KC_HASH,        KC_DLR,          KC_PERC,        /**/        KC_CIRC,           KC_AMPR,        KC_ASTR,        KC_LPRN,          KC_RPRN,        KC_EQL,
        MY_CAPS_WORD, KC_NO,              KC_TRNS,          KC_TRNS,        KC_TRNS,         KC_NO,          /**/        KC_PIPE,           RCTL_T(KC_LT),  RSFT_T(KC_GT),  LALT_T(KC_LBRC),  KC_RBRC,        RGUI_T(KC_BSLS),
        KC_NO,        KC_NO,              KC_NO,            KC_NO,          KC_NO,           KC_NO,          /**/        KC_TILD,           KC_SCLN,        KC_DQUO,        KC_LCBR,          KC_RCBR,        LT(ETC, KC_PIPE),
        /********************************************************************************************************************************************************************************************************/
                      KC_NO,              KC_TRNS,          KC_TRNS,        KC_TRNS,         MO(ETC),        /**/        MO(ETC),           KC_TRNS,        KC_TRNS,        KC_TRNS,          KC_NO
        /********************************************************************************************************************************************************************************************************/
    ),
    [NAV] = LAYOUT_split_3x6_5(
        /********************************************************************************************************************************************************************************************************/
        KC_NO,        KC_F1,              KC_F2,            KC_F3,          KC_F4,          KC_F5,           /**/         KC_F6,            KC_F7,           KC_F8,         KC_F9,            KC_F10,         KC_F11,
        KC_TRNS,      KC_NO,              KC_TRNS,          KC_TRNS,        KC_TRNS,        KC_NO,           /**/         KC_LEFT,          RCTL_T(KC_DOWN), RSFT_T(KC_UP), LALT_T(KC_RGHT),  KC_NO,          RGUI_T(KC_F12),
        KC_NO,        KC_NO,              KC_CUT,           KC_COPY,        KC_PSTE,        KC_NO,           /**/         KC_HOME,          KC_PGDN,         KC_PGUP,       KC_PGDN,          KC_END,         QK_AREP,
        /********************************************************************************************************************************************************************************************************/
                      KC_NO,              KC_TRNS,          KC_TRNS,        KC_TRNS,        MO(ETC),         /**/         MO(ETC),          KC_TRNS,         KC_TRNS,       KC_TRNS,          KC_NO
        /********************************************************************************************************************************************************************************************************/
    )
};
// clang-format on

#ifdef CHORDAL_HOLD_ENABLE
// clang-format off
const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT_split_3x6_5(
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
             'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R'
    );
// clang-format on
#endif

#ifdef OTHER_KEYMAP_C
#    include OTHER_KEYMAP_C
#endif // OTHER_KEYMAP_C

