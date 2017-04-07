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
            NKrossWrapper::w->mNVisitorBluetoothLe->tRun(NKrossWrapper::w->mNSigma00, (NParam)this);
        }

        AdvertiseData::Builder* addServiceUuid(const String& serviceUuid)
        {
            NKrossWrapper::w->mNVisitorBluetoothLe->tRun(NKrossWrapper::w->mNTau00, (NParam)this, NKrossParam(serviceUuid).n);
            return this;
        }

        AdvertiseData* build()
        {
            AdvertiseData* b = NKrossWrapper::w->mNKrossFriend->pointer<AdvertiseData>();
            return NKrossWrapper::w->mNKrossFriend->emplaceKey(b, NKrossWrapper::w->mNVisitorBluetoothLe->tRun(NKrossWrapper::w->mNUpsilon00, (NParam)this, (NParam)b));
        }
    };

    ~AdvertiseData()
    {
    }

    vector<String> getServiceUuids()
    {
        NReturn index = NKrossWrapper::w->mNVisitorBluetoothLe->tRun(NKrossWrapper::w->mNBeta00, (NParam)this);
        NReturn size = NKrossWrapper::w->mNKrossSystem->tRun(NKrossWrapper::w->mNAlpha01, index, -1);
        vector<String> vVector(size);
        nuint i;

        for (i = 0 ; i < size ; ++i) {
            vVector.push_back(NKrossWrapper::w->mNKrossSystem->tGetString(NKrossWrapper::w->mNKrossSystem->tRunObject(index, (NParam)i)));
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
