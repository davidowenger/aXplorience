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
    virtual void onDetach() override;
    virtual View* onCreateView(LayoutInflater* inflater, ViewGroup* parentView, Bundle* vBundle) override;
};

} // End namespace

#endif
