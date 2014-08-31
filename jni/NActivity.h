#ifndef __MYAPPLICATION_H__
#define __MYAPPLICATION_H__

namespace NSDEVICE
{

class NActivity : public Activity
{
public:
	void onDrop();

	Wrapper* w;
	bool mAlive;

protected:
	void onCreate();
	void onPause();
	void onActivityResult(int action, int requestCode, int resultCode, int extra);
    void onReceiveDiscoveryFinished();
    void onReceiveDiscoveryStarted();
    void onReceiveFoundDevice(BluetoothDevice* dBluetoothDevice);
    void onReceiveLocalName(String localName);
    void onReceiveState(int state, int statePrevious);
    void onReceiveScanMode(int mode, int modePrevious);
	void handleMessage(NParam a, NParam b, NParam c);
};

} // End namespace

#endif
