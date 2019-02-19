#ifndef __ImageButton_H__
#define __ImageButton_H__

namespace NSDEVICE
{

class ImageButton : public ImageView
{
friend NSNATIVE::NKrossFriend;

public:
    ImageButton(Context* context)
        : ImageView(NSNKROSS::w->mNKrossFriend->instance<ImageView>())
    {
        NSNKROSS::w->mNVisitorWidget->tRun(NSNKROSS::w->mNOmicron00, (NParam)this, (NParam)context);
    }

    virtual ~ImageButton()
    {
    }

private:
    ImageButton(NKrossFriend* vNKrossFriend)
        : ImageView(NSNKROSS::w->mNKrossFriend->instance<ImageView>())
    {
    }
};

} // End namespace

#endif
