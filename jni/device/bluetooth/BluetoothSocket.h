#ifndef __BluetoothSocket_H__
#define __BluetoothSocket_H__

namespace NSDEVICE
{

class BluetoothSocket
{
friend class NSNATIVE::NVisitorBluetooth;

public:
    int connect();
    int close();
    BluetoothDevice* getRemoteDevice();
    InputStream* getInputStream();
    OutputStream* getOutputStream();
};

} // END namespace

#endif
