#ifndef __BluetoothGatt_H__
#define __BluetoothGatt_H__

namespace NSDEVICE
{

class BluetoothGatt : public Object, public BluetoothProfile
{
friend NSNATIVE::NNoObject;

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
        NWrapper::w->mNVisitorBluetoothGatt->tRun(NWrapper::w->mNTau00, (NParam)this);
    }

    bool connect()
    {
        return (bool)NWrapper::w->mNVisitorBluetoothGatt->tRun(NWrapper::w->mNUpsilon00, (NParam)this);
    }

    void disconnect()
    {
        NWrapper::w->mNVisitorBluetoothGatt->tRun(NWrapper::w->mNPhi00, (NParam)this);
    }

    bool discoverServices()
    {
        return (bool)NWrapper::w->mNVisitorBluetoothGatt->tRun(NWrapper::w->mNSigma00, (NParam)this);
    }

    BluetoothGattService* getService(const String& uuid)
    {
        BluetoothGattService* b = NWrapper::w->mNNoObject->pointer<BluetoothGattService>();
        return NWrapper::w->mNNoObject->emplaceKey(b, NWrapper::w->mNVisitorBluetoothGatt->tRun(NWrapper::w->mNPi00, (NParam)this, (NParam)b, NParamBox(NWrapper::w, uuid).n));
    }

    NArray<BluetoothGattService*> getServices()
    {
        NReturn index = NWrapper::w->mNVisitorBluetoothGatt->tRun(NWrapper::w->mNBeta01, (NParam)this);
        NReturn size = NWrapper::w->nFrame->tRun(NWrapper::w->mNAlpha01, (NParam)this, (NParam)index, -1, -1);
        NArray<BluetoothGattService*> vNArray = NArray<BluetoothGattService*>(size);
        nuint i;

        for (i = 0 ; i < size ; ++i) {
            BluetoothGattService* b = NWrapper::w->mNNoObject->pointer<BluetoothGattService>();
            vNArray.maData[i] = NWrapper::w->mNNoObject->emplaceKey(b, NWrapper::w->nFrame->tRun(NWrapper::w->mNAlpha01, (NParam)this, (NParam)index, (NParam)i, (NParam)b));
        }
        return vNArray;
    }

    bool setCharacteristicNotification(BluetoothGattCharacteristic* characteristic, bool enable)
    {
        return (bool)NWrapper::w->mNVisitorBluetoothGatt->tRun(NWrapper::w->mNAlpha00, (NParam)this, (NParam)characteristic, (NParam)enable);
    }

    bool writeCharacteristic(BluetoothGattCharacteristic* characteristic)
    {
        return (bool)NWrapper::w->mNVisitorBluetoothGatt->tRun(NWrapper::w->mNBeta00, (NParam)this, (NParam)characteristic);
    }

private:
    BluetoothGatt(NNoObject* vNNoObject)
        : BluetoothProfile(NWrapper::w->mNNoObject->instance<BluetoothProfile>())
    {
    }
};

} // End namespace

#endif
