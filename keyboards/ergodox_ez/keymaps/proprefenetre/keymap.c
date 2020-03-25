#include QMK_KEYBOARD_H
#include "action_layer.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MOVE 2 // arrow keys &c
#define MCRO 3 // predefined macros

enum keycodes {
  M_GMAIL =  SAFE_RANGE,
  M_BZK,
  M_DEF,
  M_ROV,
  M_DEAD_Q,
  M_DEAD_A,
  DYNAMIC_MACRO_RANGE,
};

#include "dynamic_macro.h"

enum {
  ESC_GRAVE,
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  [ESC_GRAVE] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_GRAVE),
};

// keymaps
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_ergodox(

        // left hand
        /* TD(ESC_GRAVE),     KC_1,     KC_2,     KC_3,     KC_4,    KC_5,  KC_NO, */
        KC_GESC,     KC_1,     KC_2,     KC_3,     KC_4,    KC_5,  KC_NO,
        KC_TAB,      KC_QUOT,  KC_COMM,  KC_DOT,   KC_P,    KC_Y,  TG(MOVE),
        KC_LCTL,     KC_A,     KC_O,     KC_E,     KC_U,    KC_I,
        KC_LSFT,     KC_SCLN,  KC_Q,     KC_J,     KC_K,    KC_X,  MO(MCRO),
        MO(MOVE),    KC_NO,    KC_LGUI,  KC_LALT,  KC_SPC,

        // thumbs
        KC_LALT,  KC_DEL,
        KC_HOME,
        LT(SYMB,KC_BSPC),  KC_RCTL,  KC_END,

        // right hand
        KC_NO,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,    KC_EQL,
        TG(SYMB),   KC_F,     KC_G,     KC_C,     KC_R,     KC_L,    KC_SLSH,
                    KC_D,     KC_H,     KC_T,     KC_N,     KC_S,    KC_MINS,
        MO(MCRO),   KC_B,     KC_M,     KC_W,     KC_V,     KC_Z,    KC_RSFT,
                              KC_NO,    KC_RALT,  KC_RGUI,  KC_NO,   MO(SYMB),

        // thumbs
        KC_DEL,            CTL_T(KC_ESC),
        KC_PGUP,
        KC_PGDN,  KC_TAB,  LT(SYMB,KC_ENT)
        ),

    [SYMB] = LAYOUT_ergodox(

        // left hand
        KC_GRV,   KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,  _______,
        M_DEAD_Q,  M_DEAD_A,  _______,  KC_LCBR,  KC_RCBR,  KC_PIPE,  _______,
        _______,  _______,  _______,  KC_LPRN,  KC_RPRN,  KC_GRV,
        _______,  _______,  _______,  KC_LBRC,  KC_RBRC,  KC_TILD,  _______,
        _______,  _______,  _______,  _______,  _______,

        // thums
        _______,  _______,
        _______,
        _______,  _______,  _______,

        // right hand
        KC_CIRC,  KC_AMPR,  KC_ASTR,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  KC_LBRC,  KC_RBRC,  KC_EQL,   KC_BSLS,
        _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,

        // thumbs
        _______,  _______,
        _______,
        _______,  _______,  _______
                            ),

    [MOVE] = LAYOUT_ergodox(

        // left hand
        _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,

                                                // thumbs
                                                            _______,  _______,
                                                                      _______,
                                            KC_LCTL,  LSFT(KC_LCTL),  _______,
        // right hand
        KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,  _______,
        _______,  _______, _______,  _______,  _______,  _______,  _______,
                  KC_LEFT, KC_DOWN,  KC_UP,    KC_RIGHT, KC_DEL,   _______,
        RESET,    _______, _______,  _______,  _______,  _______,  _______,
                           _______,  _______,  _______,  _______,  _______,

        // thumbs
        _______,  _______,
        _______,
        _______,  _______,  _______
    ),

    [MCRO] = LAYOUT_ergodox(

        // left hand
        _______,  M_GMAIL,  M_BZK,    M_DEF,    M_ROV,    _______,  DYN_REC_START1,
        _______,  _______,  _______,  _______,  _______,  _______,  DYN_MACRO_PLAY1,
        _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,

        // thumbs
        _______,  _______,
        _______,
        _______,  _______,  _______,

        // right hand
        DYN_REC_START2,   _______,  _______,  _______,  _______,  _______,  _______,
        DYN_MACRO_PLAY2,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,          _______,  _______,  _______,  _______,  _______,
        _______,          _______,  _______,  _______,  _______,  _______,  _______,
        _______,          _______,  _______,  _______,  _______,

        // thumbs
        _______,  _______,
        _______,
        _______,  _______,  _______
    ),
};

// Macros
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  uint16_t macro_kc = (keycode == MO(MCRO) ? DYN_REC_STOP : keycode);
  if (!process_record_dynamic_macro(macro_kc, record)) {
        return false;
  }
  switch (keycode) {
  case M_DEAD_Q:
    if (record->event.pressed) {
      SEND_STRING("\"" SS_TAP(X_SPACE));
    } else {
      // when keycode is released
    }
    break;
  case M_DEAD_A:
    if (record->event.pressed) {
      SEND_STRING("\'" SS_TAP(X_SPACE));
    } else {
      // when keycode is released
    }
    break;
  case M_GMAIL:
    if (record->event.pressed) {
      // when keycode is pressed
      SEND_STRING("nielseigenraam@gmail.com");
    } else {
      // when keycode is released
    }
    break;
  case M_BZK:
    if (record->event.pressed) {
      SEND_STRING("niels.eigenraam@minbzk.nl");
    } else {
    }
    break;
  case M_DEF:
    if (record->event.pressed) {
      SEND_STRING("c.eigenraam@mindef.nl");
    } else {
    }
    break;
  case M_ROV:
    if (record->event.pressed) {
      SEND_STRING("niels.eigenraam@rijksoverheid.nl");
    } else {
    }
    break;
  default:
    break;
  }
  return true;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

void keyboard_post_init_user(void) {
#ifdef LED_BRIGHTNESS_LO
  ergodox_led_all_set(LED_BRIGHTNESS_LO);
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
        break;
      case 1:
        ergodox_right_led_1_on();
        break;
      case 2:
        ergodox_right_led_2_on();
        break;
      case 3:
        ergodox_right_led_3_on();
        break;
      default:
        break;
    }
  return state;
};
