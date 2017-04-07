#include <nkross/NKrossCommon.h>

namespace NSDEVICE
{

const String BluetoothDevice::ACTION_FOUND = "android.bluetooth.device.action.FOUND";
const String BluetoothDevice::ACTION_DISAPPEARED = "android.bluetooth.device.action.DISAPPEARED";
const String BluetoothDevice::ACTION_CLASS_CHANGED = "android.bluetooth.device.action.CLASS_CHANGED";
const String BluetoothDevice::ACTION_ACL_CONNECTED = "android.bluetooth.device.action.ACL_CONNECTED";
const String BluetoothDevice::ACTION_ACL_DISCONNECT_REQUESTED = "android.bluetooth.device.action.ACL_DISCONNECT_REQUESTED";
const String BluetoothDevice::ACTION_ACL_DISCONNECTED = "android.bluetooth.device.action.ACL_DISCONNECTED";
const String BluetoothDevice::ACTION_NAME_CHANGED = "android.bluetooth.device.action.NAME_CHANGED";
const String BluetoothDevice::ACTION_BOND_STATE_CHANGED = "android.bluetooth.device.action.BOND_STATE_CHANGED";

const String BluetoothDevice::EXTRA_DEVICE = "android.bluetooth.device.extra.DEVICE";
const String BluetoothDevice::EXTRA_NAME = "android.bluetooth.device.extra.NAME";
const String BluetoothDevice::EXTRA_RSSI = "android.bluetooth.device.extra.RSSI";
const String BluetoothDevice::EXTRA_CLASS = "android.bluetooth.device.extra.CLASS";
const String BluetoothDevice::EXTRA_BOND_STATE = "android.bluetooth.device.extra.BOND_STATE";
const String BluetoothDevice::EXTRA_PREVIOUS_BOND_STATE = "android.bluetooth.device.extra.PREVIOUS_BOND_STATE";

BluetoothGatt* BluetoothDevice::connectGatt(Context* context, bool autoConnect, BluetoothGattCallback* callback)
{
    BluetoothGatt* b = NKrossWrapper::w->mNKrossFriend->pointer<BluetoothGatt>();
    return NKrossWrapper::w->mNKrossFriend->emplaceKey(b, NKrossWrapper::w->mNVisitorBluetooth->tRun(NKrossWrapper::w->mNXi01, (NParam)this, (NParam)b, (NParam)context, (NParam)autoConnect, (NParam)callback));
}

BluetoothGatt* BluetoothDevice::connectGatt(Context* context, bool autoConnect, BluetoothGattCallback* callback, int transport)
{
    BluetoothGatt* b = NKrossWrapper::w->mNKrossFriend->pointer<BluetoothGatt>();
    return NKrossWrapper::w->mNKrossFriend->emplaceKey(b, NKrossWrapper::w->mNVisitorBluetooth->tRun(NKrossWrapper::w->mNOmicron01, (NParam)this, (NParam)b, (NParam)context, (((NParam)transport)<<32) + autoConnect, (NParam)callback));
}

bool BluetoothDevice::equals(BluetoothDevice* dBluetoothDevice)
{
    return (bool)NKrossWrapper::w->mNVisitorBluetooth->tRun(NKrossWrapper::w->mNAlpha01, (NParam)this, (NParam)dBluetoothDevice);
}

int BluetoothDevice::hashCode()
{
    return (nint)NKrossWrapper::w->mNVisitorBluetooth->tRun(NKrossWrapper::w->mNBeta01, (NParam)this);
}

String BluetoothDevice::toString()
{
    NReturn index = NKrossWrapper::w->mNVisitorBluetooth->tRun(NKrossWrapper::w->mNGamma01, (NParam)this);
    return NKrossWrapper::w->mNKrossSystem->tGetString(NKrossWrapper::w->mNKrossSystem->tRunObject((NParam)index));
}

int BluetoothDevice::describeContents()
{
    return (nint)NKrossWrapper::w->mNVisitorBluetooth->tRun(NKrossWrapper::w->mNDelta01, (NParam)this);
}

void BluetoothDevice::writeToParcel(void* out, int flags)
{
    //TODO: implement
    //NKrossWrapper::w->mNVisitorBluetooth->tRun(NKrossWrapper::w->mNepsilon01, (NParam)this, (NParam)out, (NParam)flags);
}

String BluetoothDevice::getAddress()
{
    NReturn index = NKrossWrapper::w->mNVisitorBluetooth->tRun(NKrossWrapper::w->mNDzeta01, (NParam)this);
    return NKrossWrapper::w->mNKrossSystem->tGetString(NKrossWrapper::w->mNKrossSystem->tRunObject((NParam)index));
}

String BluetoothDevice::getName()
{
    NReturn index = NKrossWrapper::w->mNVisitorBluetooth->tRun(NKrossWrapper::w->mNEta01, (NParam)this);
    return NKrossWrapper::w->mNKrossSystem->tGetString(NKrossWrapper::w->mNKrossSystem->tRunObject((NParam)index));
}

int BluetoothDevice::getBondState()
{
    return (nint)NKrossWrapper::w->mNVisitorBluetooth->tRun(NKrossWrapper::w->mNTheta01, (NParam)this);
}

BluetoothClass* BluetoothDevice::getBluetoothClass()
{
    BluetoothClass* b = NKrossWrapper::w->mNKrossFriend->pointer<BluetoothClass>();
    return NKrossWrapper::w->mNKrossFriend->emplaceKey(b, NKrossWrapper::w->mNVisitorBluetooth->tRun(NKrossWrapper::w->mNIota01, (NParam)this, (NParam)b));
}

int BluetoothDevice::getType()
{
    return (nint)NKrossWrapper::w->mNVisitorBluetooth->tRun(NKrossWrapper::w->mNPi01, (NParam)this);
}

BluetoothSocket* BluetoothDevice::createInsecureRfcommSocket(int port)
{
    BluetoothSocket* b = NKrossWrapper::w->mNKrossFriend->pointer<BluetoothSocket>();
    return NKrossWrapper::w->mNKrossFriend->emplaceKey(b, NKrossWrapper::w->mNVisitorBluetooth->tRun(NKrossWrapper::w->mNNu01, (NParam)this, (NParam)b, (NParam)port));
}

BluetoothSocket* BluetoothDevice::createInsecureRfcommSocketToServiceRecord(const String& uuid)
{
    BluetoothSocket* b = NKrossWrapper::w->mNKrossFriend->pointer<BluetoothSocket>();
    return NKrossWrapper::w->mNKrossFriend->emplaceKey(b, NKrossWrapper::w->mNVisitorBluetooth->tRun(NKrossWrapper::w->mNLambda01, (NParam)this, (NParam)b, NKrossParam(uuid).n));
}

BluetoothSocket* BluetoothDevice::createRfcommSocketToServiceRecord(const String& uuid)
{
    BluetoothSocket* b = NKrossWrapper::w->mNKrossFriend->pointer<BluetoothSocket>();
    return NKrossWrapper::w->mNKrossFriend->emplaceKey(b, NKrossWrapper::w->mNVisitorBluetooth->tRun(NKrossWrapper::w->mNKappa01, (NParam)this, (NParam)b, NKrossParam(uuid).n));
}

vector<ParcelUuid*> BluetoothDevice::getUuids()
{
    NReturn index = NKrossWrapper::w->mNVisitorBluetooth->tRun(NKrossWrapper::w->mNMu01, (NParam)this);
    NReturn size = NKrossWrapper::w->mNKrossSystem->tRun(NKrossWrapper::w->mNAlpha01, index, -1);
    vector<ParcelUuid*> vVector(size);
    nuint i;

    for (i = 0 ; i < size ; ++i) {
        ParcelUuid* b = NKrossWrapper::w->mNKrossFriend->pointer<ParcelUuid>();
        vVector.push_back(NKrossWrapper::w->mNKrossFriend->emplaceKey(b, NKrossWrapper::w->mNKrossSystem->tRun(NKrossWrapper::w->mNAlpha01, index, (NParam)i, (NParam)b)));
    }
    return vVector;
}

} // End namespace
