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

  [_NORMAL] = LAYOUT_seventy_ansi( \
 KC_ESC            ,KC_F1 ,KC_F2,KC_F3,KC_F4  ,KC_F5    ,KC_F6     ,KC_F7     ,KC_F8      ,KC_F9      ,KC_F10     ,KC_F11   ,KC_F12    ,KC_PSCR      ,KC_SLCK  ,KC_PAUS                                     \
,KC_GRV  ,KC_1     ,KC_2  ,KC_3 ,KC_4 ,KC_5   ,KC_6     ,KC_7      ,KC_8      ,KC_9       ,KC_0       ,KC_MINS    ,KC_EQL   ,KC_BSPC   ,KC_INS       ,KC_HOME  ,KC_PGUP   ,KC_NLCK   ,KC_PSLS   ,KC_PAST   ,KC_PMNS \
,KC_TAB  ,KC_Q     ,KC_W  ,KC_E ,KC_R ,KC_T   ,KC_Y     ,KC_U      ,KC_I      ,KC_O       ,KC_P       ,KC_LBRC    ,KC_RBRC  ,KC_BSLS   ,KC_DEL       ,KC_END   ,KC_PGDN   ,KC_P7     ,KC_P8     ,KC_P9      \
,KC_CAPS ,KC_A     ,KC_S  ,KC_D ,KC_F ,KC_G   ,KC_H     ,KC_J      ,KC_K      ,KC_L       ,KC_SCLN    ,KC_QUOT    ,KC_BSLS  ,KC_ENT                                       ,KC_P4     ,KC_P5     ,KC_P6     ,KC_PPLS \
,KC_LSFT ,KC_NUBS  ,KC_Z  ,KC_X ,KC_C ,KC_V   ,KC_B     ,KC_N      ,KC_M      ,KC_COMM    ,KC_DOT     ,KC_SLSH    ,KC_RSFT                           ,KC_UP               ,KC_P1     ,KC_P2     ,KC_P3      \
,KC_LCTL ,KC_LALT                                       ,KC_SPC                                       ,KC_RALT    ,KC_RCTL             ,KC_LEFT      ,KC_DOWN  ,KC_RGHT   ,KC_P0                ,KC_PDOT   ,KC_PENT \
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
  //palSetLine(LED2);
  print("\nLayer Set to 3\n");
//    palClearPad(GPIOA, 0); //ON Color A
//    palClearPad(GPIOA, 1);  //ON Color B
    break;
  default: //  for any other layers, or the default layer
  //palClearLine(LED2);
  print("\nLayer Set to 1\n");
//    palClearPad(GPIOA, 0); //ON Color A
//    palSetPad(GPIOA, 1);  //OFF Color B
    break;
  }
  return state;
}
