#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  |   ←  |           |   →  |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   ⌦    |   Q  |   W  |   E  |   R  |   T  |  L1  |           |  L1  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |   ⌫    |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2| ' / L⌘ |
 * |--------+------+------+------+------+------|  L⌘  |           |  L⌘  |------+------+------+------+------+--------|
 * |  L⇧    |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  | / / ⌃|  R⇧    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |  L⌃  |  L⌥  |  L⌘  |   ←  |   →  |                                       |   ↑  |   ↓  |   [  |   ]  | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        |  `~  |  '"  |       |   ⎋  |    ⌫   |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | PgUp |       | PgDn |        |      |
 *                                 |      |   ⌫  |------|       |------|    ⇥   |Enter |
 *                                 |      |      |  L⌥  |       |  L⌃  |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_EQL,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   KC_LEFT,
        KC_DELT,        KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   TG(SYMB),
        KC_BSPC,        KC_A,         KC_S,   KC_D,   KC_F,   KC_G,
        KC_LSFT,        KC_Z,         KC_X,   KC_C,   KC_V,   KC_B,   KC_LGUI,
        KC_LCTL,        KC_LALT,      KC_LGUI,KC_LEFT,KC_RGHT,
                                              KC_GRV, KC_QUOT,
                                                              KC_PGUP,
                                               KC_SPC,KC_BSPC,KC_LALT,
        // right hand
             KC_RGHT,     KC_6,   KC_7,   KC_8,   KC_9,   KC_0,             KC_MINS,
             TG(SYMB),    KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,             KC_BSLS,
                          KC_H,   KC_J,   KC_K,   KC_L,   LT(MDIA, KC_SCLN),GUI_T(KC_QUOT),
             KC_LGUI,     KC_N,   KC_M,   KC_COMM,KC_DOT, CTL_T(KC_SLSH),   KC_RSFT,
                                  KC_UP,  KC_DOWN,KC_LBRC,KC_RBRC,          KC_FN1,
             KC_ESC,            KC_BSPC,
             KC_PGDN,
             KC_LCTL,           KC_TAB,      KC_ENT
    ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   [  |   ]  |   {  |   }  |      |      |           |      |   /  |   7  |   8  |   9  |   *  |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   <  |   >  |   (  |   )  |      |------|           |------|   -  |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |   &  |   1  |   2  |   3  |   =  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |   0  |   .  |   ←  |   →  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       | Home |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       | End  |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = KEYMAP(
       // left hand
       KC_TRNS,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       KC_TRNS,KC_LBRC,KC_RBRC,KC_LCBR,KC_RCBR,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_LABK,KC_RABK,KC_LPRN,KC_RPRN,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, KC_SLSH, KC_7,   KC_8,    KC_9,    KC_ASTR, KC_F12,
                KC_MINS, KC_4,   KC_5,    KC_6,    KC_PLUS, KC_TRNS,
       KC_TRNS, KC_AMPR, KC_1,   KC_2,    KC_3,    KC_EQL,  KC_TRNS,
                         KC_0,   KC_DOT,  KC_LEFT, KC_RGHT, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_HOME,
       KC_END , KC_TRNS, KC_TRNS
),
/* Keymap 2: Media keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F14 |  F15 |      |      |      |      |           |  ⌘Q  |  ⌘W  | ⌘⇧`  |  ⌘`  | ⌥⇧⇥  |  ⌥⇥  |  Power |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | PgUp |      |      |      |           |      |  ⌘]  | ⌥⌘↑  |   ↑  | ⌥⌘↓  |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      | Home | PgDn |  End |      |------|           |------|  ⌘[  |   ←  |   ↓  |   →  |      |    ⏯  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |L⇧+Spc|  Spc |  ⏮  |   ⏭ |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|  ⌘C  |  ⌘V  |
 *                                 |      |      |      |       |  ⌘X  |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = KEYMAP(
       KC_TRNS, KC_F14 , KC_F15 , KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  /* F14 dims screen, F15 brightens */
       KC_TRNS, KC_TRNS, KC_TRNS, KC_PGUP, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_HOME, KC_PGDN, KC_END , KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       LGUI(KC_Q),  LGUI(KC_W),     LGUI(LSFT(KC_GRV)), LGUI(KC_GRV),   LALT(LSFT(KC_TAB)),     LALT(KC_TAB),   KC_PWR,
       KC_TRNS,     LGUI(KC_RBRC),  LGUI(LALT(KC_UP)),  KC_UP  ,        LGUI(LALT(KC_DOWN)),    KC_TRNS,        KC_TRNS,
                    LGUI(KC_LBRC),  KC_LEFT,            KC_DOWN,        KC_RGHT,                KC_TRNS,        KC_MPLY,
       KC_TRNS,     LSFT(KC_SPC),   KC_SPC ,            KC_MPRV,        KC_MNXT,                KC_TRNS,        KC_TRNS,
                                    KC_VOLU,            KC_VOLD,        KC_MUTE,                KC_TRNS,        KC_TRNS,
       KC_TRNS,     KC_TRNS,
       KC_TRNS,
       LGUI(KC_X),  LGUI(KC_C),     LGUI(KC_V)
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

// action_get_macro() is unused — remove the “#if 0” and “#endif” lines to reenable
#if 0
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
#endif

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
