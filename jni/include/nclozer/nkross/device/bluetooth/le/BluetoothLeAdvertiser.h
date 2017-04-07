#ifndef __BluetoothLeAdvertiser_H__
#define __BluetoothLeAdvertiser_H__

namespace NSDEVICE
{

class BluetoothLeAdvertiser : public Object
{
friend NSNATIVE::NKrossFriend;

public:
    virtual ~BluetoothLeAdvertiser()
    {
    }

    void startAdvertising(AdvertiseSettings* settings, AdvertiseData* advertiseData, AdvertiseCallback* callback)
    {
        NKrossWrapper::w->mNVisitorBluetoothLe->tRun(NKrossWrapper::w->mNDzeta00, (NParam)this, (NParam)settings, (NParam)advertiseData, (NParam)callback);
    }

    void startAdvertising(AdvertiseSettings* settings, AdvertiseData* advertiseData, AdvertiseData* scanResponse, AdvertiseCallback* callback)
    {
        NKrossWrapper::w->mNVisitorBluetoothLe->tRun(NKrossWrapper::w->mNEta00, (NParam)this, (NParam)settings, (NParam)advertiseData, (NParam)scanResponse, (NParam)callback);
    }

    void stopAdvertising(AdvertiseCallback* callback)
    {
        NKrossWrapper::w->mNVisitorBluetoothLe->tRun(NKrossWrapper::w->mNTheta00, (NParam)this, (NParam)callback);
    }

private:
    BluetoothLeAdvertiser(NKrossFriend* vNKrossFriend)
    {
    }
};

} // End namespace

#endif
