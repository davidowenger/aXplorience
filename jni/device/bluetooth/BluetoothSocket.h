#ifndef __BluetoothSocket_H__
#define __BluetoothSocket_H__

namespace NSDEVICE
{

class BluetoothSocket
{
friend NSNATIVE::NNoObject;

public:
    int connect();
    int close();
    BluetoothDevice* getRemoteDevice();
    InputStream* getInputStream();
    OutputStream* getOutputStream();

private:
    BluetoothSocket(NNoObject* vNNoObject)
    {
    }
};

} // END namespace

#endif
