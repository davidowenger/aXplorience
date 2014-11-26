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

	NSDEVICE::Activity::kActivity->w->nVisitorBluetooth->tRun(NSDEVICE::Activity::kActivity->w->alpha00, (NParam)this);
}

BluetoothAdapter::~BluetoothAdapter()
{
}

BluetoothDevice* BluetoothAdapter::getRemoteDevice(const String& address)
{
	BluetoothDevice* dBluetoothDevice = new BluetoothDevice();
	NSDEVICE::Activity::kActivity->w->nVisitorBluetooth->tRun(NSDEVICE::Activity::kActivity->w->beta00, (NParam)this, (NParam)dBluetoothDevice, NParamBox(NSDEVICE::Activity::kActivity->w, address).n);
	return dBluetoothDevice;
}

bool BluetoothAdapter::isEnabled()
{
	return NSDEVICE::Activity::kActivity->w->nVisitorBluetooth->tRun(NSDEVICE::Activity::kActivity->w->gamma00, (NParam)this);
}

int BluetoothAdapter::getState()
{
	return NSDEVICE::Activity::kActivity->w->nVisitorBluetooth->tRun(NSDEVICE::Activity::kActivity->w->delta00, (NParam)this);
}

bool BluetoothAdapter::enable()
{
	return NSDEVICE::Activity::kActivity->w->nVisitorBluetooth->tRun(NSDEVICE::Activity::kActivity->w->epsilon00, (NParam)this);
}

bool BluetoothAdapter::disable()
{
	return NSDEVICE::Activity::kActivity->w->nVisitorBluetooth->tRun(NSDEVICE::Activity::kActivity->w->dzeta00, (NParam)this);
}

String BluetoothAdapter::getAddress()
{
	NReturn index = NSDEVICE::Activity::kActivity->w->nVisitorBluetooth->tRun(NSDEVICE::Activity::kActivity->w->eta00, (NParam)this);
	return NSDEVICE::Activity::kActivity->w->nFrame->tGetString(NSDEVICE::Activity::kActivity->w->nFrame->tRunObject((NParam)index));
}

String BluetoothAdapter::getName()
{
	NReturn index = NSDEVICE::Activity::kActivity->w->nVisitorBluetooth->tRun(NSDEVICE::Activity::kActivity->w->theta00, (NParam)this);
	return NSDEVICE::Activity::kActivity->w->nFrame->tGetString(NSDEVICE::Activity::kActivity->w->nFrame->tRunObject((NParam)index));
}

bool BluetoothAdapter::setName(const String& name)
{
	return NSDEVICE::Activity::kActivity->w->nVisitorBluetooth->tRun(NSDEVICE::Activity::kActivity->w->iota00, (NParam)this, NParamBox(NSDEVICE::Activity::kActivity->w, name).n);
}

int BluetoothAdapter::getScanMode()
{
	return NSDEVICE::Activity::kActivity->w->nVisitorBluetooth->tRun(NSDEVICE::Activity::kActivity->w->kappa00, (NParam)this);
}

bool BluetoothAdapter::startDiscovery()
{
	return NSDEVICE::Activity::kActivity->w->nVisitorBluetooth->tRun(NSDEVICE::Activity::kActivity->w->lambda00, (NParam)this);
}

bool BluetoothAdapter::cancelDiscovery()
{
	return NSDEVICE::Activity::kActivity->w->nVisitorBluetooth->tRun(NSDEVICE::Activity::kActivity->w->mu00, (NParam)this);
}

bool BluetoothAdapter::isDiscovering()
{
	return NSDEVICE::Activity::kActivity->w->nVisitorBluetooth->tRun(NSDEVICE::Activity::kActivity->w->nu00, (NParam)this);
}

void* BluetoothAdapter::getBondedDevices()
{
	//TODO: implement
	//Set<BluetoothDevice>
	//return NSDEVICE::Activity::kActivity->w->nVisitorBluetooth->tRun(NSDEVICE::Activity::kActivity->w->xi00, (NParam)this);
	return NULL;
}

BluetoothServerSocket* BluetoothAdapter::listenUsingRfcommWithServiceRecord(const String& name, const String& uuid)
{
	BluetoothServerSocket* dBluetoothServerSocket = new BluetoothServerSocket();
	bool error = NSDEVICE::Activity::kActivity->w->nVisitorBluetooth->tRun(NSDEVICE::Activity::kActivity->w->omicron00, (NParam)this, (NParam)dBluetoothServerSocket, NParamBox(NSDEVICE::Activity::kActivity->w, name).n, NParamBox(NSDEVICE::Activity::kActivity->w, uuid).n);

	if (error) {
		delete dBluetoothServerSocket;
		dBluetoothServerSocket = nullptr;
	}
	return dBluetoothServerSocket;
}

BluetoothServerSocket* BluetoothAdapter::listenUsingInsecureRfcommWithServiceRecord(const String& name, const String& uuid)
{
	BluetoothServerSocket* dBluetoothServerSocket = new BluetoothServerSocket();
	bool error = NSDEVICE::Activity::kActivity->w->nVisitorBluetooth->tRun(NSDEVICE::Activity::kActivity->w->pi00, (NParam)this, (NParam)dBluetoothServerSocket, NParamBox(NSDEVICE::Activity::kActivity->w, name).n, NParamBox(NSDEVICE::Activity::kActivity->w, uuid).n);

	if (error) {
		delete dBluetoothServerSocket;
		dBluetoothServerSocket = nullptr;
	}
	return dBluetoothServerSocket;
}

bool BluetoothAdapter::checkBluetoothAddress(const String& address)
{
	return NSDEVICE::Activity::kActivity->w->nVisitorBluetooth->tRun(NSDEVICE::Activity::kActivity->w->rho00, NParamBox(NSDEVICE::Activity::kActivity->w, address).n);
}

void BluetoothAdapter::discoverable()
{
	discoverable(0);
}

void BluetoothAdapter::discoverable(int cTimeout)
{
	NSDEVICE::Activity::kActivity->w->nVisitorBluetooth->tRun(NSDEVICE::Activity::kActivity->w->sigma00, cTimeout);
}

} // End namespace
