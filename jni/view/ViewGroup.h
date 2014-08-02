#ifndef __VIEWGROUP_H__
#define __VIEWGROUP_H__

namespace NNSUser
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
		w->nVisitorView->tRun(w->alpha, (NParam)this, (NParam)view);
	}
};

} // End namespace

#endif
