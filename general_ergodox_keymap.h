#include QMK_KEYBOARD_H
#include "common_macros.h"

#define DOX_BASE 0  // default layer
#define DOX_LYR1 1  // symbols
#define DOX_LYR2 2  // numpad

#define KC_BRTU KC_BRMD
#define KC_BRTD KC_BRMU
#define KC_CAPS KC_CAPSLOCK
#define KC_L_BR KC_LBRACKET
#define KC_R_BR KC_RBRACKET
#define TX_SW_L TMUX_SWAP_L
#define TX_SW_R TMUX_SWAP_R


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* LAYER 0: BASIC LAYER */
  [DOX_BASE] = LAYOUT_ergodox(
                                    /* left hand */
    /* top row */                   KC_ESC,      KC_1,       KC_2,        KC_3,      KC_4,      KC_5,      KC_GRV,
                                    KC_TAB,      KC_Q,       KC_W,        KC_E,      KC_R,      KC_T,
    /* index, large top key */                                                                             MO(2),
    /* home row */                  MO(1),       KC_A,       KC_S,        KC_D,      KC_F,      KC_G,
                                    KC_LSFT,     KC_Z,       KC_X,        KC_C,      KC_V,      KC_B,
    /* index, large bottom key */                                                                          MO(2),
    /* bottom row */                KC_LCTRL,    KC_LALT,    KC_CAPS,     KC_LALT,   KC_LGUI,
    /* thumb, small top keys */                                                                                              KC_ENT,   KC_ENT,
    /* thumb, small middle key */                                                                                                      _______,
    /* thumb, big keys */                                                                                          KC_SPC,   KC_BSPC,
    /* thumb, small bottom key */                                                                                                      _______,


                                    /* right hand */
    /* top row */                                               KC_6,       KC_7,     KC_8,        KC_9,         KC_0,        KC_L_BR,     KC_R_BR,
    /* index, large top key */                                  KC_MINUS,
                                                                            KC_Y,     KC_U,        KC_I,         KC_O,        KC_P,        KC_BSLS,
    /* home row */                                                          KC_H,     KC_J,        KC_K,         KC_L,        KC_SCLN,     KC_QUOT,
    /* index, large bottom key */                               KC_EQUAL,
                                                                            KC_N,     KC_M,        KC_COMM,      KC_DOT,      KC_SLSH,     KC_RSFT,
    /* bottom row */                                                                  KC_RGUI,     KC_RALT,      KC_GRV,      KC_RALT,     KC_RCTRL,
    /* thumb, small top keys */     KC_BSPC,    KC_BSPC,
    /* thumb, small middle key */   _______,
    /* thumb, small bottom key */   _______,
    /* thumb, big keys */                       KC_ENT,  KC_SPC
  ),

  /* LAYER 1: NAVIGATION LAYER */
  [DOX_LYR1] = LAYOUT_ergodox(
                                   /* left hand */
    /* top row */                  KC_GRV,  TMUX_1,  TMUX_2,  TMUX_3,  TMUX_4,    TMUX_5,  _______,
                                   _______, WIN_TL,  WIN_T,   WIN_TR,  _______,   _______,
    /* index, large top key */                                                             _______,
    /* home row */                 _______, WIN_L,   WIN_B,   WIN_R,   WIN_F,     _______,
                                   _______, WIN_BL,  WIN_CYC, WIN_BR,  WIN_C,     _______,
    /* index, large bottom key */                                                          _______,
    /* bottom row */               P_CMP,   P_1PASS, P_OKTA,  P_CP,    P_LP,

    /* thumb, small top keys */                                                                              RESET,   RESET,
    /* thumb, small middle key */                                                                                     RESET,
    /* thumb, big keys */                                                                           _______, KC_DEL,
    /* thumb, small bottom key */                                                                                     RESET,

                                  /* right hand */
    /* top row */                                                    TMUX_6,  TMUX_7,  TMUX_8,   TMUX_9,  _______, KC_BRTD, KC_BRTU,
    /* index, large top key */                                       _______,
                                                                              TMUX_C,  TMUX_CYC, PRV_WD,  NXT_WD,  TMUX_P,  _______,
    /* home row */                                                            KC_LEFT, KC_DOWN,  KC_UP,   KC_RGHT, _______, _______,
    /* index, large bottom key */                                    _______,
                                                                              TMUX_N,  _______,  TX_SW_L, TX_SW_R, _______, _______,
    /* bottom row */                                                                   KC_MRWD,  KC_MPLY, KC_MFFD, KC_VOLD, KC_VOLU,
    /* thumb, small top keys */             KC_DEL, KC_DEL,
    /* thumb, small middle key */           RESET,
    /* thumb, small bottom key */           RESET,
    /* thumb, big keys */                           _______, _______
  ),
};
