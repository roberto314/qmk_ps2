/*
copyright 2012 Robert Offner <100prozentoffner@gmail.com>

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

#include "ch.h"
#include "hal.h"
#include "chprintf.h" //ROB
#include "ibm_xt.h"
#include "config.h"
#include QMK_KEYBOARD_H
#include "translation_XT.h"
//##################################################################
// Function Prototypes
//##################################################################
void init_XT(void);
void make_XT(uint8_t keycode);
void brake_XT(uint8_t keycode);
void send_XT(uint8_t value);
void send_XT_extended(uint8_t keycode);
void repeat_XTkeycode(void);
void DAT_ACTIVE(void);
void DAT_INACTIVE(void);
void CLK_ACTIVE(void);
void CLK_INACTIVE(void);
void _send_start(void);
void send_XTfake_shift(void);
//##################################################################
static BaseSequentialStream *const chout = (BaseSequentialStream *)&DEBUGPORT;  //ROB
uint8_t led_status = 0;
extern uint8_t key_repeat_time_init;
extern uint8_t key_repeat_time;
extern uint8_t keycode_repeat;


void init_XT(void){
 // Bitbang Output for XT Keyboard
  //palSetPadMode(GPIOB, 3, PAL_MODE_OUTPUT_PUSHPULL);
  //palSetPadMode(GPIOB, 4, PAL_MODE_OUTPUT_PUSHPULL);
  palSetLineMode(XT_CLK, PAL_MODE_OUTPUT_PUSHPULL);
  palSetLineMode(XT_DAT, PAL_MODE_OUTPUT_PUSHPULL);
  CLK_INACTIVE();
  DAT_ACTIVE();
}

void brake_XT(uint8_t keycode){
  switch (keycode){
    case KC_PENT:
    case KC_RCTL:
    case KC_PSLS:
    case KC_RALT:
    case KC_HOME:
    case KC_UP:
    case KC_PGUP:
    case KC_LEFT:
    case KC_RGHT:
    case KC_END:
    case KC_DOWN:
    case KC_PGDN:
    case KC_INS:
    case KC_DEL:
    send_XT_extended(IBM_XT[keycode] | 0x80); //Key release is Bit 7 SET
    break;
    default:
    send_XT(IBM_XT[keycode] | 0x80);
    break;
  }
  keycode_repeat = 0;
  chprintf(chout, "release kc: %0d XT: %0d\r\n", keycode, IBM_XT[keycode]  | 0x80);
}

void make_XT(uint8_t keycode){
  if (led_status & (1<<USB_LED_USBOFF)){  //switch USB off AFTER keys have been released
    led_status |= (1<<USB_LED_USBREALOFF);
  }	
  switch (keycode){
    case KC_PENT:
    case KC_RCTL:
    case KC_PSLS:
    case KC_RALT:
    case KC_HOME:
    case KC_UP:
    case KC_PGUP:
    case KC_LEFT:
    case KC_RGHT:
    case KC_END:
    case KC_DOWN:
    case KC_PGDN:
    case KC_INS:
    case KC_DEL:
    send_XT_extended(IBM_XT[keycode]);
    chprintf(chout, "kc: %0d XT ext: %0d\r\n", keycode, IBM_XT[keycode]);
    break;
    case KC_CAPS:
    //chprintf(chout, "Caps Lock sent\r\n");
    if (led_status & (1<<USB_LED_CAPS_LOCK)){
      led_status &= ~(1<<USB_LED_CAPS_LOCK);
      send_XT(IBM_XT[keycode]);
      send_XTfake_shift();  //hack because the shift "HANGS" after pressing twice it is still on!
    } else {
      led_status |= (1<<USB_LED_CAPS_LOCK);
      send_XT(IBM_XT[keycode]);
    }
    break;
    case KC_NLCK:
    //chprintf(chout, "Num Lock sent\r\n");
    if (led_status & (1<<USB_LED_NUM_LOCK)){
      led_status &= ~(1<<USB_LED_NUM_LOCK);
    } else {
      led_status |= (1<<USB_LED_NUM_LOCK);
    }
    send_XT(IBM_XT[keycode]);
    break;
    case KC_SLCK:
    //chprintf(chout, "Scroll Lock sent\r\n");
    if (led_status & (1<<USB_LED_SCROLL_LOCK)){
      led_status &= ~(1<<USB_LED_SCROLL_LOCK);
    } else {
      led_status |= (1<<USB_LED_SCROLL_LOCK);
    }
    send_XT(IBM_XT[keycode]);
    break;
    default:
    send_XT(IBM_XT[keycode]);
    keycode_repeat = keycode;
    key_repeat_time = key_repeat_time_init * 6;
    break;
  }
  chprintf(chout, "kc: %0d XT: %0d\r\n", keycode, IBM_XT[keycode]);
}

void repeat_XTkeycode(void){
	send_XT(keycode_repeat);
}


void DAT_ACTIVE(void){
#ifdef INVERT_XTDATA
  palSetLine(XT_DAT);
#else
  palClearLine(XT_DAT);
#endif  
}
void DAT_INACTIVE(void){
#ifdef INVERT_XTDATA
  palClearLine(XT_DAT);
#else
  palSetLine(XT_DAT);
#endif  
}
void CLK_ACTIVE(void){
#ifdef INVERT_XTCLOCK
  palSetLine(XT_CLK);
#else
  palClearLine(XT_CLK);
#endif  
}
void CLK_INACTIVE(void){
#ifdef INVERT_XTCLOCK
  palClearLine(XT_CLK);
#else
  palSetLine(XT_CLK);
#endif  
}

void _send_start(void){
  // CLK Line is HIGH and DATA Line is LOW
   CLK_ACTIVE(); //1
   _delay_micro(5); //Needed for my logic and protocol analyzer 
   DAT_INACTIVE();
   _delay_micro(50);
   //_delay_micro(120);
   CLK_INACTIVE();
   _delay_micro(40);
   //_delay_micro(66);
   CLK_ACTIVE(); //2
   //_delay_micro(15); 
   //_delay_micro(30); 
   //CLK_INACTIVE();
  // CLK Line is High and DATA Line is still HIGH
}

void send_XT(uint8_t value){
   //while (digitalRead(XT_CLK) != HIGH) ; 
   uint8_t bits[8];
   uint8_t p = 0; 
   uint8_t j = 0;
   uint8_t i = 0;
   for (j=0 ; j < 8; j++){
     if (value & 1) bits[j] = 1 ;
     else bits[j] = 0 ; 
     value = value >> 1 ; 
   }
   _send_start();
   
   for (i=0; i < 8; i++){
      _delay_micro(15);
      //_delay_micro(30);
      //CLK_INACTIVE();
      //_delay_micro(15);
      if (bits[p] == 1){
         DAT_INACTIVE();
      }else{
         DAT_ACTIVE();
      }
      //_delay_micro(66); 
      _delay_micro(25); 
      CLK_INACTIVE();
      _delay_micro(40);
      CLK_ACTIVE();
      //DAT_ACTIVE();
      p++ ;
   }
   _delay_micro(30);
   CLK_INACTIVE();
   _delay_micro(5);
   DAT_ACTIVE();
   //delay(1) ;
}
void send_XT_extended(uint8_t keycode){
  send_XT(0xe0);
  //_delay_micro(3500); does not work!
  chThdSleepMilliseconds(4);
  send_XT(keycode);
}
void send_XTfake_shift(void){
  chThdSleepMilliseconds(4);
  //send_XT(0xe0);
  send_XT(IBM_XT[KC_LSFT]);
  chThdSleepMilliseconds(4);
  send_XT(IBM_XT[KC_LSFT] | 0x80);
}