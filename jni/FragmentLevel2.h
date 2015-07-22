#ifndef __FragmentLevel2_H__
#define __FragmentLevel2_H__

namespace NSDEVICE
{

class FragmentLevel2 : public FragmentLevel
{
public:
    FragmentLevel2(Wrapper* vWrapper);
    virtual ~FragmentLevel2() override;

    virtual void init(nuint vcView, nuint vcDBObjectId = 1) override;
};

} // End namespace

#endif
