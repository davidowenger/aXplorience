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
        NKrossWrapper::w->mNVisitorBluetoothGatt->tRun(NKrossWrapper::w->mNXi00, (NParam)this, NKrossParam(uuid).n, (NParam)serviceType);
    }

    virtual ~BluetoothGattService()
    {
    }

    virtual bool addService(BluetoothGattService* service)
    {
        return NKrossWrapper::w->mNVisitorBluetoothGatt->tRun(NKrossWrapper::w->mNXi01, (NParam)this, (NParam)service);
    }

    virtual bool addCharacteristic(BluetoothGattCharacteristic* characteristic)
    {
        return NKrossWrapper::w->mNVisitorBluetoothGatt->tRun(NKrossWrapper::w->mNOmicron00, (NParam)this, (NParam)characteristic);
    }

    BluetoothGattCharacteristic* getCharacteristic(const String& uuid)
    {
        BluetoothGattCharacteristic* b = NKrossWrapper::w->mNKrossFriend->pointer<BluetoothGattCharacteristic>();
        return NKrossWrapper::w->mNKrossFriend->emplaceKey(b, NKrossWrapper::w->mNVisitorBluetoothGatt->tRun(NKrossWrapper::w->mNOmicron01, (NParam)this, (NParam)b, NKrossParam(uuid).n));
    }

    NArray<BluetoothGattCharacteristic*> getCharacteristics()
    {
        NReturn index = NKrossWrapper::w->mNVisitorBluetoothGatt->tRun(NKrossWrapper::w->mNPi01, (NParam)this);
        NReturn size = NKrossWrapper::w->mNKrossSystem->tRun(NKrossWrapper::w->mNAlpha01, index, -1);
        NArray<BluetoothGattCharacteristic*> vNArray = NArray<BluetoothGattCharacteristic*>(size);
        nuint i;

        for (i = 0 ; i < size ; ++i) {
            BluetoothGattCharacteristic* b = NKrossWrapper::w->mNKrossFriend->pointer<BluetoothGattCharacteristic>();
            vNArray.maData[i] = NKrossWrapper::w->mNKrossFriend->emplaceKey(b, NKrossWrapper::w->mNKrossSystem->tRun(NKrossWrapper::w->mNAlpha01, index, (NParam)i, (NParam)b));
        }
        return vNArray;
    }

    NArray<BluetoothGattService*> getIncludedServices()
    {
        NReturn index = NKrossWrapper::w->mNVisitorBluetoothGatt->tRun(NKrossWrapper::w->mNRho01, (NParam)this);
        NReturn size = NKrossWrapper::w->mNKrossSystem->tRun(NKrossWrapper::w->mNAlpha01, index, -1);
        NArray<BluetoothGattService*> vNArray = NArray<BluetoothGattService*>(size);
        nuint i;

        for (i = 0 ; i < size ; ++i) {
            BluetoothGattService* b = NKrossWrapper::w->mNKrossFriend->pointer<BluetoothGattService>();
            vNArray.maData[i] = NKrossWrapper::w->mNKrossFriend->emplaceKey(b, NKrossWrapper::w->mNKrossSystem->tRun(NKrossWrapper::w->mNAlpha01, index, (NParam)i, (NParam)b));
        }
        return vNArray;
    }

    int getInstanceId()
    {
        return NKrossWrapper::w->mNVisitorBluetoothGatt->tRun(NKrossWrapper::w->mNTau01, (NParam)this);
    }

    int getType()
    {
        return NKrossWrapper::w->mNVisitorBluetoothGatt->tRun(NKrossWrapper::w->mNSigma01, (NParam)this);
    }

    String getUuid()
    {
        NReturn index = NKrossWrapper::w->mNVisitorBluetoothGatt->tRun(NKrossWrapper::w->mNAlpha01, (NParam)this);
        return NKrossWrapper::w->mNKrossSystem->tGetString(NKrossWrapper::w->mNKrossSystem->tRunObject((NParam)index));
    }

private:
    BluetoothGattService(NKrossFriend* vNKrossFriend)
    {
    }
};

} // End namespace

#endif
