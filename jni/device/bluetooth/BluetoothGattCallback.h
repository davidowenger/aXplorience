#ifndef __BluetoothGattCallback_H__
#define __BluetoothGattCallback_H__

namespace NSDEVICE
{

class BluetoothGattCallback : public Object
{
friend NSNATIVE::NNoObject;

public:
    virtual ~BluetoothGattCallback()
    {
    }
    virtual void onCharacteristicWrite(BluetoothGatt* gatt, BluetoothGattCharacteristic* characteristic, int status) = 0;
    virtual void onConnectionStateChange(BluetoothGatt* gatt, int status, int newState) = 0;
    virtual void onServicesDiscovered(BluetoothGatt* gatt, int status) = 0;

protected:
    BluetoothGattCallback()
    {
        NWrapper::w->mNVisitorBluetoothGatt->tRun(NWrapper::w->mNGamma00, (NParam)this);
    }
};

} // End namespace

#endif
