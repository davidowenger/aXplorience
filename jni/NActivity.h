#ifndef __MYAPPLICATION_H__
#define __MYAPPLICATION_H__

namespace NSDEVICE
{

class NActivity : public Activity, OpUnit
{
public:
    NActivity(Wrapper* vWrapper);
    virtual ~NActivity() override;

    void handleMessage(NParam a = 0, NParam b = 0, NParam c = 0);
    void onActivityResult(int action, int requestCode, int resultCode, int extra);
    void onReceiveDiscoveryFinished();
    void onReceiveDiscoveryStarted();
    void onReceiveFoundDevice(BluetoothDevice* dBluetoothDevice);
    void onReceiveLocalName(String localName);
    void onReceiveState(int state, int statePrevious);
    void onReceiveScanMode(int mode, int modePrevious);
    NReturn visit(NAlpha01* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0);

protected:
	void onCreate();
    void onPause();
    void onStop();
};

} // End namespace

#endif
