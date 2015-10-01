#ifndef __BluetoothLeAdvertiser_H__
#define __BluetoothLeAdvertiser_H__

namespace NSDEVICE
{

class BluetoothLeAdvertiser : public Object
{
friend NSNATIVE::NNoObject;

public:
    virtual ~BluetoothLeAdvertiser()
    {
    }

    void startAdvertising(AdvertiseSettings* settings, AdvertiseData* advertiseData, AdvertiseCallback* callback)
    {
        NWrapper::w->mNVisitorBluetoothLe->tRun(NWrapper::w->mNDzeta00, (NParam)this, (NParam)settings, (NParam)advertiseData, (NParam)callback);
    }

    void startAdvertising(AdvertiseSettings* settings, AdvertiseData* advertiseData, AdvertiseData* scanResponse, AdvertiseCallback* callback)
    {
        NWrapper::w->mNVisitorBluetoothLe->tRun(NWrapper::w->mNEta00, (NParam)this, (NParam)settings, (NParam)advertiseData, (NParam)scanResponse, (NParam)callback);
    }

    void stopAdvertising(AdvertiseCallback* callback)
    {
        NWrapper::w->mNVisitorBluetoothLe->tRun(NWrapper::w->mNTheta00, (NParam)this, (NParam)callback);
    }

private:
    BluetoothLeAdvertiser(NNoObject* vNNoObject)
    {
    }
};

} // End namespace

#endif
