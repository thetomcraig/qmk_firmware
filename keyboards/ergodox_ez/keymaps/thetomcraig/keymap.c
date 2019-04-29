#include QMK_KEYBOARD_H
#include "version.h"

#define BASE 0 // default layer
#define NAV  1 // navigation

enum custom_keycodes {
  EPRM = SAFE_RANGE,
  VRSN,
  RGB_SLD
};

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
/* Keymap 0: Basic layer */
[BASE] = LAYOUT_ergodox(
                                                                    /* left hand */
  /* top row */                             KC_ESC,   KC_1,    KC_2,     KC_3,    KC_4,    KC_5,    KC_6,
                                            KC_TAB,   KC_Q,    KC_W,     KC_E,    KC_R,    KC_T,
  /* index, large top key */                                                                        KC_A,
  /* home row */                            KC_BSPC,  KC_A,    KC_S,     KC_D,    KC_F,    KC_G,
                                            KC_LSFT,  KC_Z,    KC_X,     KC_C,    KC_V,    KC_B,
  /* index, large bottom key */                                                                     MO(1),
  /* bottom row */                          KC_LCTRL, KC_LALT, KC_LCTRL, KC_LALT, KC_LGUI,
  /* thumb, small top keys */                                                                       KC__VOLDOWN, KC__VOLUP,
  /* thumb, small middle key */                                                                                  RESET,
  /* thumb, big keys */                                                                  KC_SPC,    KC_BSPC,
  /* thumb, small bottom key */                                                                                  MO(2),

                                                  /* right hand */
                         MO(2),      KC_7,    KC_8,    KC_9,    KC_0,     KC_LBRACKET, KC_RBRACKET, /* top row */
                         KC_MINUS,                                                                  /* index, large top key */
                                     KC_Y,    KC_U,    KC_I,    KC_O,     KC_P,        KC_BSLS,     /* home row */
                                     KC_H,    KC_J,    KC_K,    KC_L,     KC_SCLN,     KC_QUOT,
                         KC_EQUAL,                                                                  /* index, large bottom key */
                                     KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,     KC_RSFT,
                                              KC_LGUI, KC_RALT, KC_RCTRL, KC_RALT,     KC_RCTRL,    /* bottom row */
        KC_MPLY, KC_BSPC,                                                                           /* thumb, small top keys */
                  RESET,                                                                            /* thumb, small middle key */
                  MO(2),                                                                            /* thumb, small bottom key */
                         KC_ENT,    KC_SPC                                                         /* thumb, big keys */
),
/* Keymap 1: Basic layer */
[NAV] = LAYOUT_ergodox(
                                                        /* left hand */
  /* top row */                  _______, _______, _______, _______, _______, _______, _______,
                                 KC_ENT,  _______, KC_UP,   _______, _______, _______,
  /* index, large top key */                                                           _______,
  /* home row */                 _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
                                 _______, _______, _______, _______, _______, _______,
  /* index, large bottom key */                                                        _______,
  /* bottom row */               _______, _______, _______, _______, _______,
  /* thumb, small top keys */                                                          KC_MRWD, KC_MFFD,
  /* thumb, small middle key */                                                                 _______,
  /* thumb, big keys */                                                       _______, _______,
  /* thumb, small bottom key */                                                                 _______,
                                  /* right hand */
            _______, _______, _______, _______, _______, _______, _______, /* top row */
            _______,                                                       /* index, large top key */
                     _______, _______, _______, _______, _______, _______, /* home row */
                     _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
            _______,                                                       /* index, large bottom key */
                     _______, _______, _______, _______, _______, _______,
                              _______, _______, _______, _______, _______, /* bottom row */
  _______,  _______,                                                       /* thumb, small top keys */
  _______,                                                                 /* thumb, small middle key */
  _______,                                                                 /* thumb, small bottom key */
            _______, _______                                              /* thumb, big keys */
),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case EPRM:
        eeconfig_init();
        return false;
      case VRSN:
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        return false;
      #ifdef RGBLIGHT_ENABLE
      case RGB_SLD:
        rgblight_mode(1);
        return false;
      #endif
    }
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
        #endif
        break;
      default:
        break;
    }

  return state;
};
