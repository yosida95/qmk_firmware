// Netable differences vs. the default firmware for the ErgoDox EZ:
// 1. The Cmd key is now on the right side, making Cmd+Space easier.
// 2. The media keys work on OSX (But not on Windows).
#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | `      |   1  |   2  |   3  |   4  |   5  | ESC  |           | ESC  |   6  |   7  |   8  |   9  |   0  |   =    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |LAlt +|           |LGUI +|   Y  |   U  |   I  |   O  |   P  |  -/L1  |
 * |--------+------+------+------+------+------| Space|           | Space|------+------+------+------+------+--------|
 * | LCtrl  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
 * |--------+------+------+------+------+------| LGUI |           | RGUI |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  |\/RShift|
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | LALT |[Mute]|[Vol-]|[Vol+]|[Play]|                                       | Left | Down |  Up  | Right| `/RALT|
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.         ,-------------.
 *                                        | Prev | Next |         | HOME |  END |
 *                                 ,------|------|------|         |------+------+------.
 *                                 |      |      | PgUp |         | PgDn |      |      |
 *                                 | Space| Enter|------|         |------| Back | Space|
 *                                 |      |      |  [   |         |  ]   | Space|      |
 *                                 `--------------------'         `--------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_GRV,  KC_1,   KC_2,   KC_3,   KC_4,   KC_5,KC_ESC,
        KC_TAB,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,LALT(KC_SPACE),
        KC_LCTRL,KC_A,   KC_S,   KC_D,   KC_F,   KC_G,
        KC_LSFT, KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,KC_LGUI,
        KC_LALT, KC_MUTE,KC_VOLD,KC_VOLU,KC_MPLY,
                                                 KC_MPRV,KC_MNXT,
                                                         KC_PGUP,
                                        KC_SPACE,KC_ENT, KC_LBRC,

        // right hand
        KC_ESC,        KC_6,KC_7,   KC_8,   KC_9,  KC_0,   KC_EQL,
        LGUI(KC_SPACE),KC_Y,KC_U,   KC_I,   KC_O,  KC_P,   LT(SYMB,KC_MINS),
                       KC_H,KC_J,   KC_K,   KC_L,  KC_SCLN,KC_QUOT,
        KC_RGUI,       KC_N,KC_M,   KC_COMM,KC_DOT,KC_SLSH,MT(MOD_RSFT,KC_BSLS),
                            KC_LEFT,KC_DOWN,KC_UP, KC_RGHT,MT(MOD_RALT,KC_GRV),
        KC_HOME,KC_END,
        KC_PGDN,
        KC_RBRC,KC_BSPACE,KC_SPACE
    ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |  F11 |  F12 |  F13 |  F14 |  F15 |      |           |      |  F16 |  F17 |  F18 |  F19 |  F20 |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = KEYMAP(
       // left hand
       KC_TRNS,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       KC_TRNS,KC_F11, KC_F12, KC_F13, KC_F14, KC_F15, KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS,KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_TRNS,
       KC_TRNS,KC_F16, KC_F17, KC_F18, KC_F19, KC_F20, KC_TRNS,
               KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,
       KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS
),
};

const uint16_t PROGMEM fn_actions[] = {};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          register_code(KC_RSFT);
        } else {
          unregister_code(KC_RSFT);
        }
        break;
      }
    return MACRO_NONE;
};

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
