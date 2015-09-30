#ifndef __ScanRecord_H__
#define __ScanRecord_H__

namespace NSDEVICE
{

class ScanRecord : public Object
{
friend NSNATIVE::NNoObject;

public:
    ~ScanRecord()
    {
    }

    int getAdvertiseFlags()
    {
        return NWrapper::w->mNVisitorBluetoothLe->tRun(NWrapper::w->mNNu00, (NParam)this);
    }

    NArray<String> getServiceUuids()
    {
        NReturn index = NWrapper::w->mNVisitorBluetoothLe->tRun(NWrapper::w->mNXi00, (NParam)this);
        NReturn size = NWrapper::w->nFrame->tRun(NWrapper::w->mNAlpha01, (NParam)this, (NParam)index, -1, -1);
        NArray<String> vNArray = NArray<String>(size);
        nuint i;

        for (i = 0 ; i < size ; ++i) {
            index = NWrapper::w->nFrame->tRun(NWrapper::w->mNAlpha01, (NParam)this, (NParam)index, (NParam)i, (NParam)-1);
            vNArray.maData[i] = NWrapper::w->nFrame->tGetString(NWrapper::w->nFrame->tRunObject((NParam)index));
        }
        return vNArray;
    }

private:
    ScanRecord(NNoObject* vNNoObject)
    {
    }
};

} // End namespace

#endif
