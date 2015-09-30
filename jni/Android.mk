LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := \
	TActivity

LOCAL_SRC_FILES := \
	op/Op.cpp \
	op/OpUnit.cpp \
	op/OpSquad.cpp \
	db/DBFile.cpp \
	db/DBHandler.cpp \
	device/graphics/Typeface.cpp \
	device/content/Context.cpp \
	device/bluetooth/BluetoothAdapter.cpp \
	device/bluetooth/BluetoothDevice.cpp \
	device/bluetooth/BluetoothSocket.cpp \
	device/bluetooth/BluetoothServerSocket.cpp \
	device/view/GestureDetector.cpp \
	device/view/viewGroup.cpp \
	device/view/view.cpp \
	native/NParamBox.cpp \
	native/NElement.cpp \
	native/NVisitor.cpp \
	native/NFrame.cpp \
	native/NClozer.cpp \
	native/NAPI.cpp \
	native/NWrapper.cpp \
	native/NVisitorView.cpp \
	BOMessage.cpp \
	WidgetMessageEdit.cpp \
	WidgetMessageDetails.cpp \
	WidgetMessage.cpp \
	WidgetSettings.cpp \
	WidgetAbout.cpp \
	WidgetHome.cpp \
	FragmentViewEdit.cpp \
	FragmentViewDetails.cpp \
	FragmentViewSettings.cpp \
	FragmentViewAbout.cpp \
	FragmentViewHome.cpp \
	FragmentLevel.cpp \
	FragmentLevel2.cpp \
	FragmentLevel1.cpp \
	FragmentLevel0.cpp \
	RootLayout.cpp \
	OpUnitAnim.cpp \
	OpUnitNetwork.cpp \
	OpUnitListener.cpp \
	OpUnitPeer.cpp \
	OpUnitServer.cpp \
	OpUnitUI.cpp \
	OpUnitCore.cpp \
	Peer.cpp \
	NActivity.cpp

LOCAL_LDLIBS := \
	-llog \
	-lm

include $(BUILD_SHARED_LIBRARY)
