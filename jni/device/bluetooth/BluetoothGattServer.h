#ifndef __BluetoothGattServer_H__
#define __BluetoothGattServer_H__

namespace NSDEVICE
{

class BluetoothGattServer : public Object, public BluetoothProfile
{
friend NSNATIVE::NNoObject;

public:
    virtual ~BluetoothGattServer()
    {
    }

    bool addService(BluetoothGattService* service)
    {
        return NWrapper::w->mNVisitorBluetoothGatt->tRun(NWrapper::w->mNKappa00, (NParam)this, (NParam)service);
    }

    void cancelConnection(BluetoothDevice* device)
    {
        NWrapper::w->mNVisitorBluetoothGatt->tRun(NWrapper::w->mNKhi00, (NParam)this, (NParam)device);
    }

    void clearServices()
    {
        NWrapper::w->mNVisitorBluetoothGatt->tRun(NWrapper::w->mNPsi00, (NParam)this);
    }

    void close()
    {
        NWrapper::w->mNVisitorBluetoothGatt->tRun(NWrapper::w->mNOmega00, (NParam)this);
    }

    BluetoothGattService* getService(const String& uuid)
    {
        BluetoothGattService* b = NWrapper::w->mNNoObject->pointer<BluetoothGattService>();
        return NWrapper::w->mNNoObject->emplaceKey(b, NWrapper::w->mNVisitorBluetoothGatt->tRun(NWrapper::w->mNMu01, (NParam)this, (NParam)b, NParamBox(NWrapper::w, uuid).n));
    }

    NArray<BluetoothGattService*> getServices()
    {
        NReturn index = NWrapper::w->mNVisitorBluetoothGatt->tRun(NWrapper::w->mNNu01, (NParam)this);
        NReturn size = NWrapper::w->nFrame->tRun(NWrapper::w->mNAlpha01, (NParam)this, (NParam)index, -1, -1);
        NArray<BluetoothGattService*> vNArray = NArray<BluetoothGattService*>(size);
        nuint i;

        for (i = 0 ; i < size ; ++i) {
            BluetoothGattService* b = NWrapper::w->mNNoObject->pointer<BluetoothGattService>();
            vNArray.maData[i] = NWrapper::w->mNNoObject->emplaceKey(b, NWrapper::w->nFrame->tRun(NWrapper::w->mNAlpha01, (NParam)this, (NParam)index, (NParam)i, (NParam)b));
        }
        return vNArray;
    }

    // Send a notification or indication that a local characteristic has been updated.
    // A notification or indication is sent to the remote device to signal that the characteristic has been updated. This function
    // should be invoked for every client that requests notifications/indications by writing to the "Client Configuration" descriptor
    // for the given characteristic.
    bool notifyCharacteristicChanged(BluetoothDevice* device, BluetoothGattCharacteristic* characteristic, bool confirm)
    {
        return NWrapper::w->mNVisitorBluetoothGatt->tRun(NWrapper::w->mNLambda00, (NParam)this, (NParam)device, (NParam)characteristic, (NParam)confirm);
    }

    // Send a response to a read or write request to a remote device.
    // This function must be invoked in when a remote read/write request is received by one of these callback methods :
    // BluetoothGattServerCallback::onCharacteristicReadRequest(BluetoothDevice, int, int, BluetoothGattCharacteristic)
    // BluetoothGattServerCallback::onCharacteristicWriteRequest(BluetoothDevice, int, BluetoothGattCharacteristic, boolean, boolean, int, byte[])
    bool sendResponse(BluetoothDevice* device, int requestId, int status, int offset, NArray<nubyte> value)
    {
        nuint vcIndex;
        nlong vcKey = NWrapper::w->nFrame->tRun(NWrapper::w->mNBeta01, 0, value.mSize);

        for (vcIndex = offset ; vcIndex < value.mSize ; ++vcIndex) {
            NWrapper::w->nFrame->tRun(NWrapper::w->mNBeta01, vcKey, vcIndex, value.maData[vcIndex]);
        };
        return NWrapper::w->mNVisitorBluetoothGatt->tRun(NWrapper::w->mNMu00, (NParam)this, (NParam)device, (NParam)requestId, (NParam)status, (NParam)vcKey);
    }

private:
    BluetoothGattServer(NNoObject* vNNoObject)
        : BluetoothProfile(NWrapper::w->mNNoObject->instance<BluetoothProfile>())
    {
    }
};

} // End namespace

#endif
