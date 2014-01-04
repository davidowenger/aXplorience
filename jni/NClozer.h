#ifndef __NCLOZER_H__
#define __NCLOZER_H__

namespace NNameSpace
{

class NClozer : public NFrame
{
public:
	NClozer(NWrapper* w, JNIEnv* env, jobject tFrame);
	virtual ~NClozer();

	jlong nRunLong(NElement* nElement);
	jlong visitLong(NAlpha* alpha);
	jlong visitLong(NBeta* beta);
	jlong visitLong(NGamma* gamma);

	jobject nInit(jobjectArray aTElement);

	NBufferLong* factoryBufferLong(int nLength, bool bDirect);

    static const nuint mnLong = 1;

    NWrapper* w;
    NBufferLong* mBufferLong;
};

} // END namespace

#endif
