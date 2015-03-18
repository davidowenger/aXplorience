#ifndef __OutputStream_H__
#define __OutputStream_H__

namespace NSDEVICE
{

class OutputStream : public Object
{
friend NSNATIVE::NNoObject;

public:
	int close()
	{
		return NWrapper::getInstance()->mNVisitorIO->tRun(NWrapper::getInstance()->mNAlpha01, (NParam)this);
	}

    int write(const string& packet)
    {
		return NWrapper::getInstance()->mNVisitorIO->tRun(NWrapper::getInstance()->mNBeta01, (NParam)this, NParamBox(NWrapper::getInstance(), packet).n);
    }

private:
    OutputStream(NNoObject* vNNoObject)
    {
    }
};

} // End namespace

#endif
