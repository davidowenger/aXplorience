#ifndef __BluetoothGattServer_H__
#define __BluetoothGattServer_H__

namespace NSDEVICE
{

class BluetoothGattServer : public Object, public BluetoothProfile
{
friend NSNATIVE::NKrossFriend;

public:
    virtual ~BluetoothGattServer()
    {
    }

    bool addService(BluetoothGattService* service)
    {
        return NSNKROSS::w->mNVisitorBluetoothGatt->tRun(NSNKROSS::w->mNKappa00, (NParam)this, (NParam)service);
    }

    void cancelConnection(BluetoothDevice* device)
    {
        NSNKROSS::w->mNVisitorBluetoothGatt->tRun(NSNKROSS::w->mNKhi00, (NParam)this, (NParam)device);
    }

    void clearServices()
    {
        NSNKROSS::w->mNVisitorBluetoothGatt->tRun(NSNKROSS::w->mNPsi00, (NParam)this);
    }

    void close()
    {
        NSNKROSS::w->mNVisitorBluetoothGatt->tRun(NSNKROSS::w->mNOmega00, (NParam)this);
    }

    BluetoothGattService* getService(const String& uuid)
    {
        BluetoothGattService* b = NSNKROSS::w->mNKrossFriend->pointer<BluetoothGattService>();
        return NSNKROSS::w->mNKrossFriend->emplaceKey(b, NSNKROSS::w->mNVisitorBluetoothGatt->tRun(NSNKROSS::w->mNMu01, (NParam)this, (NParam)b, NKrossParam(uuid).n));
    }

    NArray<BluetoothGattService*> getServices()
    {
        NReturn index = NSNKROSS::w->mNVisitorBluetoothGatt->tRun(NSNKROSS::w->mNNu01, (NParam)this);
        NReturn size = NSNKROSS::w->mNKrossSystem->tRun(NSNKROSS::w->mNAlpha01, index, -1);
        NArray<BluetoothGattService*> vNArray = NArray<BluetoothGattService*>(size);
        nuint i;

        for (i = 0 ; i < size ; ++i) {
            BluetoothGattService* b = NSNKROSS::w->mNKrossFriend->pointer<BluetoothGattService>();
            vNArray.maData[i] = NSNKROSS::w->mNKrossFriend->emplaceKey(b, NSNKROSS::w->mNKrossSystem->tRun(NSNKROSS::w->mNAlpha01, index, (NParam)i, (NParam)b));
        }
        return vNArray;
    }

    // Send a notification or indication that a local characteristic has been updated.
    // A notification or indication is sent to the remote device to signal that the characteristic has been updated. This function
    // should be invoked for every client that requests notifications/indications by writing to the "Client Configuration" descriptor
    // for the given characteristic.
    bool notifyCharacteristicChanged(BluetoothDevice* device, BluetoothGattCharacteristic* characteristic, bool confirm)
    {
        return NSNKROSS::w->mNVisitorBluetoothGatt->tRun(NSNKROSS::w->mNLambda00, (NParam)this, (NParam)device, (NParam)characteristic, (NParam)confirm);
    }

    // Send a response to a read or write request to a remote device.
    // This function must be invoked in when a remote read/write request is received by one of these callback methods :
    // BluetoothGattServerCallback::onCharacteristicReadRequest(BluetoothDevice, int, int, BluetoothGattCharacteristic)
    // BluetoothGattServerCallback::onCharacteristicWriteRequest(BluetoothDevice, int, BluetoothGattCharacteristic, boolean, boolean, int, byte[])
    bool sendResponse(BluetoothDevice* device, int requestId, int status, int offset, NArray<nubyte> value)
    {
        nuint vcIndex;
        nlong vcKey = NSNKROSS::w->mNKrossSystem->tRun(NSNKROSS::w->mNBeta01, 0, value.mcData);

        for (vcIndex = offset ; vcIndex < value.mcData ; ++vcIndex) {
            NSNKROSS::w->mNKrossSystem->tRun(NSNKROSS::w->mNBeta01, vcKey, vcIndex, value.maData[vcIndex]);
        };
        return NSNKROSS::w->mNVisitorBluetoothGatt->tRun(NSNKROSS::w->mNMu00, (NParam)this, (NParam)device, (NParam)requestId, (NParam)status, (NParam)vcKey);
    }

private:
    BluetoothGattServer(NKrossFriend* vNKrossFriend)
        : BluetoothProfile(NSNKROSS::w->mNKrossFriend->instance<BluetoothProfile>())
    {
    }
};

} // End namespace

#endif
