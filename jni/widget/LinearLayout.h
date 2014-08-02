#ifndef __LINEARLAYOUT_H__
#define __LINEARLAYOUT_H__

namespace NNSUser
{

class LinearLayout : public ViewGroup
{
public:
	LinearLayout(Context* context)
		: ViewGroup(context)
	{
		mContext->w->nVisitorWidget->tRun(w->lambda, (NParam)this, (NParam)context);
	}

	virtual ~LinearLayout()
	{
		mContext->w->nFrame->tRun(w->delta, (NParam)this);
	}
};

} // End namespace

#endif
