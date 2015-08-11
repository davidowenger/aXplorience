#ifndef __Fragment_H__
#define __Fragment_H__

namespace NSDEVICE
{

class Fragment : public Object
{
friend NSNATIVE::NVisitorAppFragment;
friend NSNATIVE::NNoObject;

public:
    //*******************************************************************************************//
    //******************************************* Fragment **************************************//
    //*******************************************************************************************//
    Fragment()
    {
        NWrapper::w->mNVisitorAppFragment->tRun(NWrapper::w->mNAlpha00, (NParam)this);
    }

    virtual ~Fragment()
    {
    }

    virtual void setHasOptionsMenu(bool hasMenu)
    {
        NWrapper::w->mNVisitorAppFragment->tRun(NWrapper::w->mNBeta00, (NParam)this, (NParam)hasMenu);
    }

    //******************************************************************************************//
    //************************************* Fragment events ************************************//
    //* This passes the call back to the default implementation if the method is not overriden *//
    //******************************************************************************************//
    virtual void onAttach(Activity* vActivity)
    {
        NWrapper::w->mNVisitorAppFragment->tRun(NWrapper::w->mNAlpha01, (NParam)this, (NParam)vActivity);
    }

    virtual void onCreate(Bundle* vBundle)
    {
        NWrapper::w->mNVisitorAppFragment->tRun(NWrapper::w->mNBeta01, (NParam)this, (NParam)vBundle);
    }

    virtual View* onCreateView(LayoutInflater* vLayoutInflater, ViewGroup* vViewGroup, Bundle* vBundle)
    {
        //HINT: Default implementation returns null
        //return NWrapper::w->mNVisitorAppFragment->tRun(NWrapper::w->mNGamma01, (NParam)this, (NParam)vLayoutInflater, (NParam)vViewGroup, (NParam)vBundle);
        return nullptr;
    }

    virtual void onActivityCreated(Bundle* vBundle)
    {
        NWrapper::w->mNVisitorAppFragment->tRun(NWrapper::w->mNDelta01, (NParam)this, (NParam)vBundle);
    }

    virtual void onStart()
    {
        NWrapper::w->mNVisitorAppFragment->tRun(NWrapper::w->mNDzeta01, (NParam)this);
    }

    virtual void onResume()
    {
        NWrapper::w->mNVisitorAppFragment->tRun(NWrapper::w->mNEta01, (NParam)this);
    }

    virtual void onPause()
    {
        NWrapper::w->mNVisitorAppFragment->tRun(NWrapper::w->mNTheta01, (NParam)this);
    }

    virtual void onSaveInstanceState(Bundle* vBundle)
    {
        NWrapper::w->mNVisitorAppFragment->tRun(NWrapper::w->mNIota01, (NParam)this, (NParam)vBundle);
    }

    virtual void onStop()
    {
        NWrapper::w->mNVisitorAppFragment->tRun(NWrapper::w->mNKappa01, (NParam)this);
    }

    virtual void onDestroyView()
    {
        NWrapper::w->mNVisitorAppFragment->tRun(NWrapper::w->mNLambda01, (NParam)this);
    }

    virtual void onDestroy()
    {
        NWrapper::w->mNVisitorAppFragment->tRun(NWrapper::w->mNMu01, (NParam)this);
    }

    virtual void onDetach()
    {
        NWrapper::w->mNVisitorAppFragment->tRun(NWrapper::w->mNNu01, (NParam)this);
    }

    virtual void onCreateOptionsMenu(Menu* vMenu, MenuInflater* vMenuInflater)
    {
        NWrapper::w->mNVisitorAppFragment->tRun(NWrapper::w->mNXi01, (NParam)this, (NParam)vMenu, (NParam)vMenuInflater);
    }

    virtual void onPrepareOptionsMenu(Menu* vMenu)
    {
        NWrapper::w->mNVisitorAppFragment->tRun(NWrapper::w->mNOmicron01, (NParam)this, (NParam)vMenu);
    }

    virtual bool onOptionsItemSelected(MenuItem* vMenuItem)
    {
        //HINT: Default implementation returns false
        //return NWrapper::w->mNVisitorAppFragment->tRun(NWrapper::w->mNPi01, (NParam)this, (NParam)vMenuItem);
        return false;
    }

private:
    Fragment(NNoObject* vNNoObject)
    {
    }
};

} // End namespace

#endif

