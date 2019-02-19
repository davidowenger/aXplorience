#ifndef __FragmentLevel_H__
#define __FragmentLevel_H__

namespace NSDEVICE
{

class FragmentLevel : public Fragment
{
public:
    FragmentLevel(Wrapper* vWrapper);
    virtual ~FragmentLevel();

    virtual void init(nuint vcView, DBObject* vDBObject = nullptr) = 0;
    virtual void onCreate(Bundle* vBundle) override;
    virtual View* onCreateView(LayoutInflater* inflater, ViewGroup* parentView, Bundle* vBundle) override;
    virtual void onDetach() override;
    virtual void onCreateOptionsMenu(Menu* menu, MenuInflater* inflater) override;
    virtual bool onOptionsItemSelected(MenuItem* item) override;

    Wrapper* w;
    FrameLayout* mFragmentView;

    FragmentLayout mFragmentLayout;
    nuint mcView;
    nuint mcLevel;
    nint mcMaxLevel;
    nuint mcDBObjectId;
    bool mIsAdded;
};

} // End namespace

#endif
