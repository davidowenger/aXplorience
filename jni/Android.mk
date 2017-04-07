LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := \
    libfreetype
    
LOCAL_SRC_FILES := \
    libs/freetype2/libfreetype.a

LOCAL_EXPORT_C_INCLUDES := \
    $(LOCAL_PATH)/include/freetype2

LOCAL_EXPORT_CPP_INCLUDES := \
    $(LOCAL_PATH)/include/freetype2

include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)

LOCAL_MODULE := \
    TActivity

LOCAL_SRC_FILES := \
	include/nclozer/db/DBFile.cpp \
	include/nclozer/db/DBHandler.cpp \
	include/nclozer/graphics/GraphicsHandler.cpp \
	include/nclozer/graphics/GraphicsProgram.cpp \
	include/nclozer/nkross/device/bluetooth/BluetoothAdapter.cpp \
	include/nclozer/nkross/device/bluetooth/BluetoothDevice.cpp \
	include/nclozer/nkross/device/bluetooth/BluetoothSocket.cpp \
	include/nclozer/nkross/device/bluetooth/BluetoothServerSocket.cpp \
	include/nclozer/nkross/device/content/Context.cpp \
	include/nclozer/nkross/device/graphics/Typeface.cpp \
	include/nclozer/nkross/device/hardware/Camera.cpp \
	include/nclozer/nkross/device/location/LocationManager.cpp \
	include/nclozer/nkross/device/view/GestureDetector.cpp \
	include/nclozer/nkross/device/view/View.cpp \
	include/nclozer/nkross/device/view/ViewGroup.cpp \
	include/nclozer/nkross/os/android.cpp \
	include/nclozer/nkross/NKrossParam.cpp \
	include/nclozer/nkross/NKrossSystem.cpp \
	include/nclozer/nkross/NKrossVisitor.cpp \
	include/nclozer/nkross/NKrossCommon.cpp \
	include/nclozer/op/OpParam.cpp \
	include/nclozer/op/OpSquad.cpp \
	include/nclozer/op/OpUnit.cpp \
	include/nclozer/NCommon.cpp \
	include/nclozer/NElement.cpp \
	include/nclozer/NVisitor.cpp \
	src/AREngine.cpp \
	src/BOMessage.cpp \
	src/BOPOI.cpp \
	src/EventManager.cpp \
	src/NActivity.cpp \
	src/OpUnitEvents.cpp \
	src/OpUnitAnim.cpp \
	src/OpUnitAR.cpp \
	src/OpUnitDB.cpp \
	src/OpUnitListener.cpp \
	src/OpUnitPeer.cpp \
	src/OpUnitServer.cpp \
	src/OpUnitCore.cpp \
	src/RootLayout.cpp \
	src/WidgetAR.cpp \
	src/WidgetAbout.cpp \
	src/WidgetSettings.cpp \
	src/WidgetMessage.cpp \
	src/WidgetMessageList.cpp \
	src/WidgetMessageDetails.cpp \
	src/WidgetMessageEdit.cpp

LOCAL_C_INCLUDES := \
	$(LOCAL_PATH)/include/freetype2 \
	$(LOCAL_PATH)/include/nclozer \
	$(LOCAL_PATH)/src

LOCAL_CPP_INCLUDES := \
	$(LOCAL_PATH)/include/freetype2 \
	$(LOCAL_PATH)/include/nclozer \
	$(LOCAL_PATH)/src

LOCAL_LDLIBS := \
	-llog \
	-lm \
	-landroid \
	-lEGL \
	-lGLESv2

LOCAL_STATIC_LIBRARIES := \
	freetype

include $(BUILD_SHARED_LIBRARY)
