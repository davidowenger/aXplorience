#ifndef __BluetoothDevice_H__
#define __BluetoothDevice_H__

namespace NSDEVICE
{

class BluetoothClass : public Object
{
friend NSNATIVE::NKrossFriend;

private:
    BluetoothClass(NKrossFriend* vNKrossFriend)
    {
    }
};

class BluetoothDevice : public Object
{
friend NSNATIVE::NKrossFriend;

public:
    static const String ACTION_FOUND;
    static const String ACTION_DISAPPEARED;
    static const String ACTION_CLASS_CHANGED;
    static const String ACTION_ACL_CONNECTED;
    static const String ACTION_ACL_DISCONNECT_REQUESTED;
    static const String ACTION_ACL_DISCONNECTED;
    static const String ACTION_NAME_CHANGED;
    static const String ACTION_BOND_STATE_CHANGED;
    static const String EXTRA_DEVICE;
    static const String EXTRA_NAME;
    static const String EXTRA_RSSI;
    static const String EXTRA_CLASS;
    static const String EXTRA_BOND_STATE;
    static const String EXTRA_PREVIOUS_BOND_STATE;

    static const int BOND_BONDED = 0x0000000c;
    static const int BOND_BONDING = 0x0000000b;
    static const int BOND_NONE = 0x0000000a;
    static const int ERROR = 0x80000000;
    static const int TRANSPORT_AUTO = 0x00000000;
    static const int TRANSPORT_BREDR = 0x00000001;
    static const int TRANSPORT_LE = 0x00000002;

    BluetoothGatt* connectGatt(Context* context, bool autoConnect, BluetoothGattCallback* callback);
    BluetoothGatt* connectGatt(Context* context, bool autoConnect, BluetoothGattCallback* callback, int transport);
    bool equals(BluetoothDevice* dBluetoothDevice);
    int hashCode();
    String toString();
    int describeContents();
    void writeToParcel(void* out, int flags);
    String getAddress();
    String getName();
    int getBondState();
    BluetoothClass* getBluetoothClass();
    int getType();
    BluetoothSocket* createInsecureRfcommSocket(int port);
    BluetoothSocket* createInsecureRfcommSocketToServiceRecord(const String& uuid);
    BluetoothSocket* createRfcommSocketToServiceRecord(const String& uuid);
    vector<ParcelUuid*> getUuids();

private:
    BluetoothDevice(NKrossFriend* vNKrossFriend)
    {
    }
};

} // End namespace

#endif
