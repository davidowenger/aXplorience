#ifndef __BluetoothGattDescriptor_H__
#define __BluetoothGattDescriptor_H__

namespace NSDEVICE
{

class BluetoothGattDescriptor : public Object
{
friend NSNATIVE::NNoObject;

public:
    BluetoothGattDescriptor(const String& uuid, int permissions)
    {
        NWrapper::w->mNVisitorBluetoothGatt->tRun(NWrapper::w->mNEta01, (NParam)this, NParamBox(NWrapper::w, uuid).n, (NParam)permissions);
    }

    virtual ~BluetoothGattDescriptor()
    {
    }

    virtual int getPermissions()
    {
        return NWrapper::w->mNVisitorBluetoothGatt->tRun(NWrapper::w->mNTheta01, (NParam)this);
    }

    virtual String getUuid()
    {
        NReturn index = NWrapper::w->mNVisitorBluetoothGatt->tRun(NWrapper::w->mNIota01, (NParam)this);
        return NWrapper::w->nFrame->tGetString(NWrapper::w->nFrame->tRunObject((NParam)index));
    }

    virtual NArray<nubyte> getValue()
    {
        NReturn index = NWrapper::w->mNVisitorBluetoothGatt->tRun(NWrapper::w->mNKappa01, (NParam)this);
        NReturn size = NWrapper::w->nFrame->tRun(NWrapper::w->mNAlpha01, (NParam)this, (NParam)index, -1, -1);
        NArray<nubyte> vNArray = NArray<nubyte>(size);
        nuint i;

        for (i = 0 ; i < size ; ++i) {
            vNArray.maData[i] = (nubyte)NWrapper::w->nFrame->tRun(NWrapper::w->mNAlpha01, (NParam)this, (NParam)index, (NParam)i, -1);
        }
        return vNArray;
    }

    virtual bool setValue(NArray<nubyte> value)
    {
        nuint vcIndex;
        nlong vcKey = NWrapper::w->nFrame->tRun(NWrapper::w->mNBeta01, 0, value.mSize);

        for (vcIndex = 0 ; vcIndex < value.mSize ; ++vcIndex) {
            NWrapper::w->nFrame->tRun(NWrapper::w->mNBeta01, vcKey, vcIndex, value.maData[vcIndex]);
        };
        return NWrapper::w->mNVisitorBluetoothGatt->tRun(NWrapper::w->mNLambda01, (NParam)this, (NParam)vcKey);
    }

private:
    BluetoothGattDescriptor(NNoObject* vNNoObject)
    {
    }
};

} // End namespace

#endif
