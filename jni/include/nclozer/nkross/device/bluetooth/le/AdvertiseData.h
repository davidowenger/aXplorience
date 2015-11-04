#ifndef __AdvertiseData_H__
#define __AdvertiseData_H__

namespace NSDEVICE
{

class AdvertiseData : public Object
{
friend NSNATIVE::NKrossFriend;

public:
    class Builder
    {
    public:
        Builder()
        {
            NSNKROSS::w->mNVisitorBluetoothLe->tRun(NSNKROSS::w->mNSigma00, (NParam)this);
        }

        AdvertiseData::Builder* addServiceUuid(const String& serviceUuid)
        {
            NSNKROSS::w->mNVisitorBluetoothLe->tRun(NSNKROSS::w->mNTau00, (NParam)this, NKrossParam(serviceUuid).n);
            return this;
        }

        AdvertiseData* build()
        {
            AdvertiseData* b = NSNKROSS::w->mNKrossFriend->pointer<AdvertiseData>();
            return NSNKROSS::w->mNKrossFriend->emplaceKey(b, NSNKROSS::w->mNVisitorBluetoothLe->tRun(NSNKROSS::w->mNUpsilon00, (NParam)this, (NParam)b));
        }
    };

    ~AdvertiseData()
    {
    }

    vector<String> getServiceUuids()
    {
        NReturn index = NSNKROSS::w->mNVisitorBluetoothLe->tRun(NSNKROSS::w->mNBeta00, (NParam)this);
        NReturn size = NSNKROSS::w->mNKrossSystem->tRun(NSNKROSS::w->mNAlpha01, index, -1);
        vector<String> vVector(size);
        nuint i;

        for (i = 0 ; i < size ; ++i) {
            vVector.push_back(NSNKROSS::w->mNKrossSystem->tGetString(NSNKROSS::w->mNKrossSystem->tRunObject(index, (NParam)i)));
        }
        return vVector;
    }

private:
    AdvertiseData(NKrossFriend* vNKrossFriend)
    {
    }
};

} // End namespace

#endif
