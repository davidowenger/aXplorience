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
        NSNKROSS::w->mNVisitorBluetoothLe->tRun(NSNKROSS::w->mNOmicron00, (NParam)this, (NParam)device, (NParam)scanRecord, (NParam)rssi, (NParam)timestampNanos);
    }

    ~ScanResult()
    {
    }

    BluetoothDevice* getDevice()
    {
        BluetoothDevice* b = NSNKROSS::w->mNKrossFriend->pointer<BluetoothDevice>();
        return NSNKROSS::w->mNKrossFriend->emplaceKey(b, NSNKROSS::w->mNVisitorBluetoothLe->tRun(NSNKROSS::w->mNPi00, (NParam)this, (NParam)b));
    }

    ScanRecord* getScanRecord()
    {
        ScanRecord* b = NSNKROSS::w->mNKrossFriend->pointer<ScanRecord>();
        return NSNKROSS::w->mNKrossFriend->emplaceKey(b, NSNKROSS::w->mNVisitorBluetoothLe->tRun(NSNKROSS::w->mNRho00, (NParam)this, (NParam)b));
    }

private:
    ScanResult(NKrossFriend* vNKrossFriend)
    {
    }
};

} // End namespace

#endif
