#include "Common.h"

namespace NSDEVICE
{

FragmentLevel::FragmentLevel(Wrapper* vWrapper)
    : w(vWrapper), mFragmentView(nullptr), mMenu(nullptr), mFragmentLayout(), mcView(0), mcLevel(0), mcMaxLevel(0), mcDBObjectId(0), mIsAdded(false)
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

void FragmentLevel::onCreateOptionsMenu(Menu* menu, MenuInflater* inflater)
{
    mMenu = menu;
    w->maFragmentView[mFragmentLayout.mcView]->init(mFragmentLayout.mcView, mMenu, mcDBObjectId);
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
