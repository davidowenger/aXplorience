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
        NKrossWrapper::w->mNVisitorAppFragment->tRun(NKrossWrapper::w->mNAlpha00, (NParam)this);
    }

    virtual ~Fragment()
    {
    }

    virtual void setHasOptionsMenu(bool hasMenu)
    {
        NKrossWrapper::w->mNVisitorAppFragment->tRun(NKrossWrapper::w->mNBeta00, (NParam)this, (NParam)hasMenu);
    }

    //******************************************************************************************//
    //************************************* Fragment events ************************************//
    //* This passes the call back to the default implementation if the method is not overriden *//
    //******************************************************************************************//
    virtual void onAttach(Activity* vActivity)
    {
        NKrossWrapper::w->mNVisitorAppFragment->tRun(NKrossWrapper::w->mNAlpha01, (NParam)this, (NParam)vActivity);
    }

    virtual void onCreate(Bundle* vBundle)
    {
        NKrossWrapper::w->mNVisitorAppFragment->tRun(NKrossWrapper::w->mNBeta01, (NParam)this, (NParam)vBundle);
    }

    virtual View* onCreateView(LayoutInflater* vLayoutInflater, ViewGroup* vViewGroup, Bundle* vBundle)
    {
        //HINT: Default implementation returns null
        //return NKrossWrapper::w->mNVisitorAppFragment->tRun(NKrossWrapper::w->mNGamma01, (NParam)this, (NParam)vLayoutInflater, (NParam)vViewGroup, (NParam)vBundle);
        return nullptr;
    }

    virtual void onActivityCreated(Bundle* vBundle)
    {
        NKrossWrapper::w->mNVisitorAppFragment->tRun(NKrossWrapper::w->mNDelta01, (NParam)this, (NParam)vBundle);
    }

    virtual void onStart()
    {
        NKrossWrapper::w->mNVisitorAppFragment->tRun(NKrossWrapper::w->mNDzeta01, (NParam)this);
    }

    virtual void onResume()
    {
        NKrossWrapper::w->mNVisitorAppFragment->tRun(NKrossWrapper::w->mNEta01, (NParam)this);
    }

    virtual void onPause()
    {
        NKrossWrapper::w->mNVisitorAppFragment->tRun(NKrossWrapper::w->mNTheta01, (NParam)this);
    }

    virtual void onSaveInstanceState(Bundle* vBundle)
    {
        NKrossWrapper::w->mNVisitorAppFragment->tRun(NKrossWrapper::w->mNIota01, (NParam)this, (NParam)vBundle);
    }

    virtual void onStop()
    {
        NKrossWrapper::w->mNVisitorAppFragment->tRun(NKrossWrapper::w->mNKappa01, (NParam)this);
    }

    virtual void onDestroyView()
    {
        NKrossWrapper::w->mNVisitorAppFragment->tRun(NKrossWrapper::w->mNLambda01, (NParam)this);
    }

    virtual void onDestroy()
    {
        NKrossWrapper::w->mNVisitorAppFragment->tRun(NKrossWrapper::w->mNMu01, (NParam)this);
    }

    virtual void onDetach()
    {
        NKrossWrapper::w->mNVisitorAppFragment->tRun(NKrossWrapper::w->mNNu01, (NParam)this);
    }

    virtual void onCreateOptionsMenu(Menu* vMenu, MenuInflater* vMenuInflater)
    {
        NKrossWrapper::w->mNVisitorAppFragment->tRun(NKrossWrapper::w->mNXi01, (NParam)this, (NParam)vMenu, (NParam)vMenuInflater);
    }

    virtual void onPrepareOptionsMenu(Menu* vMenu)
    {
        NKrossWrapper::w->mNVisitorAppFragment->tRun(NKrossWrapper::w->mNOmicron01, (NParam)this, (NParam)vMenu);
    }

    virtual bool onOptionsItemSelected(MenuItem* vMenuItem)
    {
        //HINT: Default implementation returns false
        //return NKrossWrapper::w->mNVisitorAppFragment->tRun(NKrossWrapper::w->mNPi01, (NParam)this, (NParam)vMenuItem);
        return false;
    }

private:
    Fragment(NKrossFriend* vNKrossFriend)
    {
    }
};

} // End namespace

#endif

