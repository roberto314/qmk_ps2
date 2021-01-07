#pragma once

#include "quantum.h"
#include "led.h"

#define LAYOUT_seventy_ansi( \
    K00,  K01,  K02,  K03,  K04,  K05,  K06,  K07,  K08,  K09,  K0A,  K0B,  K0C,  K0D,  K0E,  K0F,  K10, \
    K11,  K12,  K13,  K14,  K15,  K16,  K17,  K18,  K19,  K1A,  K1B,  K1C,  K1D,  K1E, \
    K20,  K21,  K22,  K23,  K24,  K25,  K26,  K27,  K28,  K29,  K2A,  K2B,  K2C,  K2D, \
    K30,  K31,  K32,  K33,  K34,  K35,  K36,  K37,  K38,  K39,  K3A,  K3B,  K3C,       \
    K40,  K41,  K42,  K43,  K44,  K45,  K46,  K47,  K48,  K49,  K4A,  K4B,  K4C,       \
    K50,  K51,  K52,  K53,           K54,              K55,  K56,  K57,     K58,  K59,  K5A, \
                                                                            K60,  K61,  K62  \
) { \
  { K00,  K51,  KC_NO,KC_NO,K40,  KC_NO,KC_NO,K3B,  K2B,  K39,  K17,  K41,  K1B,  K07,  K0A,  K09 }, \
  { K01,  K04,  K50,  KC_NO,KC_NO,KC_NO,KC_NO,K3A,  K38,  K29,  K28,  K05,  K19,  K3C,  KC_NO,K08 }, \
  { K02,  K03,  KC_NO,KC_NO,KC_NO,K52,  KC_NO,K1C,  KC_NO,K2A,  K27,  KC_NO,KC_NO,K1A,  K0C,  K0D }, \
  { K20,  K30,  KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,K44,  K47,  K36,  K42,  K31,  K54,  K06,  KC_NO,K61 }, \
  { K14,  K13,  KC_NO,K56,  KC_NO,KC_NO,K55,  KC_NO,K46,  K4A,  K33,  K22,  KC_NO,KC_NO,KC_NO,K62 }, \
  { KC_NO,K15,  KC_NO,K58,  K4C,  KC_NO,KC_NO,K34,  K45,  K35,  K26,  K24,  K59,  K1E,  KC_NO,K10 }, \
  { K12,  K21,  K57,  K5A,  KC_NO,KC_NO,KC_NO,K43,  K48,  K37,  K23,  K16,  KC_NO,K2D,  K0F,  K60 }, \
  { K11,  K21  ,KC_NO,KC_NO,KC_NO,KC_NO,K53,  K2C,  K49,  K4B,  K25,  K32,  K18,  K1D,  K0B,  K0E }, \
}

/*  ISO LAYOUT
  ESC| F1 | F2 | F3 | F4 | F5 | F6 | F7 | F8 | F9 | F10| F11| F12| PSC| PGU| PGD
  GRA| 1  | 2  | 3  | 4  | 5  | 6  | 7  | 8  | 9  | 0  | '  | ¡  |   BCKS  | DEL
  TAB| Q  | W  | E  | R  | T  | Y  | U  | I  | O  | P  | `  | +  |         | HOM
  CAP| A  | S  | D  | F  | G  | H  | J  | K  | L  | Ñ  | ´  | Ç  |   ENTER | END
  LSI| <  | Z  | X  | C  | V  | B  | N  | M  | ,  | .  | -  |   RSHIF | UP | FNL
  LCT| WIN| ALT|               ESPACE             | ALG| FN | RCT| LEF| DOW| RIG
*/

#define LAYOUT_seventy_iso( \
  K00, K01, K02, K03,   K04,   K05,   K06, K07,   K08,   K09, K0A, K0B, K0C, K0D, K0E, K0F, \
  K10, K11, K12, K13,   K14,   K15,   K16, K17,   K18,   K19, K1A, K1B, K1C,    K1D,   K1E, \
  K20, K21, K22, K23,   K24,   K25,   K26, K27,   K28,   K29, K2A, K2B, K2C,           K2D, \
  K30, K31, K32, K33,   K34,   K35,   K36, K37,   K38,   K39, K3A, K3B, K3C,      K3D, K3E, \
  K40, K41, K42, K43,   K44,   K45,   K46, K47,   K48,   K49, K4A, K4B,      K4C, K4D, K4E, \
  K50, K51, K52,                      K53,               K54, K55, K56, K57, K58, K59 \
) { \
  { K00, K01, K02, K03,   K04,   K05,   K06, K07,   K08,  K09, K0A, K0B, K0C, K0D, K0F }, \
  { K10, K11, K12, K13,   K14,   K15,   K16, K17,   K18,  K19, K1A, K1B, K1C, K0E, K1E }, \
  { K20, K21, K22, K23,   K24,   K25,   K26, K27,   K28,  K29, K2A, K2B, K2C, K1D, K2D }, \
  { K30, K31, K32, K33,   K34,   K35,   K36, K37,   K38,  K39, K3A, K3B, K3C, K3D, K3E }, \
  { K40, K41, K42, K43,   K44,   K45,   K46, K47,   K48,  K49, K4A, K4B, K4C, K4D, K4E }, \
  { K50, K51, K52, KC_NO, KC_NO, KC_NO, K53, KC_NO, KC_NO,K54, K55, K56, K57, K58, K59 } \
}
