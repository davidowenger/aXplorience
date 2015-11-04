#ifndef __NVisitorBluetoothLe_H__
#define __NVisitorBluetoothLe_H__

namespace NSNATIVE
{

class NVisitorBluetoothLe : public NKrossVisitor
{
public:
    NVisitorBluetoothLe(NWrapper* w)
        : NKrossVisitor(w)
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
        if (b == -1 && c == 1) vcRet = (NReturn)mNWrapper->mNKrossWrapper->mNKrossFriend->pointer<AdvertiseSettings>();
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
            NReturn size = mNWrapper->mNKrossWrapper->mNKrossSystem->tRun(mNWrapper->mNKrossWrapper->mNAlpha01, (NParam)this, (NParam)b, -1, -1);
            NArray<ScanResult*> vNArray = NArray<ScanResult*>(size);
            int i;

            for (i = 0 ; i < size ; ++i) {
                ScanResult* vScanResult = mNWrapper->mNKrossWrapper->mNKrossFriend->pointer<ScanResult>();
                vNArray.maData[i] = mNWrapper->mNKrossWrapper->mNKrossFriend->emplaceKey(vScanResult, mNWrapper->mNKrossWrapper->mNKrossSystem->tRun(mNWrapper->mNKrossWrapper->mNAlpha01, (NParam)this, (NParam)b, (NParam)i, (NParam)vScanResult));
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
        if (b == -1 && c == 1) vcRet = (NReturn)mNWrapper->mNKrossWrapper->mNKrossFriend->pointer<ScanResult>();
        if (b != -1) ((ScanCallback*)a)->onScanResult(b, (ScanResult*)c);
        return vcRet;
    }
};

} // END namespace

#endif
