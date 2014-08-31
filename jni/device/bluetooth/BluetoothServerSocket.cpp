#include "native/NCommon.h"

namespace NSDEVICE
{

BluetoothSocket* BluetoothServerSocket::accept()
{
	BluetoothSocket* dBluetoothSocket = new BluetoothSocket();
	bool error = NWrapper::w->nVisitorBluetooth->tRun(NWrapper::w->alpha02, (NParam)this, (NParam)dBluetoothSocket);

	if (error) {
		delete dBluetoothSocket;
		dBluetoothSocket = nullptr;
	}
	return dBluetoothSocket;
}

BluetoothSocket* BluetoothServerSocket::accept(int timeout)
{
	BluetoothSocket* dBluetoothSocket = new BluetoothSocket();
	bool error = NWrapper::w->nVisitorBluetooth->tRun(NWrapper::w->beta02, (NParam)this, (NParam)dBluetoothSocket, (NParam)timeout);

	if (error) {
		delete dBluetoothSocket;
		dBluetoothSocket = NULL;
	}
	return dBluetoothSocket;
}

void BluetoothServerSocket::close()
{
	NWrapper::w->nVisitorBluetooth->tRun(NWrapper::w->gamma02, (NParam)this);
}

} // End namespace
