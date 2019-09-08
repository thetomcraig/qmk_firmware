#include QMK_KEYBOARD_H
#include "secrets.h"

extern keymap_config_t keymap_config;

#define _BASE 0  // default layer
#define _LYR1 1  // symbols
#define _LYR2 2  // numpad
#define _LYR3 3

enum custom_keycodes {
  BASE = SAFE_RANGE,
  LYR1,
  LYR2,
  LYR3,

  TMUX_N,
  TMUX_P,
  TMUX_C,
  TMUX_CYC,
  TMUX_SWAP_L,
  TMUX_SWAP_R,
  TMUX_1,
  TMUX_2,
  TMUX_3,
  TMUX_4,
  TMUX_5,
  TMUX_6,
  TMUX_7,
  TMUX_8,
  TMUX_9,
  PRV_WD,
  NXT_WD,
  NP_COL,
  P_CMP,
  P_1PASS,
  P_OKTA,
  P_CP,
  P_LP,
  EPRM,
  VRSN,
  RGB_SLD,
};




// This is only for passwords
// These string edfined in a file NOT in VCS
bool process_password_keys(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case P_CMP:
      if (record->event.pressed) {
        send_string(computer_password);
        send_string(SS_TAP(X_ENTER));
      }
      break;
    case P_1PASS:
      if (record->event.pressed) {
        send_string(one_pass_password);
        send_string(SS_TAP(X_ENTER));
      }
      break;
    case P_OKTA:
      if (record->event.pressed) {
        send_string(okta_password);
        send_string(SS_TAP(X_ENTER));
      }
      break;
    case P_CP:
      if (record->event.pressed) {
        send_string(coachportal_password);
        send_string(SS_TAP(X_ENTER));
      }
      break;
    case P_LP:
      if (record->event.pressed) {
        send_string(last_pass_password);
        send_string(SS_TAP(X_ENTER));
      }
      break;
  }
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  bool still_need_to_process = process_password_keys(keycode, record);
  if (still_need_to_process == false) {
    return false;
  }

  switch (keycode) {
    case BASE:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_BASE);
      }
      return false;
      break;
    case LYR1:
      if (record->event.pressed) {
        layer_on(_LYR1);
        update_tri_layer(_LYR1, _LYR2, _LYR3);
      } else {
        layer_off(_LYR1);
        update_tri_layer(_LYR1, _LYR2, _LYR3);
      }
      return false;
      break;
    case LYR2:
      if (record->event.pressed) {
        layer_on(_LYR2);
        update_tri_layer(_LYR1, _LYR2, _LYR3);
      } else {
        layer_off(_LYR2);
        update_tri_layer(_LYR1, _LYR2, _LYR3);
      }
      return false;
      break;
    case LYR3:
      if (record->event.pressed) {
        layer_on(_LYR3);
      } else {
        layer_off(_LYR3);
      }
      return false;
      break;
    case NP_COL:
      if (record->event.pressed) {
        send_string(":");
      }
    case TMUX_N:
      if (record->event.pressed) {
        send_string(SS_LCTRL("b")"n");
      }
      break;
    case TMUX_P:
      if (record->event.pressed) {
        send_string(SS_LCTRL("b")"p");
      }
      break;
    case TMUX_C:
      if (record->event.pressed) {
        send_string(SS_LCTRL("b")"c");
      }
      break;
    case TMUX_CYC:
      if (record->event.pressed) {
        send_string(SS_LCTRL("f"));
      }
      break;
    case TMUX_SWAP_L:
      if (record->event.pressed) {
        send_string(SS_LCTRL("["));
      }
      break;
    case TMUX_SWAP_R:
      if (record->event.pressed) {
        send_string(SS_LCTRL("]"));
      }
      break;
    case TMUX_1:
      if (record->event.pressed) {
        send_string(SS_LCTRL("1"));
      }
      break;
    case TMUX_2:
      if (record->event.pressed) {
        send_string(SS_LCTRL("2"));
      }
      break;
    case TMUX_3:
      if (record->event.pressed) {
        send_string(SS_LCTRL("3"));
      }
      break;
    case TMUX_4:
      if (record->event.pressed) {
        send_string(SS_LCTRL("4"));
      }
      break;
    case TMUX_5:
      if (record->event.pressed) {
        send_string(SS_LCTRL("5"));
      }
      break;
    case TMUX_6:
      if (record->event.pressed) {
        send_string(SS_LCTRL("6"));
      }
      break;
    case TMUX_7:
      if (record->event.pressed) {
        send_string(SS_LCTRL("7"));
      }
      break;
    case TMUX_8:
      if (record->event.pressed) {
        send_string(SS_LCTRL("8"));
      }
      break;
    case TMUX_9:
      if (record->event.pressed) {
        send_string(SS_LCTRL("9"));
      }
      break;
    case NXT_WD:
      if (record->event.pressed) {
        send_string(SS_DOWN(X_LALT) SS_DOWN(X_RIGHT));
      }
      else {
        send_string(SS_UP(X_RIGHT) SS_UP(X_LALT));
      }
      break;
    case PRV_WD:
      if (record->event.pressed) {
        send_string(SS_DOWN(X_LALT) SS_DOWN(X_LEFT));
      }
      else {
        send_string(SS_UP(X_LEFT) SS_UP(X_LALT));
      }
      break;
  }
  return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    LYR1,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     LYR1,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LGUI,          KC_RGUI,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LCTL, KC_BSPC, KC_SPC,                    KC_SPC,   KC_ENT,  KC_RALT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_LYR1] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_TILD, TMUX_1,  TMUX_2,  TMUX_3,  TMUX_4,  TMUX_5,                             TMUX_6,  TMUX_7,  TMUX_8,  TMUX_9,  _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_ENT,  _______, KC_UP,   _______, _______, _______,                            TMUX_C,  TMUX_CYC,PRV_WD,  NXT_WD,  TMUX_P,  _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,                            KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, RESET,             RESET,  TMUX_N,  KC_MRWD, KC_MPLY, KC_MFFD, KC__VOLDOWN, KC__VOLUP,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, KC_DEL,  _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_LYR2] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_LYR3] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};
