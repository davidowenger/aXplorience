#ifndef __LINEARLAYOUT_H__
#define __LINEARLAYOUT_H__

namespace NSDEVICE
{

class LinearLayout : public ViewGroup
{
public:
	LinearLayout(Context* context)
		: ViewGroup(context)
	{
		NSDEVICE::Activity::kActivity->w->nVisitorWidget->tRun(NSDEVICE::Activity::kActivity->w->lambda00, (NParam)this, (NParam)context);
	}

	virtual ~LinearLayout()
	{
		NSDEVICE::Activity::kActivity->w->nFrame->tRun(NSDEVICE::Activity::kActivity->w->delta00, (NParam)this);
	}
};

} // End namespace

#endif
