#include "native/NCommon.h"

namespace NSDEVICE
{

BluetoothSocket* BluetoothServerSocket::accept()
{
	// Blocks until a connection is established
	BluetoothSocket* dBluetoothSocket = new BluetoothSocket();
	bool error = NWrapper::getInstance()->mNVisitorBluetooth->tRun(NWrapper::getInstance()->mNAlpha02, (NParam)this, (NParam)dBluetoothSocket);

	if (error) {
		delete dBluetoothSocket;
		dBluetoothSocket = nullptr;
	}
	return dBluetoothSocket;
}

BluetoothSocket* BluetoothServerSocket::accept(int timeout)
{
	// Blocks until a connection is established, up to timeout
	BluetoothSocket* dBluetoothSocket = new BluetoothSocket();
	bool error = NWrapper::getInstance()->mNVisitorBluetooth->tRun(NWrapper::getInstance()->mNBeta02, (NParam)this, (NParam)dBluetoothSocket, (NParam)timeout);

	if (error) {
		delete dBluetoothSocket;
		dBluetoothSocket = nullptr;
	}
	return dBluetoothSocket;
}

void BluetoothServerSocket::close()
{
	NWrapper::getInstance()->mNVisitorBluetooth->tRun(NWrapper::getInstance()->mNGamma02, (NParam)this);
}

} // End namespace
