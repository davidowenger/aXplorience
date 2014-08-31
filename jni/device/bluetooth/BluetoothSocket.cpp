#include "native/NCommon.h"

namespace NSDEVICE
{

int BluetoothSocket::connect()
{
	return NWrapper::w->nVisitorBluetooth->tRun(NWrapper::w->alpha03, (NParam)this);
}

int BluetoothSocket::close()
{
	return NWrapper::w->nVisitorBluetooth->tRun(NWrapper::w->beta03, (NParam)this);
}

BluetoothDevice* BluetoothSocket::getRemoteDevice()
{
	BluetoothDevice* dBluetoothDevice = new BluetoothDevice();
	NWrapper::w->nVisitorBluetooth->tRun(NWrapper::w->gamma03, (NParam)this, (NParam)dBluetoothDevice);
	return dBluetoothDevice;
}

InputStream* BluetoothSocket::getInputStream()
{
	InputStream* dInputStream = new InputStream();
	bool error = NWrapper::w->nVisitorBluetooth->tRun(NWrapper::w->delta03, (NParam)this, (NParam)dInputStream);

	if (error) {
		delete dInputStream;
		dInputStream = nullptr;
	}
	return dInputStream;
}

OutputStream* BluetoothSocket::getOutputStream()
{
	OutputStream* dOutputStream = new OutputStream();
	bool error = NWrapper::w->nVisitorBluetooth->tRun(NWrapper::w->epsilon03, (NParam)this, (NParam)dOutputStream);

	if (error) {
		delete dOutputStream;
		dOutputStream = nullptr;
	}
	return dOutputStream;
}

} // END namespace
