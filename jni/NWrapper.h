#ifndef __NWRAPPER_H__
#define __NWRAPPER_H__

namespace NNameSpace
{

class NWrapper
{
public :
    static const nuint nNElement = 3;

	JNIEnv* env;
	NFrame* nFrame;
	jobject tFrame;
	nlong* apNElement;
	NElement* alpha;
	NElement* beta;
	NElement* gamma;
	jclass jclassByteBuffer;
	jmethodID jmidByteBufferAllocate;
};

} // END namespace

#endif
