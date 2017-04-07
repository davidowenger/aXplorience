#ifndef __BluetoothGattDescriptor_H__
#define __BluetoothGattDescriptor_H__

namespace NSDEVICE
{

class BluetoothGattDescriptor : public Object
{
friend NSNATIVE::NKrossFriend;

public:
    BluetoothGattDescriptor(const String& uuid, int permissions)
    {
        NKrossWrapper::w->mNVisitorBluetoothGatt->tRun(NKrossWrapper::w->mNEta01, (NParam)this, NKrossParam(uuid).n, (NParam)permissions);
    }

    virtual ~BluetoothGattDescriptor()
    {
    }

    virtual int getPermissions()
    {
        return NKrossWrapper::w->mNVisitorBluetoothGatt->tRun(NKrossWrapper::w->mNTheta01, (NParam)this);
    }

    virtual String getUuid()
    {
        NReturn index = NKrossWrapper::w->mNVisitorBluetoothGatt->tRun(NKrossWrapper::w->mNIota01, (NParam)this);
        return NKrossWrapper::w->mNKrossSystem->tGetString(NKrossWrapper::w->mNKrossSystem->tRunObject((NParam)index));
    }

    virtual NArray<nubyte> getValue()
    {
        NReturn index = NKrossWrapper::w->mNVisitorBluetoothGatt->tRun(NKrossWrapper::w->mNKappa01, (NParam)this);
        NReturn size = NKrossWrapper::w->mNKrossSystem->tRun(NKrossWrapper::w->mNAlpha01, index, -1);
        NArray<nubyte> vNArray = NArray<nubyte>(size);
        nuint i;

        for (i = 0 ; i < size ; ++i) {
            vNArray.maData[i] = (nubyte)NKrossWrapper::w->mNKrossSystem->tRun(NKrossWrapper::w->mNAlpha01, index, (NParam)i, -1);
        }
        return vNArray;
    }

    virtual bool setValue(NArray<nubyte> value)
    {
        nuint vcIndex;
        nlong vcKey = NKrossWrapper::w->mNKrossSystem->tRun(NKrossWrapper::w->mNBeta01, 0, value.mcData);

        for (vcIndex = 0 ; vcIndex < value.mcData ; ++vcIndex) {
            NKrossWrapper::w->mNKrossSystem->tRun(NKrossWrapper::w->mNBeta01, vcKey, vcIndex, value.maData[vcIndex]);
        };
        return NKrossWrapper::w->mNVisitorBluetoothGatt->tRun(NKrossWrapper::w->mNLambda01, (NParam)this, (NParam)vcKey);
    }

private:
    BluetoothGattDescriptor(NKrossFriend* vNKrossFriend)
    {
    }
};

} // End namespace

#endif
