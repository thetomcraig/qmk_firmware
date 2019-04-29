#include QMK_KEYBOARD_H
#include "version.h"

#define BASE 0 // default layer
#define NAV 1 // symbols

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
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

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
        case 1:
        if (record->event.pressed) { // For resetting EEPROM
          eeconfig_init();
        }
        break;
      }
    return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};
