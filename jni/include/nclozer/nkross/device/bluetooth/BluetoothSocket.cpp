#include <nkross/NKrossCommon.h>

namespace NSDEVICE
{

int BluetoothSocket::connect()
{
    return (nint)NKrossWrapper::w->mNVisitorBluetooth->tRun(NKrossWrapper::w->mNAlpha03, (NParam)this);
}

int BluetoothSocket::close()
{
    return (nint)NKrossWrapper::w->mNVisitorBluetooth->tRun(NKrossWrapper::w->mNBeta03, (NParam)this);
}

BluetoothDevice* BluetoothSocket::getRemoteDevice()
{
    BluetoothDevice* b = NKrossWrapper::w->mNKrossFriend->pointer<BluetoothDevice>();
    return NKrossWrapper::w->mNKrossFriend->emplaceKey(b, NKrossWrapper::w->mNVisitorBluetooth->tRun(NKrossWrapper::w->mNGamma03, (NParam)this, (NParam)b));
}

InputStream* BluetoothSocket::getInputStream()
{
    InputStream* b = NKrossWrapper::w->mNKrossFriend->pointer<InputStream>();
    return NKrossWrapper::w->mNKrossFriend->emplaceKey(b, NKrossWrapper::w->mNVisitorBluetooth->tRun(NKrossWrapper::w->mNDelta03, (NParam)this, (NParam)b));
}

OutputStream* BluetoothSocket::getOutputStream()
{
    OutputStream* b = NKrossWrapper::w->mNKrossFriend->pointer<OutputStream>();
    return NKrossWrapper::w->mNKrossFriend->emplaceKey(b, NKrossWrapper::w->mNVisitorBluetooth->tRun(NKrossWrapper::w->mNEpsilon03, (NParam)this, (NParam)b));
}

int BluetoothSocket::getPort()
{
    return (nint)NKrossWrapper::w->mNVisitorBluetooth->tRun(NKrossWrapper::w->mNDzeta03, (NParam)this);
}

} // END namespace
