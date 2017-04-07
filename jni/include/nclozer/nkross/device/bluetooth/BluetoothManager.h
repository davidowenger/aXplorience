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
        BluetoothGattServer* b = NKrossWrapper::w->mNKrossFriend->pointer<BluetoothGattServer>();
        return NKrossWrapper::w->mNKrossFriend->emplaceKey(b, NKrossWrapper::w->mNVisitorBluetooth->tRun(NKrossWrapper::w->mNEpsilon02, (NParam)this, (NParam)b, (NParam)context, (NParam)callback));
    }

private:
    BluetoothManager(NKrossFriend* vNKrossFriend)
    {
    }
};

} // End namespace

#endif
