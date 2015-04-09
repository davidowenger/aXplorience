#include "Common.h"

namespace NSDEVICE
{

OpCallback::OpCallback(NReturn* vNReturn, bool* vDone)
    : mNReturn(vNReturn), mDone(vDone)
{
    *mDone = false;
}

OpCallback::~OpCallback()
{
    delete mNReturn;
    delete mDone;
}

Op::Op(NElement* vNElement, nlong a, nlong b, nlong c, nlong d, nlong e, OpCallback* vOpCallback)
	: mNElement(vNElement), mOpCallback(vOpCallback), a(a), b(b), c(c), d(d), e(e)
{
}

Op::~Op()
{
}

OpParam::OpParam(nlong a, nlong b, nlong c, nlong d, nlong e)
    : Op(nullptr, a, b, c, d, e, nullptr)
{
}

OpParam::~OpParam()
{
}

OpMessage::OpMessage(const String& vStringA, const String& vStringB, const String& vStringC, const String& vStringD, const String& vStringE, nlong b, nlong c, nlong d, nlong e)
    : Op(nullptr, 0, b, c, d, e, nullptr), mStringA(vStringA), mStringB(vStringB), mStringC(vStringC), mStringD(vStringD), mStringE(vStringE)
{
    a = (nlong)this;
}

OpMessage::~OpMessage()
{
}

OpMessageForResult::OpMessageForResult(const String& vStringA, const String& vStringB, const String& vStringC, const String& vStringD, const String& vStringE, nlong b, nlong c, nlong d, nlong e)
    : Op(nullptr, 0, b, c, d, e, nullptr), mStringA(vStringA), mStringB(vStringB), mStringC(vStringC), mStringD(vStringD), mStringE(vStringE)
{
    a = (nlong)this;
    mOpCallback = new OpCallback(new NReturn(), new bool());
}

OpMessageForResult::~OpMessageForResult()
{
    *mOpCallback->mDone = true;
}

} // End namespace
