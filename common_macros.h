#include QMK_KEYBOARD_H
#include "secrets.h"

extern keymap_config_t keymap_config;


enum custom_keycodes {
  // iris
  BASE = SAFE_RANGE,
  LYR1,
  LYR2,
  LYR3,
  // ergodox
  EPRM,
  VRSN,
  RGB_SLD,

  // passwords
  P_CMP,
  P_1PASS,
  P_OKTA,
  P_CP,
  P_LP,

  // tmux
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

// This is for my custom macros; keyboard agnostic
bool process_custom_macro_keys(uint16_t keycode, keyrecord_t *record) {
  bool still_need_to_process = process_password_keys(keycode, record);
  if (still_need_to_process == false) {
    return false;
  }

  switch (keycode) {
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
