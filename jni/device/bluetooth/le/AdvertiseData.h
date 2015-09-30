#ifndef __AdvertiseData_H__
#define __AdvertiseData_H__

namespace NSDEVICE
{

class AdvertiseData : public Object
{
friend NSNATIVE::NNoObject;

public:
    class Builder
    {
    public:
        Builder()
        {
            NWrapper::w->mNVisitorBluetoothLe->tRun(NWrapper::w->mNSigma00, (NParam)this);
        }

        AdvertiseData::Builder* addServiceUuid(const String& serviceUuid)
        {
            NWrapper::w->mNVisitorBluetoothLe->tRun(NWrapper::w->mNTau00, (NParam)this, NParamBox(NWrapper::w, serviceUuid).n);
            return this;
        }

        AdvertiseData* build()
        {
            AdvertiseData* b = NWrapper::w->mNNoObject->pointer<AdvertiseData>();
            return NWrapper::w->mNNoObject->emplaceKey(b, NWrapper::w->mNVisitorBluetoothLe->tRun(NWrapper::w->mNUpsilon00, (NParam)this, (NParam)b));
        }
    };

    ~AdvertiseData()
    {
    }

    NArray<String> getServiceUuids()
    {
        NReturn index = NWrapper::w->mNVisitorBluetoothLe->tRun(NWrapper::w->mNBeta00, (NParam)this);
        NReturn size = NWrapper::w->nFrame->tRun(NWrapper::w->mNAlpha01, (NParam)this, (NParam)index, -1, -1);
        NArray<String> vNArray = NArray<String>(size);
        nuint i;

        for (i = 0 ; i < size ; ++i) {
            vNArray.maData[i] = NWrapper::w->nFrame->tGetString(NWrapper::w->nFrame->tRunObject((NParam)index, (NParam)i));
        }
        return vNArray;
    }

private:
    AdvertiseData(NNoObject* vNNoObject)
    {
    }
};

} // End namespace

#endif
