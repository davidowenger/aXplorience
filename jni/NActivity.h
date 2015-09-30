#ifndef __MYAPPLICATION_H__
#define __MYAPPLICATION_H__

namespace NSDEVICE
{

class NActivity : public Activity, public OpUnit
{
public:
    NActivity(Wrapper* vWrapper);
    virtual ~NActivity() override;

    virtual void handleMessage(NParam m) override;
    virtual void onReceiveDiscoveryFinished() override;
    virtual void onReceiveFoundDevice(BluetoothDevice* dBluetoothDevice) override;

    void addWidget();
    void renderHeader();
    void removeWidget(nuint vcDBObjectId);
    void scan();
    void setView(nint vcView, DBObject* vDBObject = nullptr);
    void sort(DBCollection* vDBCollection);
    void tilt(nuint color);
    void update(DBObject* vDBObject, nint vcView);

    NReturn visit(NAlpha01* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;
    NReturn visit(NBeta01* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;
    NReturn visit(NGamma01* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;
    NReturn visit(NDelta01* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;
    NReturn visit(NEpsilon01* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;
    NReturn visit(NDzeta01* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;
    NReturn visit(NEta01* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;
    NReturn visit(NTheta01* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;

    nuint mState;

protected:
    void onCreate(Bundle* savedInstanceState) override;
    void onResume() override;
    void onPause() override;
    void onDestroy() override;
};

} // End namespace

#endif
