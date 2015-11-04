#ifndef __BluetoothGattServerCallback_H__
#define __BluetoothGattServerCallback_H__

namespace NSDEVICE
{

class BluetoothGattServerCallback : public Object
{
friend NSNATIVE::NKrossFriend;

public:
    virtual ~BluetoothGattServerCallback()
    {
    }

    // A remote client has requested to write to a local characteristic.
    // An application must call BluetoothGattServer::sendResponse(BluetoothDevice, int, int, int, byte[]) to complete the request.
    virtual void onCharacteristicWriteRequest(
        BluetoothDevice* device,
        int requestId,
        BluetoothGattCharacteristic* characteristic,
        bool preparedWrite,
        bool responseNeeded,
        int offset,
        NArray<nubyte> value
    ) = 0;
    virtual void onConnectionStateChange(BluetoothDevice* device, int status, int newState) = 0;
    virtual void onNotificationSent(BluetoothDevice* device, int status) = 0;
    virtual void onServiceAdded(int status, BluetoothGattService* service) = 0;

protected:
    BluetoothGattServerCallback()
    {
        NSNKROSS::w->mNVisitorBluetoothGatt->tRun(NSNKROSS::w->mNNu00, (NParam)this);
    }
};

} // End namespace

#endif
