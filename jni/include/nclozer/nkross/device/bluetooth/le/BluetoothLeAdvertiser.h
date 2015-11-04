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
        NSNKROSS::w->mNVisitorBluetoothLe->tRun(NSNKROSS::w->mNDzeta00, (NParam)this, (NParam)settings, (NParam)advertiseData, (NParam)callback);
    }

    void startAdvertising(AdvertiseSettings* settings, AdvertiseData* advertiseData, AdvertiseData* scanResponse, AdvertiseCallback* callback)
    {
        NSNKROSS::w->mNVisitorBluetoothLe->tRun(NSNKROSS::w->mNEta00, (NParam)this, (NParam)settings, (NParam)advertiseData, (NParam)scanResponse, (NParam)callback);
    }

    void stopAdvertising(AdvertiseCallback* callback)
    {
        NSNKROSS::w->mNVisitorBluetoothLe->tRun(NSNKROSS::w->mNTheta00, (NParam)this, (NParam)callback);
    }

private:
    BluetoothLeAdvertiser(NKrossFriend* vNKrossFriend)
    {
    }
};

} // End namespace

#endif
