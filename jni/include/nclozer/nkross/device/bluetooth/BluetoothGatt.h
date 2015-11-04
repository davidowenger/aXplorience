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
        NSNKROSS::w->mNVisitorBluetoothGatt->tRun(NSNKROSS::w->mNTau00, (NParam)this);
    }

    bool connect()
    {
        return (bool)NSNKROSS::w->mNVisitorBluetoothGatt->tRun(NSNKROSS::w->mNUpsilon00, (NParam)this);
    }

    void disconnect()
    {
        NSNKROSS::w->mNVisitorBluetoothGatt->tRun(NSNKROSS::w->mNPhi00, (NParam)this);
    }

    bool discoverServices()
    {
        return (bool)NSNKROSS::w->mNVisitorBluetoothGatt->tRun(NSNKROSS::w->mNSigma00, (NParam)this);
    }

    BluetoothGattService* getService(const String& uuid)
    {
        BluetoothGattService* b = NSNKROSS::w->mNKrossFriend->pointer<BluetoothGattService>();
        return NSNKROSS::w->mNKrossFriend->emplaceKey(b, NSNKROSS::w->mNVisitorBluetoothGatt->tRun(NSNKROSS::w->mNPi00, (NParam)this, (NParam)b, NKrossParam(uuid).n));
    }

    NArray<BluetoothGattService*> getServices()
    {
        NReturn index = NSNKROSS::w->mNVisitorBluetoothGatt->tRun(NSNKROSS::w->mNBeta01, (NParam)this);
        NReturn size = NSNKROSS::w->mNKrossSystem->tRun(NSNKROSS::w->mNAlpha01, index, -1);
        NArray<BluetoothGattService*> vNArray = NArray<BluetoothGattService*>(size);
        nuint i;

        for (i = 0 ; i < size ; ++i) {
            BluetoothGattService* b = NSNKROSS::w->mNKrossFriend->pointer<BluetoothGattService>();
            vNArray.maData[i] = NSNKROSS::w->mNKrossFriend->emplaceKey(b, NSNKROSS::w->mNKrossSystem->tRun(NSNKROSS::w->mNAlpha01, index, (NParam)i, (NParam)b));
        }
        return vNArray;
    }

    bool setCharacteristicNotification(BluetoothGattCharacteristic* characteristic, bool enable)
    {
        return (bool)NSNKROSS::w->mNVisitorBluetoothGatt->tRun(NSNKROSS::w->mNAlpha00, (NParam)this, (NParam)characteristic, (NParam)enable);
    }

    bool writeCharacteristic(BluetoothGattCharacteristic* characteristic)
    {
        return (bool)NSNKROSS::w->mNVisitorBluetoothGatt->tRun(NSNKROSS::w->mNBeta00, (NParam)this, (NParam)characteristic);
    }

private:
    BluetoothGatt(NKrossFriend* vNKrossFriend)
        : BluetoothProfile(NSNKROSS::w->mNKrossFriend->instance<BluetoothProfile>())
    {
    }
};

} // End namespace

#endif
