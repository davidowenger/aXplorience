#include <nkross/NKrossCommon.h>

namespace NSDEVICE
{

BluetoothSocket* BluetoothServerSocket::accept()
{
    // Blocks until a connection is established
    BluetoothSocket* b = NSNKROSS::w->mNKrossFriend->pointer<BluetoothSocket>();
    return NSNKROSS::w->mNKrossFriend->emplaceKey(b, NSNKROSS::w->mNVisitorBluetooth->tRun(NSNKROSS::w->mNAlpha02, (NParam)this, (NParam)b));
}

BluetoothSocket* BluetoothServerSocket::accept(int timeout)
{
    // Blocks until a connection is established, up to timeout
    BluetoothSocket* b = NSNKROSS::w->mNKrossFriend->pointer<BluetoothSocket>();
    return NSNKROSS::w->mNKrossFriend->emplaceKey(b, NSNKROSS::w->mNVisitorBluetooth->tRun(NSNKROSS::w->mNBeta02, (NParam)this, (NParam)b, (NParam)timeout));
}

int BluetoothServerSocket::getChannel()
{
    return (nint)NSNKROSS::w->mNVisitorBluetooth->tRun(NSNKROSS::w->mNDelta02, (NParam)this);
}

void BluetoothServerSocket::close()
{
    NSNKROSS::w->mNVisitorBluetooth->tRun(NSNKROSS::w->mNGamma02, (NParam)this);
}

} // End namespace
