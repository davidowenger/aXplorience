#ifndef __NBUFFERLONG_H__
#define __NBUFFERLONG_H__

namespace NNameSpace
{

class NBufferLong
{
public:
	NBufferLong(NWrapper* w, int nLength, bool bDirect);
	~NBufferLong();

	nlong get(NElement* e);
	nlong get(NElement* e, const nlong* aNlong, int nLength);
	void set(NElement* e, nlong nValue);
	void set(NElement* e, nlong* const aNlong, int nLength);

    NWrapper* w;
    nlong* maBufferMem;
    jobject mjBuffer;
	bool mbDirect;
};

} // END namespace

#endif
