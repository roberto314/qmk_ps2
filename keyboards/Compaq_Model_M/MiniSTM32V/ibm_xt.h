
#include "ch.h"
#include "hal.h"
#include QMK_KEYBOARD_H

#pragma once

#define INVERT_XTDATA 1
#define INVERT_XTCLOCK 1
//#define USB_LED_USBOFF 5 //additional to defines 0..4 in led.h
//#define USB_LED_USBREALOFF 6 //additional to defines 0..4 in led.h

void init_XT(void);
void make_XT(uint8_t keycode);
void brake_XT(uint8_t keycode);
void repeat_XTkeycode(void);
void send_XT(uint8_t value);
void send_XT_extended(uint8_t keycode);
void send_XTfake_shift(void);
