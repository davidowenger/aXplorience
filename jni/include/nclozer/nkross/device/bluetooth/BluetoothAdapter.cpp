#include <nkross/NKrossCommon.h>

namespace NSDEVICE
{

BluetoothAdapter::LeScanCallback::LeScanCallback()
{
    NKrossWrapper::w->mNVisitorBluetooth->tRun(NKrossWrapper::w->mNDzeta02, (NParam)this);
}

BluetoothAdapter::LeScanCallback::~LeScanCallback()
{
    NKrossWrapper::w->mNKrossSystem->tRun(NKrossWrapper::w->mNDelta00, (NParam)this);
}

BluetoothAdapter* BluetoothAdapter::getDefaultAdapter()
{
    BluetoothAdapter* b = NKrossWrapper::w->mNKrossFriend->pointer<BluetoothAdapter>();
    return NKrossWrapper::w->mNKrossFriend->emplaceKey(b, NKrossWrapper::w->mNVisitorBluetooth->tRun(NKrossWrapper::w->mNAlpha00, (NParam)b));
}

bool BluetoothAdapter::checkBluetoothAddress(const String& address)
{
    return (bool)NKrossWrapper::w->mNVisitorBluetooth->tRun(NKrossWrapper::w->mNRho00, NKrossParam(address).n);
}

BluetoothAdapter::~BluetoothAdapter()
{
}

BluetoothLeAdvertiser* BluetoothAdapter::getBluetoothLeAdvertiser()
{
    BluetoothLeAdvertiser* b = NKrossWrapper::w->mNKrossFriend->pointer<BluetoothLeAdvertiser>();
    return NKrossWrapper::w->mNKrossFriend->emplaceKey(b, NKrossWrapper::w->mNVisitorBluetooth->tRun(NKrossWrapper::w->mNPsi00, (NParam)this, (NParam)b));
}

BluetoothLeScanner* BluetoothAdapter::getBluetoothLeScanner()
{
    BluetoothLeScanner* b = NKrossWrapper::w->mNKrossFriend->pointer<BluetoothLeScanner>();
    return NKrossWrapper::w->mNKrossFriend->emplaceKey(b, NKrossWrapper::w->mNVisitorBluetooth->tRun(NKrossWrapper::w->mNOmega00, (NParam)this, (NParam)b));
}

BluetoothDevice* BluetoothAdapter::getRemoteDevice(const String& address)
{
    BluetoothDevice* b = NKrossWrapper::w->mNKrossFriend->pointer<BluetoothDevice>();
    return NKrossWrapper::w->mNKrossFriend->emplaceKey(b, NKrossWrapper::w->mNVisitorBluetooth->tRun(NKrossWrapper::w->mNBeta00, (NParam)this, (NParam)b, NKrossParam(address).n));
}

bool BluetoothAdapter::isEnabled()
{
    return NKrossWrapper::w->mNVisitorBluetooth->tRun(NKrossWrapper::w->mNGamma00, (NParam)this);
}

bool BluetoothAdapter::isMultipleAdvertisementSupported()
{
    return NKrossWrapper::w->mNVisitorBluetooth->tRun(NKrossWrapper::w->mNRho01, (NParam)this);
}

int BluetoothAdapter::getState()
{
    return NKrossWrapper::w->mNVisitorBluetooth->tRun(NKrossWrapper::w->mNDelta00, (NParam)this);
}

bool BluetoothAdapter::enable()
{
    return NKrossWrapper::w->mNVisitorBluetooth->tRun(NKrossWrapper::w->mNEpsilon00, (NParam)this);
}

bool BluetoothAdapter::disable()
{
    return NKrossWrapper::w->mNVisitorBluetooth->tRun(NKrossWrapper::w->mNDzeta00, (NParam)this);
}

String BluetoothAdapter::getAddress()
{
    NReturn index = NKrossWrapper::w->mNVisitorBluetooth->tRun(NKrossWrapper::w->mNEta00, (NParam)this);
    return NKrossWrapper::w->mNKrossSystem->tGetString(NKrossWrapper::w->mNKrossSystem->tRunObject((NParam)index));
}

String BluetoothAdapter::getName()
{
    NReturn index = NKrossWrapper::w->mNVisitorBluetooth->tRun(NKrossWrapper::w->mNTheta00, (NParam)this);
    return NKrossWrapper::w->mNKrossSystem->tGetString(NKrossWrapper::w->mNKrossSystem->tRunObject((NParam)index));
}

bool BluetoothAdapter::setName(const String& name)
{
    return (bool)NKrossWrapper::w->mNVisitorBluetooth->tRun(NKrossWrapper::w->mNIota00, (NParam)this, NKrossParam(name).n);
}

int BluetoothAdapter::getScanMode()
{
    return (nint)NKrossWrapper::w->mNVisitorBluetooth->tRun(NKrossWrapper::w->mNKappa00, (NParam)this);
}

bool BluetoothAdapter::startDiscovery()
{
    return (bool)NKrossWrapper::w->mNVisitorBluetooth->tRun(NKrossWrapper::w->mNLambda00, (NParam)this);
}

bool BluetoothAdapter::startLeScan(BluetoothAdapter::LeScanCallback* callback)
{
    return (bool)NKrossWrapper::w->mNVisitorBluetooth->tRun(NKrossWrapper::w->mNKhi00, (NParam)this, (NParam)callback);
}

bool BluetoothAdapter::startLeScan(NArray<String> serviceUuids, BluetoothAdapter::LeScanCallback* callback)
{
    nuint vcIndex;
    nlong vcKey = NKrossWrapper::w->mNKrossSystem->tRun(NKrossWrapper::w->mNBeta01, 0, serviceUuids.mcData);
    NParamObject* vaTString = new NParamObject[serviceUuids.mcData]();

    for (vcIndex = 0 ; vcIndex < serviceUuids.mcData ; ++vcIndex) {
        vaTString[vcIndex] = NKrossWrapper::w->mNKrossSystem->tRunString(serviceUuids.maData[vcIndex]);
        NKrossWrapper::w->mNKrossSystem->tRun(NKrossWrapper::w->mNBeta01, vcKey, vcIndex, (NParam)&vaTString[vcIndex]);
    };
    vcKey = (nuint)NKrossWrapper::w->mNVisitorBluetooth->tRun(NKrossWrapper::w->mNUpsilon00, (NParam)this, (NParam)vcKey, (NParam)callback);

    for (vcIndex = 0 ; vcIndex < serviceUuids.mcData ; ++vcIndex) {
        NKrossWrapper::w->mNKrossSystem->tDeleteGlobalRef(vaTString[vcIndex]);
    };
    return (bool)vcKey;
}

void BluetoothAdapter::stopLeScan(BluetoothAdapter::LeScanCallback* callback)
{
    NKrossWrapper::w->mNVisitorBluetooth->tRun(NKrossWrapper::w->mNPhi00, (NParam)this, (NParam)callback);
}

bool BluetoothAdapter::cancelDiscovery()
{
    return (bool)NKrossWrapper::w->mNVisitorBluetooth->tRun(NKrossWrapper::w->mNMu00, (NParam)this);
}

bool BluetoothAdapter::isDiscovering()
{
    return (bool)NKrossWrapper::w->mNVisitorBluetooth->tRun(NKrossWrapper::w->mNNu00, (NParam)this);
}

void* BluetoothAdapter::getBondedDevices()
{
    //TODO: implement
    //Set<BluetoothDevice>
    //return NKrossWrapper::w->mNVisitorBluetooth->tRun(NKrossWrapper::w->mNxi00, (NParam)this);
    return NULL;
}

BluetoothServerSocket* BluetoothAdapter::listenUsingInsecureRfcommOn(int channel)
{
    BluetoothServerSocket* b = NKrossWrapper::w->mNKrossFriend->pointer<BluetoothServerSocket>();
    return NKrossWrapper::w->mNKrossFriend->emplaceKey(b, NKrossWrapper::w->mNVisitorBluetooth->tRun(NKrossWrapper::w->mNTau00, (NParam)this, (NParam)b, (NParam)channel));
}

BluetoothServerSocket* BluetoothAdapter::listenUsingInsecureRfcommWithServiceRecord(const String& name, const String& uuid)
{
    BluetoothServerSocket* b = NKrossWrapper::w->mNKrossFriend->pointer<BluetoothServerSocket>();
    return NKrossWrapper::w->mNKrossFriend->emplaceKey(b, NKrossWrapper::w->mNVisitorBluetooth->tRun(NKrossWrapper::w->mNPi00, (NParam)this, (NParam)b, NKrossParam(name).n, NKrossParam(uuid).n));
}

BluetoothServerSocket* BluetoothAdapter::listenUsingRfcommWithServiceRecord(const String& name, const String& uuid)
{
    BluetoothServerSocket* b = NKrossWrapper::w->mNKrossFriend->pointer<BluetoothServerSocket>();
    return NKrossWrapper::w->mNKrossFriend->emplaceKey(b, NKrossWrapper::w->mNVisitorBluetooth->tRun(NKrossWrapper::w->mNOmicron00, (NParam)this, (NParam)b, NKrossParam(name).n, NKrossParam(uuid).n));
}

void BluetoothAdapter::discoverable()
{
    discoverable(0);
}

void BluetoothAdapter::discoverable(int cTimeout)
{
    NKrossWrapper::w->mNVisitorBluetooth->tRun(NKrossWrapper::w->mNSigma00, cTimeout);
}

} // End namespace
