#ifndef __BluetoothServerSocket_H__
#define __BluetoothServerSocket_H__

namespace NSDEVICE
{

class BluetoothServerSocket
{
friend class NSNATIVE::NVisitorBluetooth;

public:
	BluetoothSocket* accept();
	BluetoothSocket* accept(int timeout);
    void close();
};

} // End namespace

#endif
