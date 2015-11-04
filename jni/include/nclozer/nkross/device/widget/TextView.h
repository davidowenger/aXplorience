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
        : View(NSNKROSS::w->mNKrossFriend->instance<View>())
    {
        NSNKROSS::w->mNVisitorWidgetView->tRun(NSNKROSS::w->mNIota00, (NParam)this, (NParam)context);
    }

    virtual ~TextView()
    {
    }

    virtual void setEnabled(bool enabled)
    {
        NSNKROSS::w->mNVisitorWidgetView->tRun(NSNKROSS::w->mNLambda00, (NParam)this, (NParam)enabled);
    }

    virtual void setGravity(int gravity)
    {
        NSNKROSS::w->mNVisitorWidgetView->tRun(NSNKROSS::w->mNMu00, (NParam)this, (NParam)gravity);
    }

    virtual void setHint(const String& hint)
    {
        NSNKROSS::w->mNVisitorWidgetView->tRun(NSNKROSS::w->mNUpsilon00, (NParam)this, NKrossParam(hint).n);
    }

    virtual void setImeOptions(int imeOptions)
    {
        NSNKROSS::w->mNVisitorWidgetView->tRun(NSNKROSS::w->mNPhi00, (NParam)this, (NParam)imeOptions);
    }

    virtual void setLines(int lines)
    {
        NSNKROSS::w->mNVisitorWidgetView->tRun(NSNKROSS::w->mNNu00, (NParam)this, (NParam)lines);
    }

    virtual void setPadding(int left, int top, int right, int bottom)
    {
        NSNKROSS::w->mNVisitorWidgetView->tRun(NSNKROSS::w->mNXi00, (NParam)this, (NParam)left, (NParam)top, (NParam)right, (NParam)bottom);
    }

    virtual void setRawInputType(int type)
    {
        NSNKROSS::w->mNVisitorWidgetView->tRun(NSNKROSS::w->mNKhi00, (NParam)this, (NParam)type);
    }

    virtual void setSelected(bool selected)
    {
        NSNKROSS::w->mNVisitorWidgetView->tRun(NSNKROSS::w->mNOmicron00, (NParam)this, (NParam)selected);
    }

    virtual void setText(const String& text)
    {
        NSNKROSS::w->mNVisitorWidgetView->tRun(NSNKROSS::w->mNPi00, (NParam)this, NKrossParam(text).n);
    }

    virtual void setTextColor(int color)
    {
        NSNKROSS::w->mNVisitorWidgetView->tRun(NSNKROSS::w->mNPsi00, (NParam)this, (NParam)color);
    }

    virtual void setTextSize(float size)
    {
        ndouble vcSize = size;
        NSNKROSS::w->mNVisitorWidgetView->tRun(NSNKROSS::w->mNRho00, (NParam)this, *reinterpret_cast<nlong*>(&vcSize));
    }

    virtual void setTypeface(Typeface* tf)
    {
        NSNKROSS::w->mNVisitorWidgetView->tRun(NSNKROSS::w->mNSigma00, (NParam)this, (NParam)tf);
    }

private:
    TextView(NKrossFriend* vNKrossFriend)
        : View(NSNKROSS::w->mNKrossFriend->instance<View>())
    {
    }
};

} // End namespace

#endif
