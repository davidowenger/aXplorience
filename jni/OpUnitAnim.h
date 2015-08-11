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
};

} // End namespace

#endif
