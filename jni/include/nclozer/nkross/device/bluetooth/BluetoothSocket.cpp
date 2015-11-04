#include <nkross/NKrossCommon.h>

namespace NSDEVICE
{

int BluetoothSocket::connect()
{
    return (nint)NSNKROSS::w->mNVisitorBluetooth->tRun(NSNKROSS::w->mNAlpha03, (NParam)this);
}

int BluetoothSocket::close()
{
    return (nint)NSNKROSS::w->mNVisitorBluetooth->tRun(NSNKROSS::w->mNBeta03, (NParam)this);
}

BluetoothDevice* BluetoothSocket::getRemoteDevice()
{
    BluetoothDevice* b = NSNKROSS::w->mNKrossFriend->pointer<BluetoothDevice>();
    return NSNKROSS::w->mNKrossFriend->emplaceKey(b, NSNKROSS::w->mNVisitorBluetooth->tRun(NSNKROSS::w->mNGamma03, (NParam)this, (NParam)b));
}

InputStream* BluetoothSocket::getInputStream()
{
    InputStream* b = NSNKROSS::w->mNKrossFriend->pointer<InputStream>();
    return NSNKROSS::w->mNKrossFriend->emplaceKey(b, NSNKROSS::w->mNVisitorBluetooth->tRun(NSNKROSS::w->mNDelta03, (NParam)this, (NParam)b));
}

OutputStream* BluetoothSocket::getOutputStream()
{
    OutputStream* b = NSNKROSS::w->mNKrossFriend->pointer<OutputStream>();
    return NSNKROSS::w->mNKrossFriend->emplaceKey(b, NSNKROSS::w->mNVisitorBluetooth->tRun(NSNKROSS::w->mNEpsilon03, (NParam)this, (NParam)b));
}

int BluetoothSocket::getPort()
{
    return (nint)NSNKROSS::w->mNVisitorBluetooth->tRun(NSNKROSS::w->mNDzeta03, (NParam)this);
}

} // END namespace
