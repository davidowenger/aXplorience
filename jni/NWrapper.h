#ifndef __NWRAPPER_H__
#define __NWRAPPER_H__

namespace NNameSpace
{

typedef struct NElementListType
{
	NElement* alpha;
	NElement* beta;
	NElement* gamma;
} NElementList;

class NWrapper
{
public :
	JNIEnv* env;
	NFrame* nFrame;
	jobject tFrame;
	NElementList* nElementList;
};

} // END namespace

#endif
