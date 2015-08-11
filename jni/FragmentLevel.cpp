#include "Common.h"

namespace NSDEVICE
{

FragmentLevel::FragmentLevel(Wrapper* vWrapper)
    : w(vWrapper), mFragmentView(nullptr), mFragmentLayout(), mcView(0), mcLevel(0), mcMaxLevel(0), mcDBObjectId(0), mIsAdded(false)
{
    mFragmentView = new FrameLayout(w->mApplication);
    mFragmentView->setLayoutParams(new FrameLayout::LayoutParams(FrameLayout::LayoutParams::MATCH_PARENT, FrameLayout::LayoutParams::MATCH_PARENT));
    mFragmentView->setPadding(0,0,0,0);
}

FragmentLevel::~FragmentLevel()
{
    if (mFragmentView) {
        delete mFragmentView;
    }
}

void FragmentLevel::onCreate(Bundle* vBundle)
{
    setHasOptionsMenu(true);
    Fragment::onCreate(vBundle);
}

View* FragmentLevel::onCreateView(LayoutInflater* inflater, ViewGroup* parentView, Bundle* vBundle)
{
    return mFragmentView;
}

void FragmentLevel::onDetach()
{
    mIsAdded = false;
    mFragmentView->removeAllViews();

    if (mFragmentLayout.mcPriority != 0 && w->mcMaxLevel > 0 && w->mMenu) {
        --w->mcMaxLevel;
        w->mcView = w->maRootLayoutItem[mcView].maFragmentLayout[w->mcMaxLevel].mcView;
        w->mNActivity->sendOp(w->mOpUnitUIId, w->w->mNIota00, new OpParam(w->maRootLayoutItem[mcView].maFragmentLayout[w->mcMaxLevel].mcRootLayoutItem, mcDBObjectId));
    }
    Fragment::onDetach();
}

void FragmentLevel::onCreateOptionsMenu(Menu* menu, MenuInflater* inflater)
{
    w->mMenu = menu;
    w->maFragmentView[mFragmentLayout.mcView]->init(mFragmentLayout.mcView, nullptr);
    Fragment::onCreateOptionsMenu(menu, inflater);
}

bool FragmentLevel::onOptionsItemSelected(MenuItem* item)
{
    bool ret = false;

    if (w->mcMaxLevel == mcLevel) {
        ret = w->maFragmentView[mFragmentLayout.mcView]->onMenuItemSelected(item->getItemId());
    }
    return ret;
}

} // End namespace
