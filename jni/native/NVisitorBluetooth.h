#ifndef __NVisitorBluetooth_H__
#define __NVisitorBluetooth_H__

namespace NSNATIVE
{

class NVisitorBluetooth : public NVisitor
{
public:
    NVisitorBluetooth(NWrapper* w)
        : NVisitor(w)
    {
    }

   ~NVisitorBluetooth()
    {
    }

    //*******************************************************************************************
    //**************************************** LeScanCallback ***********************************
    //*******************************************************************************************
    //void onLeScan(BluetoothDevice device, int rssi, byte[] scanRecord)
    NReturn visit(NAlpha01* element, NParam a, NParam b, NParam c, NParam d, NParam e)
    {
        NReturn vcRet = 0;
        if (b == -1 && c == 1) vcRet = (NReturn)NWrapper::w->mNNoObject->pointer<BluetoothDevice>();
        if (b != -1) {
            NReturn size = NWrapper::w->nFrame->tRun(NWrapper::w->mNAlpha01, (NParam)this, (NParam)d, -1, -1);
            NArray<nubyte> vaNArray = NArray<nubyte>(size);
            int i;

            for (i = 0 ; i < size ; ++i) {
                vaNArray.maData[i] = NWrapper::w->nFrame->tRun(NWrapper::w->mNAlpha01, (NParam)this, (NParam)d, (NParam)i, (NParam)-1);
            }
            ((BluetoothAdapter::LeScanCallback*)a)->onLeScan((BluetoothDevice*)b, c, vaNArray);
        }
        return vcRet;
    }
};

} // END namespace

#endif
