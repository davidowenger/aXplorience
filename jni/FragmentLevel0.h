#ifndef __FragmentLevel0_H__
#define __FragmentLevel0_H__

namespace NSDEVICE
{

class FragmentLevel0 : public FragmentLevel
{
public:
    FragmentLevel0(Wrapper* vWrapper);
    virtual ~FragmentLevel0() override;

    virtual void init(nuint vcView, DBObject* vDBObject = nullptr) override;
};

} // End namespace

#endif
