#pragma once

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x6464
#define DEVICE_VER      0x0001

//  Modified by Xydane
#define MANUFACTURER "QMK"
#define PRODUCT "Retro KVM"
#define DESCRIPTION "QMK keyboard firmware with ChibiOS"

/* key matrix size */
//  Modified by Xydane
#define MATRIX_ROWS 8
#define MATRIX_COLS 16
//#define DIODE_DIRECTION COL2ROW
#define MATRIX_HAS_GHOST
#define DEBUGPORT SD1  //ROB