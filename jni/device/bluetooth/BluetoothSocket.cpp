#include "native/NCommon.h"

namespace NSDEVICE
{

int BluetoothSocket::connect()
{
	return (nint)NWrapper::w->mNVisitorBluetooth->tRun(NWrapper::w->mNAlpha03, (NParam)this);
}

int BluetoothSocket::close()
{
	return (nint)NWrapper::w->mNVisitorBluetooth->tRun(NWrapper::w->mNBeta03, (NParam)this);
}

BluetoothDevice* BluetoothSocket::getRemoteDevice()
{
    BluetoothDevice* b = NWrapper::w->mNNoObject->pointer<BluetoothDevice>();
    return NWrapper::w->mNNoObject->emplaceKey(b, NWrapper::w->mNVisitorBluetooth->tRun(NWrapper::w->mNGamma03, (NParam)this, (NParam)b));
}

InputStream* BluetoothSocket::getInputStream()
{
    InputStream* b = NWrapper::w->mNNoObject->pointer<InputStream>();
    return NWrapper::w->mNNoObject->emplaceKey(b, NWrapper::w->mNVisitorBluetooth->tRun(NWrapper::w->mNDelta03, (NParam)this, (NParam)b));
}

OutputStream* BluetoothSocket::getOutputStream()
{
    OutputStream* b = NWrapper::w->mNNoObject->pointer<OutputStream>();
    return NWrapper::w->mNNoObject->emplaceKey(b, NWrapper::w->mNVisitorBluetooth->tRun(NWrapper::w->mNEpsilon03, (NParam)this, (NParam)b));
}

} // END namespace
