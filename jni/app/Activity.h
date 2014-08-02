#ifndef __ACTIVITY_H__
#define __ACTIVITY_H__

namespace NNSUser
{

class Activity : public ContextThemeWrapper
{
friend class NNameSpace::NVisitorApp;

public:
	Activity()
	{
	}

	virtual ~Activity()
	{
	}

	void setContentView(View* view)
	{
		w->nVisitorApp->tRun(w->alpha, (NParam)this, (NParam)view);
	}

protected:
	virtual void onCreate(Bundle* savedInstanceState)
	{
	}

	virtual void onPause()
	{
		w->nVisitorApp->tRun(w->pi, (NParam)this);
	}

	virtual void onResume()
	{
		w->nVisitorApp->tRun(w->rho, (NParam)this);
	}
};

} // End namespace

#endif
