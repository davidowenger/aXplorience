#ifndef __BluetoothSocket_H__
#define __BluetoothSocket_H__

namespace NSDEVICE
{

class BluetoothSocket
{
friend NSNATIVE::NKrossFriend;

public:
    int connect();
    int close();
    BluetoothDevice* getRemoteDevice();
    InputStream* getInputStream();
    OutputStream* getOutputStream();
    int getPort();


private:
    BluetoothSocket(NKrossFriend* vNKrossFriend)
    {
    }
};

} // END namespace

#endif
