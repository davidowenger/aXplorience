#ifndef __ScanResult_H__
#define __ScanResult_H__

namespace NSDEVICE
{

class ScanResult : public Object
{
friend NSNATIVE::NKrossFriend;

public:
    ScanResult(BluetoothDevice* device, ScanRecord* scanRecord, int rssi, long timestampNanos)
    {
        NKrossWrapper::w->mNVisitorBluetoothLe->tRun(NKrossWrapper::w->mNOmicron00, (NParam)this, (NParam)device, (NParam)scanRecord, (NParam)rssi, (NParam)timestampNanos);
    }

    ~ScanResult()
    {
    }

    BluetoothDevice* getDevice()
    {
        BluetoothDevice* b = NKrossWrapper::w->mNKrossFriend->pointer<BluetoothDevice>();
        return NKrossWrapper::w->mNKrossFriend->emplaceKey(b, NKrossWrapper::w->mNVisitorBluetoothLe->tRun(NKrossWrapper::w->mNPi00, (NParam)this, (NParam)b));
    }

    ScanRecord* getScanRecord()
    {
        ScanRecord* b = NKrossWrapper::w->mNKrossFriend->pointer<ScanRecord>();
        return NKrossWrapper::w->mNKrossFriend->emplaceKey(b, NKrossWrapper::w->mNVisitorBluetoothLe->tRun(NKrossWrapper::w->mNRho00, (NParam)this, (NParam)b));
    }

private:
    ScanResult(NKrossFriend* vNKrossFriend)
    {
    }
};

} // End namespace

#endif
