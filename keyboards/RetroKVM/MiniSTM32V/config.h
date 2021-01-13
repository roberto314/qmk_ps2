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

#define DEBUGPORT SD1  //ROB

// XT Keyboard Output
#define GPTIM GPTD4 // Timer for polled timeout
#define F_TIM 24 //in MHz! One Tic @ 72MHz is 13.8ns
#define TICS_P100 ((F_TIM/10)+1) //Tics per 100us - rounding up
#define TIC       ((1000/F_TIM)+1) //us for one tic
#define MS        (F_TIM/24)
#define _delay_micro(x) (gptPolledDelay(&GPTIM, (x*1000/42)))
#define INVERT_DATA 1
#define INVERT_CLOCK 1