#include "native/NCommon.h"

namespace NSDEVICE
{

int BluetoothSocket::connect()
{
	return NSDEVICE::Activity::kActivity->w->nVisitorBluetooth->tRun(NSDEVICE::Activity::kActivity->w->alpha03, (NParam)this);
}

int BluetoothSocket::close()
{
	return NSDEVICE::Activity::kActivity->w->nVisitorBluetooth->tRun(NSDEVICE::Activity::kActivity->w->beta03, (NParam)this);
}

BluetoothDevice* BluetoothSocket::getRemoteDevice()
{
	BluetoothDevice* dBluetoothDevice = new BluetoothDevice();
	NSDEVICE::Activity::kActivity->w->nVisitorBluetooth->tRun(NSDEVICE::Activity::kActivity->w->gamma03, (NParam)this, (NParam)dBluetoothDevice);
	return dBluetoothDevice;
}

InputStream* BluetoothSocket::getInputStream()
{
	InputStream* dInputStream = new InputStream();
	bool error = NSDEVICE::Activity::kActivity->w->nVisitorBluetooth->tRun(NSDEVICE::Activity::kActivity->w->delta03, (NParam)this, (NParam)dInputStream);

	if (error) {
		delete dInputStream;
		dInputStream = nullptr;
	}
	return dInputStream;
}

OutputStream* BluetoothSocket::getOutputStream()
{
	OutputStream* dOutputStream = new OutputStream();
	bool error = NSDEVICE::Activity::kActivity->w->nVisitorBluetooth->tRun(NSDEVICE::Activity::kActivity->w->epsilon03, (NParam)this, (NParam)dOutputStream);

	if (error) {
		delete dOutputStream;
		dOutputStream = nullptr;
	}
	return dOutputStream;
}

} // END namespace
