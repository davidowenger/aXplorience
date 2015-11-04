#ifndef __NKrossParam_H__
#define __NKrossParam_H__

namespace NSNATIVE
{

class NKrossParam
{
public:
    NKrossParam(const String& boxed);
    virtual ~NKrossParam();

    NParam n;
    NReturnObject mTString;
};

} // END namespace

#endif
