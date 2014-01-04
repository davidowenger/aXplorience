LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := TApp
LOCAL_SRC_FILES := NElement.cpp NVisitor.cpp NFrame.cpp NWrapper.cpp NBufferLong.cpp NClozer.cpp NView.cpp NLib.cpp
LOCAL_LDLIBS    := -llog -ljnigraphics -lm -lGLESv2
#LOCAL_CFLAGS    := -Werror

include $(BUILD_SHARED_LIBRARY)
