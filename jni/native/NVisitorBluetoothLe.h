#ifndef __NVisitorBluetoothLe_H__
#define __NVisitorBluetoothLe_H__

namespace NSNATIVE
{

class NVisitorBluetoothLe : public NVisitor
{
public:
    NVisitorBluetoothLe(NWrapper* w)
        : NVisitor(w)
    {
    }

   ~NVisitorBluetoothLe()
    {
    }

    //*******************************************************************************************
    //**************************************** TAdvertiseCallback *******************************
    //*******************************************************************************************
    //void onStartSuccess(AdvertiseSettings settingsInEffect)
    NReturn visit(NAlpha02* element, NParam a, NParam b, NParam c, NParam d, NParam e)
    {
        NReturn vcRet = 0;
        if (b == -1 && c == 1) vcRet = (NReturn)NWrapper::w->mNNoObject->pointer<AdvertiseSettings>();
        if (b != -1) ((AdvertiseCallback*)a)->onStartSuccess((AdvertiseSettings*)b);
        return vcRet;
    }

    //void onStartFailure(int errorCode)
    NReturn visit(NBeta02* element, NParam a, NParam b, NParam c, NParam d, NParam e)
    {
        NReturn vcRet = 0;
        if (b != -1) ((AdvertiseCallback*)a)->onStartFailure(b);
        return vcRet;
    }

    //*******************************************************************************************
    //**************************************** TScanCallback ************************************
    //*******************************************************************************************
    //void onBatchScanResults(List<ScanResult> results)
    NReturn visit(NGamma02* element, NParam a, NParam b, NParam c, NParam d, NParam e)
    {
        NReturn vcRet = 0;
        if (b != -1) {
            NReturn size = NWrapper::w->nFrame->tRun(NWrapper::w->mNAlpha01, (NParam)this, (NParam)b, -1, -1);
            NArray<ScanResult*> vNArray = NArray<ScanResult*>(size);
            int i;

            for (i = 0 ; i < size ; ++i) {
                ScanResult* vScanResult = NWrapper::w->mNNoObject->pointer<ScanResult>();
                vNArray.maData[i] = NWrapper::w->mNNoObject->emplaceKey(vScanResult, NWrapper::w->nFrame->tRun(NWrapper::w->mNAlpha01, (NParam)this, (NParam)b, (NParam)i, (NParam)vScanResult));
            }
            ((ScanCallback*)a)->onBatchScanResults(vNArray);
        }
        return vcRet;
    }

    //void onScanFailed(int errorCode)
    NReturn visit(NDelta02* element, NParam a, NParam b, NParam c, NParam d, NParam e)
    {
        NReturn vcRet = 0;
        if (b != -1) ((ScanCallback*)a)->onScanFailed(b);
        return vcRet;
    }

    //void onScanResult(int callbackType, ScanResult result)
    NReturn visit(NEpsilon02* element, NParam a, NParam b, NParam c, NParam d, NParam e)
    {
        NReturn vcRet = 0;
        if (b == -1 && c == 1) vcRet = (NReturn)NWrapper::w->mNNoObject->pointer<ScanResult>();
        if (b != -1) ((ScanCallback*)a)->onScanResult(b, (ScanResult*)c);
        return vcRet;
    }
};

} // END namespace

#endif
