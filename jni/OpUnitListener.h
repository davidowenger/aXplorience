#ifndef __OpUnitListener_H__
#define __OpUnitListener_H__

namespace NSDEVICE
{

class OpUnitListener : public OpUnit
{
public:
	OpUnitListener(Wrapper* w, OpUnit* mOpUnit, InputStream* vInputStream);
   ~OpUnitListener();

    virtual void run() override;
    virtual void cancel() override;

    nint mOpUnitId;
    nint mOpUnitIdUnique;
    nint mOpUnitCoreId;
    InputStream* mInputStream;
    String mBuffer;
};

} // End namespace

#endif
