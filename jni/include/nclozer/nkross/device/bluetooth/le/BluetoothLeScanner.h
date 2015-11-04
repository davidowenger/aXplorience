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
        NSNKROSS::w->mNVisitorBluetoothLe->tRun(NSNKROSS::w->mNIota00, (NParam)this, (NParam)callback);
    }

    void startScan(ScanCallback* callback)
    {
        NSNKROSS::w->mNVisitorBluetoothLe->tRun(NSNKROSS::w->mNKappa00, (NParam)this,(NParam)callback);
    }

    void stopScan(ScanCallback* callback)
    {
        NSNKROSS::w->mNVisitorBluetoothLe->tRun(NSNKROSS::w->mNLambda00, (NParam)this, (NParam)callback);
    }

private:
    BluetoothLeScanner(NKrossFriend* vNKrossFriend)
    {
    }
};

} // End namespace

#endif
