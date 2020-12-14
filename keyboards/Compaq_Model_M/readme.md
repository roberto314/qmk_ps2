
# MiniSTM32V Compaq_Model_M

Keyboards using a MiniSTM32V controller (Chinese STM32F103VC) and based on the [KC64 of Xydane](https://github.com/Xydane/qmk_firmware).

Keyboard Maintainer: roberto314 (on Github)
Hardware Supported: MiniSTM32V (STM32F103VC)
Hardware Availability: Aliexpress, ebay

Make example for MiniSTM32V (after setting up your build environment):

    make Compaq_Model_M:default

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

Read everything before using it.

## Introduction

First of all thanks to [Xydane](https://github.com/Xydane) at [GeekHack](https://geekhack.org/) for his advice and his repository, without it you couldn't be reading this.

That's was an attempt to create a firmware using an STM32F103VC.

## No bootloader

Neither Xydane or I used the bootloader, the code for it is commented and you can use it if you want. I didn't achieve to run it and just used a serial programmer (FTDI, ST-LINK).

## Pinout
See the spreadsheet Compaq_Matrix.ods
