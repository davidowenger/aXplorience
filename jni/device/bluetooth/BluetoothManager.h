#ifndef __BluetoothManager_H__
#define __BluetoothManager_H__

namespace NSDEVICE
{

class BluetoothManager : public Object
{
friend NSNATIVE::NNoObject;

public:
    virtual ~BluetoothManager()
    {
    }

    BluetoothGattServer* openGattServer(Context* context, BluetoothGattServerCallback* callback)
    {
        BluetoothGattServer* b = NWrapper::w->mNNoObject->pointer<BluetoothGattServer>();
        return NWrapper::w->mNNoObject->emplaceKey(b, NWrapper::w->mNVisitorBluetooth->tRun(NWrapper::w->mNEpsilon02, (NParam)this, (NParam)b, (NParam)context, (NParam)callback));
    }

private:
    BluetoothManager(NNoObject* vNNoObject)
    {
    }
};

} // End namespace

#endif
