#ifndef __TEXTVIEW_H__
#define __TEXTVIEW_H__

namespace NSDEVICE
{

class TextView : public View
{
friend NSNATIVE::NNoObject;

public:
    enum BufferType { EDITABLE, NORMAL, SPANNABLE };

	TextView(Context* context)
        : View(NWrapper::w->mNNoObject->instance<View>())
	{
		NWrapper::getInstance()->mNVisitorWidgetView->tRun(NWrapper::getInstance()->mNIota00, (NParam)this, (NParam)context);
	}

    virtual ~TextView()
    {
    }

    virtual void onSaveInstanceState()
    {
        NWrapper::w->mNVisitorWidgetView->tRun(NWrapper::w->mNKappa00, (NParam)this);
    }

    virtual void setEnabled(bool enabled)
    {
        NWrapper::w->mNVisitorWidgetView->tRun(NWrapper::w->mNLambda00, (NParam)this, (NParam)enabled);
    }

    virtual void setGravity(int gravity)
    {
        NWrapper::w->mNVisitorWidgetView->tRun(NWrapper::w->mNMu00, (NParam)this, (NParam)gravity);
    }

    virtual void setLines(int lines)
    {
        NWrapper::w->mNVisitorWidgetView->tRun(NWrapper::w->mNNu00, (NParam)this, (NParam)lines);
    }

    virtual void setPadding(int left, int top, int right, int bottom)
    {
        NWrapper::w->mNVisitorWidgetView->tRun(NWrapper::w->mNXi00, (NParam)this, (NParam)left, (NParam)top, (NParam)right, (NParam)bottom);
    }

    virtual void setSelected(bool selected)
    {
        NWrapper::w->mNVisitorWidgetView->tRun(NWrapper::w->mNOmicron00, (NParam)this, (NParam)selected);
    }

    virtual void setText(const String& text)
	{
		NWrapper::w->mNVisitorWidgetView->tRun(NWrapper::getInstance()->mNPi00, (NParam)this, NParamBox(NWrapper::getInstance(), text).n);
	}

    virtual void setTextSize(float size)
    {
        double vcSize = size;
        NWrapper::w->mNVisitorWidgetView->tRun(NWrapper::getInstance()->mNRho00, (NParam)this, (NParam)*reinterpret_cast<long*>(&vcSize));
    }

    virtual void setTypeface(Typeface* tf)
    {
        NWrapper::w->mNVisitorWidgetView->tRun(NWrapper::w->mNSigma00, (NParam)this, (NParam)tf);
    }

private:
    TextView(NNoObject* vNNoObject)
        : View(NWrapper::w->mNNoObject->instance<View>())
    {
    }
};

} // End namespace

#endif
