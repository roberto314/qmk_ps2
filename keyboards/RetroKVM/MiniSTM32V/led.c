/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

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

#include "hal.h"
#include "led.h"
#include "print.h"
#include "chprintf.h" //ROB
#define USB_LED_USBOFF 5 //additional to defines 0..4 in led.h

void led_set_user_2(uint8_t usb_led){
//void led_set(uint8_t usb_led){
  //chprintf(chout, "In led_set %0d\r\n", usb_led);
  if (usb_led & (1<<USB_LED_CAPS_LOCK)) {
    //palClearLine(LED_NUM);
    //print("Caps Lock ON\n");
  } else {
    //palSetLine(LED_NUM);
    //print("Caps Lock OFF\n");
  }
  if (usb_led & (1<<USB_LED_NUM_LOCK)) {
    //palClearLine(LED_CAPS);
    //print("NUM Lock ON\n");
  } else {
    //palSetLine(LED_CAPS);
    //print("NUM Lock OFF\n");
  }
  if (usb_led & (1<<USB_LED_SCROLL_LOCK)) {
    //palClearLine(LED_SCRL);
    //print("\nScroll Lock ON\n");
  } else {
    //palSetLine(LED_SCRL);
    //print("\nScroll Lock OFF\n");
  }
  if (usb_led & (1<<USB_LED_USBOFF)) {
    palClearLine(LED_USB);
  } else {
    palSetLine(LED_USB);
  }
}

//void led_set(uint8_t usb_led){
//  if (usb_led & (1<<USB_LED_CAPS_LOCK)) {
//    /* generic STM32F103C8T6 board */
//    #ifdef BOARD_GENERIC_STM32_F103
//      //palClearPad(GPIOC, 13);
//      palSetLine(LED1);
//    #endif
//  } else {
//    /* generic STM32F103C8T6 board */
//    #ifdef BOARD_GENERIC_STM32_F103
//      //palSetPad(GPIOC, 13);
//      palClearLine(LED1);
//    #endif
//  }
//}

// inline void gh60_caps_led_off(void)     { DDRB &= ~(1<<2); PORTB &= ~(1<<2); }

// inline void gh60_caps_led_on(void)      { DDRB |=  (1<<2); PORTB &= ~(1<<2); }