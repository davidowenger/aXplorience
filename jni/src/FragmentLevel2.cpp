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

void FragmentLevel2::init(nuint vcView, DBObject* vDBObject)
{
    mcLevel = 2;
    mcView = vcView;
    mFragmentLayout = w->maRootLayoutItem[mcView].maFragmentLayout[mcLevel];
    mcDBObjectId = ( vDBObject ? vDBObject->mId : 0 );

    if (mFragmentLayout.mcPriority != 0) {
        w->mcMaxLevel = w->maRootLayoutItem[mcView].mcMaxLevel;
        w->mcView = w->maRootLayoutItem[mcView].maFragmentLayout[w->mcMaxLevel].mcView;

        mFragmentView->removeAllViews();
        mFragmentView->addView(w->maFragmentView[mFragmentLayout.mcView]);
    }
    if (mFragmentLayout.mcPriority != 0 && !mIsAdded) {
        mIsAdded = true;
        FragmentTransaction* vFragmentTransaction = w->mFragmentManager->beginTransaction();
        vFragmentTransaction->add(w->mRootLayoutId, this);
        vFragmentTransaction->addToBackStack();
        vFragmentTransaction->commit();
        delete vFragmentTransaction;
    }
    if (mFragmentLayout.mcPriority != 0) {
        w->maFragmentView[mFragmentLayout.mcView]->init(mFragmentLayout.mcView, vDBObject);
    }
    if (mFragmentLayout.mcPriority == 0 && mIsAdded) {
        mIsAdded = false;
        w->mFragmentManager->popBackStack();
    }
}

} // End namespace
