# The ARMv7 is significanly faster due to the use of the hardware FPU
NDK_TOOLCHAIN_VERSION := 4.9
APP_ABI :=  armeabi-v7a
 # APP_ABI := x86 armeabi-v7a
 # APP_ABI := armeabi-v7a x86
 # APP_ABI := armeabi-v7a
 # APP_ABI := x86
APP_PLATFORM := android-9
APP_OPTIM := debug
APP_CFLAG += -g -ggdb -O0
APP_CPPFLAGS += -std=gnu++11 -fexceptions
APP_CPPFLAGS += -Wall -Wno-unused-parameter -Wextra -Wl,--fatal-warnings
APP_STL := gnustl_shared

#APP_CPPFLAGS += -std=gnu++11 -frtti -fexceptions
#APP_CPPFLAGS += -Wall -Wno-unused-parameter -Wextra -Wl,--fatal-warnings -Wl,-nostdlib -Wl,-E -Wl,-Bsymbolic
#APP_CPPFLAGS += -gdwarf-2
#APP_STL := c++_shared
#APP_STL := gnustl_shared
#APP_CFLAGS += -std=gnu++11
#APP_CPPFLAGS += -std=c++11
#APP_CPPFLAGS := -std=gnu++11
#APP_CPPFLAGS += -fexceptions
#APP_CPPFLAGS += -D__GXX_EXPERIMENTAL_CXX0X__
