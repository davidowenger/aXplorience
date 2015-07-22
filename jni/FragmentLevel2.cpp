#include "Common.h"

namespace NSDEVICE
{

FragmentLevel2::FragmentLevel2(Wrapper* vWrapper)
    : FragmentLevel(vWrapper)
{
}

FragmentLevel2::~FragmentLevel2()
{
}

void FragmentLevel2::init(nuint vcView, nuint vcDBObjectId)
{
    mcLevel = 2;
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

} // End namespace