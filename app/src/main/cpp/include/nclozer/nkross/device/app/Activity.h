#ifndef __ACTIVITY_H__
#define __ACTIVITY_H__

namespace NSDEVICE
{

class Activity : public ContextThemeWrapper
{
friend NSNATIVE::NVisitorAppActivity;
friend NSNATIVE::NKrossFriend;

public:
    Activity()
        : ContextThemeWrapper(NSNKROSS::w->mNKrossFriend->instance<ContextThemeWrapper>())
    {
        NSNKROSS::w->mNVisitorAppActivity->tRun(NSNKROSS::w->mNAlpha00, (NParam)this);
    }

    virtual ~Activity()
    {
    }

    Activity* getInstance(NWrapper* vNWrapper);

    virtual void finish()
    {
        NSNKROSS::w->mNVisitorAppActivity->tRun(NSNKROSS::w->mNEta00, (NParam)this);
    }

    virtual ActionBar* getActionBar()
    {
        ActionBar* b = NSNKROSS::w->mNKrossFriend->pointer<ActionBar>();
        return NSNKROSS::w->mNKrossFriend->emplaceKey(b, NSNKROSS::w->mNVisitorAppActivity->tRun(NSNKROSS::w->mNBeta00, (NParam)this, (NParam)b));
    }

    virtual Application* getApplication()
    {
        Application* b = NSNKROSS::w->mNKrossFriend->pointer<Application>();
        return NSNKROSS::w->mNKrossFriend->emplaceKey(b, NSNKROSS::w->mNVisitorAppActivity->tRun(NSNKROSS::w->mNGamma00, (NParam)this, (NParam)b));
    }

    virtual FragmentManager* getFragmentManager()
    {
        FragmentManager* b = NSNKROSS::w->mNKrossFriend->pointer<FragmentManager>();
        return NSNKROSS::w->mNKrossFriend->emplaceKey(b, NSNKROSS::w->mNVisitorAppActivity->tRun(NSNKROSS::w->mNDelta00, (NParam)this, (NParam)b));
    }

    virtual WindowManager* getWindowManager ()
    {
        WindowManager* b = NSNKROSS::w->mNKrossFriend->pointer<WindowManager>();
        return NSNKROSS::w->mNKrossFriend->emplaceKey(b, NSNKROSS::w->mNVisitorAppActivity->tRun(NSNKROSS::w->mNTheta00, (NParam)this, (NParam)b));
    }

    virtual void setContentView(View* view)
    {
        NSNKROSS::w->mNVisitorAppActivity->tRun(NSNKROSS::w->mNEpsilon00, (NParam)this, (NParam)view);
    }

    virtual void sendMessage(long long int m)
    {
        NSNKROSS::w->mNVisitorAppActivity->tRun(NSNKROSS::w->mNDzeta00, (NParam)this, (NParam)m);
    }

protected:
    //******************************************************************************************
    //************************************* Activity events ************************************
    //* This passes the call back to the default implementation if the method is not overriden *
    //******************************************************************************************
    virtual void onCreate(Bundle* savedInstanceState)
    {
        NSNKROSS::w->mNVisitorAppActivity->tRun(NSNKROSS::w->mNAlpha03, (NParam)this, (NParam)savedInstanceState);
    }

    virtual void onRestart()
    {
        NSNKROSS::w->mNVisitorAppActivity->tRun(NSNKROSS::w->mNBeta03, (NParam)this);
    }

    virtual void onStart()
    {
        NSNKROSS::w->mNVisitorAppActivity->tRun(NSNKROSS::w->mNGamma03, (NParam)this);
    }

    virtual void onResume()
    {
        // Resume here animations and other things that may be consuming CPU
        NSNKROSS::w->mNVisitorAppActivity->tRun(NSNKROSS::w->mNDelta03, (NParam)this);
    }

    virtual void onPause()
    {
        // This is the last method garanteed to be called before the process may be killed
        // Stop things that may be consuming CPU (like animations) here
        NSNKROSS::w->mNVisitorAppActivity->tRun(NSNKROSS::w->mNEpsilon03, (NParam)this);
    }

    virtual void onStop()
    {
        NSNKROSS::w->mNVisitorAppActivity->tRun(NSNKROSS::w->mNDzeta03, (NParam)this);
    }

    virtual void onDestroy()
    {
        // Called only if the system must not recover memory in an emergency
        // Clean memory here
        NSNKROSS::w->mNVisitorAppActivity->tRun(NSNKROSS::w->mNEta03, (NParam)this);
    }

    virtual void onActivityResult(int action, int requestCode, int resultCode, int extra)
    {
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

    virtual void handleMessage(NParam m)
    {
    }

private:
    Activity(NKrossFriend* vNKrossFriend)
        : ContextThemeWrapper(NSNKROSS::w->mNKrossFriend->instance<ContextThemeWrapper>())
    {
    }
};

} // End namespace

#endif


//HINT:
// Methods requiring an xml resource ID as parameter will not be implemented, because there is no android xml parser on iOs
// - inflater
// - setTextAppearance(Context context, int resid)
