#include "quantum.h"

#ifdef LOGO_SELECTION
static const char PROGMEM raw_logo[] = {
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    192,
    240,
    248,
    248,
    124,
    188,
    222,
    222,
    222,
    222,
    222,
    222,
    220,
    220,
    216,
    208,
    192,
    192,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    128,
    192,
    192,
    224,
    96,
    96,
    96,
    96,
    96,
    96,
    96,
    32,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    192,
    224,
    224,
    224,
    0,
    0,
    128,
    224,
    224,
    224,
    32,
    0,
    0,
    224,
    224,
    224,
    32,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    127,
    255,
    255,
    3,
    252,
    255,
    231,
    251,
    61,
    206,
    238,
    246,
    246,
    246,
    246,
    246,
    246,
    246,
    246,
    54,
    0,
    0,
    0,
    0,
    0,
    240,
    254,
    255,
    255,
    15,
    1,
    0,
    0,
    0,
    0,
    0,
    224,
    248,
    252,
    254,
    15,
    3,
    3,
    3,
    195,
    251,
    255,
    127,
    30,
    0,
    224,
    252,
    255,
    127,
    15,
    3,
    3,
    131,
    243,
    255,
    255,
    63,
    6,
    0,
    56,
    60,
    62,
    63,
    59,
    59,
    59,
    251,
    251,
    251,
    115,
    3,
    129,
    240,
    254,
    255,
    63,
    7,
    128,
    240,
    252,
    255,
    63,
    15,
    1,
    224,
    252,
    255,
    127,
    15,
    193,
    248,
    255,
    255,
    31,
    3,
    0,
    0,
    224,
    252,
    255,
    127,
    15,
    129,
    240,
    254,
    255,
    63,
    7,
    2,
    3,
    195,
    251,
    255,
    255,
    31,
    2,
    3,
    3,
    227,
    255,
    255,
    127,
    14,
    0,
    1,
    3,
    6,
    13,
    11,
    20,
    11,
    4,
    11,
    7,
    15,
    15,
    15,
    15,
    15,
    7,
    3,
    1,
    0,
    0,
    0,
    0,
    0,
    0,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    0,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    0,
    0,
    0,
    1,
    1,
    1,
    1,
    0,
    0,
    0,
    0,
    1,
    1,
    1,
    1,
    0,
    2,
    3,
    3,
    3,
    3,
    3,
    3,
    3,
    1,
    1,
    1,
    0,
    0,
    0,
    1,
    1,
    1,
    1,
    0,
    0,
    1,
    1,
    1,
    1,
    0,
    0,
    1,
    1,
    1,
    1,
    0,
    0,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    0,
    0,
    1,
    1,
    1,
    1,
    0,
    0,
    0,
    0,
    1,
    1,
    1,
    0,
    0,
    0,
    0,
    1,
    1,
    1,
    1,
    0,
    0,

};
static const char PROGMEM raw_logo[] = {
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    192,
    240,
    248,
    248,
    124,
    188,
    222,
    222,
    222,
    222,
    222,
    222,
    220,
    220,
    216,
    208,
    192,
    192,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    128,
    192,
    192,
    224,
    96,
    96,
    96,
    96,
    96,
    96,
    96,
    32,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    192,
    224,
    224,
    224,
    0,
    0,
    128,
    224,
    224,
    224,
    32,
    0,
    0,
    224,
    224,
    224,
    32,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    127,
    255,
    255,
    3,
    252,
    255,
    231,
    251,
    61,
    206,
    238,
    246,
    246,
    246,
    246,
    246,
    246,
    246,
    246,
    54,
    0,
    0,
    0,
    0,
    0,
    240,
    254,
    255,
    255,
    15,
    1,
    0,
    0,
    0,
    0,
    0,
    224,
    248,
    252,
    254,
    15,
    3,
    3,
    3,
    195,
    251,
    255,
    127,
    30,
    0,
    224,
    252,
    255,
    127,
    15,
    3,
    3,
    131,
    243,
    255,
    255,
    63,
    6,
    0,
    56,
    60,
    62,
    63,
    59,
    59,
    59,
    251,
    251,
    251,
    115,
    3,
    129,
    240,
    254,
    255,
    63,
    7,
    128,
    240,
    252,
    255,
    63,
    15,
    1,
    224,
    252,
    255,
    127,
    15,
    193,
    248,
    255,
    255,
    31,
    3,
    0,
    0,
    224,
    252,
    255,
    127,
    15,
    129,
    240,
    254,
    255,
    63,
    7,
    2,
    3,
    195,
    251,
    255,
    255,
    31,
    2,
    3,
    3,
    227,
    255,
    255,
    127,
    14,
    0,
    1,
    3,
    6,
    13,
    11,
    20,
    11,
    4,
    11,
    7,
    15,
    15,
    15,
    15,
    15,
    7,
    3,
    1,
    0,
    0,
    0,
    0,
    0,
    0,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    0,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    0,
    0,
    0,
    1,
    1,
    1,
    1,
    0,
    0,
    0,
    0,
    1,
    1,
    1,
    1,
    0,
    2,
    3,
    3,
    3,
    3,
    3,
    3,
    3,
    1,
    1,
    1,
    0,
    0,
    0,
    1,
    1,
    1,
    1,
    0,
    0,
    1,
    1,
    1,
    1,
    0,
    0,
    1,
    1,
    1,
    1,
    0,
    0,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    0,
    0,
    1,
    1,
    1,
    1,
    0,
    0,
    0,
    0,
    1,
    1,
    1,
    0,
    0,
    0,
    0,
    1,
    1,
    1,
    1,
    0,
    0,
};
#endif

// 90 degrees flipped
static const char PROGMEM raw_logo[] = {
    0,
    0,
    0,
    64,
    176,
    88,
    172,
    182,
    246,
    247,
    247,
    183,
    183,
    119,
    239,
    239,
    222,
    190,
    124,
    252,
    248,
    224,
    128,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    250,
    253,
    254,
    254,
    254,
    254,
    253,
    249,
    7,
    255,
    254,
    1,
    255,
    255,
    0,
    255,
    255,
    127,
    31,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    1,
    3,
    7,
    7,
    7,
    15,
    15,
    0,
    15,
    15,
    0,
    7,
    7,
    0,
    1,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    254,
    30,
    30,
    30,
    30,
    60,
    60,
    60,
    120,
    120,
    240,
    192,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    247,
    240,
    240,
    240,
    224,
    224,
    192,
    128,
    0,
    0,
    63,
    127,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    63,
    112,
    240,
    224,
    224,
    225,
    193,
    255,
    255,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    30,
    28,
    60,
    60,
    57,
    121,
    121,
    241,
    240,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    192,
    158,
    30,
    28,
    60,
    60,
    56,
    120,
    127,
    63,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    63,
    255,
    128,
    128,
    255,
    255,
    255,
    14,
    252,
    248,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    241,
    243,
    231,
    231,
    231,
    195,
    192,
    207,
    159,
    128,
    128,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    60,
    60,
    56,
    121,
    121,
    241,
    243,
    227,
    227,
    231,
    199,
    199,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    207,
    206,
    222,
    158,
    156,
    188,
    60,
    56,
    121,
    113,
    113,
    243,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    255,
    195,
    195,
    195,
    135,
    135,
    135,
    15,
    15,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    121,
    121,
    115,
    243,
    243,
    231,
    231,
    231,
    207,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    56,
    120,
    120,
    112,
    240,
    240,
    225,
    255,
    253,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    60,
    56,
    120,
    120,
    112,
    240,
    240,
    255,
    126,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
};