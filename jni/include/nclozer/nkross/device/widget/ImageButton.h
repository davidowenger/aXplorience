#ifndef __ImageButton_H__
#define __ImageButton_H__

namespace NSDEVICE
{

class ImageButton : public ImageView
{
friend NSNATIVE::NKrossFriend;

public:
    ImageButton(Context* context)
        : ImageView(NKrossWrapper::w->mNKrossFriend->instance<ImageView>())
    {
        NKrossWrapper::w->mNVisitorWidget->tRun(NKrossWrapper::w->mNOmicron00, (NParam)this, (NParam)context);
    }

    virtual ~ImageButton()
    {
    }

private:
    ImageButton(NKrossFriend* vNKrossFriend)
        : ImageView(NKrossWrapper::w->mNKrossFriend->instance<ImageView>())
    {
    }
};

} // End namespace

#endif
