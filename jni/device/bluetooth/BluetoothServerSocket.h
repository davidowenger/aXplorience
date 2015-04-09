#ifndef __BluetoothServerSocket_H__
#define __BluetoothServerSocket_H__

namespace NSDEVICE
{

class BluetoothServerSocket
{
friend NSNATIVE::NNoObject;

public:
	BluetoothSocket* accept();
	BluetoothSocket* accept(int timeout);
    void close();

private:
    BluetoothServerSocket(NNoObject* vNNoObject)
    {
    }
};

} // End namespace

#endif
