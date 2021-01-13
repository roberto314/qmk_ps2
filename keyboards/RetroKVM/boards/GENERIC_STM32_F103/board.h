/*
    ChibiOS - Copyright (C) 2006..2015 Giovanni Di Sirio

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

#ifndef _BOARD_H_
#define _BOARD_H_

/*
 * Setup for a Generic STM32F103 board.
 */

/*
 * Board identifier.
 */
#define BOARD_GENERIC_STM32_F103
#define BOARD_NAME              "Generic STM32F103x board"

/*
 * Board frequencies.
 */
#define STM32_LSECLK            32768
#define STM32_HSECLK            8000000

/*
 * MCU type, supported types are defined in ./os/hal/platforms/hal_lld.h.
 */
//#define STM32F103xB
#define STM32F103xE

/*
 * IO pins assignments
 */

/* on-board */


#define XT_CLK        PAL_LINE(GPIOB, 14)
#define XT_DAT        PAL_LINE(GPIOB, 15)
#define LED_USB       PAL_LINE(GPIOB, 0)
#define LED2          PAL_LINE(GPIOB, 1)
#define DEBUGPIN      PAL_LINE(GPIOB, 9)
/* Backlighting */

/*#define GPIOC_BACKLIGHT_PIN               15*/

/* In case your board has a "USB enable" hardware
   controlled by a pin, define it here. (It could be just
   a 1.5k resistor connected to D+ line.)
*/

#define GPIOB_USB_DISC          7

#define LINE_ROW_1                  PAL_LINE(GPIOC, 0)   // Pin 1 ok
#define LINE_ROW_2                  PAL_LINE(GPIOC, 1)   // Pin 2 ok
#define LINE_ROW_3                  PAL_LINE(GPIOC, 2)   // Pin 3 ok
#define LINE_ROW_4                  PAL_LINE(GPIOC, 3)   // Pin 4 ok
#define LINE_ROW_5                  PAL_LINE(GPIOC, 4)   // Pin18 ok
#define LINE_ROW_6                  PAL_LINE(GPIOC, 5)   // Pin19 ok
#define LINE_ROW_7                  PAL_LINE(GPIOC, 6)   // Pin20 ok
#define LINE_ROW_8                  PAL_LINE(GPIOC, 7)   // Pin24 ok

#define LINE_COL_1                  PAL_LINE(GPIOE, 0)   // Pin 5
#define LINE_COL_2                  PAL_LINE(GPIOE, 1)  // Pin 6 ok
#define LINE_COL_3                  PAL_LINE(GPIOE, 2)   // Pin 7 ok
#define LINE_COL_4                  PAL_LINE(GPIOE, 3)   // Pin 8 ok
#define LINE_COL_5                  PAL_LINE(GPIOE, 4)   // Pin 9 ok
#define LINE_COL_6                  PAL_LINE(GPIOE, 5)  // Pin10 ok
#define LINE_COL_7                  PAL_LINE(GPIOE, 6)   // Pin11 ok
#define LINE_COL_8                  PAL_LINE(GPIOE, 7)   // Pin12
#define LINE_COL_9                  PAL_LINE(GPIOE, 8)  // Pin13 ok
#define LINE_COL_10                 PAL_LINE(GPIOE, 9)  // Pin14 ok
#define LINE_COL_11                 PAL_LINE(GPIOE, 10)  // Pin15 ok
#define LINE_COL_12                 PAL_LINE(GPIOE, 11)  // Pin16 ok
#define LINE_COL_13                 PAL_LINE(GPIOE, 12)  // Pin17 ok
#define LINE_COL_14                 PAL_LINE(GPIOE, 13)   // Pin21
#define LINE_COL_15                 PAL_LINE(GPIOE, 14)   // Pin22
#define LINE_COL_16                 PAL_LINE(GPIOE, 15)   // Pin23

/*
 * I/O ports initial setup, this configuration is established soon after reset
 * in the initialization code.
 *
 * The digits have the following meaning:
 *   0 - Analog input.
 *   1 - Push Pull output 10MHz.
 *   2 - Push Pull output 2MHz.
 *   3 - Push Pull output 50MHz.
 *   4 - Digital input.
 *   5 - Open Drain output 10MHz.
 *   6 - Open Drain output 2MHz.
 *   7 - Open Drain output 50MHz.
 *   8 - Digital input with PullUp or PullDown resistor depending on ODR.
 *   9 - Alternate Push Pull output 10MHz.
 *   A - Alternate Push Pull output 2MHz.
 *   B - Alternate Push Pull output 50MHz.
 *   C - Reserved.
 *   D - Alternate Open Drain output 10MHz.
 *   E - Alternate Open Drain output 2MHz.
 *   F - Alternate Open Drain output 50MHz.
 * Please refer to the STM32 Reference Manual for details.
 */

/*
 * Port A setup.
 * Everything input with pull-up except:
 * PA2  - Alternate output  (USART2 TX).
 * PA3  - Normal input      (USART2 RX).
 * PA9  - Alternate output  (USART1 TX).
 * PA10 - Normal input      (USART1 RX).
 */
//#define VAL_GPIOACRL            0x88884B88      /*  PA7...PA0 */
#define VAL_GPIOACRL            0x88888888      /*  PA7...PA0 */
#define VAL_GPIOACRH            0x88888888      /* PA15...PA8 */
//#define VAL_GPIOACRH            0x888884B8      /* PA15...PA8 */
#define VAL_GPIOAODR            0xFFFFFFFF

/*
 * Port B setup.
 * Everything input with pull-up except:
 * PB0    - LED1
 * PB1    - LED2
 * PB7    - Push Pull output  (USB switch).
 */
#define VAL_GPIOBCRL            0x38833833      /*  PB7...PB0 */
#define VAL_GPIOBCRH            0x33888838      /* PB15...PB8 */
//#define VAL_GPIOBCRH            0x88888388      /* PB15...PB8 */
#define VAL_GPIOBODR            0xFFFFFFFF

/*
 * Port C setup.
 * Everything input with pull-up except:
 */
#define VAL_GPIOCCRL            0x88888888      /*  PC7...PC0 */
#define VAL_GPIOCCRH            0x88888888      /* PC15...PC8 */
#define VAL_GPIOCODR            0xFFFFFFFF

/*
 * Port D setup.
 * Everything input with pull-up except:
 * PD0  - Normal input (XTAL).
 * PD1  - Normal input (XTAL).
 */
#define VAL_GPIODCRL            0x88888844      /*  PD7...PD0 */
#define VAL_GPIODCRH            0x88888888      /* PD15...PD8 */
#define VAL_GPIODODR            0xFFFFFFFF

/*
 * Port E setup.
 * Everything input with pull-up except:
 */
#define VAL_GPIOECRL            0x88888888      /*  PE7...PE0 */
#define VAL_GPIOECRH            0x88888888      /* PE15...PE8 */
#define VAL_GPIOEODR            0xFFFFFFFF

/*
 * USB bus activation macro, required by the USB driver.
 */
/* The point is that most of the generic STM32F103* boards
   have a 1.5k resistor connected on one end to the D+ line
   and on the other end to some pin. Or even a slightly more
   complicated "USB enable" circuit, controlled by a pin.
   That should go here.

   However on some boards (e.g. one that I have), there's no
   such hardware. In which case it's better to not do anything.
*/

#define usb_lld_connect_bus(usbp) palClearPad(GPIOB, GPIOB_USB_DISC)

//#define usb_lld_connect_bus(usbp) palSetPadMode(GPIOA, 12, PAL_MODE_INPUT);

/*
 * USB bus de-activation macro, required by the USB driver.
 */

#define usb_lld_disconnect_bus(usbp) palSetPad(GPIOB, GPIOB_USB_DISC)

//#define usb_lld_disconnect_bus(usbp) palSetPadMode(GPIOA, 12, PAL_MODE_OUTPUT_PUSHPULL); palClearPad(GPIOA, 12);

#if !defined(_FROM_ASM_)
#ifdef __cplusplus
extern "C" {
#endif
  void boardInit(void);
#ifdef __cplusplus
}
#endif
#endif /* _FROM_ASM_ */

#endif /* _BOARD_H_ */
