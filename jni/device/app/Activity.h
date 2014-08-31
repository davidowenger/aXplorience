#ifndef __ACTIVITY_H__
#define __ACTIVITY_H__

namespace NSDEVICE
{

class Activity : public ContextThemeWrapper
{
friend class NSNATIVE::NVisitorApp;

public:
	static Activity* const kActivity;
	static NWrapper* const kWrapper;

	Activity()
	{
	}

	virtual ~Activity()
	{
	}

	virtual void setContentView(View* view)
	{
		NWrapper::w->nVisitorApp->tRun(NWrapper::w->theta00, (NParam)this, (NParam)view);
	}

	virtual void send(NParam a = 0, NParam b = 0, NParam c = 0)
	{
		NWrapper::w->nFrame->tRun(NWrapper::w->iota00, (NParam)this, (NParam)a, (NParam)b, (NParam)c);
	}

protected:
	virtual void onCreate()
	{
		NWrapper::w->nVisitorApp->tRun(NWrapper::w->alpha00, (NParam)this);
	}

	virtual void onDestroy()
	{
		// Called only if the system must not recover memory in an emergency
		// Clean memory here
		NWrapper::w->nVisitorApp->tRun(NWrapper::w->beta00, (NParam)this);
	}

	virtual void onPause()
	{
		// This is the last method garanteed to be called before the process may be killed
		// Stop things that may be consuming CPU (like animations) here
		NWrapper::w->nVisitorApp->tRun(NWrapper::w->gamma00, (NParam)this);
	}

	virtual void onRestart()
	{
		NWrapper::w->nVisitorApp->tRun(NWrapper::w->delta00, (NParam)this);
	}

	virtual void onResume()
	{
		// Resume here animations and other things that may be consuming CPU
		NWrapper::w->nVisitorApp->tRun(NWrapper::w->epsilon00, (NParam)this);
	}

	virtual void onStart()
	{
		NWrapper::w->nVisitorApp->tRun(NWrapper::w->dzeta00, (NParam)this);
	}

	virtual void onStop()
	{
		NWrapper::w->nVisitorApp->tRun(NWrapper::w->eta00, (NParam)this);
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
	}

	virtual void onReceiveLocalName(String localName)
	{
	}

	virtual void onReceiveState(int state, int statePrevious)
	{
	}

	virtual void onReceiveScanMode(int mode, int modePrevious)
	{
	}

	virtual void handleMessage(NParam a, NParam b, NParam c)
	{
	}
};

} // End namespace

#endif
