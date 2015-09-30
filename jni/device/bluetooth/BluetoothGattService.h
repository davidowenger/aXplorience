#ifndef __BluetoothGattService_H__
#define __BluetoothGattService_H__

namespace NSDEVICE
{

class BluetoothGattService : public Object
{
friend NSNATIVE::NNoObject;

public:
    static const int SERVICE_TYPE_PRIMARY = 0x00000000;
    static const int SERVICE_TYPE_SECONDARY = 0x00000001;

    BluetoothGattService(const String& uuid, int serviceType)
    {
        NWrapper::w->mNVisitorBluetoothGatt->tRun(NWrapper::w->mNXi00, (NParam)this, NParamBox(NWrapper::w, uuid).n, (NParam)serviceType);
    }

    virtual ~BluetoothGattService()
    {
    }

    virtual bool addService(BluetoothGattService* service)
    {
        return NWrapper::w->mNVisitorBluetoothGatt->tRun(NWrapper::w->mNXi01, (NParam)this, (NParam)service);
    }

    virtual bool addCharacteristic(BluetoothGattCharacteristic* characteristic)
    {
        return NWrapper::w->mNVisitorBluetoothGatt->tRun(NWrapper::w->mNOmicron00, (NParam)this, (NParam)characteristic);
    }

    BluetoothGattCharacteristic* getCharacteristic(const String& uuid)
    {
        BluetoothGattCharacteristic* b = NWrapper::w->mNNoObject->pointer<BluetoothGattCharacteristic>();
        return NWrapper::w->mNNoObject->emplaceKey(b, NWrapper::w->mNVisitorBluetoothGatt->tRun(NWrapper::w->mNOmicron01, (NParam)this, (NParam)b, NParamBox(NWrapper::w, uuid).n));
    }

    NArray<BluetoothGattCharacteristic*> getCharacteristics()
    {
        NReturn index = NWrapper::w->mNVisitorBluetoothGatt->tRun(NWrapper::w->mNPi01, (NParam)this);
        NReturn size = NWrapper::w->nFrame->tRun(NWrapper::w->mNAlpha01, (NParam)this, (NParam)index, -1, -1);
        NArray<BluetoothGattCharacteristic*> vNArray = NArray<BluetoothGattCharacteristic*>(size);
        nuint i;

        for (i = 0 ; i < size ; ++i) {
            BluetoothGattCharacteristic* b = NWrapper::w->mNNoObject->pointer<BluetoothGattCharacteristic>();
            vNArray.maData[i] = NWrapper::w->mNNoObject->emplaceKey(b, NWrapper::w->nFrame->tRun(NWrapper::w->mNAlpha01, (NParam)this, (NParam)index, (NParam)i, (NParam)b));
        }
        return vNArray;
    }

    NArray<BluetoothGattService*> getIncludedServices()
    {
        NReturn index = NWrapper::w->mNVisitorBluetoothGatt->tRun(NWrapper::w->mNRho01, (NParam)this);
        NReturn size = NWrapper::w->nFrame->tRun(NWrapper::w->mNAlpha01, (NParam)this, (NParam)index, -1, -1);
        NArray<BluetoothGattService*> vNArray = NArray<BluetoothGattService*>(size);
        nuint i;

        for (i = 0 ; i < size ; ++i) {
            BluetoothGattService* b = NWrapper::w->mNNoObject->pointer<BluetoothGattService>();
            vNArray.maData[i] = NWrapper::w->mNNoObject->emplaceKey(b, NWrapper::w->nFrame->tRun(NWrapper::w->mNAlpha01, (NParam)this, (NParam)index, (NParam)i, (NParam)b));
        }
        return vNArray;
    }

    int getInstanceId()
    {
        return NWrapper::w->mNVisitorBluetoothGatt->tRun(NWrapper::w->mNTau01, (NParam)this);
    }

    int getType()
    {
        return NWrapper::w->mNVisitorBluetoothGatt->tRun(NWrapper::w->mNSigma01, (NParam)this);
    }

    String getUuid()
    {
        NReturn index = NWrapper::w->mNVisitorBluetoothGatt->tRun(NWrapper::w->mNAlpha01, (NParam)this);
        return NWrapper::w->nFrame->tGetString(NWrapper::w->nFrame->tRunObject((NParam)index));
    }

private:
    BluetoothGattService(NNoObject* vNNoObject)
    {
    }
};

} // End namespace

#endif
