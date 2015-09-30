#ifndef __ScanResult_H__
#define __ScanResult_H__

namespace NSDEVICE
{

class ScanResult : public Object
{
friend NSNATIVE::NNoObject;

public:
    ScanResult(BluetoothDevice* device, ScanRecord* scanRecord, int rssi, long timestampNanos)
    {
        NWrapper::w->mNVisitorBluetoothLe->tRun(NWrapper::w->mNOmicron00, (NParam)this, (NParam)device, (NParam)scanRecord, (NParam)rssi, (NParam)timestampNanos);
    }

    ~ScanResult()
    {
    }

    BluetoothDevice* getDevice()
    {
        BluetoothDevice* b = NWrapper::w->mNNoObject->pointer<BluetoothDevice>();
        return NWrapper::w->mNNoObject->emplaceKey(b, NWrapper::w->mNVisitorBluetoothLe->tRun(NWrapper::w->mNPi00, (NParam)this, (NParam)b));
    }

    ScanRecord* getScanRecord()
    {
        ScanRecord* b = NWrapper::w->mNNoObject->pointer<ScanRecord>();
        return NWrapper::w->mNNoObject->emplaceKey(b, NWrapper::w->mNVisitorBluetoothLe->tRun(NWrapper::w->mNRho00, (NParam)this, (NParam)b));
    }

private:
    ScanResult(NNoObject* vNNoObject)
    {
    }
};

} // End namespace

#endif
