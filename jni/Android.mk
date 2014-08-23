LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := TApp
LOCAL_SRC_FILES := TApp.cpp

include $(BUILD_SHARED_LIBRARY)
