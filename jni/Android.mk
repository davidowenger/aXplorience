LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := \
	TApp

LOCAL_SRC_FILES := \
	NParamBox.cpp \
	NElement.cpp \
	NVisitor.cpp \
	NFrame.cpp \
	NWrapper.cpp \
	NClozer.cpp \
	NAPI.cpp \
	MyApplication.cpp
	
LOCAL_LDLIBS := \
	-llog \
	-ljnigraphics \
	-lm \
	-lGLESv2

LOCAL_CPP_FEATURES += exceptions
LOCAL_CPPFLAGS += -fexceptions
#LOCAL_CFLAGS := -Werror

include $(BUILD_SHARED_LIBRARY)
