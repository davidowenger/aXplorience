#ifndef __BluetoothManager_H__
#define __BluetoothManager_H__

namespace NSDEVICE
{

class BluetoothManager : public Object
{
friend NSNATIVE::NKrossFriend;

public:
    virtual ~BluetoothManager()
    {
    }

    BluetoothGattServer* openGattServer(Context* context, BluetoothGattServerCallback* callback)
    {
        BluetoothGattServer* b = NSNKROSS::w->mNKrossFriend->pointer<BluetoothGattServer>();
        return NSNKROSS::w->mNKrossFriend->emplaceKey(b, NSNKROSS::w->mNVisitorBluetooth->tRun(NSNKROSS::w->mNEpsilon02, (NParam)this, (NParam)b, (NParam)context, (NParam)callback));
    }

private:
    BluetoothManager(NKrossFriend* vNKrossFriend)
    {
    }
};

} // End namespace

#endif
