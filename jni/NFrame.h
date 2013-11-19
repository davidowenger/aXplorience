#ifndef __NFRAME_H__
#define __NFRAME_H__

namespace NNameSpace
{

class NFrame : public NVisitor
{
public:
	NFrame();
   ~NFrame();

    virtual void initEnv(JNIEnv* env, jobject tFrame) = 0;
	virtual jobject initElement(jobjectArray aTElement) = 0;
	virtual jlong runLong(NElement* nElement) = 0;
	virtual jobject runObject(NElement* nElement) = 0;
};

} // END namespace

#endif
