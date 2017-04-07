NDK_TOOLCHAIN_VERSION := 4.9
APP_MODULES := TActivity
APP_ABI := armeabi-v7a
APP_PLATFORM := android-11
#APP_OPTIM := release
#APP_CFLAG += -DNDEBUG -03
APP_OPTIM := debug
APP_CFLAG += -g -ggdb
APP_CPPFLAGS += -std=gnu++11 -fexceptions
APP_CPPFLAGS += -Wall -Wno-unused-parameter -Wextra -Wl,--fatal-warnings
APP_CPPFLAGS += -gdwarf-2
APP_STL := gnustl_shared
