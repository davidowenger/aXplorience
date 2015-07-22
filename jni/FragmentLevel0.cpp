#include "Common.h"

namespace NSDEVICE
{

FragmentLevel0::FragmentLevel0(Wrapper* vWrapper)
    : FragmentLevel(vWrapper)
{
}

FragmentLevel0::~FragmentLevel0()
{
    if (mMenu) {
        mMenu->removeItem(Wrapper::kViewAdd);
        mMenu->removeItem(Wrapper::kViewEdit);
        mMenu->removeItem(Wrapper::kViewDelete);
        mMenu->removeItem(Wrapper::kViewSave);
    }
}

void FragmentLevel0::init(nuint vcView, nuint vcDBObjectId)
{
    mcLevel = 0;
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
        vFragmentTransaction->commit();
        mIsAdded = true;
    }
    if (mFragmentLayout.mcPriority != 0 && mMenu) {
        w->maFragmentView[mFragmentLayout.mcView]->init(mFragmentLayout.mcView, mMenu, mcDBObjectId);
    }
    if (mFragmentLayout.mcPriority == 0 && mIsAdded) {
        w->mFragmentManager->popBackStack();
        mIsAdded = false;
    }
}

} // End namespace
