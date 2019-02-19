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
        return NSNKROSS::w->mNVisitorBluetoothLe->tRun(NSNKROSS::w->mNNu00, (NParam)this);
    }

    NArray<String> getServiceUuids()
    {
        NReturn index = NSNKROSS::w->mNVisitorBluetoothLe->tRun(NSNKROSS::w->mNXi00, (NParam)this);
        NReturn size = NSNKROSS::w->mNKrossSystem->tRun(NSNKROSS::w->mNAlpha01, index, -1);
        NArray<String> vNArray = NArray<String>(size);
        nuint i;

        for (i = 0 ; i < size ; ++i) {
            vNArray.maData[i] = NSNKROSS::w->mNKrossSystem->tGetString(NSNKROSS::w->mNKrossSystem->tRunObject(index, (NParam)i));
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
