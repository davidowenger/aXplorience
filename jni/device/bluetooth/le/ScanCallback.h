#ifndef __ScanCallback_H__
#define __ScanCallback_H__

namespace NSDEVICE
{

class ScanCallback : public Object
{
friend NSNATIVE::NNoObject;

public:
    static const int SCAN_FAILED_ALREADY_STARTED = 0x00000001;
    static const int SCAN_FAILED_APPLICATION_REGISTRATION_FAILED = 0x00000002;
    static const int SCAN_FAILED_FEATURE_UNSUPPORTED = 0x00000004;
    static const int SCAN_FAILED_INTERNAL_ERROR = 0x00000003;

    ScanCallback()
    {
        NWrapper::w->mNVisitorBluetoothLe->tRun(NWrapper::w->mNMu00, (NParam)this);
    }

    virtual ~ScanCallback()
    {
    }

    virtual void onBatchScanResults(NArray<ScanResult*> results) = 0;
    virtual bool onScanFailed(int errorCode) = 0;
    virtual void onScanResult(int callbackType, ScanResult* result) = 0;

private:
    ScanCallback(NNoObject* vNNoObject)
    {
    }
};

} // End namespace

#endif
