// Copyright 2021 Joric (@joric)
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

enum layers {
    _QWERTY = 0,
    _LOWER = 1,
    _RAISE = 2,
    _ADJUST= 3,
    _NUMBER,
};


enum custom_keycodes {
    RGBRST = SAFE_RANGE
};

#define RBR_RGU MT(MOD_RGUI, KC_RBRC)
#define F12_RGU MT(MOD_RGUI, KC_F12)
#define PLS_LCT MT(MOD_LCTL, KC_PPLS)
#define EQL_LCT MT(MOD_LCTL, KC_PEQL)
#define APP_LCT MT(MOD_LCTL, KC_APP)
#define EQL_RCT MT(MOD_RCTL, KC_PEQL)
#define QUO_RCT MT(MOD_RCTL, KC_QUOT)
#define APP_RCT MT(MOD_RCTL, KC_APP)
#define MIN_RCT MT(MOD_RCTL, KC_MINS)
#define EQL_LAL MT(MOD_LALT, KC_EQL)
#define BSL_RAL MT(MOD_RALT, KC_BSLS)
#define BSP_LSH MT(MOD_LSFT, KC_BSPC)
#define SPC_RSH MT(MOD_RSFT, KC_SPC)
#define DEL_RSE LT(_RAISE, KC_DEL)
#define TAB_RSE LT(_RAISE, KC_TAB)
#define ENT_LWR LT(_LOWER, KC_ENT)
#define ESC_LWR LT(_LOWER, KC_ESC)
#define ESC_ADJ LT(_ADJUST, KC_ESC)

#define SFT_ADJ LT(_ADJUST, KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT(
           KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,BSL_RAL,                           KC_RBRC,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
           KC_RALT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,KC_MINS,                           KC_EQL,   KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, RCTL_T(KC_QUOT),
           KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,MO(_NUMBER),  ENT_LWR,         ENT_LWR,ESC_ADJ,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_GRV,
                                      MO(_NUMBER), KC_LSFT,      KC_SPC,      DEL_RSE,      MO(_NUMBER), BSP_LSH,    ENT_LWR, KC_LGUI
),

[_LOWER] = LAYOUT(
           KC_UNDS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,  KC_LGUI,                            _______,KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
           PLS_LCT, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,KC_LPRN,                            KC_RPRN,KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, MIN_RCT,
           EQL_LAL, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   _______,_______,            _______,_______,KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
                                      _______, _______, _______,_______,            _______,_______, _______, _______
),

[_RAISE] = LAYOUT(
           KC_NLCK, KC_PSLS, KC_HOME, KC_UP,   KC_END,   KC_PGUP,_______,                        _______,KC_VOLU, KC_HOME, KC_PSCR, KC_PGUP, KC_SLCK, KC_CAPS,
           EQL_LCT, KC_PAST, KC_LEFT, KC_DOWN, KC_RGHT,   KC_PGDN,_______,                        _______,KC_MUTE, KC_LEFT, KC_UP,   KC_RGHT, KC_INS,  APP_RCT,
           _______,KC_1,    KC_2,    KC_3,    KC_4,    KC_5, _______,_______,        _______,_______,KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,
                                      _______, _______, _______,_______,                _______,_______, _______, _______
),

[_ADJUST] = LAYOUT(
KC_NLCK, KC_PSLS, KC_HOME, KC_UP,   KC_END,   KC_PGUP,_______,                        _______,KC_VOLU, KC_HOME, KC_PSCR, KC_PGUP, KC_SLCK, KC_CAPS,
           EQL_LCT, KC_PAST, KC_LEFT, KC_DOWN, KC_RGHT,   KC_PGDN,_______,                        _______,KC_MUTE, KC_LEFT, KC_UP,   KC_RGHT, KC_INS,  APP_RCT,
           _______,KC_1,    KC_2,    KC_3,    KC_4,    KC_5, KC_TRNS,KC_TRNS,        _______,_______,KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,
                                      _______, _______, _______,_______,                _______,_______, _______, _______
),
[_NUMBER] = LAYOUT(
           _______,KC_1,    KC_2,    KC_3,    KC_4,    KC_5, _______,                 _______,KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,
          RGB_TOG, KC_PAST, KC_4, KC_5, KC_6, KC_PPLS,_______,                        _______,_______, _______, RGB_VAI, RGB_SAI, RGB_HUI, RGB_TOG,
           RGB_MOD, KC_0, KC_1, KC_2, KC_3, KC_PCMM,   _______,_______,        _______,_______,_______, _______, RGB_VAD, RGB_SAD, RGB_HUD, RGB_MOD,
                                      _______, SH_TG,  _______,_______,        _______,_______, SH_TG,   _______
),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
        }
      #endif
      break;
  }
  return true;
}

