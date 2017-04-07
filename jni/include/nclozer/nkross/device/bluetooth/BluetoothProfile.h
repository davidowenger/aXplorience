#ifndef __BluetoothProfile_H__
#define __BluetoothProfile_H__

namespace NSDEVICE
{

class BluetoothProfile
{
friend NSNATIVE::NKrossFriend;

public:
    static const int STATE_CONNECTED = 0x00000002;
    static const int STATE_CONNECTING = 0x00000001;
    static const int STATE_DISCONNECTED = 0x00000000;
    static const int STATE_DISCONNECTING = 0x00000003;

    virtual ~BluetoothProfile()
    {
        NKrossWrapper::w->mNKrossSystem->tRun(NKrossWrapper::w->mNDelta00, (NParam)this);
    }

protected:
    BluetoothProfile()
    {
        NKrossWrapper::w->mNVisitorBluetoothGatt->tRun(NKrossWrapper::w->mNGamma00, (NParam)this);
    }

private:
    BluetoothProfile(NKrossFriend* vNKrossFriend)
    {
    }
};

} // End namespace

#endif
