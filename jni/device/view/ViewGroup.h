#ifndef __VIEWGROUP_H__
#define __VIEWGROUP_H__

namespace NSDEVICE
{

class ViewGroup : public View
{
public:
	ViewGroup(Context* context)
		: View(context)
	{
	}

	virtual ~ViewGroup()
	{
	}

	void addView(View* view)
	{
		NSDEVICE::Activity::kActivity->w->nVisitorView->tRun(NSDEVICE::Activity::kActivity->w->alpha02, (NParam)this, (NParam)view);
	}
};

} // End namespace

#endif
