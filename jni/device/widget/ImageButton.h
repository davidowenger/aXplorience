#ifndef __ImageButton_H__
#define __ImageButton_H__

namespace NSDEVICE
{

class ImageButton : public ImageView
{
friend NSNATIVE::NNoObject;

public:
    ImageButton(Context* context)
        : ImageView(NWrapper::w->mNNoObject->instance<ImageView>())
	{
        NWrapper::w->mNVisitorWidget->tRun(NWrapper::w->mNOmicron00, (NParam)this);
	}

	virtual ~ImageButton()
	{
	}

private:
    ImageButton(NNoObject* vNNoObject)
        : ImageView(NWrapper::w->mNNoObject->instance<ImageView>())
    {
    }
};

} // End namespace

#endif
