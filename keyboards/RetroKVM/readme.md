
# MiniSTM32V RetroKVM

Keyboards using a MiniSTM32V controller (Chinese STM32F103VC) and based on the [KC64 of Xydane](https://github.com/Xydane/qmk_firmware).

Keyboard Maintainer: 
Hardware Supported: MiniSTM32V (STM32F103VC)
Hardware Availability: Aliexpress, ebay

Make example for MiniSTM32V (after setting up your build environment):

    make RetroKVM:default

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

Read everything before using it.

## Introduction

First of all thanks to [Xydane](https://github.com/Xydane) at [GeekHack](https://geekhack.org/) for his advice and his repository, without it you couldn't be reading this.

That's was an attempt to create a firmware using an STM32F103VC.

## No bootloader

Neither Xydane or I used the bootloader, the code for it is commented and you can use it if you want. I didn't achieve to run it and just used a serial programmer (FTDI, ST-LINK).

## Adding layouts and revisions

If you want to create new layouts just add them to the keymaps folder. If you prefer to develop a more complex 
revision just copy the bluepill70 folder, rename it and create a new keymap in /keymap.c (I tried to 
divide the project even more but it didn't worked).

## Pinout

That's the pinout;
           Pin5|Pin6|Pin7|Pin8|Pin9|Pin10|Pin11|Pin12|Pin13|Pin14|Pin15|Pin16|Pin17|Pin21|Pin22|Pin23
             E0  E1   E2   E3   E4   E5    E6    E7    E8    E9    E10   E11   E12   E13   E14   E15
Pin1    C0  ESC| Fn | NO | NO |LSHT| NO  | NO  |  ,  |  ]  |  L  |  6  |  \  |  0  |  F7 | F10 |  F9
Pin2    C1  F1 | F4 |LCTR| NO | NO | NO  | NO  |  ;  |  K  |  O  |  I  |  F5 |  8  |  #  | NO  |  F8
Pin3    C2  F2 | F3 | NO | NO | NO |LGUI | NO  |  -  |  NO |  P  |  U  |  NO |  NO |  9  | F12 |NUMLCK  
Pin4    C3  TAB|CAPS| NO | NO | NO | NO  | NO  |  C  |  N  |  H  |  Z  |  A  |  SPC|  F6 | NO  | DOWN
Pin18   C4   3 | 2  | NO |RGUI| NO | NO  |RALT |  NO |  B  |  .  |  D  |  W  |  NO |  NO | NO  | RIGHT
Pin19   C5  NO | 4  | NO |PGUP|RSHT| NO  | NO  |  F  |  V  |  G  |  Y  |  R  |  UP |BSPC | NO  | PAUSE
Pin20   C6   1 | Q  |RCTL|PGDN| NO | NO  | NO  |  X  |  M  |  J  |  E  |  5  |  NO |ENTER| DEL | LEFT
Pin24   C7   ~ | NO | NO | NO | NO | NO  |LALT |  [  |  ,  |  /  |  T  |  S  |  7  |  =  | F11 |INSERT

It also uses:  
PB0: Caps Lock LED
PB1: Num Loc
