#ifndef __NCLOZER_H__
#define __NCLOZER_H__

namespace NNameSpace
{

class NClozer : public NFrame
{
public:
    NWrapper* w;
    int mnTotal;
    long* mapNElement;
    jobject mbbNElement;

	NClozer(NWrapper* w, JNIEnv* env, jobject tFrame);
	virtual ~NClozer();

	jobject nInit(jobjectArray aTElement);
	jlong nRunLong(NElement* nElement);
	jobject nRunObject(NElement* nElement);
	jlong nVisitLong(NAlpha* alpha);
	jobject nVisitObject(NAlpha* alpha);
	jlong nVisitLong(NBeta* beta);
	jobject nVisitObject(NBeta* beta);
	jlong nVisitLong(NGamma* gamma);
	jobject nVisitObject(NGamma* gamma);

    jobject factoryDirectBuffer(void* pData, long nLength, size_t nSize);
};

} // END namespace

#endif
