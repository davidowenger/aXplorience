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
		NSDEVICE::Activity::kActivity->w->nVisitorWidget->tRun(NSDEVICE::Activity::kActivity->w->tau01, (NParam)this, (NParam)context);
	}

	virtual ~TextView()
	{
		NSDEVICE::Activity::kActivity->w->nFrame->tRun(NSDEVICE::Activity::kActivity->w->delta01, (NParam)this);
	}

	void setTextSize(float size)
	{
		NSDEVICE::Activity::kActivity->w->nVisitorWidget->tRun(NSDEVICE::Activity::kActivity->w->upsilon01, (NParam)this, (NParam)size);
	}

	void setText(const String& text)
	{
		NSDEVICE::Activity::kActivity->w->nVisitorWidget->tRun(NSDEVICE::Activity::kActivity->w->phi01, (NParam)this, NParamBox(NSDEVICE::Activity::kActivity->w, text).n);
	}
};

} // End namespace

#endif
