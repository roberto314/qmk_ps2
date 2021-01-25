# MCU name
MCU = STM32F103
MCU_LDSCRIPT = STM32F103xC
#MCU_LDSCRIPT = STM32F103xB
# Enter lower-power sleep mode when on the ChibiOS idle thread
OPT_DEFS += -DCORTEX_ENABLE_WFI_IDLE=TRUE

# project specific files
SRC = matrix.c \
      led.c \
      ibm_xt.c
