#include "native/NCommon.h"

namespace NSDEVICE
{

const int BluetoothDevice::ERROR = -1 >> 1;
const int BluetoothDevice::BOND_NONE = 10;
const int BluetoothDevice::BOND_BONDING = 11;
const int BluetoothDevice::BOND_BONDED = 12;

const String BluetoothDevice::ACTION_FOUND = "android.bluetooth.device.action.FOUND";
const String BluetoothDevice::ACTION_DISAPPEARED = "android.bluetooth.device.action.DISAPPEARED";
const String BluetoothDevice::ACTION_CLASS_CHANGED = "android.bluetooth.device.action.CLASS_CHANGED";
const String BluetoothDevice::ACTION_ACL_CONNECTED = "android.bluetooth.device.action.ACL_CONNECTED";
const String BluetoothDevice::ACTION_ACL_DISCONNECT_REQUESTED = "android.bluetooth.device.action.ACL_DISCONNECT_REQUESTED";
const String BluetoothDevice::ACTION_ACL_DISCONNECTED = "android.bluetooth.device.action.ACL_DISCONNECTED";
const String BluetoothDevice::ACTION_NAME_CHANGED = "android.bluetooth.device.action.NAME_CHANGED";
const String BluetoothDevice::ACTION_BOND_STATE_CHANGED = "android.bluetooth.device.action.BOND_STATE_CHANGED";

const String BluetoothDevice::EXTRA_DEVICE = "android.bluetooth.device.extra.DEVICE";
const String BluetoothDevice::EXTRA_NAME = "android.bluetooth.device.extra.NAME";
const String BluetoothDevice::EXTRA_RSSI = "android.bluetooth.device.extra.RSSI";
const String BluetoothDevice::EXTRA_CLASS = "android.bluetooth.device.extra.CLASS";
const String BluetoothDevice::EXTRA_BOND_STATE = "android.bluetooth.device.extra.BOND_STATE";
const String BluetoothDevice::EXTRA_PREVIOUS_BOND_STATE = "android.bluetooth.device.extra.PREVIOUS_BOND_STATE";

bool BluetoothDevice::equals(BluetoothDevice* dBluetoothDevice)
{
	return NSDEVICE::Activity::kActivity->w->nVisitorBluetooth->tRun(NSDEVICE::Activity::kActivity->w->alpha01, (NParam)this, (NParam)dBluetoothDevice);
}

int BluetoothDevice::hashCode()
{
	return NSDEVICE::Activity::kActivity->w->nVisitorBluetooth->tRun(NSDEVICE::Activity::kActivity->w->beta01, (NParam)this);
}

String BluetoothDevice::toString()
{
	NReturn index = NSDEVICE::Activity::kActivity->w->nVisitorBluetooth->tRun(NSDEVICE::Activity::kActivity->w->gamma01, (NParam)this);
	return NSDEVICE::Activity::kActivity->w->nFrame->tGetString(NSDEVICE::Activity::kActivity->w->nFrame->tRunObject((NParam)index));
}

int BluetoothDevice::describeContents()
{
	return NSDEVICE::Activity::kActivity->w->nVisitorBluetooth->tRun(NSDEVICE::Activity::kActivity->w->delta01, (NParam)this);
}

void BluetoothDevice::writeToParcel(void* out, int flags)
{
	//TODO: implement
	//NSDEVICE::Activity::kActivity->w->nVisitorBluetooth->tRun(NSDEVICE::Activity::kActivity->w->epsilon01, (NParam)this, (NParam)out, (NParam)flags);
}

String BluetoothDevice::getAddress()
{
	NReturn index = NSDEVICE::Activity::kActivity->w->nVisitorBluetooth->tRun(NSDEVICE::Activity::kActivity->w->dzeta01, (NParam)this);
	return NSDEVICE::Activity::kActivity->w->nFrame->tGetString(NSDEVICE::Activity::kActivity->w->nFrame->tRunObject((NParam)index));
}

String BluetoothDevice::getName()
{
	NReturn index = NSDEVICE::Activity::kActivity->w->nVisitorBluetooth->tRun(NSDEVICE::Activity::kActivity->w->eta01, (NParam)this);
	return NSDEVICE::Activity::kActivity->w->nFrame->tGetString(NSDEVICE::Activity::kActivity->w->nFrame->tRunObject((NParam)index));
}

int BluetoothDevice::getBondState()
{
	return NSDEVICE::Activity::kActivity->w->nVisitorBluetooth->tRun(NSDEVICE::Activity::kActivity->w->theta01, (NParam)this);
}

BluetoothClass* BluetoothDevice::getBluetoothClass()
{
	BluetoothClass* dBluetoothClass = new BluetoothClass();
	NSDEVICE::Activity::kActivity->w->nVisitorBluetooth->tRun(NSDEVICE::Activity::kActivity->w->iota01, (NParam)this, (NParam)dBluetoothClass);
	return dBluetoothClass;
}

BluetoothSocket* BluetoothDevice::createRfcommSocketToServiceRecord(const String& uuid)
{
	BluetoothSocket* dBluetoothSocket = new BluetoothSocket();
	bool error = NSDEVICE::Activity::kActivity->w->nVisitorBluetooth->tRun(NSDEVICE::Activity::kActivity->w->kappa01, (NParam)this, (NParam)dBluetoothSocket, NParamBox(NSDEVICE::Activity::kActivity->w, uuid).n);

	if (error) {
		delete dBluetoothSocket;
		dBluetoothSocket = nullptr;
	}
	return dBluetoothSocket;
}

BluetoothSocket* BluetoothDevice::createInsecureRfcommSocketToServiceRecord(const String& uuid)
{
	BluetoothSocket* dBluetoothSocket = new BluetoothSocket();
	bool error = NSDEVICE::Activity::kActivity->w->nVisitorBluetooth->tRun(NSDEVICE::Activity::kActivity->w->lambda01, (NParam)this, (NParam)dBluetoothSocket, NParamBox(NSDEVICE::Activity::kActivity->w, uuid).n);

	if (error) {
		delete dBluetoothSocket;
		dBluetoothSocket = nullptr;
	}
	return dBluetoothSocket;
}

} // End namespace
