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

/* key combination for magic key command */
/* defined by default; to change, uncomment and set to the combination you want */
// #define IS_COMMAND() (get_mods() == MOD_MASK_SHIFT)

#define GPTIM GPTD4
#define F_TIM 24 //in MHz! One Tic @ 72MHz is 13.8ns
#define TICS_P100 ((F_TIM/10)+1) //Tics per 100us - rounding up
#define TIC       ((1000/F_TIM)+1) //us for one tic
#define MS        (F_TIM/24)