#ifndef __Op_H__
#define __Op_H__

namespace NSDEVICE
{

class OpCallback
{
public:
    OpCallback(NReturn* vNReturn = nullptr, bool* vDone = nullptr);
    virtual ~OpCallback();

    NReturn* mNReturn;
    bool* mDone;
};

class Op
{
public:
    Op(NElement* vNElement = nullptr, nlong a = 0, nlong b = 0, nlong c = 0, nlong d = 0, nlong e = 0, OpCallback* vOpCallback = nullptr);
    virtual ~Op();

    NElement* mNElement;
    OpCallback* mOpCallback;
    nlong a;
    nlong b;
    nlong c;
    nlong d;
    nlong e;
};

class OpParam : public Op
{
public:
    OpParam(nlong a = 0, nlong b = 0, nlong c = 0, nlong d = 0, nlong e = 0);
    virtual ~OpParam() override;
};

class OpMessage : public Op
{
public:
    OpMessage(const String& vStringA = "", const String& vStringB = "", const String& vStringC = "", const String& vStringD = "", const String& vStringE = "", nlong b = 0, nlong c = 0, nlong d = 0, nlong e = 0);
    virtual ~OpMessage() override;

    String mStringA;
    String mStringB;
    String mStringC;
    String mStringD;
    String mStringE;
};

class OpParamForResult : public Op
{
public:
    OpParamForResult(nlong a = 0, nlong b = 0, nlong c = 0, nlong d = 0, nlong e = 0);
    virtual ~OpParamForResult() override;
};

class OpMessageForResult : public Op
{
public:
    OpMessageForResult(const String& vStringA = "", const String& vStringB = "", const String& vStringC = "", const String& vStringD = "", const String& vStringE = "", nlong b = 0, nlong c = 0, nlong d = 0, nlong e = 0);
    virtual ~OpMessageForResult() override;

    String mStringA;
    String mStringB;
    String mStringC;
    String mStringD;
    String mStringE;
};

} // End namespace

#endif
