#include "native/NCommon.h"

namespace NSDEVICE
{

BluetoothSocket* BluetoothServerSocket::accept()
{
    // Blocks until a connection is established
    BluetoothSocket* b = NWrapper::w->mNNoObject->pointer<BluetoothSocket>();
    return NWrapper::w->mNNoObject->emplaceKey(b, NWrapper::w->mNVisitorBluetooth->tRun(NWrapper::w->mNAlpha02, (NParam)this, (NParam)b));
}

BluetoothSocket* BluetoothServerSocket::accept(int timeout)
{
    // Blocks until a connection is established, up to timeout
    BluetoothSocket* b = NWrapper::w->mNNoObject->pointer<BluetoothSocket>();
    return NWrapper::w->mNNoObject->emplaceKey(b, NWrapper::w->mNVisitorBluetooth->tRun(NWrapper::w->mNBeta02, (NParam)this, (NParam)b, (NParam)timeout));
}

int BluetoothServerSocket::getChannel()
{
    return (nint)NWrapper::w->mNVisitorBluetooth->tRun(NWrapper::w->mNDelta02, (NParam)this);
}

void BluetoothServerSocket::close()
{
	NWrapper::w->mNVisitorBluetooth->tRun(NWrapper::w->mNGamma02, (NParam)this);
}

} // End namespace
