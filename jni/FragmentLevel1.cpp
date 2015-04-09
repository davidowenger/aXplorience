#include "Common.h"

namespace NSDEVICE
{

FragmentLevel1::FragmentLevel1(Wrapper* vWrapper)
    : FragmentLevel(vWrapper)
{
}

FragmentLevel1::~FragmentLevel1()
{
}

void FragmentLevel1::init(nuint vcView, nuint vcDBObjectId)
{
    mcLevel = 1;
    mcView = vcView;
    mFragmentLayout = w->maRootLayoutItem[mcView].maFragmentLayout[mcLevel];
    mcDBObjectId = vcDBObjectId;

    if (mFragmentLayout.mcPriority != 0) {
        w->mcMaxLevel = w->maRootLayoutItem[mcView].mcMaxLevel;
        w->mcView = w->maRootLayoutItem[mcView].maFragmentLayout[w->mcMaxLevel].mcView;

        mFragmentView->removeAllViews();
        mFragmentView->addView(w->maFragmentView[mFragmentLayout.mcView]);
    }
    if (mFragmentLayout.mcPriority != 0 && !mIsAdded) {
        FragmentTransaction* vFragmentTransaction = w->mFragmentManager->beginTransaction();
        vFragmentTransaction->add(w->mRootLayoutId, this);
        vFragmentTransaction->addToBackStack();
        vFragmentTransaction->commit();
        mIsAdded = true;
    }
    if (mFragmentLayout.mcPriority == 0 && mIsAdded) {
        w->mFragmentManager->popBackStack();
        mIsAdded = false;
    }
    if (mFragmentLayout.mcPriority != 0 && mMenu) {
        w->maFragmentView[mFragmentLayout.mcView]->init(mFragmentLayout.mcView, mMenu, mcDBObjectId);
    }
}

View* FragmentLevel1::onCreateView(LayoutInflater* inflater, ViewGroup* parentView, Bundle* vBundle)
{
    return mFragmentView;
}

void FragmentLevel1::onDetach()
{
    if (mFragmentLayout.mcPriority != 0) {
        w->mcMaxLevel--;
        w->mcView = w->maRootLayoutItem[mcView].maFragmentLayout[w->mcMaxLevel].mcView;
        w->maFragmentView[w->mcView]->init(w->mcView, mMenu, mcDBObjectId);
    }
    mFragmentView->removeAllViews();
    mIsAdded = false;
    Fragment::onDetach();
    Fragment::onDetach();
}

} // End namespace
