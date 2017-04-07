#ifndef __BluetoothLeScanner_H__
#define __BluetoothLeScanner_H__

namespace NSDEVICE
{

class BluetoothLeScanner : public Object
{
friend NSNATIVE::NKrossFriend;

public:
    virtual ~BluetoothLeScanner()
    {
    }

    void flushPendingScanResults(ScanCallback* callback)
    {
        NKrossWrapper::w->mNVisitorBluetoothLe->tRun(NKrossWrapper::w->mNIota00, (NParam)this, (NParam)callback);
    }

    void startScan(ScanCallback* callback)
    {
        NKrossWrapper::w->mNVisitorBluetoothLe->tRun(NKrossWrapper::w->mNKappa00, (NParam)this,(NParam)callback);
    }

    void stopScan(ScanCallback* callback)
    {
        NKrossWrapper::w->mNVisitorBluetoothLe->tRun(NKrossWrapper::w->mNLambda00, (NParam)this, (NParam)callback);
    }

private:
    BluetoothLeScanner(NKrossFriend* vNKrossFriend)
    {
    }
};

} // End namespace

#endif
