#include "native/NCommon.h"

namespace NSDEVICE
{

const int BluetoothDevice::ERROR = -1 >> 1;
const int BluetoothDevice::BOND_NONE = 10;
const int BluetoothDevice::BOND_BONDING = 11;
const int BluetoothDevice::BOND_BONDED = 12;

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

bool BluetoothDevice::equals(BluetoothDevice* dBluetoothDevice)
{
    return (bool)NWrapper::w->mNVisitorBluetooth->tRun(NWrapper::w->mNAlpha01, (NParam)this, (NParam)dBluetoothDevice);
}

int BluetoothDevice::hashCode()
{
    return (nint)NWrapper::w->mNVisitorBluetooth->tRun(NWrapper::w->mNBeta01, (NParam)this);
}

String BluetoothDevice::toString()
{
    NReturn index = NWrapper::w->mNVisitorBluetooth->tRun(NWrapper::w->mNGamma01, (NParam)this);
    return NWrapper::w->nFrame->tGetString(NWrapper::w->nFrame->tRunObject((NParam)index));
}

int BluetoothDevice::describeContents()
{
    return (nint)NWrapper::w->mNVisitorBluetooth->tRun(NWrapper::w->mNDelta01, (NParam)this);
}

void BluetoothDevice::writeToParcel(void* out, int flags)
{
    //TODO: implement
    //NWrapper::w->mNVisitorBluetooth->tRun(NWrapper::w->mNepsilon01, (NParam)this, (NParam)out, (NParam)flags);
}

String BluetoothDevice::getAddress()
{
    NReturn index = NWrapper::w->mNVisitorBluetooth->tRun(NWrapper::w->mNDzeta01, (NParam)this);
    return NWrapper::w->nFrame->tGetString(NWrapper::w->nFrame->tRunObject((NParam)index));
}

String BluetoothDevice::getName()
{
    NReturn index = NWrapper::w->mNVisitorBluetooth->tRun(NWrapper::w->mNEta01, (NParam)this);
    return NWrapper::w->nFrame->tGetString(NWrapper::w->nFrame->tRunObject((NParam)index));
}

int BluetoothDevice::getBondState()
{
    return (nint)NWrapper::w->mNVisitorBluetooth->tRun(NWrapper::w->mNTheta01, (NParam)this);
}

BluetoothClass* BluetoothDevice::getBluetoothClass()
{
    BluetoothClass* b = NWrapper::w->mNNoObject->pointer<BluetoothClass>();
    return NWrapper::w->mNNoObject->emplaceKey(b, NWrapper::w->mNVisitorBluetooth->tRun(NWrapper::w->mNIota01, (NParam)this, (NParam)b));
}

BluetoothSocket* BluetoothDevice::createInsecureRfcommSocket(int port)
{
    BluetoothSocket* b = NWrapper::w->mNNoObject->pointer<BluetoothSocket>();
    return NWrapper::w->mNNoObject->emplaceKey(b, NWrapper::w->mNVisitorBluetooth->tRun(NWrapper::w->mNNu01, (NParam)this, (NParam)b, (NParam)port));
}

BluetoothSocket* BluetoothDevice::createInsecureRfcommSocketToServiceRecord(const String& uuid)
{
    BluetoothSocket* b = NWrapper::w->mNNoObject->pointer<BluetoothSocket>();
    return NWrapper::w->mNNoObject->emplaceKey(b, NWrapper::w->mNVisitorBluetooth->tRun(NWrapper::w->mNLambda01, (NParam)this, (NParam)b, NParamBox(NWrapper::w, uuid).n));
}

BluetoothSocket* BluetoothDevice::createRfcommSocketToServiceRecord(const String& uuid)
{
    BluetoothSocket* b = NWrapper::w->mNNoObject->pointer<BluetoothSocket>();
    return NWrapper::w->mNNoObject->emplaceKey(b, NWrapper::w->mNVisitorBluetooth->tRun(NWrapper::w->mNKappa01, (NParam)this, (NParam)b, NParamBox(NWrapper::w, uuid).n));
}

vector<ParcelUuid*> BluetoothDevice::getUuids()
{
    vector<ParcelUuid*> vaParcelUuid;
    NReturn index = NWrapper::w->mNVisitorBluetooth->tRun(NWrapper::w->mNMu01, (NParam)this);
    NReturn size = NWrapper::w->nFrame->tRun(NWrapper::w->mNAlpha01, (NParam)this, (NParam)index, -1, -1);
    int i;

    for (i = 0 ; i < size ; ++i) {
        ParcelUuid* b = NWrapper::w->mNNoObject->pointer<ParcelUuid>();
        ParcelUuid* key = NWrapper::w->mNNoObject->emplaceKey(b, NWrapper::w->nFrame->tRun(NWrapper::w->mNAlpha01, (NParam)this, (NParam)index, (NParam)i, (NParam)b));
        vaParcelUuid.push_back(key);
    }
    return vaParcelUuid;
}

} // End namespace
