#ifndef __MYAPPLICATION_H__
#define __MYAPPLICATION_H__

namespace NSDEVICE
{

class NActivity : public Activity, public OpUnit
{
public:
    NActivity(Wrapper* vWrapper);
    virtual ~NActivity() override;

    void buzz(DBCollection* vDBCollection);
    void clear(DBCollection* vDBCollection);
    void renderHeader(DBCollection* vDBCollection);
    void render(DBCollection* vDBCollection);
    bool setView(nint vcView, nint vcDBObjectId = 1);
    void tilt(nuint color);

    virtual void handleMessage(NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0) override;
    virtual void onReceiveDiscoveryFinished() override;
    virtual void onReceiveFoundDevice(BluetoothDevice* dBluetoothDevice) override;

    NReturn visit(NAlpha01* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;
    NReturn visit(NBeta01* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;
    NReturn visit(NGamma01* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;
    NReturn visit(NDelta01* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;
    NReturn visit(NEpsilon01* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;
    NReturn visit(NDzeta01* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;

    nint mcView;
    nuint mState;
    nint mCount;

protected:
	void onCreate(Bundle* savedInstanceState) override;
    void onStart() override;
    void onPause() override;
    void onStop() override;
    void onDestroy() override;
};

} // End namespace

#endif
