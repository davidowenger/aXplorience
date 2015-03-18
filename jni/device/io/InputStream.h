#ifndef __InputStream_H__
#define __InputStream_H__

namespace NSDEVICE
{

class InputStream : public Object
{
friend NSNATIVE::NNoObject;

public:
	int close()
	{
		return NWrapper::getInstance()->mNVisitorIO->tRun(NWrapper::getInstance()->mNAlpha00, (NParam)this);
	}

    int read(string& buffer, int cMaxByte)
    {
    	// Blocks and returns the number of bytes read
    	// -1 if end of the stream is reached
    	// -2 if stream closed or another IO exception
    	// -3 if UTF-8 is not supported
		int err = (int)NWrapper::getInstance()->mNVisitorIO->tRun(NWrapper::getInstance()->mNBeta00, (NParam)this, (NParam)cMaxByte);

		if (err >= 0) {
			buffer += NWrapper::getInstance()->nFrame->tGetString(NWrapper::getInstance()->nFrame->tRunObject((NParam)err));
			err = 0;
		}
		return -err;
	}

private:
    InputStream(NNoObject* vNNoObject)
    {
    }
};

} // End namespace

#endif
