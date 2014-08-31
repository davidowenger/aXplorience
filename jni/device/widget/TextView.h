#ifndef __TEXTVIEW_H__
#define __TEXTVIEW_H__

namespace NSDEVICE
{

class TextView : public View
{
public:
	TextView(Context* context)
		: View(context)
	{
		NWrapper::w->nVisitorWidget->tRun(NWrapper::w->tau01, (NParam)this, (NParam)context);
	}

	virtual ~TextView()
	{
		NWrapper::w->nFrame->tRun(NWrapper::w->delta01, (NParam)this);
	}

	void setTextSize(float size)
	{
		NWrapper::w->nVisitorWidget->tRun(NWrapper::w->upsilon01, (NParam)this, (NParam)size);
	}

	void setText(const String& text)
	{
		NWrapper::w->nVisitorWidget->tRun(NWrapper::w->phi01, (NParam)this, NParamBox(NWrapper::w, text).n);
	}
};

} // End namespace

#endif
