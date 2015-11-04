#ifndef __NVisitorBluetoothGatt_H__
#define __NVisitorBluetoothGatt_H__

namespace NSNATIVE
{

class NVisitorBluetoothGatt : public NKrossVisitor
{
public:
    NVisitorBluetoothGatt(NWrapper* w)
        : NKrossVisitor(w)
    {
    }

   ~NVisitorBluetoothGatt()
    {
    }

    //*******************************************************************************************
    //**************************************** TBluetoothGattCallback ***************************
    //*******************************************************************************************
    //void onCharacteristicWrite(BluetoothGatt gatt, BluetoothGattCharacteristic characteristic, int status)
    NReturn visit(NAlpha01* element, NParam a, NParam b, NParam c, NParam d, NParam e)
    {
        NReturn vcRet = 0;
        if (b == -1 && c == 2) vcRet = (NReturn)mNWrapper->mNKrossWrapper->mNKrossFriend->pointer<BluetoothGatt>();
        if (b == -1 && c == 1) vcRet = (NReturn)mNWrapper->mNKrossWrapper->mNKrossFriend->pointer<BluetoothGattCharacteristic>();
        if (b != -1) ((BluetoothGattCallback*)a)->onCharacteristicWrite((BluetoothGatt*)b, (BluetoothGattCharacteristic*)c, d);
        return vcRet;
    }

    //void onConnectionStateChange(BluetoothGatt gatt, int status, int newState)
    NReturn visit(NBeta01* element, NParam a, NParam b, NParam c, NParam d, NParam e)
    {
        NReturn vcRet = 0;
        if (b == -1 && c == 1) vcRet = (NReturn)mNWrapper->mNKrossWrapper->mNKrossFriend->pointer<BluetoothGatt>();
        if (b != -1) ((BluetoothGattCallback*)a)->onConnectionStateChange((BluetoothGatt*)b, c, d);
        return vcRet;
    }

    //void onServicesDiscovered(BluetoothGatt gatt, int status)
    NReturn visit(NGamma01* element, NParam a, NParam b, NParam c, NParam d, NParam e)
    {
        NReturn vcRet = 0;
        if (b == -1 && c == 1) vcRet = (NReturn)mNWrapper->mNKrossWrapper->mNKrossFriend->pointer<BluetoothGatt>();
        if (b != -1) ((BluetoothGattCallback*)a)->onServicesDiscovered((BluetoothGatt*)b, c);
        return vcRet;
    }

    //*******************************************************************************************
    //********************************** TBluetoothGattServerCallback ***************************
    //*******************************************************************************************
    //void onCharacteristicWriteRequest(
    //    BluetoothDevice device,
    //    int requestId,
    //    BluetoothGattCharacteristic characteristic,
    //    boolean preparedWrite,
    //    boolean responseNeeded,
    //    int offset,
    //    byte[] value
    //) {
    NReturn visit(NDelta01* element, NParam a, NParam b, NParam c, NParam d, NParam e)
    {
        NReturn vcRet = 0;
        if (b == -1 && c == 2) vcRet = (NReturn)mNWrapper->mNKrossWrapper->mNKrossFriend->pointer<BluetoothDevice>();
        if (b == -1 && c == 1) vcRet = (NReturn)mNWrapper->mNKrossWrapper->mNKrossFriend->pointer<BluetoothGattCharacteristic>();
        if (b != -1) {
            NReturn size = mNWrapper->mNKrossWrapper->mNKrossSystem->tRun(mNWrapper->mNKrossWrapper->mNAlpha01, (NParam)this, (NParam)d, -1, -1);
            NArray<nubyte> vaNArray = NArray<nubyte>(size);
            int i;

            for (i = 0 ; i < size ; ++i) {
                vaNArray.maData[i] = mNWrapper->mNKrossWrapper->mNKrossSystem->tRun(mNWrapper->mNKrossWrapper->mNAlpha01, (NParam)this, (NParam)d, (NParam)i, (NParam)-1);
            }
            ((BluetoothGattServerCallback*)a)->onCharacteristicWriteRequest((BluetoothDevice*)b, e >> 32, (BluetoothGattCharacteristic*)c, (e&0x0000000000000002), (e&0x0000000000000001), (e&0x00000000FFFFFFFB), vaNArray);
        }
        return vcRet;
    }

    //void onConnectionStateChange(BluetoothDevice device, int status, int newState)
    NReturn visit(NEpsilon01* element, NParam a, NParam b, NParam c, NParam d, NParam e)
    {
        NReturn vcRet = 0;
        if (b == -1 && c == 1) vcRet = (NReturn)mNWrapper->mNKrossWrapper->mNKrossFriend->pointer<BluetoothDevice>();
        if (b != -1) ((BluetoothGattServerCallback*)a)->onConnectionStateChange((BluetoothDevice*)b, c, d);
        return vcRet;
    }

    //void onNotificationSent(BluetoothDevice device, int status)
    NReturn visit(NDzeta01* element, NParam a, NParam b, NParam c, NParam d, NParam e)
    {
        NReturn vcRet = 0;
        if (b == -1 && c == 1) vcRet = (NReturn)mNWrapper->mNKrossWrapper->mNKrossFriend->pointer<BluetoothDevice>();
        if (b != -1) ((BluetoothGattServerCallback*)a)->onNotificationSent((BluetoothDevice*)b, c);
        return vcRet;
    }

    //void onServiceAdded(int status, BluetoothGattService service)
    NReturn visit(NEta01* element, NParam a, NParam b, NParam c, NParam d, NParam e)
    {
        NReturn vcRet = 0;
        if (b == -1 && c == 1) vcRet = (NReturn)mNWrapper->mNKrossWrapper->mNKrossFriend->pointer<BluetoothGattService>();
        if (b != -1) ((BluetoothGattServerCallback*)a)->onServiceAdded(b, (BluetoothGattService*)c);
        return vcRet;
    }
};

} // END namespace

#endif
