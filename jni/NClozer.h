#ifndef __NCLOZER_H__
#define __NCLOZER_H__

namespace NNameSpace
{

class NClozer : public NFrame
{
public:
    NWrapper* w;
    long* maPNElement;
    jobject mbbNElement;

	NClozer(NWrapper* w);
   ~NClozer();

  	void initEnv(JNIEnv* env, jobject tFrame);
	jobject initElement(jobjectArray aTElement);
	jlong runLong(NElement* nElement);
	jobject runObject(NElement* nElement);
	jlong visitLong(NAlpha* alpha);
	jobject visitObject(NAlpha* alpha);
	jlong visitLong(NBeta* beta);
	jobject visitObject(NBeta* beta);
	jlong visitLong(NGamma* gamma);
	jobject visitObject(NGamma* gamma);

    jobject factoryDirectBuffer(void* pData, long nLength, size_t nSize);
};

} // END namespace

#endif
