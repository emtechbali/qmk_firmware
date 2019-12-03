#----------------------------------------------------------------------------
# make gergo:germ:dfu
# Make sure you have dfu-programmer installed!
# Do not edit this file! Make a copy of keymaps/default and modify that!
#----------------------------------------------------------------------------
# Source includes
SRC += matrix.c i2c_master.c

# Hardware info
MCU = atmega32u4
F_CPU = 16000000
ARCH = AVR8
BOOTLOADER = atmel-dfu
F_USB = $(F_CPU)

CUSTOM_MATRIX 		= yes
POINTING_DEVICE_ENABLE	= yes
EXTRAKEY_ENABLE		= yes
CONSOLE_ENABLE  	= yes
COMMAND_ENABLE		= yes
BALLER_DEBUG      = yes
