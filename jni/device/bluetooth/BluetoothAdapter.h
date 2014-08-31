#ifndef __BluetoothAdapter_H__
#define __BluetoothAdapter_H__

namespace NSDEVICE
{

class BluetoothAdapter
{
friend class NSNATIVE::NVisitorBluetooth;

public:
	const int ERROR = -1 >> 1;
    const int STATE_OFF = 10;
    const int STATE_TURNING_ON = 11;
    const int STATE_ON = 12;
    const int STATE_TURNING_OFF = 13;
    const int SCAN_MODE_NONE = 20;
    const int SCAN_MODE_CONNECTABLE = 21;
    const int SCAN_MODE_CONNECTABLE_DISCOVERABLE = 23;

	//const int BluetoothAdapter::ERROR = -1 >> 1;
	//const int BluetoothAdapter::STATE_OFF = 10;
	//const int BluetoothAdapter::STATE_TURNING_ON = 11;
	//const int BluetoothAdapter::STATE_ON = 12;
	//const int BluetoothAdapter::STATE_TURNING_OFF = 13;
	//const int BluetoothAdapter::SCAN_MODE_NONE = 20;
	//const int BluetoothAdapter::SCAN_MODE_CONNECTABLE = 21;
	//const int BluetoothAdapter::SCAN_MODE_CONNECTABLE_DISCOVERABLE = 23;

    BluetoothAdapter();
   ~BluetoothAdapter();

    BluetoothDevice* getRemoteDevice(const String& address);
    bool isEnabled();
    int getState();
    bool enable();
    bool disable();
    String getAddress();
    String getName();
    bool setName(const String& name);
    int getScanMode();
    bool startDiscovery();
    bool cancelDiscovery();
    bool isDiscovering();
    void* getBondedDevices(); //List...<BluetoothDevice>
    BluetoothServerSocket* listenUsingRfcommWithServiceRecord(const String& name, const String& uuid);
    BluetoothServerSocket* listenUsingInsecureRfcommWithServiceRecord(const String& name, const String& uuid);
    bool checkBluetoothAddress(const String& address);
    void discoverable();
    void discoverable(int cTimeout);
};

} // End namespace

#endif
