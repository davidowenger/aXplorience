#ifndef __ACTIVITY_H__
#define __ACTIVITY_H__

namespace NSDEVICE
{

class Activity : public ContextThemeWrapper
{
friend NSNATIVE::NVisitorAppActivity;
friend NSNATIVE::NNoObject;

public:
    Activity()
        : ContextThemeWrapper(NWrapper::w->mNNoObject->instance<ContextThemeWrapper>())
    {
        NWrapper::w->mNVisitorAppActivity->tRun(NWrapper::w->mNAlpha00, (NParam)this);
    }

    virtual ~Activity()
    {
    }

    Activity* getInstance(NWrapper* const vNWrapper);

    virtual void finish()
    {
        NWrapper::w->mNVisitorAppActivity->tRun(NWrapper::w->mNEta00, (NParam)this);
    }

    virtual ActionBar* getActionBar()
    {
        ActionBar* b = NWrapper::w->mNNoObject->pointer<ActionBar>();
        return NWrapper::w->mNNoObject->emplaceKey(b, NWrapper::w->mNVisitorAppActivity->tRun(NWrapper::w->mNBeta00, (NParam)this, (NParam)b));
    }

    virtual Application* getApplication()
    {
        Application* b = NWrapper::w->mNNoObject->pointer<Application>();
        return NWrapper::w->mNNoObject->emplaceKey(b, NWrapper::w->mNVisitorAppActivity->tRun(NWrapper::w->mNGamma00, (NParam)this, (NParam)b));
    }

    virtual FragmentManager* getFragmentManager()
    {
        FragmentManager* b = NWrapper::w->mNNoObject->pointer<FragmentManager>();
        return NWrapper::w->mNNoObject->emplaceKey(b, NWrapper::w->mNVisitorAppActivity->tRun(NWrapper::w->mNDelta00, (NParam)this, (NParam)b));
    }

    virtual void setContentView(View* view)
    {
        NWrapper::w->mNVisitorAppActivity->tRun(NWrapper::w->mNEpsilon00, (NParam)this, (NParam)view);
    }

    virtual void sendMessage(long long int m)
    {
        NWrapper::w->mNVisitorAppActivity->tRun(NWrapper::w->mNDzeta00, (NParam)this, (NParam)m);
    }

protected:
    //******************************************************************************************
    //************************************* Activity events ************************************
    //* This passes the call back to the default implementation if the method is not overriden *
    //******************************************************************************************
    virtual void onCreate(Bundle* savedInstanceState)
    {
        NWrapper::w->mNVisitorAppActivity->tRun(NWrapper::w->mNAlpha03, (NParam)this, (NParam)savedInstanceState);
    }

    virtual void onRestart()
    {
        NWrapper::w->mNVisitorAppActivity->tRun(NWrapper::w->mNBeta03, (NParam)this);
    }

    virtual void onStart()
    {
        NWrapper::w->mNVisitorAppActivity->tRun(NWrapper::w->mNGamma03, (NParam)this);
    }

    virtual void onResume()
    {
        // Resume here animations and other things that may be consuming CPU
        NWrapper::w->mNVisitorAppActivity->tRun(NWrapper::w->mNDelta03, (NParam)this);
    }

    virtual void onPause()
    {
        // This is the last method garanteed to be called before the process may be killed
        // Stop things that may be consuming CPU (like animations) here
        NWrapper::w->mNVisitorAppActivity->tRun(NWrapper::w->mNEpsilon03, (NParam)this);
    }

    virtual void onStop()
    {
        NWrapper::w->mNVisitorAppActivity->tRun(NWrapper::w->mNDzeta03, (NParam)this);
    }

    virtual void onDestroy()
    {
        // Called only if the system must not recover memory in an emergency
        // Clean memory here
        NWrapper::w->mNVisitorAppActivity->tRun(NWrapper::w->mNEta03, (NParam)this);
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

    virtual void handleMessage(long long int m)
    {
    }

private:
    Activity(NNoObject* vNNoObject)
        : ContextThemeWrapper(NWrapper::w->mNNoObject->instance<ContextThemeWrapper>())
    {
    }
};

} // End namespace

#endif


//HINT:
// Methods requiring an xml resource ID as parameter will not be implemented, because there is no android xml parser on iOs
// - inflater
// - setTextAppearance(Context context, int resid)
