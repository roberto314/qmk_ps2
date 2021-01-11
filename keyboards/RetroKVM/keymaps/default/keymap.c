/*
Copyright 2012,2013 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
//#include "chprintf.h" //ROB

/* These are the keys above the keyboard named with 1-4 and Enter, left of the Power Button.
See picture in the root directory of the RetroKVM Tree.
*/
enum Retro_KVM_keycodes {
  APP_1 = SAFE_RANGE,
  APP_2,
  APP_3,
  APP_4,
  APP_ENTR
};

// Define layer names
#define _NORMAL 0
#define _FNONE 1
#define _FNTWO 2

//static BaseSequentialStream *const chout = (BaseSequentialStream *)&DEBUGPORT;  //ROB

// Highly Modified by Xydane
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*  [_NORMAL] = LAYOUT_seventy_ansi(
  KC_ESC, KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11,  KC_F12,KC_NUMLOCK,KC_INSERT,KC_PSCREEN,KC_DELETE,KC_PAUSE, \
  KC_QUOTE, KC_1,   KC_2,    KC_3,    KC_4,    KC_5,     KC_6,     KC_7,      KC_8,     KC_9,     KC_0,      KC_MINS,    KC_EQL,                 KC_BSPC,     \
  KC_TAB,        KC_Q,   KC_W,   KC_E,   KC_R,    KC_T,       KC_Y,      KC_U,      KC_I,     KC_O,     KC_P,      KC_LBRC,       KC_RBRC,        KC_ENT,     \
  KC_CAPS,           KC_A,    KC_S,    KC_D,   KC_F,    KC_G,      KC_H,      KC_J,      KC_K,      KC_L,     KC_SCLN,    KC_QUOT,   KC_NONUS_HASH,           \
  KC_LSHFT, KC_BSLASH,   KZ_Z,   KC_X,   KC_C,    KC_V,   KC_B,     KC_N,     KC_M,      KC_COMM,       KC_DOT,     KC_SLSH,           KC_RSHFT,              \
  KC_LCTL,  MO(1),   KC_LGUI,   KC_LALT,                       KC_SPC,               KC_RALT,     KC_RGUI,      KC_RCTL,       KC_PGUP,    KC_UP,  KC_PGDOWN, \
                                                                                                                               KC_LEFT,   KC_DOWN, KC_RIGHT,  \
  ),
*/
  [_NORMAL] = LAYOUT_seventy_ansi(
                                                                        APP_1,    APP_2,    APP_3,    APP_4,    APP_ENTR, \
  KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,    TG(2)  ,       KC_INSERT, KC_PAUSE, KC_DELETE, \
  KC_GRAVE, KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINUS, KC_EQL,    KC_BSPC, \
  KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,   KC_ENT,  \
  KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_HASH,     \
  KC_LSHIFT,KC_BSLASH,KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSHIFT,   \
  KC_LCTL,  MO(1),    KC_LGUI,  KC_LALT,  KC_SPC,   KC_RALT,  KC_RGUI,  KC_RCTL,  KC_PGUP,  KC_UP,    KC_PGDOWN, \
                                                                                  KC_LEFT,  KC_DOWN,  KC_RIGHT \
  ),
 [_FNONE] = LAYOUT_seventy_ansi(
                                                                        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, \
  KC_TRNS,  KC_MNXT,  KC_TRNS,  KC_MUTE,  KC_TRNS,  KC_TRNS,  KC_BRID,  KC_BRIU,  KC_VOLD,  KC_VOLU,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_SCROLLLOCK, KC_PSCR,   KC_TRNS,  KC_TRNS, \
  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS, \
  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS, \
  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   \
  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   \
  KC_TRNS,  XXXXXXX,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_HOME,  KC_TRNS,  KC_END,   \
                                                                                  KC_TRNS,  KC_TRNS,  KC_TRNS
  ),
[_FNTWO] = LAYOUT_seventy_ansi(
                                                                        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, \
  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  XXXXXXX,  XXXXXXX,   KC_TRNS,       KC_TRNS,   KC_TRNS,  KC_TRNS, \
  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_7,     KC_8,     KC_9,     KC_PSLS,  XXXXXXX,  XXXXXXX,   KC_TRNS, \
  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_4,     KC_5,     KC_6,     KC_PAST,  XXXXXXX,  XXXXXXX,   KC_PENT, \
  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_1,     KC_2,     KC_3,     KC_PMNS,  XXXXXXX,  XXXXXXX,  \
  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_0,     KC_COMM,  KC_DOT,   KC_PPLS,  XXXXXXX,  \
  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   \
                                                                                  KC_TRNS,  KC_TRNS,  KC_TRNS \
  )
};

//__attribute__ ((weak))
//bool process_action_user(keyrecord_t *record) {
//    return true;
//}


/* Layer based ilumination, just binary */
layer_state_t layer_state_set_user(layer_state_t state) {
  switch (get_highest_layer(state)) {
  case _FNONE:
  print("\nLayer Set to 2\n");
//    palSetPad(GPIOA, 0);  //OFF Color A
//    palClearPad(GPIOA, 1); //ON Color B
    break;
  case _FNTWO:
  palSetLine(LED2);
  print("\nLayer Set to 3\n");
//    palClearPad(GPIOA, 0); //ON Color A
//    palClearPad(GPIOA, 1);  //ON Color B
    break;
  default: //  for any other layers, or the default layer
  palClearLine(LED2);
  print("\nLayer Set to 1\n");
//    palClearPad(GPIOA, 0); //ON Color A
//    palSetPad(GPIOA, 1);  //OFF Color B
    break;
  }
  return state;
}
