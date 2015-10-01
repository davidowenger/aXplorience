#ifndef __BluetoothLeScanner_H__
#define __BluetoothLeScanner_H__

namespace NSDEVICE
{

class BluetoothLeScanner : public Object
{
friend NSNATIVE::NNoObject;

public:
    virtual ~BluetoothLeScanner()
    {
    }

    void flushPendingScanResults(ScanCallback* callback)
    {
        NWrapper::w->mNVisitorBluetoothLe->tRun(NWrapper::w->mNIota00, (NParam)this, (NParam)callback);
    }

    void startScan(ScanCallback* callback)
    {
        NWrapper::w->mNVisitorBluetoothLe->tRun(NWrapper::w->mNKappa00, (NParam)this,(NParam)callback);
    }

    void stopScan(ScanCallback* callback)
    {
        NWrapper::w->mNVisitorBluetoothLe->tRun(NWrapper::w->mNLambda00, (NParam)this, (NParam)callback);
    }

private:
    BluetoothLeScanner(NNoObject* vNNoObject)
    {
    }
};

} // End namespace

#endif
