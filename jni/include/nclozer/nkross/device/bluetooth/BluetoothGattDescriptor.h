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
        NSNKROSS::w->mNVisitorBluetoothGatt->tRun(NSNKROSS::w->mNEta01, (NParam)this, NKrossParam(uuid).n, (NParam)permissions);
    }

    virtual ~BluetoothGattDescriptor()
    {
    }

    virtual int getPermissions()
    {
        return NSNKROSS::w->mNVisitorBluetoothGatt->tRun(NSNKROSS::w->mNTheta01, (NParam)this);
    }

    virtual String getUuid()
    {
        NReturn index = NSNKROSS::w->mNVisitorBluetoothGatt->tRun(NSNKROSS::w->mNIota01, (NParam)this);
        return NSNKROSS::w->mNKrossSystem->tGetString(NSNKROSS::w->mNKrossSystem->tRunObject((NParam)index));
    }

    virtual NArray<nubyte> getValue()
    {
        NReturn index = NSNKROSS::w->mNVisitorBluetoothGatt->tRun(NSNKROSS::w->mNKappa01, (NParam)this);
        NReturn size = NSNKROSS::w->mNKrossSystem->tRun(NSNKROSS::w->mNAlpha01, index, -1);
        NArray<nubyte> vNArray = NArray<nubyte>(size);
        nuint i;

        for (i = 0 ; i < size ; ++i) {
            vNArray.maData[i] = (nubyte)NSNKROSS::w->mNKrossSystem->tRun(NSNKROSS::w->mNAlpha01, index, (NParam)i, -1);
        }
        return vNArray;
    }

    virtual bool setValue(NArray<nubyte> value)
    {
        nuint vcIndex;
        nlong vcKey = NSNKROSS::w->mNKrossSystem->tRun(NSNKROSS::w->mNBeta01, 0, value.mcData);

        for (vcIndex = 0 ; vcIndex < value.mcData ; ++vcIndex) {
            NSNKROSS::w->mNKrossSystem->tRun(NSNKROSS::w->mNBeta01, vcKey, vcIndex, value.maData[vcIndex]);
        };
        return NSNKROSS::w->mNVisitorBluetoothGatt->tRun(NSNKROSS::w->mNLambda01, (NParam)this, (NParam)vcKey);
    }

private:
    BluetoothGattDescriptor(NKrossFriend* vNKrossFriend)
    {
    }
};

} // End namespace

#endif
