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
    Op(NElement* vNElement = nullptr, NLong a = 0, NLong b = 0, NLong c = 0, NLong d = 0, OpCallback* vOpCallback = nullptr);
    virtual ~Op();

    NElement* mNElement;
    OpCallback* mOpCallback;
    NLong a;
    NLong b;
    NLong c;
    NLong d;
};

class OpParam : public Op
{
public:
    OpParam(NLong a = 0, NLong b = 0, NLong c = 0, NLong d = 0);
    virtual ~OpParam() override;
};


class OpMessage : public Op
{
public:
    OpMessage(const String& vString);
    virtual ~OpMessage() override;

    String mString;
};


class OpMessageForResult : public Op
{
public:
    OpMessageForResult(const String& vString);
    virtual ~OpMessageForResult() override;

    String mString;
};

} // End namespace

#endif
