#ifndef __BluetoothGattCharacteristic_H__
#define __BluetoothGattCharacteristic_H__

namespace NSDEVICE
{

class BluetoothGattCharacteristic : public Object
{
friend NSNATIVE::NKrossFriend;

public:
    static const int PERMISSION_READ = 0x00000001;
    static const int PERMISSION_READ_ENCRYPTED = 0x00000002;
    static const int PERMISSION_READ_ENCRYPTED_MITM = 0x00000004;
    static const int PERMISSION_WRITE = 0x00000010;
    static const int PERMISSION_WRITE_ENCRYPTED = 0x00000020;
    static const int PERMISSION_WRITE_ENCRYPTED_MITM = 0x00000040;
    static const int PERMISSION_WRITE_SIGNED = 0x00000080;
    static const int PERMISSION_WRITE_SIGNED_MITM = 0x00000100;
    static const int PROPERTY_BROADCAST = 0x00000001;
    static const int PROPERTY_EXTENDED_PROPS = 0x00000080;
    static const int PROPERTY_INDICATE = 0x00000020;
    static const int PROPERTY_NOTIFY = 0x00000010;
    static const int PROPERTY_READ = 0x00000002;
    static const int PROPERTY_SIGNED_WRITE = 0x00000008;
    static const int PROPERTY_WRITE = 0x00000004;
    static const int PROPERTY_WRITE_NO_RESPONSE = 0x00000004;
    static const int WRITE_TYPE_DEFAULT = 0x00000002;
    static const int WRITE_TYPE_NO_RESPONSE = 0x00000001;
    static const int WRITE_TYPE_SIGNED = 0x00000004;

    BluetoothGattCharacteristic(const String& uuid, int properties, int permissions)
    {
        NKrossWrapper::w->mNVisitorBluetoothGatt->tRun(NKrossWrapper::w->mNDelta00, (NParam)this, NKrossParam(uuid).n, (NParam)properties, (NParam)permissions);
    }

    virtual ~BluetoothGattCharacteristic()
    {
    }

    virtual bool addDescriptor(BluetoothGattDescriptor* descriptor)
    {
        return NKrossWrapper::w->mNVisitorBluetoothGatt->tRun(NKrossWrapper::w->mNUpsilon01, (NParam)this, (NParam)descriptor);
    }

    virtual BluetoothGattDescriptor* getDescriptor(const String& uuid)
    {
        BluetoothGattDescriptor* b = NKrossWrapper::w->mNKrossFriend->pointer<BluetoothGattDescriptor>();
        return NKrossWrapper::w->mNKrossFriend->emplaceKey(b, NKrossWrapper::w->mNVisitorBluetoothGatt->tRun(NKrossWrapper::w->mNGamma01, (NParam)this, (NParam)b, NKrossParam(uuid).n));
    }

    virtual NArray<BluetoothGattDescriptor*> getDescriptors()
    {
        NReturn index = NKrossWrapper::w->mNVisitorBluetoothGatt->tRun(NKrossWrapper::w->mNBeta01, (NParam)this);
        NReturn size = NKrossWrapper::w->mNKrossSystem->tRun(NKrossWrapper::w->mNAlpha01, index, -1);
        NArray<BluetoothGattDescriptor*> vNArray = NArray<BluetoothGattDescriptor*>(size);
        nuint i;

        for (i = 0 ; i < size ; ++i) {
            BluetoothGattDescriptor* b = NKrossWrapper::w->mNKrossFriend->pointer<BluetoothGattDescriptor>();
            vNArray.maData[i] = NKrossWrapper::w->mNKrossFriend->emplaceKey(b, NKrossWrapper::w->mNKrossSystem->tRun(NKrossWrapper::w->mNAlpha01, index, (NParam)i, (NParam)b));
        }
        return vNArray;
    }

    virtual int getProperties()
    {
        return NKrossWrapper::w->mNVisitorBluetoothGatt->tRun(NKrossWrapper::w->mNEpsilon01, (NParam)this);
    }

    virtual String getUuid()
    {
        NReturn index = NKrossWrapper::w->mNVisitorBluetoothGatt->tRun(NKrossWrapper::w->mNDzeta01, (NParam)this);
        return NKrossWrapper::w->mNKrossSystem->tGetString(NKrossWrapper::w->mNKrossSystem->tRunObject((NParam)index));
    }

    virtual NArray<nubyte> getValue()
    {
        NReturn index = NKrossWrapper::w->mNVisitorBluetoothGatt->tRun(NKrossWrapper::w->mNEpsilon00, (NParam)this);
        NReturn size = NKrossWrapper::w->mNKrossSystem->tRun(NKrossWrapper::w->mNAlpha01, index, -1);
        NArray<nubyte> vNArray =  NArray<nubyte>(size);
        nuint i;

        for (i = 0 ; i < size ; ++i) {
            vNArray.maData[i] = (nubyte)NKrossWrapper::w->mNKrossSystem->tRun(NKrossWrapper::w->mNAlpha01, index, (NParam)i);
        }
        return vNArray;
    }

    virtual String getStringValue(int offset)
    {
        NReturn index = NKrossWrapper::w->mNVisitorBluetoothGatt->tRun(NKrossWrapper::w->mNDzeta00, (NParam)this, (NParam)offset);
        return NKrossWrapper::w->mNKrossSystem->tGetString(NKrossWrapper::w->mNKrossSystem->tRunObject((NParam)index));
    }

    virtual bool setValue(NArray<nubyte> value)
    {
        nuint vcIndex;
        nlong vcKey = NKrossWrapper::w->mNKrossSystem->tRun(NKrossWrapper::w->mNBeta01, 0, value.mcData);

        for (vcIndex = 0 ; vcIndex < value.mcData ; ++vcIndex) {
            NKrossWrapper::w->mNKrossSystem->tRun(NKrossWrapper::w->mNBeta01, vcKey, vcIndex, value.maData[vcIndex]);
        };
        return NKrossWrapper::w->mNVisitorBluetoothGatt->tRun(NKrossWrapper::w->mNEta00, (NParam)this, (NParam)vcKey);
    }

    virtual bool setValue(const String& value)
    {
        return NKrossWrapper::w->mNVisitorBluetoothGatt->tRun(NKrossWrapper::w->mNTheta00, (NParam)this, NKrossParam(value).n);
    }

    virtual void setWriteType(int writeType)
    {
        NKrossWrapper::w->mNVisitorBluetoothGatt->tRun(NKrossWrapper::w->mNIota00, (NParam)this, (NParam)writeType);
    }

private:
    BluetoothGattCharacteristic(NKrossFriend* vNKrossFriend)
    {
    }
};

} // End namespace

#endif
