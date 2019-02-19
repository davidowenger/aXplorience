#ifndef __BluetoothGattService_H__
#define __BluetoothGattService_H__

namespace NSDEVICE
{

class BluetoothGattService : public Object
{
friend NSNATIVE::NKrossFriend;

public:
    static const int SERVICE_TYPE_PRIMARY = 0x00000000;
    static const int SERVICE_TYPE_SECONDARY = 0x00000001;

    BluetoothGattService(const String& uuid, int serviceType)
    {
        NSNKROSS::w->mNVisitorBluetoothGatt->tRun(NSNKROSS::w->mNXi00, (NParam)this, NKrossParam(uuid).n, (NParam)serviceType);
    }

    virtual ~BluetoothGattService()
    {
    }

    virtual bool addService(BluetoothGattService* service)
    {
        return NSNKROSS::w->mNVisitorBluetoothGatt->tRun(NSNKROSS::w->mNXi01, (NParam)this, (NParam)service);
    }

    virtual bool addCharacteristic(BluetoothGattCharacteristic* characteristic)
    {
        return NSNKROSS::w->mNVisitorBluetoothGatt->tRun(NSNKROSS::w->mNOmicron00, (NParam)this, (NParam)characteristic);
    }

    BluetoothGattCharacteristic* getCharacteristic(const String& uuid)
    {
        BluetoothGattCharacteristic* b = NSNKROSS::w->mNKrossFriend->pointer<BluetoothGattCharacteristic>();
        return NSNKROSS::w->mNKrossFriend->emplaceKey(b, NSNKROSS::w->mNVisitorBluetoothGatt->tRun(NSNKROSS::w->mNOmicron01, (NParam)this, (NParam)b, NKrossParam(uuid).n));
    }

    NArray<BluetoothGattCharacteristic*> getCharacteristics()
    {
        NReturn index = NSNKROSS::w->mNVisitorBluetoothGatt->tRun(NSNKROSS::w->mNPi01, (NParam)this);
        NReturn size = NSNKROSS::w->mNKrossSystem->tRun(NSNKROSS::w->mNAlpha01, index, -1);
        NArray<BluetoothGattCharacteristic*> vNArray = NArray<BluetoothGattCharacteristic*>(size);
        nuint i;

        for (i = 0 ; i < size ; ++i) {
            BluetoothGattCharacteristic* b = NSNKROSS::w->mNKrossFriend->pointer<BluetoothGattCharacteristic>();
            vNArray.maData[i] = NSNKROSS::w->mNKrossFriend->emplaceKey(b, NSNKROSS::w->mNKrossSystem->tRun(NSNKROSS::w->mNAlpha01, index, (NParam)i, (NParam)b));
        }
        return vNArray;
    }

    NArray<BluetoothGattService*> getIncludedServices()
    {
        NReturn index = NSNKROSS::w->mNVisitorBluetoothGatt->tRun(NSNKROSS::w->mNRho01, (NParam)this);
        NReturn size = NSNKROSS::w->mNKrossSystem->tRun(NSNKROSS::w->mNAlpha01, index, -1);
        NArray<BluetoothGattService*> vNArray = NArray<BluetoothGattService*>(size);
        nuint i;

        for (i = 0 ; i < size ; ++i) {
            BluetoothGattService* b = NSNKROSS::w->mNKrossFriend->pointer<BluetoothGattService>();
            vNArray.maData[i] = NSNKROSS::w->mNKrossFriend->emplaceKey(b, NSNKROSS::w->mNKrossSystem->tRun(NSNKROSS::w->mNAlpha01, index, (NParam)i, (NParam)b));
        }
        return vNArray;
    }

    int getInstanceId()
    {
        return NSNKROSS::w->mNVisitorBluetoothGatt->tRun(NSNKROSS::w->mNTau01, (NParam)this);
    }

    int getType()
    {
        return NSNKROSS::w->mNVisitorBluetoothGatt->tRun(NSNKROSS::w->mNSigma01, (NParam)this);
    }

    String getUuid()
    {
        NReturn index = NSNKROSS::w->mNVisitorBluetoothGatt->tRun(NSNKROSS::w->mNAlpha01, (NParam)this);
        return NSNKROSS::w->mNKrossSystem->tGetString(NSNKROSS::w->mNKrossSystem->tRunObject((NParam)index));
    }

private:
    BluetoothGattService(NKrossFriend* vNKrossFriend)
    {
    }
};

} // End namespace

#endif
