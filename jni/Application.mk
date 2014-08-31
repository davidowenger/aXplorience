# The ARMv7 is significanly faster due to the use of the hardware FPU
NDK_TOOLCHAIN_VERSION := 4.8
APP_ABI := armeabi-v7a
APP_PLATFORM := android-9
APP_OPTIM := debug
APP_CFLAG := -g -ggdb -O0
APP_CPPFLAGS += -std=gnu++11 \
	-gdwarf-2
APP_STL := gnustl_static

#APP_STL := c++_shared
#APP_STL := gnustl_shared
#APP_CFLAGS += -std=gnu++11
#APP_CPPFLAGS += -std=c++11
#APP_CPPFLAGS := -std=gnu++11
#APP_CPPFLAGS += -fexceptions
#APP_CPPFLAGS += -D__GXX_EXPERIMENTAL_CXX0X__
