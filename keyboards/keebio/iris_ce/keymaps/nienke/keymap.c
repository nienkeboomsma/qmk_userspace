// Copyright 2023 Danny Nguyen (@nooges)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum custom_layers {
   _ALP,
   _LFT,
   _RGT,
   _NAV,
   _NUM,
   _MSE
};

// Tap dance declarations
enum {
   JK,
};

// Tap once for KC_J, twice for KC_J and KC_K
void jk(tap_dance_state_t *state, void *user_data) {
   if (state->count == 1) {
      tap_code(KC_K);
   }

   if (state->count == 2) {
      tap_code(KC_K);
      reset_tap_dance(state);
   }
}

// Tap dance definitions
tap_dance_action_t tap_dance_actions[] = {
    [JK] = ACTION_TAP_DANCE_FN_ADVANCED(jk, NULL, NULL),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_ALP] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                               TD(JK),  KC_L,    KC_U,    KC_Y,    KC_SLSH, KC_SCLN,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                               KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_RSFT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_GRAVE,LSFT_T(KC_Z),LCTL_T(KC_X),LALT_T(KC_C),LGUI_T(KC_D),KC_V,_______,

                                                         _______,KC_K,RGUI_T(KC_H),RALT_T(KC_COMM),RCTL_T(KC_DOT),RSFT_T(KC_QUOT),KC_BSLS,
  //└────────┴────────┴────┬───┴────┬───┴────────┴─┬──────┴───────┬┘        └┬───────┴──────┬─┴────────┴───┬────┴───┬────┴────────┴────────┘
                            TT(2),   LT(3, KC_ENT), LT(4, KC_TAB),            KC_BSPC,       LT(5, KC_SPC), TT(1)
  //                       └────────┴──────────────┴──────────────┘          └──────────────┴──────────────┴────────┘
  ),

  [_LFT] = LAYOUT(                                                                 
  // Activated with the right hand
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_HASH, KC_AT,   KC_AMPR, KC_PIPE, KC_PERC,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_ASTR, KC_PLUS, KC_MINS, KC_EQL,  KC_DLR,  KC_GRV,                             _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_EXLM, KC_LABK, KC_SLSH, KC_RABK, QK_REP,  _______,          QK_BOOT, _______, KC_RGUI, KC_RALT, KC_RCTL, KC_RSFT, _______,
  //└────────┴────────┴────┬───┴────┬───┴────────┴─┬──────┴───────┬┘        └┬───────┴──────┬─┴────────┴───┬────┴───┬────┴────────┴────────┘
                            _______, KC_ENT,        KC_TAB,                   KC_BSPC,       KC_SPC,        _______
  //                       └────────┴──────────────┴──────────────┘          └──────────────┴──────────────┴────────┘
  ),

  [_RGT] = LAYOUT(                                                                   // Activated with the left hand
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            KC_CIRC, KC_UNDS, KC_COLN, KC_QUES, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            KC_SCLN, KC_LPRN, KC_LCBR, KC_LBRC, KC_DQUO, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _______, QK_BOOT,          _______, QK_REP,  KC_RPRN, KC_RCBR, KC_RBRC, KC_TILD, _______,
  //└────────┴────────┴────┬───┴────┬───┴────────┴─┬──────┴───────┬┘        └┬───────┴──────┬─┴────────┴───┬────┴───┬────┴────────┴────────┘
                            _______, KC_ENT,        KC_TAB,                   KC_BSPC,       KC_SPC,        _______
  //                       └────────┴──────────────┴──────────────┘          └──────────────┴──────────────┴────────┘
  ),

  [_NAV] = LAYOUT(                                                                 // Activated with the left hand
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            KC_COPY, KC_PGUP, KC_UP,   _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            KC_CUT,  KC_LEFT, KC_DOWN, KC_RGHT, KC_PSTE, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _______, _______,          _______, _______, KC_HOME, KC_PGDN, KC_END,  KC_UNDO, _______,
  //└────────┴────────┴────┬───┴────┬───┴────────┴─┬──────┴───────┬┘        └┬───────┴──────┬─┴────────┴───┬────┴───┬────┴────────┴────────┘
                            _______, _______,       KC_TAB,                   KC_BSPC,       KC_SPC,        _______
  //                       └────────┴──────────────┴──────────────┘          └──────────────┴──────────────┴────────┘
  ),

  [_NUM] = LAYOUT(                                                               // Activated with the left hand
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            KC_MINS, KC_7,    KC_8,    KC_9,    KC_ASTR, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            KC_PLUS, KC_4,    KC_5,    KC_6,    KC_EQL,  _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _______, _______,          _______, KC_SLSH,  KC_1,    KC_2,    KC_3,   KC_DOT,  _______,
  //└────────┴────────┴────┬───┴────┬───┴────────┴─┬──────┴───────┬┘        └┬───────┴──────┬─┴────────┴───┬────┴───┬────┴────────┴────────┘
                            _______, KC_ENT,        _______,                  KC_BSPC,       KC_SPC,        KC_0
  //                       └────────┴──────────────┴──────────────┘          └──────────────┴──────────────┴────────┘
  ),

  [_MSE] = LAYOUT( 
  // Activated with the right hand
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, MS_WHLD, MS_WHLU, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, MS_BTN2, MS_LEFT, MS_DOWN, MS_RGHT, _______,                            _______, MS_BTN1, MS_BTN2, MS_ACL0, MS_ACL1, MS_ACL2,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, MS_BTN1, MS_WHLR, MS_UP,   MS_WHLL, _______, _______,          _______, _______, KC_RGUI, KC_RALT, KC_RCTL, KC_RSFT, _______,
  //└────────┴────────┴────┬───┴────┬───┴────────┴─┬──────┴───────┬┘        └┬───────┴──────┬─┴────────┴───┬────┴───┬────┴────────┴────────┘
                            _______, KC_ENT,        KC_TAB,                   KC_BSPC,       _______,       _______
  //                       └────────┴──────────────┴──────────────┘          └──────────────┴──────────────┴────────┘
  ),
};

// Achordion
// DOCS: https://getreuer.info/posts/keyboards/achordion/index.html#achordion_eager_mod
#include "achordion/achordion.h"

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (!process_achordion(keycode, record)) { return false; }
  
  // Any future macros go here

  return true;
}

void matrix_scan_user(void) {
  achordion_task();
}

bool achordion_eager_mod(uint8_t mod) {
  switch (mod) {
    case MOD_LSFT:
    case MOD_RSFT:
    case MOD_LCTL:
    case MOD_RCTL:
      return true;  // Eagerly apply Shift and Ctrl mods.

    default:
      return false;
  }
}
