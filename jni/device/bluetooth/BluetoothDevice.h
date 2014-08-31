#ifndef __BluetoothDevice_H__
#define __BluetoothDevice_H__

namespace NSDEVICE
{

class BluetoothClass
{

};

class BluetoothDevice
{
friend class NSNATIVE::NVisitorBluetooth;

public:
    static const int ERROR;
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
    static const int BOND_NONE;
    static const int BOND_BONDING;
    static const int BOND_BONDED;

    bool equals(BluetoothDevice* dBluetoothDevice);
    int hashCode();
    String toString();
    int describeContents();
    void writeToParcel(void* out, int flags);
    String getAddress();
    String getName();
    int getBondState();
    BluetoothClass* getBluetoothClass();
    BluetoothSocket* createRfcommSocketToServiceRecord(const String& uuid);
    BluetoothSocket* createInsecureRfcommSocketToServiceRecord(const String& uuid);
};

} // End namespace

#endif
