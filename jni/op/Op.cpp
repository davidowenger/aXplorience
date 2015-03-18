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

Op::Op(NElement* vNElement, NLong a, NLong b, NLong c, NLong d, OpCallback* vOpCallback)
	: mNElement(vNElement), mOpCallback(vOpCallback), a(a), b(b), c(c), d(d)
{
}

Op::~Op()
{
    if (mOpCallback) {
        *mOpCallback->mDone = true;
    }
}

OpParam::OpParam(NLong a, NLong b, NLong c, NLong d)
    : Op(nullptr, a, b, c, d, nullptr)
{
}

OpParam::~OpParam()
{
}

OpMessage::OpMessage(const String& vString)
    : Op(nullptr, 0, 0, 0, 0, nullptr), mString(vString)
{
    a = (NLong)this;
}

OpMessage::~OpMessage()
{
}

OpMessageForResult::OpMessageForResult(const String& vString)
    : Op(nullptr, 0, 0, 0, 0, nullptr), mString(vString)
{
    a = (NLong)this;
    mOpCallback = new OpCallback(new NReturn(), new bool());
}

OpMessageForResult::~OpMessageForResult()
{
    *mOpCallback->mDone = true;
}

} // End namespace
