#ifndef __ACTIVITY_H__
#define __ACTIVITY_H__

namespace NSDEVICE
{

class Activity : public ContextThemeWrapper
{
friend class NSNATIVE::NVisitorApp;

public:
	static Activity* kActivity;

	Activity()
	{
		w = nullptr;
	}

	virtual ~Activity()
	{
		delete w;
	}

	virtual NWrapper* getWrapper()
	{
		return new NWrapper();
	}

	virtual void setContentView(View* view)
	{
		NSDEVICE::Activity::kActivity->w->nVisitorApp->tRun(NSDEVICE::Activity::kActivity->w->theta00, (NParam)this, (NParam)view);
	}

	virtual void send(NParam a = 0, NParam b = 0, NParam c = 0)
	{
		NSDEVICE::Activity::kActivity->w->nFrame->tRun(NSDEVICE::Activity::kActivity->w->iota00, (NParam)this, (NParam)a, (NParam)b, (NParam)c);
	}

	NWrapper* w;

protected:
	virtual void onCreate()
	{
		NSDEVICE::Activity::kActivity->w->nVisitorApp->tRun(NSDEVICE::Activity::kActivity->w->alpha00, (NParam)this);
	}

	virtual void onDestroy()
	{
		// Called only if the system must not recover memory in an emergency
		// Clean memory here
		NSDEVICE::Activity::kActivity->w->nVisitorApp->tRun(NSDEVICE::Activity::kActivity->w->beta00, (NParam)this);
	}

	virtual void onPause()
	{
		// This is the last method garanteed to be called before the process may be killed
		// Stop things that may be consuming CPU (like animations) here
		NSDEVICE::Activity::kActivity->w->nVisitorApp->tRun(NSDEVICE::Activity::kActivity->w->gamma00, (NParam)this);
	}

	virtual void onRestart()
	{
		NSDEVICE::Activity::kActivity->w->nVisitorApp->tRun(NSDEVICE::Activity::kActivity->w->delta00, (NParam)this);
	}

	virtual void onResume()
	{
		// Resume here animations and other things that may be consuming CPU
		NSDEVICE::Activity::kActivity->w->nVisitorApp->tRun(NSDEVICE::Activity::kActivity->w->epsilon00, (NParam)this);
	}

	virtual void onStart()
	{
		NSDEVICE::Activity::kActivity->w->nVisitorApp->tRun(NSDEVICE::Activity::kActivity->w->dzeta00, (NParam)this);
	}

	virtual void onStop()
	{
		NSDEVICE::Activity::kActivity->w->nVisitorApp->tRun(NSDEVICE::Activity::kActivity->w->eta00, (NParam)this);
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
