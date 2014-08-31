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
		NWrapper::w->nVisitorWidget->tRun(NWrapper::w->lambda00, (NParam)this, (NParam)context);
	}

	virtual ~LinearLayout()
	{
		NWrapper::w->nFrame->tRun(NWrapper::w->delta00, (NParam)this);
	}
};

} // End namespace

#endif
