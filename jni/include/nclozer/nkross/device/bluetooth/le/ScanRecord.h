#ifndef __ScanRecord_H__
#define __ScanRecord_H__

namespace NSDEVICE
{

class ScanRecord : public Object
{
friend NSNATIVE::NKrossFriend;

public:
    ~ScanRecord()
    {
    }

    int getAdvertiseFlags()
    {
        return NKrossWrapper::w->mNVisitorBluetoothLe->tRun(NKrossWrapper::w->mNNu00, (NParam)this);
    }

    NArray<String> getServiceUuids()
    {
        NReturn index = NKrossWrapper::w->mNVisitorBluetoothLe->tRun(NKrossWrapper::w->mNXi00, (NParam)this);
        NReturn size = NKrossWrapper::w->mNKrossSystem->tRun(NKrossWrapper::w->mNAlpha01, index, -1);
        NArray<String> vNArray = NArray<String>(size);
        nuint i;

        for (i = 0 ; i < size ; ++i) {
            vNArray.maData[i] = NKrossWrapper::w->mNKrossSystem->tGetString(NKrossWrapper::w->mNKrossSystem->tRunObject(index, (NParam)i));
        }
        return vNArray;
    }

private:
    ScanRecord(NKrossFriend* vNKrossFriend)
    {
    }
};

} // End namespace

#endif
