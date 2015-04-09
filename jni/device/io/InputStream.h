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
		return (nint)NWrapper::w->mNVisitorIO->tRun(NWrapper::w->mNAlpha00, (NParam)this);
	}

    int read(String& buffer, int byteCount)
    {
    	// Blocks and returns the number of bytes read
    	// -1 if end of the stream is reached
    	// -2 if stream closed or another IO exception
    	// -3 if UTF-8 is not supported
        size_t size = buffer.size();
		NReturn err = NWrapper::w->mNVisitorIO->tRun(NWrapper::w->mNBeta00, (NParam)this, (NParam)byteCount);

		if (err >= 0) {
			buffer += NWrapper::w->nFrame->tGetString(NWrapper::w->nFrame->tRunObject((NParam)err));
			err = buffer.size() - size;
		}
		return err;
	}

private:
    InputStream(NNoObject* vNNoObject)
    {
    }
};

} // End namespace

#endif
