#include "native/NCommon.h"

namespace NSDEVICE
{

int BluetoothSocket::connect()
{
	return NWrapper::getInstance()->mNVisitorBluetooth->tRun(NWrapper::getInstance()->mNAlpha03, (NParam)this);
}

int BluetoothSocket::close()
{
	return NWrapper::getInstance()->mNVisitorBluetooth->tRun(NWrapper::getInstance()->mNBeta03, (NParam)this);
}

BluetoothDevice* BluetoothSocket::getRemoteDevice()
{
	BluetoothDevice* dBluetoothDevice = new BluetoothDevice();
	NWrapper::getInstance()->mNVisitorBluetooth->tRun(NWrapper::getInstance()->mNGamma03, (NParam)this, (NParam)dBluetoothDevice);
	return dBluetoothDevice;
}

InputStream* BluetoothSocket::getInputStream()
{
    InputStream* vInputStream = NWrapper::w->mNNoObject->pointer<InputStream>();
	bool error = NWrapper::getInstance()->mNVisitorBluetooth->tRun(NWrapper::getInstance()->mNDelta03, (NParam)this, (NParam)vInputStream);

	if (error) {
		delete vInputStream;
		vInputStream = nullptr;
	}
	return vInputStream;
}

OutputStream* BluetoothSocket::getOutputStream()
{
    OutputStream* vOutputStream = NWrapper::w->mNNoObject->pointer<OutputStream>();
	bool error = NWrapper::getInstance()->mNVisitorBluetooth->tRun(NWrapper::getInstance()->mNEpsilon03, (NParam)this, (NParam)vOutputStream);

	if (error) {
		delete vOutputStream;
		vOutputStream = nullptr;
	}
	return vOutputStream;
}

} // END namespace
