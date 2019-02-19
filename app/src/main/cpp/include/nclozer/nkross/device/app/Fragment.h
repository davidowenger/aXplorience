#ifndef __Fragment_H__
#define __Fragment_H__

namespace NSDEVICE
{

class Fragment : public Object
{
friend NSNATIVE::NVisitorAppFragment;
friend NSNATIVE::NKrossFriend;

public:
    //*******************************************************************************************//
    //******************************************* Fragment **************************************//
    //*******************************************************************************************//
    Fragment()
    {
        NSNKROSS::w->mNVisitorAppFragment->tRun(NSNKROSS::w->mNAlpha00, (NParam)this);
    }

    virtual ~Fragment()
    {
    }

    virtual void setHasOptionsMenu(bool hasMenu)
    {
        NSNKROSS::w->mNVisitorAppFragment->tRun(NSNKROSS::w->mNBeta00, (NParam)this, (NParam)hasMenu);
    }

    //******************************************************************************************//
    //************************************* Fragment events ************************************//
    //* This passes the call back to the default implementation if the method is not overriden *//
    //******************************************************************************************//
    virtual void onAttach(Activity* vActivity)
    {
        NSNKROSS::w->mNVisitorAppFragment->tRun(NSNKROSS::w->mNAlpha01, (NParam)this, (NParam)vActivity);
    }

    virtual void onCreate(Bundle* vBundle)
    {
        NSNKROSS::w->mNVisitorAppFragment->tRun(NSNKROSS::w->mNBeta01, (NParam)this, (NParam)vBundle);
    }

    virtual View* onCreateView(LayoutInflater* vLayoutInflater, ViewGroup* vViewGroup, Bundle* vBundle)
    {
        //HINT: Default implementation returns null
        //return NSNKROSS::w->mNVisitorAppFragment->tRun(NSNKROSS::w->mNGamma01, (NParam)this, (NParam)vLayoutInflater, (NParam)vViewGroup, (NParam)vBundle);
        return nullptr;
    }

    virtual void onActivityCreated(Bundle* vBundle)
    {
        NSNKROSS::w->mNVisitorAppFragment->tRun(NSNKROSS::w->mNDelta01, (NParam)this, (NParam)vBundle);
    }

    virtual void onStart()
    {
        NSNKROSS::w->mNVisitorAppFragment->tRun(NSNKROSS::w->mNDzeta01, (NParam)this);
    }

    virtual void onResume()
    {
        NSNKROSS::w->mNVisitorAppFragment->tRun(NSNKROSS::w->mNEta01, (NParam)this);
    }

    virtual void onPause()
    {
        NSNKROSS::w->mNVisitorAppFragment->tRun(NSNKROSS::w->mNTheta01, (NParam)this);
    }

    virtual void onSaveInstanceState(Bundle* vBundle)
    {
        NSNKROSS::w->mNVisitorAppFragment->tRun(NSNKROSS::w->mNIota01, (NParam)this, (NParam)vBundle);
    }

    virtual void onStop()
    {
        NSNKROSS::w->mNVisitorAppFragment->tRun(NSNKROSS::w->mNKappa01, (NParam)this);
    }

    virtual void onDestroyView()
    {
        NSNKROSS::w->mNVisitorAppFragment->tRun(NSNKROSS::w->mNLambda01, (NParam)this);
    }

    virtual void onDestroy()
    {
        NSNKROSS::w->mNVisitorAppFragment->tRun(NSNKROSS::w->mNMu01, (NParam)this);
    }

    virtual void onDetach()
    {
        NSNKROSS::w->mNVisitorAppFragment->tRun(NSNKROSS::w->mNNu01, (NParam)this);
    }

    virtual void onCreateOptionsMenu(Menu* vMenu, MenuInflater* vMenuInflater)
    {
        NSNKROSS::w->mNVisitorAppFragment->tRun(NSNKROSS::w->mNXi01, (NParam)this, (NParam)vMenu, (NParam)vMenuInflater);
    }

    virtual void onPrepareOptionsMenu(Menu* vMenu)
    {
        NSNKROSS::w->mNVisitorAppFragment->tRun(NSNKROSS::w->mNOmicron01, (NParam)this, (NParam)vMenu);
    }

    virtual bool onOptionsItemSelected(MenuItem* vMenuItem)
    {
        //HINT: Default implementation returns false
        //return NSNKROSS::w->mNVisitorAppFragment->tRun(NSNKROSS::w->mNPi01, (NParam)this, (NParam)vMenuItem);
        return false;
    }

private:
    Fragment(NKrossFriend* vNKrossFriend)
    {
    }
};

} // End namespace

#endif

