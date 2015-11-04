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
    BluetoothGatt* b = NSNKROSS::w->mNKrossFriend->pointer<BluetoothGatt>();
    return NSNKROSS::w->mNKrossFriend->emplaceKey(b, NSNKROSS::w->mNVisitorBluetooth->tRun(NSNKROSS::w->mNXi01, (NParam)this, (NParam)b, (NParam)context, (NParam)autoConnect, (NParam)callback));
}

BluetoothGatt* BluetoothDevice::connectGatt(Context* context, bool autoConnect, BluetoothGattCallback* callback, int transport)
{
    BluetoothGatt* b = NSNKROSS::w->mNKrossFriend->pointer<BluetoothGatt>();
    return NSNKROSS::w->mNKrossFriend->emplaceKey(b, NSNKROSS::w->mNVisitorBluetooth->tRun(NSNKROSS::w->mNOmicron01, (NParam)this, (NParam)b, (NParam)context, (((NParam)transport)<<32) + autoConnect, (NParam)callback));
}

bool BluetoothDevice::equals(BluetoothDevice* dBluetoothDevice)
{
    return (bool)NSNKROSS::w->mNVisitorBluetooth->tRun(NSNKROSS::w->mNAlpha01, (NParam)this, (NParam)dBluetoothDevice);
}

int BluetoothDevice::hashCode()
{
    return (nint)NSNKROSS::w->mNVisitorBluetooth->tRun(NSNKROSS::w->mNBeta01, (NParam)this);
}

String BluetoothDevice::toString()
{
    NReturn index = NSNKROSS::w->mNVisitorBluetooth->tRun(NSNKROSS::w->mNGamma01, (NParam)this);
    return NSNKROSS::w->mNKrossSystem->tGetString(NSNKROSS::w->mNKrossSystem->tRunObject((NParam)index));
}

int BluetoothDevice::describeContents()
{
    return (nint)NSNKROSS::w->mNVisitorBluetooth->tRun(NSNKROSS::w->mNDelta01, (NParam)this);
}

void BluetoothDevice::writeToParcel(void* out, int flags)
{
    //TODO: implement
    //NSNKROSS::w->mNVisitorBluetooth->tRun(NSNKROSS::w->mNepsilon01, (NParam)this, (NParam)out, (NParam)flags);
}

String BluetoothDevice::getAddress()
{
    NReturn index = NSNKROSS::w->mNVisitorBluetooth->tRun(NSNKROSS::w->mNDzeta01, (NParam)this);
    return NSNKROSS::w->mNKrossSystem->tGetString(NSNKROSS::w->mNKrossSystem->tRunObject((NParam)index));
}

String BluetoothDevice::getName()
{
    NReturn index = NSNKROSS::w->mNVisitorBluetooth->tRun(NSNKROSS::w->mNEta01, (NParam)this);
    return NSNKROSS::w->mNKrossSystem->tGetString(NSNKROSS::w->mNKrossSystem->tRunObject((NParam)index));
}

int BluetoothDevice::getBondState()
{
    return (nint)NSNKROSS::w->mNVisitorBluetooth->tRun(NSNKROSS::w->mNTheta01, (NParam)this);
}

BluetoothClass* BluetoothDevice::getBluetoothClass()
{
    BluetoothClass* b = NSNKROSS::w->mNKrossFriend->pointer<BluetoothClass>();
    return NSNKROSS::w->mNKrossFriend->emplaceKey(b, NSNKROSS::w->mNVisitorBluetooth->tRun(NSNKROSS::w->mNIota01, (NParam)this, (NParam)b));
}

int BluetoothDevice::getType()
{
    return (nint)NSNKROSS::w->mNVisitorBluetooth->tRun(NSNKROSS::w->mNPi01, (NParam)this);
}

BluetoothSocket* BluetoothDevice::createInsecureRfcommSocket(int port)
{
    BluetoothSocket* b = NSNKROSS::w->mNKrossFriend->pointer<BluetoothSocket>();
    return NSNKROSS::w->mNKrossFriend->emplaceKey(b, NSNKROSS::w->mNVisitorBluetooth->tRun(NSNKROSS::w->mNNu01, (NParam)this, (NParam)b, (NParam)port));
}

BluetoothSocket* BluetoothDevice::createInsecureRfcommSocketToServiceRecord(const String& uuid)
{
    BluetoothSocket* b = NSNKROSS::w->mNKrossFriend->pointer<BluetoothSocket>();
    return NSNKROSS::w->mNKrossFriend->emplaceKey(b, NSNKROSS::w->mNVisitorBluetooth->tRun(NSNKROSS::w->mNLambda01, (NParam)this, (NParam)b, NKrossParam(uuid).n));
}

BluetoothSocket* BluetoothDevice::createRfcommSocketToServiceRecord(const String& uuid)
{
    BluetoothSocket* b = NSNKROSS::w->mNKrossFriend->pointer<BluetoothSocket>();
    return NSNKROSS::w->mNKrossFriend->emplaceKey(b, NSNKROSS::w->mNVisitorBluetooth->tRun(NSNKROSS::w->mNKappa01, (NParam)this, (NParam)b, NKrossParam(uuid).n));
}

vector<ParcelUuid*> BluetoothDevice::getUuids()
{
    NReturn index = NSNKROSS::w->mNVisitorBluetooth->tRun(NSNKROSS::w->mNMu01, (NParam)this);
    NReturn size = NSNKROSS::w->mNKrossSystem->tRun(NSNKROSS::w->mNAlpha01, index, -1);
    vector<ParcelUuid*> vVector(size);
    nuint i;

    for (i = 0 ; i < size ; ++i) {
        ParcelUuid* b = NSNKROSS::w->mNKrossFriend->pointer<ParcelUuid>();
        vVector.push_back(NSNKROSS::w->mNKrossFriend->emplaceKey(b, NSNKROSS::w->mNKrossSystem->tRun(NSNKROSS::w->mNAlpha01, index, (NParam)i, (NParam)b)));
    }
    return vVector;
}

} // End namespace
