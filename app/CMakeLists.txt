# Sets the minimum version of CMake required to build your native library.
# This ensures that a certain set of CMake features is available to
# your build.

cmake_minimum_required(VERSION 3.4.1)

# Base directory
set( base_dir ${CMAKE_CURRENT_LIST_DIR}/src/main/cpp )

# Set compile flags for Release build
add_compile_options("$<$<CONFIG:RELEASE>:-O3>")
add_compile_options("$<$<CONFIG:RELEASE>:-DNDEBUG>")
add_compile_options("$<$<CONFIG:RELEASE>:-std=c++11>")

# Set compile flags for Debug build
add_compile_options("$<$<CONFIG:DEBUG>:-g>")
add_compile_options("$<$<CONFIG:DEBUG>:-std=c++11>")

##
# Configure the native module
##

# Specifies a library name, specifies whether the library is STATIC or
# SHARED, and provides relative paths to the source code. You can
# define multiple libraries by adding multiple add.library() commands,
# and CMake builds them for you. When you build your app, Gradle
# automatically packages shared libraries with your APK.
add_library(
    # Specifies the name of the library
    TActivity
    # Sets the library as a shared library
    SHARED
    # Provides a relative path to your source files
	src/main/cpp/include/nclozer/db/DBFile.cpp
	src/main/cpp/include/nclozer/db/DBHandler.cpp
	src/main/cpp/include/nclozer/graphics/GraphicsHandler.cpp
	src/main/cpp/include/nclozer/graphics/GraphicsProgram.cpp
	src/main/cpp/include/nclozer/nkross/device/bluetooth/BluetoothAdapter.cpp
	src/main/cpp/include/nclozer/nkross/device/bluetooth/BluetoothDevice.cpp
	src/main/cpp/include/nclozer/nkross/device/bluetooth/BluetoothSocket.cpp
	src/main/cpp/include/nclozer/nkross/device/bluetooth/BluetoothServerSocket.cpp
	src/main/cpp/include/nclozer/nkross/device/content/Context.cpp
	src/main/cpp/include/nclozer/nkross/device/graphics/Typeface.cpp
	src/main/cpp/include/nclozer/nkross/device/hardware/Camera.cpp
	src/main/cpp/include/nclozer/nkross/device/location/LocationManager.cpp
	src/main/cpp/include/nclozer/nkross/device/view/GestureDetector.cpp
	src/main/cpp/include/nclozer/nkross/device/view/View.cpp
	src/main/cpp/include/nclozer/nkross/device/view/ViewGroup.cpp
	src/main/cpp/include/nclozer/nkross/os/android.cpp
	src/main/cpp/include/nclozer/nkross/NKrossParam.cpp
	src/main/cpp/include/nclozer/nkross/NKrossSystem.cpp
	src/main/cpp/include/nclozer/nkross/NKrossVisitor.cpp
	src/main/cpp/include/nclozer/op/OpParam.cpp
	src/main/cpp/include/nclozer/op/OpSquad.cpp
	src/main/cpp/include/nclozer/op/OpUnit.cpp
	src/main/cpp/include/nclozer/NCommon.cpp
	src/main/cpp/include/nclozer/NElement.cpp
	src/main/cpp/include/nclozer/NVisitor.cpp
	src/main/cpp/src/AREngine.cpp
	src/main/cpp/src/BOMessage.cpp
	src/main/cpp/src/BOPOI.cpp
	src/main/cpp/src/NActivity.cpp
	src/main/cpp/src/OpUnitEvents.cpp
	src/main/cpp/src/OpUnitAnim.cpp
	src/main/cpp/src/OpUnitListener.cpp
	src/main/cpp/src/OpUnitPeer.cpp
	src/main/cpp/src/OpUnitServer.cpp
	src/main/cpp/src/OpUnitCore.cpp
	src/main/cpp/src/OpUnitUI.cpp
	src/main/cpp/src/FragmentLevel.cpp
	src/main/cpp/src/FragmentLevel0.cpp
	src/main/cpp/src/FragmentLevel1.cpp
	src/main/cpp/src/FragmentLevel2.cpp
	src/main/cpp/src/RootLayout.cpp
	src/main/cpp/src/WidgetAR.cpp
	src/main/cpp/src/WidgetAbout.cpp
	src/main/cpp/src/WidgetHome.cpp
	src/main/cpp/src/WidgetSettings.cpp
	src/main/cpp/src/WidgetMessage.cpp
	src/main/cpp/src/WidgetMessageDetails.cpp
	src/main/cpp/src/WidgetMessageEdit.cpp
	src/main/cpp/src/FragmentViewEdit.cpp
	src/main/cpp/src/FragmentViewDetails.cpp
	src/main/cpp/src/FragmentViewSettings.cpp
	src/main/cpp/src/FragmentViewAbout.cpp
	src/main/cpp/src/FragmentViewAR.cpp
	src/main/cpp/src/FragmentViewHome.cpp
)

# Specifies a path to native header files
include_directories(
    src/main/cpp/include/nclozer
    src/main/cpp/src
)

##
# Add NDK binary libraries
##

find_library(
    # Defines the name of the path variable that stores the
    # location of the NDK library
    log-lib
    # Specifies the name of the NDK library that
    # CMake needs to locate
    log
)
find_library(
    m-lib
    m
)
find_library(
    android-lib
    android
)
find_library(
    EGL-lib
    EGL
)
find_library(
    GLESv2-lib
    GLESv2
)

##
# Add other prebuilt libraries
##

add_library(
    freetype2-lib
    STATIC
    IMPORTED
)

set_target_properties(
    # Specifies the target library.
    freetype2-lib
    # Specifies the parameter you want to define.
    PROPERTIES IMPORTED_LOCATION
    # Provides the path to the library you want to import
    ${base_dir}/libs/freetype2/libfreetype.a
)

include_directories( src/main/cpp/include/freetype2 )

##
# Link the libraries
##

# You need to link static libraries against your shared native library
# If you want to package a prebuilt library that is not a build-time dependency, for example when
# adding a prebuilt library that is a dependency of imported-lib, you do not need perform the
# following instructions to link the library
# Links your native library against one or more other native libraries
target_link_libraries(
    TActivity
    freetype2-lib
    ${log-lib}
    ${m-lib}
    ${android-lib}
    ${EGL-lib}
    ${GLESv2-lib}
)
