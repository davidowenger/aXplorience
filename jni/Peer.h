#ifndef __Peer_H__
#define __Peer_H__

namespace NSDEVICE
{

class Peer
{
public:
    Peer(Wrapper* const w, BluetoothDevice* vBluetoothDevice, const String& vsMac, bool vIsClient);
    ~Peer();

    nuint write(const String& vPacked);

    Wrapper* w;
    BluetoothDevice* mBluetoothDevice;
    BluetoothGatt* mBluetoothGatt;
    BluetoothGattCharacteristic* mBluetoothGattCharacteristic;
    NetworkClientCallback* mNetworkClientCallback;
    String mMac;
    bool mAsClient;
};

} // End namespace

#endif
