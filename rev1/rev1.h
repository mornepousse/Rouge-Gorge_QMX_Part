#pragma once

#include "rouge_gorge.h"

/* This a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */

#define LAYOUT( \
      L00, L01, L02, L03, L04, L05, L06,                                   R00, R01, R02, R03, R04, R05, R06, \
      L10, L11, L12, L13, L14, L15, L16,                                   R10, R11, R12, R13, R14, R15, R16, \
      L20, L21, L22, L23, L24, L25, L35, L34,                         R31, R30, R20, R21, R22, R23, R24, R25, \
                          L30, L31, L32,L33,                          R32, R33, R34, R35 \
  ) \
  { \
    { L00, L01, L02, L03, L04, L05, L06 }, \
    { L10, L11, L12, L13, L14, L15, L16 }, \
    { L20, L21, L22, L23, L24, L25, KC_NO }, \
    { L33, L34,  L35, L30, L31, L32, KC_NO }, \
    { R06,   R05, R04, R03, R02, R01, R00 }, \
    { R16,   R15, R14, R13, R12, R11, R10 }, \
    { R25, R24, R23, R22, R21, R20,KC_NO }, \
    {  R32, R31,  R30, R35, R34, R33,KC_NO } \
  }


