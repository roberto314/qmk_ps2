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


void led_set(uint8_t usb_led){
  if (usb_led & (1<<USB_LED_CAPS_LOCK)) {
    palClearLine(LED_NUM);
    print("Caps Lock ON\n");
  } else {
    palSetLine(LED_NUM);
    print("Caps Lock OFF\n");
  }
  if (usb_led & (1<<USB_LED_NUM_LOCK)) {
    palClearLine(LED_CAPS);
    print("NUM Lock ON\n");
  } else {
    palSetLine(LED_CAPS);
    print("NUM Lock OFF\n");
  }
  if (usb_led & (1<<USB_LED_SCROLL_LOCK)) {
    palClearLine(LED_SCRL);
    print("\nScroll Lock ON\n");
  } else {
    palSetLine(LED_SCRL);
    print("\nScroll Lock OFF\n");
  }
}

// inline void gh60_caps_led_off(void)     { DDRB &= ~(1<<2); PORTB &= ~(1<<2); }

// inline void gh60_caps_led_on(void)      { DDRB |=  (1<<2); PORTB &= ~(1<<2); }