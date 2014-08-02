#ifndef __TEXTVIEW_H__
#define __TEXTVIEW_H__

namespace NNSUser
{

class TextView : public View
{
public:
	TextView(Context* context)
		: View(context)
	{
		w->nVisitorWidget->tRun(w->tau, (NParam)this, (NParam)context);
	}

	virtual ~TextView()
	{
		w->nFrame->tRun(w->delta, (NParam)this);
	}

	void setTextSize(float size)
	{
		w->nVisitorWidget->tRun(w->upsilon, (NParam)this, (NParam)size);
	}

	void setText(CharSequence text)
	{
		w->nVisitorWidget->tRun(w->phi, (NParam)this, NParamBox(w, text).n);
	}
};

} // End namespace

#endif
