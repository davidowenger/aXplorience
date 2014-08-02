# The ARMv7 is significanly faster due to the use of the hardware FPU
APP_ABI := armeabi-v7a
APP_PLATFORM := android-9
APP_OPTIM := debug
APP_CFLAG := -g -ggdb -O0
#APP_STL := c++_shared
APP_STL := gnustl_static
#APP_STL := gnustl_shared
#APP_CPPFLAGS += -fexceptions
