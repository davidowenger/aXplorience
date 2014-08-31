#ifndef __VIEW_H__
#define __VIEW_H__

namespace NSDEVICE
{

class View
{
public:
	Context* mContext;

	View(Context* context)
		: mContext(context)
	{
	}

	virtual ~View()
	{
	}
};

} // End namespace

#endif
