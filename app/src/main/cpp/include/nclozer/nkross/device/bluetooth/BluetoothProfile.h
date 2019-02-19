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
        NSNKROSS::w->mNKrossSystem->tRun(NSNKROSS::w->mNDelta00, (NParam)this);
    }

protected:
    BluetoothProfile()
    {
        NSNKROSS::w->mNVisitorBluetoothGatt->tRun(NSNKROSS::w->mNGamma00, (NParam)this);
    }

private:
    BluetoothProfile(NKrossFriend* vNKrossFriend)
    {
    }
};

} // End namespace

#endif
