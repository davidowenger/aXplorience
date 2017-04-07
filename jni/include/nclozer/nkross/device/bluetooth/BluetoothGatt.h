#ifndef __BluetoothGatt_H__
#define __BluetoothGatt_H__

namespace NSDEVICE
{

class BluetoothGatt : public Object, public BluetoothProfile
{
friend NSNATIVE::NKrossFriend;

public:
    static const int GATT_FAILURE = 0x00000101;
    static const int GATT_INSUFFICIENT_AUTHENTICATION = 0x00000005;
    static const int GATT_INSUFFICIENT_ENCRYPTION = 0x0000000f;
    static const int GATT_INVALID_ATTRIBUTE_LENGTH = 0x0000000d;
    static const int GATT_INVALID_OFFSET = 0x00000007;
    static const int GATT_READ_NOT_PERMITTED = 0x00000002;
    static const int GATT_REQUEST_NOT_SUPPORTED = 0x00000006;
    static const int GATT_SUCCESS = 0x00000000;
    static const int GATT_WRITE_NOT_PERMITTED = 0x00000003;

    virtual ~BluetoothGatt()
    {
    }

    void close()
    {
        NKrossWrapper::w->mNVisitorBluetoothGatt->tRun(NKrossWrapper::w->mNTau00, (NParam)this);
    }

    bool connect()
    {
        return (bool)NKrossWrapper::w->mNVisitorBluetoothGatt->tRun(NKrossWrapper::w->mNUpsilon00, (NParam)this);
    }

    void disconnect()
    {
        NKrossWrapper::w->mNVisitorBluetoothGatt->tRun(NKrossWrapper::w->mNPhi00, (NParam)this);
    }

    bool discoverServices()
    {
        return (bool)NKrossWrapper::w->mNVisitorBluetoothGatt->tRun(NKrossWrapper::w->mNSigma00, (NParam)this);
    }

    BluetoothGattService* getService(const String& uuid)
    {
        BluetoothGattService* b = NKrossWrapper::w->mNKrossFriend->pointer<BluetoothGattService>();
        return NKrossWrapper::w->mNKrossFriend->emplaceKey(b, NKrossWrapper::w->mNVisitorBluetoothGatt->tRun(NKrossWrapper::w->mNPi00, (NParam)this, (NParam)b, NKrossParam(uuid).n));
    }

    NArray<BluetoothGattService*> getServices()
    {
        NReturn index = NKrossWrapper::w->mNVisitorBluetoothGatt->tRun(NKrossWrapper::w->mNBeta01, (NParam)this);
        NReturn size = NKrossWrapper::w->mNKrossSystem->tRun(NKrossWrapper::w->mNAlpha01, index, -1);
        NArray<BluetoothGattService*> vNArray = NArray<BluetoothGattService*>(size);
        nuint i;

        for (i = 0 ; i < size ; ++i) {
            BluetoothGattService* b = NKrossWrapper::w->mNKrossFriend->pointer<BluetoothGattService>();
            vNArray.maData[i] = NKrossWrapper::w->mNKrossFriend->emplaceKey(b, NKrossWrapper::w->mNKrossSystem->tRun(NKrossWrapper::w->mNAlpha01, index, (NParam)i, (NParam)b));
        }
        return vNArray;
    }

    bool setCharacteristicNotification(BluetoothGattCharacteristic* characteristic, bool enable)
    {
        return (bool)NKrossWrapper::w->mNVisitorBluetoothGatt->tRun(NKrossWrapper::w->mNAlpha00, (NParam)this, (NParam)characteristic, (NParam)enable);
    }

    bool writeCharacteristic(BluetoothGattCharacteristic* characteristic)
    {
        return (bool)NKrossWrapper::w->mNVisitorBluetoothGatt->tRun(NKrossWrapper::w->mNBeta00, (NParam)this, (NParam)characteristic);
    }

private:
    BluetoothGatt(NKrossFriend* vNKrossFriend)
        : BluetoothProfile(NKrossWrapper::w->mNKrossFriend->instance<BluetoothProfile>())
    {
    }
};

} // End namespace

#endif
