#ifndef __OpUnitAnim_H__
#define __OpUnitAnim_H__

namespace NSDEVICE
{

class OpUnitAnim : public OpUnit
{
public:
    OpUnitAnim(Wrapper* const w);
    virtual ~OpUnitAnim() override;
    virtual void run() override;

    virtual NReturn visit(NAlpha00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;
    virtual NReturn visit(NBeta00* element, NParam a = 0, NParam b = 0, NParam c = 0, NParam d = 0, NParam e = 0) override;

    Wrapper* w;
    bool mIsARInitialized;
};

} // End namespace

#endif
