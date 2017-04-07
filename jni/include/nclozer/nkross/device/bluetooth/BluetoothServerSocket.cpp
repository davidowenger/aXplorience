#include <nkross/NKrossCommon.h>

namespace NSDEVICE
{

BluetoothSocket* BluetoothServerSocket::accept()
{
    // Blocks until a connection is established
    BluetoothSocket* b = NKrossWrapper::w->mNKrossFriend->pointer<BluetoothSocket>();
    return NKrossWrapper::w->mNKrossFriend->emplaceKey(b, NKrossWrapper::w->mNVisitorBluetooth->tRun(NKrossWrapper::w->mNAlpha02, (NParam)this, (NParam)b));
}

BluetoothSocket* BluetoothServerSocket::accept(int timeout)
{
    // Blocks until a connection is established, up to timeout
    BluetoothSocket* b = NKrossWrapper::w->mNKrossFriend->pointer<BluetoothSocket>();
    return NKrossWrapper::w->mNKrossFriend->emplaceKey(b, NKrossWrapper::w->mNVisitorBluetooth->tRun(NKrossWrapper::w->mNBeta02, (NParam)this, (NParam)b, (NParam)timeout));
}

int BluetoothServerSocket::getChannel()
{
    return (nint)NKrossWrapper::w->mNVisitorBluetooth->tRun(NKrossWrapper::w->mNDelta02, (NParam)this);
}

void BluetoothServerSocket::close()
{
    NKrossWrapper::w->mNVisitorBluetooth->tRun(NKrossWrapper::w->mNGamma02, (NParam)this);
}

} // End namespace
