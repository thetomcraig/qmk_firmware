#include QMK_KEYBOARD_H
#include "version.h"
#include "secrets.h"

#define BASE 0  // default layer
#define LYR1 1  // symbols
#define LYR2 2  // numpad

enum custom_keycodes {
  TMUX_N = SAFE_RANGE,
  TMUX_P,
  TMUX_C,
  TMUX_CYC,
  PRV_WD,
  NXT_WD,
  EPRM,
  VRSN,
  RGB_SLD,
  P_CMP,
  P_1PASS,
  P_OKTA,
  P_CP,
  P_LP,
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

// This is only for my custom macros
// Called by the general "process_record_user"
bool process_custom_macro_keys(uint16_t keycode, keyrecord_t *record) {
  // First call helper function to process if it's a password macro
  bool still_need_to_process = process_password_keys(keycode, record);
  if (still_need_to_process == false) {
    return false;
  }
  // Not a password macro; move on
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
    case NXT_WD:
      if (record->event.pressed) {
        send_string(SS_LALT("x"));
      }
      break;
    case PRV_WD:
      if (record->event.pressed) {
        send_string(SS_LALT("a"));
      }
      break;
  }
  return true;
}
/*

                                                       left hand
   top row                   _______, _______, _______, _______, _______, _______, _______,
                             _______, _______, _______, _______, _______, _______,
   index, large top key                                                            _______,
   home row                  _______, _______, _______, _______, _______, _______,
                             _______, _______, _______, _______, _______, _______,
   index, large bottom key                                                         _______,
   bottom row                _______, _______, _______, _______, _______,
   thumb, small top keys                                                           _______, _______,
   thumb, small middle key                                                                  _______,
   thumb, big keys                                                        _______, _______,
   thumb, small bottom key                                                                  _______,
                                      right hand
            _______, _______, _______, _______, _______, _______, _______,  top row
            _______,                                                        index, large top key
                     _______, _______, _______, _______, _______, _______,  home row
                     _______, _______, _______, _______, _______, _______,
            _______,                                                        index, large bottom key
                     _______, _______, _______, _______, _______, _______,
                              _______, _______, _______, _______, _______,  bottom row
  _______,  _______,                                                        thumb, small top keys
  _______,                                                                  thumb, small middle key
  _______,                                                                  thumb, small bottom key
            _______, _______,                                               thumb, big keys

*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/************************/
/* LAYER 0: BASIC LAYER */
/************************/
[BASE] = LAYOUT_ergodox(
                                                           /* left hand */
  /* top row */                   KC_ESC,   KC_1,    KC_2,     KC_3,    KC_4,      KC_5,    KC_GRV,
                                  KC_TAB,   KC_Q,    KC_W,     KC_E,    KC_R,      KC_T,
  /* index, large top key */                                                                MO(1),
  /* home row */                  MO(1),    KC_A,    KC_S,     KC_D,    KC_F,      KC_G,
                                  KC_LSFT,  KC_Z,    KC_X,     KC_C,    KC_V,      KC_B,
  /* index, large bottom key */                                                             MO(2),
  /* bottom row */                KC_LCTRL, _______,  _______, KC_LALT, KC_LGUI,
  /* thumb, small top keys */                                                               KC_ENT,  _______,
  /* thumb, small middle key */                                                                      KC_CAPSLOCK,
  /* thumb, big keys */                                                           KC_SPC,   KC_BSPC,
  /* thumb, small bottom key */                                                                      MO(1),

                                                                            /* right hand */
  /* top row */                                       KC_6,    KC_7,    KC_8,     KC_9,    KC_0,        KC_LBRACKET, KC_RBRACKET,
  /* index, large top key */                          KC_MINUS,
                                                               KC_Y,    KC_U,    KC_I,     KC_O,        KC_P,        KC_BSLS,
  /* home row */                                               KC_H,    KC_J,    KC_K,     KC_L,        KC_SCLN,     KC_QUOT,
  /* index, large bottom key */                       KC_EQUAL,
                                                               KC_N,    KC_M,    KC_COMM,  KC_DOT,      KC_SLSH,     KC_RSFT,
  /* bottom row */                                                      KC_RGUI, KC_RALT,  _______,     _______,     KC_RCTRL,
  /* thumb, small top keys */             KC_DEL,     KC_BSPC,
  /* thumb, small middle key */           KC_CAPSLOCK,
  /* thumb, small bottom key */           MO(1),
  /* thumb, big keys */                               KC_ENT,  KC_SPC
),

/*****************************/
/* LAYER 1: NAVIGATION LAYER */
/*****************************/
[LYR1] = LAYOUT_ergodox(
                                                        /* left hand */
  /* top row */                  KC_GRV,  _______, _______, _______, _______, _______, _______,
                                 KC_ENT,  _______, KC_UP,   _______, _______, _______,
  /* index, large top key */                                                           _______,
  /* home row */                 _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
                                 _______, _______, _______, _______, _______, _______,
  /* index, large bottom key */                                                        _______,
  /* bottom row */               _______, _______, _______, _______, _______,
  /* thumb, small top keys */                                                          _______, _______,
  /* thumb, small middle key */                                                                 RESET,
  /* thumb, big keys */                                                       _______, KC_DEL,
  /* thumb, small bottom key */                                                                 _______,

                                                                           /* right hand */
  /* top row */                                     _______, _______, _______, _______, _______, _______,     _______,
  /* index, large top key */                        _______,
                                                             TMUX_C,  TMUX_CYC,PRV_WD,  NXT_WD,  TMUX_P,      _______,
  /* home row */                                             KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,     _______,
  /* index, large bottom key */                     _______,
                                                             TMUX_N,  _______, _______, _______, _______,     _______,
  /* bottom row */                                                    KC_MRWD, KC_MPLY, KC_MFFD, KC__VOLDOWN, KC__VOLUP,
  /* thumb, small top keys */             _______,  KC_DEL,
  /* thumb, small middle key */           RESET,
  /* thumb, small bottom key */           _______,
  /* thumb, big keys */                             _______, _______
),
/*************************/
/* LAYER 2: NUMPAD LAYER */
/*************************/
[LYR2] = LAYOUT_ergodox(
                                                        /* left hand */
  /* top row */                  _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______,
  /* index, large top key */                                                           _______,
  /* home row */                 _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______,
  /* index, large bottom key */                                                        _______,
  /* bottom row */               P_CMP,   P_1PASS, P_OKTA,  P_CP,    P_LP,
  /* thumb, small top keys */                                                          _______, _______,
  /* thumb, small middle key */                                                                 _______,
  /* thumb, big keys */                                                       _______, _______,
  /* thumb, small bottom key */                                                                 _______,

                                                                           /* right hand */
  /* top row */                                     _______, _______, KC_ESC,  KC_PSLS, KC_PAST, KC_PMNS,  _______,
  /* index, large top key */                        _______,
                                                             _______, KC_7,    KC_8,    KC_9,    KC_PPLS,  _______,
  /* home row */                                             _______, KC_4,    KC_5,    KC_6,    KC_PPLS,  _______,
  /* index, large bottom key */                     _______,
                                                             _______, KC_1,    KC_2,    KC_3,    KC_PENT,  _______,
  /* bottom row */                                                    KC_0,    KC_PDOT, KC_PENT, KC_PENT,  _______,
  /* thumb, small top keys */             _______,  _______,
  /* thumb, small middle key */           _______,
  /* thumb, small bottom key */           _______,
  /* thumb, big keys */                             _______, _______
),
};
