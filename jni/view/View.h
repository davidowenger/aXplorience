#ifndef __VIEW_H__
#define __VIEW_H__

namespace NNSUser
{

class View
{
public:
	Context* mContext;
	NWrapper* w;

	View(Context* context)
		: mContext(context), w(context->w)
	{
	}

	virtual ~View()
	{
	}
};

} // End namespace

#endif
