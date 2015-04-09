#ifndef __FragmentLevel0_H__
#define __FragmentLevel0_H__

namespace NSDEVICE
{

class FragmentLevel0 : public FragmentLevel
{
public:
    FragmentLevel0(Wrapper* vWrapper);
    virtual ~FragmentLevel0() override;

    virtual void init(nuint vcView, nuint vcDBObjectId = 1) override;
    virtual void onDetach() override;
    virtual View* onCreateView(LayoutInflater* inflater, ViewGroup* parentView, Bundle* vBundle) override;
};

} // End namespace

#endif
