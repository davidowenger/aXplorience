#ifndef __ACTIVITY_H__
#define __ACTIVITY_H__

namespace NSDEVICE
{

class Activity : public ContextThemeWrapper
{
friend NSNATIVE::NVisitorAppActivity;
friend NSNATIVE::NKrossFriend;

public:
    // You have to implement this method to return your own child object
    Activity* getInstance(NWrapper* vNWrapper);

public:
    Activity() :
        ContextThemeWrapper(NKrossWrapper::w->mNKrossFriend->instance<ContextThemeWrapper>())
    {
        NKrossWrapper::w->mNVisitorAppActivity->tRun(NKrossWrapper::w->mNAlpha00, (NParam)this);
    }

    virtual ~Activity()
    {
    }

protected:
    //******************************************************************************************
    //************************************* Activity events ************************************
    //* This passes the call back to the default implementation if the method is not overriden *
    //******************************************************************************************
    virtual void onCreate(Bundle* savedInstanceState)
    {
        NKrossWrapper::w->mNVisitorAppActivity->tRun(NKrossWrapper::w->mNAlpha03, (NParam)this, (NParam)savedInstanceState);
    }

    virtual void onRestart()
    {
        NKrossWrapper::w->mNVisitorAppActivity->tRun(NKrossWrapper::w->mNBeta03, (NParam)this);
    }

    virtual void onStart()
    {
        NKrossWrapper::w->mNVisitorAppActivity->tRun(NKrossWrapper::w->mNGamma03, (NParam)this);
    }

    virtual void onResume()
    {
        // Resume here animations and other things that may be consuming CPU
        NKrossWrapper::w->mNVisitorAppActivity->tRun(NKrossWrapper::w->mNDelta03, (NParam)this);
    }

    virtual void onPause()
    {
        // This is the last method garanteed to be called before the process may be killed
        // Stop things that may be consuming CPU (like animations) here
        NKrossWrapper::w->mNVisitorAppActivity->tRun(NKrossWrapper::w->mNEpsilon03, (NParam)this);
    }

    virtual void onStop()
    {
        NKrossWrapper::w->mNVisitorAppActivity->tRun(NKrossWrapper::w->mNDzeta03, (NParam)this);
    }

    virtual void onDestroy()
    {
        // Called only if the system must not recover memory in an emergency
        // Clean memory here
        NKrossWrapper::w->mNVisitorAppActivity->tRun(NKrossWrapper::w->mNEta03, (NParam)this);
    }

public:
    virtual void handleMessage(long long int m)
    {
    }

    virtual void finish()
    {
        NKrossWrapper::w->mNVisitorAppActivity->tRun(NKrossWrapper::w->mNEta00, (NParam)this);
    }

    virtual ActionBar* getActionBar()
    {
        ActionBar* b = NKrossWrapper::w->mNKrossFriend->pointer<ActionBar>();
        return NKrossWrapper::w->mNKrossFriend->emplaceKey(b, NKrossWrapper::w->mNVisitorAppActivity->tRun(NKrossWrapper::w->mNBeta00, (NParam)this, (NParam)b));
    }

    virtual Application* getApplication()
    {
        Application* b = NKrossWrapper::w->mNKrossFriend->pointer<Application>();
        return NKrossWrapper::w->mNKrossFriend->emplaceKey(b, NKrossWrapper::w->mNVisitorAppActivity->tRun(NKrossWrapper::w->mNGamma00, (NParam)this, (NParam)b));
    }

    virtual FragmentManager* getFragmentManager()
    {
        FragmentManager* b = NKrossWrapper::w->mNKrossFriend->pointer<FragmentManager>();
        return NKrossWrapper::w->mNKrossFriend->emplaceKey(b, NKrossWrapper::w->mNVisitorAppActivity->tRun(NKrossWrapper::w->mNDelta00, (NParam)this, (NParam)b));
    }

    virtual WindowManager* getWindowManager ()
    {
        WindowManager* b = NKrossWrapper::w->mNKrossFriend->pointer<WindowManager>();
        return NKrossWrapper::w->mNKrossFriend->emplaceKey(b, NKrossWrapper::w->mNVisitorAppActivity->tRun(NKrossWrapper::w->mNTheta00, (NParam)this, (NParam)b));
    }

protected:
    virtual void onActivityResult(int action, int requestCode, int resultCode, int extra)
    {
    }

public:
    virtual void onBackPressed()
    {
        NKrossWrapper::w->mNVisitorAppActivity->tRun(NKrossWrapper::w->mNMu03, (NParam)this);
    }

    virtual bool onCreateOptionsMenu(Menu* menu)
    {
        return NKrossWrapper::w->mNVisitorAppActivity->tRun(NKrossWrapper::w->mNIota03, (NParam)this, (NParam)menu);
    }

    virtual bool onOptionsItemSelected(MenuItem* item)
    {
        return NKrossWrapper::w->mNVisitorAppActivity->tRun(NKrossWrapper::w->mNLambda03, (NParam)this, (NParam)item);
    }

    virtual bool onPrepareOptionsMenu(Menu* menu)
    {
        return NKrossWrapper::w->mNVisitorAppActivity->tRun(NKrossWrapper::w->mNKappa03, (NParam)this, (NParam)menu);
    }

    virtual void onReceiveDiscoveryFinished()
    {
    }

    virtual void onReceiveDiscoveryStarted()
    {
    }

    virtual void onReceiveFoundDevice(BluetoothDevice* dBluetoothDevice)
    {
        delete dBluetoothDevice;
    }

    virtual void onReceiveLocalName(const String& localName)
    {
    }

    virtual void onReceiveState(int state, int statePrevious)
    {
    }

    virtual void onReceiveScanMode(int mode, int modePrevious)
    {
    }

    virtual void setContentView(View* view)
    {
        NKrossWrapper::w->mNVisitorAppActivity->tRun(NKrossWrapper::w->mNEpsilon00, (NParam)this, (NParam)view);
    }

    virtual void sendMessage(long long int m)
    {
        NKrossWrapper::w->mNVisitorAppActivity->tRun(NKrossWrapper::w->mNDzeta00, (NParam)this, (NParam)m);
    }

private:
    Activity(NKrossFriend* vNKrossFriend)
        : ContextThemeWrapper(NKrossWrapper::w->mNKrossFriend->instance<ContextThemeWrapper>())
    {
    }
};

} // End namespace

#endif


//HINT:
// Methods requiring an xml resource ID as parameter will not be implemented, because there is no android xml parser on iOs
// - inflater
// - setTextAppearance(Context context, int resid)
