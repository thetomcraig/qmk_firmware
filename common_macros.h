// Common Macros used by my mechanical keyboards
// Keyboard keymaps can use these macros by including this .h file

#include QMK_KEYBOARD_H
#include "version.h"
#include "secrets.h"

#define DOX_BASE 0  
#define DOX_LYR1 1 
#define DOX_LYR2 2

#define KC_BRTU KC_BRMU
#define KC_BRTD KC_BRMD
#define KC_CAPS KC_CAPSLOCK
#define KC_L_BR KC_LBRACKET
#define KC_R_BR KC_RBRACKET
#define TX_SW_L TMUX_SWAP_L
#define TX_SW_R TMUX_SWAP_R

extern keymap_config_t keymap_config;

enum custom_keycodes {
  /********/
  /* IRIS */
  /********/
  IRIS_BASE = SAFE_RANGE,
  IRIS_LYR1,
  IRIS_LYR2,
  IRIS_LYR3,

  /***********/
  /* ERGODOX */
  /***********/
  EPRM,
  VRSN,
  RGB_SLD,

  /**********/
  /* NUMPAD */
  /**********/
  NP_COL,

  /*************/
  /* PASSWORDS */
  /*************/
  P_CMP,
  P_1PASS,
  P_OKTA,
  P_CP,
  P_LP,

  /***********/
  /* WINDOWS */
  /***********/
  // Move to left half of screen
  WIN_L,
  // Move to right half of screen
  WIN_R,
  // Move to top half of screen
  WIN_T,
  // Move to bottom half of screen
  WIN_B,
  // Move to top left quarter of screen
  WIN_TL,
  // Move to top right quarter of screen
  WIN_TR,
  // Move to bottom left quarter of screen
  WIN_BL, 
  // Move to bottom right quarter of screen
  WIN_BR,
  // Make full size
  WIN_F,
  // (Center) Make medium size and center on screen
  WIN_C,
  // Cycle to the next screen (left to right)
  WIN_CYC,

  /********/
  /* TMUX */
  /********/
  // Next window
  TMUX_N,
  // Previous window
  TMUX_P,
  // Create new window
  TMUX_C,
  // Cycle through panes
  TMUX_CYC,
  // Move window to the left
  TMUX_SWAP_L,
  // Move window to the right
  TMUX_SWAP_R,
  // Move to window number N
  TMUX_1,
  TMUX_2,
  TMUX_3,
  TMUX_4,
  TMUX_5,
  TMUX_6,
  TMUX_7,
  TMUX_8,
  TMUX_9,

  /********/
  /* BASH */
  /********/
  // Move cursor to previous word
  PRV_WD,
  // Move cursor to next word
  NXT_WD,
};


// This function enters passwords
// The strings are defined in a file NOT in VCS, called "secrets.h"
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

// This processes all other custom macros; they're keys defined above
bool process_custom_macro_keys(uint16_t keycode, keyrecord_t *record) {
  bool still_need_to_process = process_password_keys(keycode, record);
  if (still_need_to_process == false) {
    return false;
  }

  switch (keycode) {
    case NP_COL:
      if (record->event.pressed) {
        send_string(":");
      }
    case WIN_L:
      if (record->event.pressed) {
        send_string(SS_LCTRL(SS_LALT(SS_LGUI("m"))) "h");
        send_string(SS_TAP(X_ESCAPE));
      }
      break;
    case WIN_R:
      if (record->event.pressed) {
        send_string(SS_LCTRL(SS_LALT(SS_LGUI("m"))) "l");
        send_string(SS_TAP(X_ESCAPE));
      }
      break;
    case WIN_T:
      if (record->event.pressed) {
        send_string(SS_LCTRL(SS_LALT(SS_LGUI("m"))) "k");
        send_string(SS_TAP(X_ESCAPE));
      }
      break;
    case WIN_B:
      if (record->event.pressed) {
        send_string(SS_LCTRL(SS_LALT(SS_LGUI("m"))) "j");
        send_string(SS_TAP(X_ESCAPE));
      }
      break;
    case WIN_TL:
      if (record->event.pressed) {
        send_string(SS_LCTRL(SS_LALT(SS_LGUI("m"))) "kh");
        send_string(SS_TAP(X_ESCAPE));
      }
      break;
    case WIN_TR:
      if (record->event.pressed) {
        send_string(SS_LCTRL(SS_LALT(SS_LGUI("m"))) "kl");
        send_string(SS_TAP(X_ESCAPE));
      }
      break;
    case WIN_BL: 
      if (record->event.pressed) {
        send_string(SS_LCTRL(SS_LALT(SS_LGUI("m"))) "jh");
        send_string(SS_TAP(X_ESCAPE));
      }
      break;
    case WIN_BR:
      if (record->event.pressed) {
        send_string(SS_LCTRL(SS_LALT(SS_LGUI("m"))) "jl");
        send_string(SS_TAP(X_ESCAPE));
      }
      break;
    case WIN_F:
      if (record->event.pressed) {
        send_string(SS_LCTRL(SS_LALT(SS_LGUI("m"))) SS_TAP(X_SPACE)); 
        send_string(SS_TAP(X_ESCAPE));
      }
      break;
    case WIN_C:
      if (record->event.pressed) {
        send_string(SS_LCTRL(SS_LALT(SS_LGUI("v"))));
      }
      break;
    case WIN_CYC:
      if (record->event.pressed) {
        send_string(SS_LCTRL(SS_LALT(SS_LGUI("x"))));
      }
      break;
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
        send_string(SS_LCTRL("b")"s");
      }
      break;
    case TMUX_SWAP_L:
      if (record->event.pressed) {
        send_string(SS_LCTRL("b")"i");
      }
      break;
    case TMUX_SWAP_R:
      if (record->event.pressed) {
        send_string(SS_LCTRL("b")"o");
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
