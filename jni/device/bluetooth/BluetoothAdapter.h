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

    class LeScanCallback
    {
    public:
        virtual ~LeScanCallback();
        virtual void onLeScan(BluetoothDevice* device, int rssi, NArray<nubyte> scanRecord) = 0;
    protected:
        LeScanCallback();
    };

    static bool checkBluetoothAddress(const String& address);
    static BluetoothAdapter* getDefaultAdapter();

    virtual ~BluetoothAdapter() override;

    BluetoothLeAdvertiser* getBluetoothLeAdvertiser();
    BluetoothLeScanner* getBluetoothLeScanner();
    BluetoothDevice* getRemoteDevice(const String& address);
    bool isEnabled();
    bool isMultipleAdvertisementSupported();
    int getState();
    bool enable();
    bool disable();
    String getAddress();
    String getName();
    bool setName(const String& name);
    int getScanMode();
    bool startDiscovery();
    bool startLeScan(BluetoothAdapter::LeScanCallback* callback);
    bool startLeScan(NArray<String> serviceUuids, BluetoothAdapter::LeScanCallback* callback);
    void stopLeScan(BluetoothAdapter::LeScanCallback* callback);
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
