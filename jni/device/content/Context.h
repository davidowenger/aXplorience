#ifndef __Context_H__
#define __Context_H__

namespace NSDEVICE
{

class Context : public Object
{
friend NSNATIVE::NNoObject;

public:
	virtual ~Context()
	{
	}

//    virtual Context* getApplicationContext()
//    {
//        Context* b = NWrapper::w->mNNoObject->pointer<Context>();
//        return NWrapper::w->mNNoObject->emplaceKey(b, NWrapper::w->mNVisitorContent->tRun(NWrapper::w->mNAlpha00, (NParam)this, (NParam)b));
//    }

private:
    Context(NNoObject* vNNoObject)
    {
    }
};

} // End namespace

#endif
