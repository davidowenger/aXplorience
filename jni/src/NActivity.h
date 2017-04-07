#ifndef __MYAPPLICATION_H__
#define __MYAPPLICATION_H__

namespace NSDEVICE
{

class NActivity : public Activity, public OpUnit
{
public:
    NActivity(Wrapper* vWrapper);
    virtual ~NActivity() override;

    void appSetView(nint vcView, DBObject* vDBObject = nullptr);
    void arSetResources(nint vcState);
    void handleMessage(NParam m) override;
    void onBackPressed() override;
    bool onCreateOptionsMenu(Menu* vMenu) override;
    bool onOptionsItemSelected(MenuItem* vMenuItem) override;
    void onReceiveDiscoveryFinished() override;
    void onReceiveFoundDevice(BluetoothDevice* dBluetoothDevice) override;
    bool onReceiveOption(nint vMenuItemId);
    void poiList(DBCollection* vDBCollection);
    void poiSort(DBCollection* vDBCollection);
    void settingsFeed();

    NReturn visit(NAlpha00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;
    NReturn visit(NBeta00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;
    NReturn visit(NGamma00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;
    NReturn visit(NEpsilon00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;

    nuint mState;
    nuint mLevel;
    nuint mView;
    nuint mDBObjectId;
    Wrapper* w;

protected:
    void onCreate(Bundle* savedInstanceState) override;
    void onStart() override;
    void onResume() override;
    void onPause() override;
    void onStop() override;
    void onDestroy() override;
};

} // End namespace

#endif
