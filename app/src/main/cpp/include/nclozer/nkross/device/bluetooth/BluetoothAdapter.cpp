#include <nkross/NKrossCommon.h>

namespace NSDEVICE
{

BluetoothAdapter::LeScanCallback::LeScanCallback()
{
    NSNKROSS::w->mNVisitorBluetooth->tRun(NSNKROSS::w->mNDzeta02, (NParam)this);
}

BluetoothAdapter::LeScanCallback::~LeScanCallback()
{
    NSNKROSS::w->mNKrossSystem->tRun(NSNKROSS::w->mNDelta00, (NParam)this);
}

BluetoothAdapter* BluetoothAdapter::getDefaultAdapter()
{
    BluetoothAdapter* b = NSNKROSS::w->mNKrossFriend->pointer<BluetoothAdapter>();
    return NSNKROSS::w->mNKrossFriend->emplaceKey(b, NSNKROSS::w->mNVisitorBluetooth->tRun(NSNKROSS::w->mNAlpha00, (NParam)b));
}

bool BluetoothAdapter::checkBluetoothAddress(const String& address)
{
    return (bool)NSNKROSS::w->mNVisitorBluetooth->tRun(NSNKROSS::w->mNRho00, NKrossParam(address).n);
}

BluetoothAdapter::~BluetoothAdapter()
{
}

BluetoothLeAdvertiser* BluetoothAdapter::getBluetoothLeAdvertiser()
{
    BluetoothLeAdvertiser* b = NSNKROSS::w->mNKrossFriend->pointer<BluetoothLeAdvertiser>();
    return NSNKROSS::w->mNKrossFriend->emplaceKey(b, NSNKROSS::w->mNVisitorBluetooth->tRun(NSNKROSS::w->mNPsi00, (NParam)this, (NParam)b));
}

BluetoothLeScanner* BluetoothAdapter::getBluetoothLeScanner()
{
    BluetoothLeScanner* b = NSNKROSS::w->mNKrossFriend->pointer<BluetoothLeScanner>();
    return NSNKROSS::w->mNKrossFriend->emplaceKey(b, NSNKROSS::w->mNVisitorBluetooth->tRun(NSNKROSS::w->mNOmega00, (NParam)this, (NParam)b));
}

BluetoothDevice* BluetoothAdapter::getRemoteDevice(const String& address)
{
    BluetoothDevice* b = NSNKROSS::w->mNKrossFriend->pointer<BluetoothDevice>();
    return NSNKROSS::w->mNKrossFriend->emplaceKey(b, NSNKROSS::w->mNVisitorBluetooth->tRun(NSNKROSS::w->mNBeta00, (NParam)this, (NParam)b, NKrossParam(address).n));
}

bool BluetoothAdapter::isEnabled()
{
    return NSNKROSS::w->mNVisitorBluetooth->tRun(NSNKROSS::w->mNGamma00, (NParam)this);
}

bool BluetoothAdapter::isMultipleAdvertisementSupported()
{
    return NSNKROSS::w->mNVisitorBluetooth->tRun(NSNKROSS::w->mNRho01, (NParam)this);
}

int BluetoothAdapter::getState()
{
    return NSNKROSS::w->mNVisitorBluetooth->tRun(NSNKROSS::w->mNDelta00, (NParam)this);
}

bool BluetoothAdapter::enable()
{
    return NSNKROSS::w->mNVisitorBluetooth->tRun(NSNKROSS::w->mNEpsilon00, (NParam)this);
}

bool BluetoothAdapter::disable()
{
    return NSNKROSS::w->mNVisitorBluetooth->tRun(NSNKROSS::w->mNDzeta00, (NParam)this);
}

String BluetoothAdapter::getAddress()
{
    NReturn index = NSNKROSS::w->mNVisitorBluetooth->tRun(NSNKROSS::w->mNEta00, (NParam)this);
    return NSNKROSS::w->mNKrossSystem->tGetString(NSNKROSS::w->mNKrossSystem->tRunObject((NParam)index));
}

String BluetoothAdapter::getName()
{
    NReturn index = NSNKROSS::w->mNVisitorBluetooth->tRun(NSNKROSS::w->mNTheta00, (NParam)this);
    return NSNKROSS::w->mNKrossSystem->tGetString(NSNKROSS::w->mNKrossSystem->tRunObject((NParam)index));
}

bool BluetoothAdapter::setName(const String& name)
{
    return (bool)NSNKROSS::w->mNVisitorBluetooth->tRun(NSNKROSS::w->mNIota00, (NParam)this, NKrossParam(name).n);
}

int BluetoothAdapter::getScanMode()
{
    return (nint)NSNKROSS::w->mNVisitorBluetooth->tRun(NSNKROSS::w->mNKappa00, (NParam)this);
}

bool BluetoothAdapter::startDiscovery()
{
    return (bool)NSNKROSS::w->mNVisitorBluetooth->tRun(NSNKROSS::w->mNLambda00, (NParam)this);
}

bool BluetoothAdapter::startLeScan(BluetoothAdapter::LeScanCallback* callback)
{
    return (bool)NSNKROSS::w->mNVisitorBluetooth->tRun(NSNKROSS::w->mNKhi00, (NParam)this, (NParam)callback);
}

bool BluetoothAdapter::startLeScan(NArray<String> serviceUuids, BluetoothAdapter::LeScanCallback* callback)
{
    nuint vcIndex;
    nlong vcKey = NSNKROSS::w->mNKrossSystem->tRun(NSNKROSS::w->mNBeta01, 0, serviceUuids.mcData);
    NParamObject* vaTString = new NParamObject[serviceUuids.mcData]();

    for (vcIndex = 0 ; vcIndex < serviceUuids.mcData ; ++vcIndex) {
        vaTString[vcIndex] = NSNKROSS::w->mNKrossSystem->tRunString(serviceUuids.maData[vcIndex]);
        NSNKROSS::w->mNKrossSystem->tRun(NSNKROSS::w->mNBeta01, vcKey, vcIndex, (NParam)&vaTString[vcIndex]);
    };
    vcKey = (nuint)NSNKROSS::w->mNVisitorBluetooth->tRun(NSNKROSS::w->mNUpsilon00, (NParam)this, (NParam)vcKey, (NParam)callback);

    for (vcIndex = 0 ; vcIndex < serviceUuids.mcData ; ++vcIndex) {
        NSNKROSS::w->mNKrossSystem->tDeleteGlobalRef(vaTString[vcIndex]);
    };
    return (bool)vcKey;
}

void BluetoothAdapter::stopLeScan(BluetoothAdapter::LeScanCallback* callback)
{
    NSNKROSS::w->mNVisitorBluetooth->tRun(NSNKROSS::w->mNPhi00, (NParam)this, (NParam)callback);
}

bool BluetoothAdapter::cancelDiscovery()
{
    return (bool)NSNKROSS::w->mNVisitorBluetooth->tRun(NSNKROSS::w->mNMu00, (NParam)this);
}

bool BluetoothAdapter::isDiscovering()
{
    return (bool)NSNKROSS::w->mNVisitorBluetooth->tRun(NSNKROSS::w->mNNu00, (NParam)this);
}

void* BluetoothAdapter::getBondedDevices()
{
    //TODO: implement
    //Set<BluetoothDevice>
    //return NSNKROSS::w->mNVisitorBluetooth->tRun(NSNKROSS::w->mNxi00, (NParam)this);
    return NULL;
}

BluetoothServerSocket* BluetoothAdapter::listenUsingInsecureRfcommOn(int channel)
{
    BluetoothServerSocket* b = NSNKROSS::w->mNKrossFriend->pointer<BluetoothServerSocket>();
    return NSNKROSS::w->mNKrossFriend->emplaceKey(b, NSNKROSS::w->mNVisitorBluetooth->tRun(NSNKROSS::w->mNTau00, (NParam)this, (NParam)b, (NParam)channel));
}

BluetoothServerSocket* BluetoothAdapter::listenUsingInsecureRfcommWithServiceRecord(const String& name, const String& uuid)
{
    BluetoothServerSocket* b = NSNKROSS::w->mNKrossFriend->pointer<BluetoothServerSocket>();
    return NSNKROSS::w->mNKrossFriend->emplaceKey(b, NSNKROSS::w->mNVisitorBluetooth->tRun(NSNKROSS::w->mNPi00, (NParam)this, (NParam)b, NKrossParam(name).n, NKrossParam(uuid).n));
}

BluetoothServerSocket* BluetoothAdapter::listenUsingRfcommWithServiceRecord(const String& name, const String& uuid)
{
    BluetoothServerSocket* b = NSNKROSS::w->mNKrossFriend->pointer<BluetoothServerSocket>();
    return NSNKROSS::w->mNKrossFriend->emplaceKey(b, NSNKROSS::w->mNVisitorBluetooth->tRun(NSNKROSS::w->mNOmicron00, (NParam)this, (NParam)b, NKrossParam(name).n, NKrossParam(uuid).n));
}

void BluetoothAdapter::discoverable()
{
    discoverable(0);
}

void BluetoothAdapter::discoverable(int cTimeout)
{
    NSNKROSS::w->mNVisitorBluetooth->tRun(NSNKROSS::w->mNSigma00, cTimeout);
}

} // End namespace
