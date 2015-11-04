#ifndef __BluetoothServerSocket_H__
#define __BluetoothServerSocket_H__

namespace NSDEVICE
{

class BluetoothServerSocket
{
friend NSNATIVE::NKrossFriend;

public:
    BluetoothSocket* accept();
    BluetoothSocket* accept(int timeout);
    int getChannel();
    void close();

private:
    BluetoothServerSocket(NKrossFriend* vNKrossFriend)
    {
    }
};

} // End namespace

#endif
