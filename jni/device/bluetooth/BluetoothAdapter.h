#ifndef __BluetoothAdapter_H__
#define __BluetoothAdapter_H__

namespace NSDEVICE
{

class BluetoothAdapter : public Object
{
friend NSNATIVE::NNoObject;

public:
	const int ERROR = -1 >> 1;
    const int STATE_OFF = 10;
    const int STATE_TURNING_ON = 11;
    const int STATE_ON = 12;
    const int STATE_TURNING_OFF = 13;
    const int SCAN_MODE_NONE = 20;
    const int SCAN_MODE_CONNECTABLE = 21;
    const int SCAN_MODE_CONNECTABLE_DISCOVERABLE = 23;

    static BluetoothAdapter* getDefaultAdapter();
    static bool checkBluetoothAddress(const String& address);

    virtual ~BluetoothAdapter() override;

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
    BluetoothServerSocket* listenUsingInsecureRfcommOn(int channel);
    BluetoothServerSocket* listenUsingInsecureRfcommWithServiceRecord(const String& name, const String& uuid);
    BluetoothServerSocket* listenUsingRfcommWithServiceRecord(const String& name, const String& uuid);

    //TODO: restore Android API
    void discoverable();
    void discoverable(int cTimeout);

private:
    BluetoothAdapter(NNoObject* vNNoObject)
    {
    }
};

} // End namespace

#endif
