#include "native/NCommon.h"

namespace NSDEVICE
{

BluetoothAdapter::BluetoothAdapter()
{
	//const int BluetoothAdapter::ERROR = -1 >> 1;
	//const int BluetoothAdapter::STATE_OFF = 10;
	//const int BluetoothAdapter::STATE_TURNING_ON = 11;
	//const int BluetoothAdapter::STATE_ON = 12;
	//const int BluetoothAdapter::STATE_TURNING_OFF = 13;
	//const int BluetoothAdapter::SCAN_MODE_NONE = 20;
	//const int BluetoothAdapter::SCAN_MODE_CONNECTABLE = 21;
	//const int BluetoothAdapter::SCAN_MODE_CONNECTABLE_DISCOVERABLE = 23;

	NWrapper::w->mNVisitorBluetooth->tRun(NWrapper::w->mNAlpha00, (NParam)this);
}

BluetoothAdapter::~BluetoothAdapter()
{
}

BluetoothDevice* BluetoothAdapter::getRemoteDevice(const String& address)
{
	BluetoothDevice* dBluetoothDevice = new BluetoothDevice();
	NWrapper::w->mNVisitorBluetooth->tRun(NWrapper::w->mNBeta00, (NParam)this, (NParam)dBluetoothDevice, NParamBox(NWrapper::w, address).n);
	return dBluetoothDevice;
}

bool BluetoothAdapter::isEnabled()
{
	return NWrapper::w->mNVisitorBluetooth->tRun(NWrapper::w->mNGamma00, (NParam)this);
}

int BluetoothAdapter::getState()
{
	return NWrapper::w->mNVisitorBluetooth->tRun(NWrapper::w->mNDelta00, (NParam)this);
}

bool BluetoothAdapter::enable()
{
	return NWrapper::w->mNVisitorBluetooth->tRun(NWrapper::w->mNEpsilon00, (NParam)this);
}

bool BluetoothAdapter::disable()
{
	return NWrapper::w->mNVisitorBluetooth->tRun(NWrapper::w->mNDzeta00, (NParam)this);
}

String BluetoothAdapter::getAddress()
{
	NReturn index = NWrapper::w->mNVisitorBluetooth->tRun(NWrapper::w->mNEta00, (NParam)this);
	return NWrapper::w->nFrame->tGetString(NWrapper::w->nFrame->tRunObject((NParam)index));
}

String BluetoothAdapter::getName()
{
	NReturn index = NWrapper::w->mNVisitorBluetooth->tRun(NWrapper::w->mNTheta00, (NParam)this);
	return NWrapper::w->nFrame->tGetString(NWrapper::w->nFrame->tRunObject((NParam)index));
}

bool BluetoothAdapter::setName(const String& name)
{
	return NWrapper::w->mNVisitorBluetooth->tRun(NWrapper::w->mNIota00, (NParam)this, NParamBox(NWrapper::w, name).n);
}

int BluetoothAdapter::getScanMode()
{
	return NWrapper::w->mNVisitorBluetooth->tRun(NWrapper::w->mNKappa00, (NParam)this);
}

bool BluetoothAdapter::startDiscovery()
{
	return NWrapper::w->mNVisitorBluetooth->tRun(NWrapper::w->mNLambda00, (NParam)this);
}

bool BluetoothAdapter::cancelDiscovery()
{
	return NWrapper::w->mNVisitorBluetooth->tRun(NWrapper::w->mNMu00, (NParam)this);
}

bool BluetoothAdapter::isDiscovering()
{
	return NWrapper::w->mNVisitorBluetooth->tRun(NWrapper::w->mNNu00, (NParam)this);
}

void* BluetoothAdapter::getBondedDevices()
{
	//TODO: implement
	//Set<BluetoothDevice>
	//return NWrapper::w->mNVisitorBluetooth->tRun(NWrapper::w->mNxi00, (NParam)this);
	return NULL;
}

BluetoothServerSocket* BluetoothAdapter::listenUsingRfcommWithServiceRecord(const String& name, const String& uuid)
{
	BluetoothServerSocket* dBluetoothServerSocket = new BluetoothServerSocket();
	bool error = NWrapper::w->mNVisitorBluetooth->tRun(NWrapper::w->mNOmicron00, (NParam)this, (NParam)dBluetoothServerSocket, NParamBox(NWrapper::w, name).n, NParamBox(NWrapper::w, uuid).n);

	if (error) {
		delete dBluetoothServerSocket;
		dBluetoothServerSocket = nullptr;
	}
	return dBluetoothServerSocket;
}

BluetoothServerSocket* BluetoothAdapter::listenUsingInsecureRfcommWithServiceRecord(const String& name, const String& uuid)
{
	BluetoothServerSocket* dBluetoothServerSocket = new BluetoothServerSocket();
	bool error = NWrapper::w->mNVisitorBluetooth->tRun(NWrapper::w->mNPi00, (NParam)this, (NParam)dBluetoothServerSocket, NParamBox(NWrapper::w, name).n, NParamBox(NWrapper::w, uuid).n);

	if (error) {
		delete dBluetoothServerSocket;
		dBluetoothServerSocket = nullptr;
	}
	return dBluetoothServerSocket;
}

bool BluetoothAdapter::checkBluetoothAddress(const String& address)
{
	return NWrapper::w->mNVisitorBluetooth->tRun(NWrapper::w->mNRho00, NParamBox(NWrapper::w, address).n);
}

void BluetoothAdapter::discoverable()
{
	discoverable(0);
}

void BluetoothAdapter::discoverable(int cTimeout)
{
	NWrapper::w->mNVisitorBluetooth->tRun(NWrapper::w->mNSigma00, cTimeout);
}

} // End namespace
