#ifndef __NKrossCommon_H__
#define __NKrossCommon_H__

#include <NCommon.h>

namespace NSDEVICE
{

using NSNATIVE::NKrossWrapper;

class Bundle;
class FragmentTransaction;
class FragmentManager;
class Activity;
class View;
class ViewGroup;
class BluetoothAdapter;
class BluetoothDevice;
class BluetoothManager;

} // END namespace

namespace NSNATIVE
{

using namespace NSDEVICE;

class NVisitor;
class NKrossVisitor;
class NKrossSystem;
class NVisitorApp;
class NVisitorAppActivity;
class NVisitorAppFragment;
class NVisitorBluetooth;
class NVisitorBluetoothLe;
class NVisitorContentRes;
class NVisitorIO;
class NVisitorView;
class NVisitorWidget;

} // END namespace

#include "NArray.h"
#include "NElement.h"
#include "NVisitor.h"
#include "NWrapper.h"

#include "NKrossFriend.h"
#include "NKrossParam.h"
#include "NKrossWrapper.h"
#include "NKrossVisitor.h"
#include "NKrossSystem.h"
#include "NKrossHolder.h"

#include "device/lang/object.h"
#include "device/R.h"
#include "device/util/DisplayMetrics.h"
#include "device/os/Build.h"
#include "device/os/BaseBundle.h"
#include "device/os/Bundle.h"
#include "device/os/Looper.h"
#include "device/os/ParcelUuid.h"
#include "device/graphics/drawable/Drawable.h"
#include "device/graphics/drawable/ColorDrawable.h"
#include "device/graphics/drawable/DrawableContainer.h"
#include "device/graphics/drawable/StateListDrawable.h"
#include "device/graphics/SurfaceTexture.h"
#include "device/graphics/Typeface.h"
#include "device/location/Location.h"
#include "device/location/LocationListener.h"
#include "device/location/LocationProvider.h"
#include "device/location/LocationManager.h"
#include "device/content/res/Configuration.h"
#include "device/content/res/Resources.h"
#include "device/content/Context.h"
#include "device/content/ContextWrapper.h"
#include "device/text/InputType.h"
#include "device/view/inputmethod/EditorInfo.h"
#include "device/view/Gravity.h"
#include "device/view/InputEvent.h"
#include "device/view/MotionEvent.h"
#include "device/view/GestureDetector.h"
#include "device/view/MenuItem.h"
#include "device/view/Menu.h"
#include "device/view/MenuInflater.h"
#include "device/view/LayoutInflater.h"
#include "device/view/ContextMenu.h"
#include "device/view/ContextThemeWrapper.h"
#include "device/view/Display.h"
#include "device/view/View.h"
#include "device/view/ViewGroup.h"
#include "device/view/Surface.h"
#include "device/view/SurfaceHolder.h"
#include "device/view/SurfaceView.h"
#include "device/view/WindowManager.h"
#include "device/view/Window.h"
#include "device/opengl/GLSurfaceView.h"
#include "device/io/InputStream.h"
#include "device/io/OutputStream.h"
#include "device/hardware/Camera.h"
#include "device/hardware/Sensor.h"
#include "device/bluetooth/le/ScanRecord.h"
#include "device/bluetooth/le/ScanResult.h"
#include "device/bluetooth/le/ScanCallback.h"
#include "device/bluetooth/le/AdvertiseSettings.h"
#include "device/bluetooth/le/AdvertiseCallback.h"
#include "device/bluetooth/le/AdvertiseData.h"
#include "device/bluetooth/le/BluetoothLeAdvertiser.h"
#include "device/bluetooth/le/BluetoothLeScanner.h"
#include "device/bluetooth/BluetoothProfile.h"
#include "device/bluetooth/BluetoothGattDescriptor.h"
#include "device/bluetooth/BluetoothGattCharacteristic.h"
#include "device/bluetooth/BluetoothGattService.h"
#include "device/bluetooth/BluetoothGatt.h"
#include "device/bluetooth/BluetoothGattCallback.h"
#include "device/bluetooth/BluetoothGattServerCallback.h"
#include "device/bluetooth/BluetoothGattServer.h"
#include "device/bluetooth/BluetoothManager.h"
#include "device/bluetooth/BluetoothSocket.h"
#include "device/bluetooth/BluetoothServerSocket.h"
#include "device/bluetooth/BluetoothDevice.h"
#include "device/bluetooth/BluetoothAdapter.h"
#include "device/app/ActionBar.h"
#include "device/app/Application.h"
#include "device/app/Activity.h"
#include "device/app/Fragment.h"
#include "device/app/FragmentTransaction.h"
#include "device/app/FragmentManager.h"
#include "device/widget/Adapter.h"
#include "device/widget/SpinnerAdapter.h"
#include "device/widget/BaseAdapter.h"
#include "device/widget/AdapterView.h"
#include "device/widget/AbsListView.h"
#include "device/widget/AbsSpinner.h"
#include "device/widget/Spinner.h"
#include "device/widget/TextView.h"
#include "device/widget/Button.h"
#include "device/widget/CompoundButton.h"
#include "device/widget/ImageView.h"
#include "device/widget/EditText.h"
#include "device/widget/ImageButton.h"
#include "device/widget/ToggleButton.h"
#include "device/widget/LinearLayout.h"
#include "device/widget/FrameLayout.h"
#include "device/widget/ScrollView.h"

#include "visitor/NVisitorApp.h"
#include "visitor/NVisitorAppActivity.h"
#include "visitor/NVisitorAppFragment.h"
#include "visitor/NVisitorBluetooth.h"
#include "visitor/NVisitorBluetoothGatt.h"
#include "visitor/NVisitorBluetoothLe.h"
#include "visitor/NVisitorContent.h"
#include "visitor/NVisitorContentRes.h"
#include "visitor/NVisitorIO.h"
#include "visitor/NVisitorOpengl.h"
#include "visitor/NVisitorOS.h"
#include "visitor/NVisitorGraphics.h"
#include "visitor/NVisitorHardware.h"
#include "visitor/NVisitorLocation.h"
#include "visitor/NVisitorMicroedition.h"
#include "visitor/NVisitorUtil.h"
#include "visitor/NVisitorView.h"
#include "visitor/NVisitorViewView.h"
#include "visitor/NVisitorViewViewGroup.h"
#include "visitor/NVisitorWidget.h"
#include "visitor/NVisitorWidgetLayout.h"
#include "visitor/NVisitorWidgetView.h"

//*******************************************************************************
//******************************** ANDROID **************************************
//*******************************************************************************
#ifdef TARGET_ANDROID

#include "os/android.h"

#endif // TARGET_ANDROID

#endif
