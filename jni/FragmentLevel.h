#ifndef __FragmentLevel_H__
#define __FragmentLevel_H__

namespace NSDEVICE
{

class FragmentLevel : public Fragment
{
public:
    FragmentLevel(Wrapper* vWrapper);
    virtual ~FragmentLevel();

    virtual void init(nuint vcView, nuint vcDBObjectId = 1) = 0;
    virtual void onCreate(Bundle* vBundle) override;
    virtual void onCreateOptionsMenu(Menu* menu, MenuInflater* inflater) override;
    virtual bool onOptionsItemSelected(MenuItem* item) override;

    Wrapper* w;
    FrameLayout* mFragmentView;
    Menu* mMenu;

    FragmentLayout mFragmentLayout;
    nuint mcView;
    nuint mcLevel;
    nint mcMaxLevel;
    nuint mcDBObjectId;
    bool mIsAdded;
};

} // End namespace

#endif
