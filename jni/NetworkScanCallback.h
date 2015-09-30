#ifndef __NetworkScanCallback_H__
#define __NetworkScanCallback_H__

namespace NSDEVICE
{

class NetworkScanCallback : public BluetoothAdapter::LeScanCallback
{
public:
    NetworkScanCallback(Wrapper* vWrapper)
        : w(vWrapper)
    {
    }

    virtual ~NetworkScanCallback()
    {
    }

    virtual void onLeScan(BluetoothDevice* device, int rssi, NArray<nubyte> scanRecord)
    {
        w->mOpUnitNetwork->sendOp(w->mOpUnitNetworkId, w->w->mNAlpha00, new OpParam((NParam)device));
    }

    Wrapper* w;
};

} // End namespace

#endif
