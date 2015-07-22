#ifndef __FragmentLevel1_H__
#define __FragmentLevel1_H__

namespace NSDEVICE
{

class FragmentLevel1 : public FragmentLevel
{
public:
    FragmentLevel1(Wrapper* vWrapper);
    virtual ~FragmentLevel1() override;

    virtual void init(nuint vcView, nuint vcDBObjectId = 1) override;
};

} // End namespace

#endif
