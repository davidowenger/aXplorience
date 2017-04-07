#ifndef __TEXTVIEW_H__
#define __TEXTVIEW_H__

namespace NSDEVICE
{

class TextView : public View
{
friend NSNATIVE::NKrossFriend;

public:
    enum BufferType { EDITABLE, NORMAL, SPANNABLE };

    TextView(Context* context)
        : View(NKrossWrapper::w->mNKrossFriend->instance<View>())
    {
        NKrossWrapper::w->mNVisitorWidgetView->tRun(NKrossWrapper::w->mNIota00, (NParam)this, (NParam)context);
    }

    virtual ~TextView()
    {
    }

    virtual void setAllCaps(bool allCaps)
    {
        NKrossWrapper::w->mNVisitorWidgetView->tRun(NKrossWrapper::w->mNAlpha01, (NParam)this, (NParam)allCaps);
    }

    virtual void setEnabled(bool enabled)
    {
        NKrossWrapper::w->mNVisitorWidgetView->tRun(NKrossWrapper::w->mNLambda00, (NParam)this, (NParam)enabled);
    }

    virtual void setGravity(int gravity)
    {
        NKrossWrapper::w->mNVisitorWidgetView->tRun(NKrossWrapper::w->mNMu00, (NParam)this, (NParam)gravity);
    }

    virtual void setHint(const String& hint)
    {
        NKrossWrapper::w->mNVisitorWidgetView->tRun(NKrossWrapper::w->mNUpsilon00, (NParam)this, NKrossParam(hint).n);
    }

    virtual void setImeOptions(int imeOptions)
    {
        NKrossWrapper::w->mNVisitorWidgetView->tRun(NKrossWrapper::w->mNPhi00, (NParam)this, (NParam)imeOptions);
    }

    virtual void setLines(int lines)
    {
        NKrossWrapper::w->mNVisitorWidgetView->tRun(NKrossWrapper::w->mNNu00, (NParam)this, (NParam)lines);
    }

    virtual void setPadding(int left, int top, int right, int bottom)
    {
        NKrossWrapper::w->mNVisitorWidgetView->tRun(NKrossWrapper::w->mNXi00, (NParam)this, (NParam)left, (NParam)top, (NParam)right, (NParam)bottom);
    }

    virtual void setRawInputType(int type)
    {
        NKrossWrapper::w->mNVisitorWidgetView->tRun(NKrossWrapper::w->mNKhi00, (NParam)this, (NParam)type);
    }

    virtual void setSelected(bool selected)
    {
        NKrossWrapper::w->mNVisitorWidgetView->tRun(NKrossWrapper::w->mNOmicron00, (NParam)this, (NParam)selected);
    }

    virtual void setText(const String& text)
    {
        NKrossWrapper::w->mNVisitorWidgetView->tRun(NKrossWrapper::w->mNPi00, (NParam)this, NKrossParam(text).n);
    }

    virtual void setTextColor(int color)
    {
        NKrossWrapper::w->mNVisitorWidgetView->tRun(NKrossWrapper::w->mNPsi00, (NParam)this, (NParam)color);
    }

    virtual void setTextSize(float size)
    {
        ndouble vcSize = size;
        NKrossWrapper::w->mNVisitorWidgetView->tRun(NKrossWrapper::w->mNRho00, (NParam)this, *reinterpret_cast<nlong*>(&vcSize));
    }

    virtual void setTypeface(Typeface* tf)
    {
        NKrossWrapper::w->mNVisitorWidgetView->tRun(NKrossWrapper::w->mNSigma00, (NParam)this, (NParam)tf);
    }

private:
    TextView(NKrossFriend* vNKrossFriend)
        : View(NKrossWrapper::w->mNKrossFriend->instance<View>())
    {
    }
};

} // End namespace

#endif
