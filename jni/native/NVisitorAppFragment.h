#ifndef __NVisitorAppFragement_H__
#define __NVisitorAppFragement_H__

namespace NSNATIVE
{

class NVisitorAppFragment : public NVisitor
{
public:
    NVisitorAppFragment(NWrapper* w)
        : NVisitor(w)
    {
    }

    virtual ~NVisitorAppFragment()
    {
    }

    //******************************************************************************************//
    //************************************* Fragment events ************************************//
    //* This passes the call back to the default implementation if the method is not overriden *//
    //******************************************************************************************//
    //void onAttach(Activity vActivity)
    NReturn visit(NAlpha01* element, NParam a, NParam b, NParam c, NParam d, NParam e)
    {
        NReturn vcRet = 0;

        if (b == -1 && c == 1) {
            vcRet = (NReturn)NWrapper::w->mNNoObject->pointer<Activity>();
        }
        if (b != -1) {
            ((Fragment*)a)->onAttach((Activity*)b);
        }
        return vcRet;
    }

    //void onCreate(Bundle vBundle)
    NReturn visit(NBeta01* element, NParam a, NParam b, NParam c, NParam d, NParam e)
    {
        NReturn vcRet = 0;

        if (b == -1 && c == 1) {
            vcRet = (NReturn)NWrapper::w->mNNoObject->pointer<Bundle>();
        }
        if (b != -1) {
            ((Fragment*)a)->onCreate((Bundle*)b);
        }
        return vcRet;
    }

    //View onCreateView(LayoutInflater inflater, ViewGroup parentView, Bundle vBundle)
    NReturn visit(NGamma01* element, NParam a, NParam b, NParam c, NParam d, NParam e)
    {
        NReturn vcRet = 0;

        if (b == -1 && c == 3) {
            vcRet = (NReturn)NWrapper::w->mNNoObject->pointer<LayoutInflater>();
        }
        if (b == -1 && c == 2) {
            vcRet = (NReturn)NWrapper::w->mNNoObject->pointer<ViewGroup>();
        }
        if (b == -1 && c == 1) {
            vcRet = (NReturn)NWrapper::w->mNNoObject->pointer<Bundle>();
        }
        if (b != -1) {
            vcRet = (NReturn)((Fragment*)a)->onCreateView((LayoutInflater*)b, (ViewGroup*)c, (Bundle*)d);
        }
        return vcRet;
    }

    //void onActivityCreated(Bundle vBundle)
    NReturn visit(NDelta01* element, NParam a, NParam b, NParam c, NParam d, NParam e)
    {
        NReturn vcRet = 0;

        if (b == -1 && c == 1) {
            vcRet = (NReturn)NWrapper::w->mNNoObject->pointer<Bundle>();
        }
        if (b != -1) {
            ((Fragment*)a)->onActivityCreated((Bundle*)b);
        }
        return vcRet;
    }

    //void onViewStateRestored(Bundle vBundle)
    NReturn visit(NEpsilon01* element, NParam a, NParam b, NParam c, NParam d, NParam e)
    {
        NReturn vcRet = 0;

        if (b == -1 && c == 1) {
            vcRet = (NReturn)NWrapper::w->mNNoObject->pointer<Bundle>();
        }
        if (b != -1) {
            ((Fragment*)a)->onViewStateRestored((Bundle*)b);
        }
        return vcRet;
    }

    //void onStart()
    NReturn visit(NDzeta01* element, NParam a, NParam b, NParam c, NParam d, NParam e)
    {
        ((Fragment*)a)->onStart();
        return 0;
    }

    //void onResume()
    NReturn visit(NEta01* element, NParam a, NParam b, NParam c, NParam d, NParam e)
    {
        ((Fragment*)a)->onResume();
        return 0;
    }

    //void onPause()
    NReturn visit(NTheta01* element, NParam a, NParam b, NParam c, NParam d, NParam e)
    {
        ((Fragment*)a)->onPause();
        return 0;
    }


    //void onSaveInstanceState(Bundle vBundle)
    NReturn visit(NIota01* element, NParam a, NParam b, NParam c, NParam d, NParam e)
    {
        NReturn vcRet = 0;

        if (b == -1 && c == 1) {
            vcRet = (NReturn)NWrapper::w->mNNoObject->pointer<Bundle>();
        }
        if (b != -1) {
            ((Fragment*)a)->onSaveInstanceState((Bundle*)b);
        }
        return vcRet;
    }

    //void onStop()
    NReturn visit(NKappa01* element, NParam a, NParam b, NParam c, NParam d, NParam e)
    {
        ((Fragment*)a)->onStop();
        return 0;
    }

    //void onDestroyView()
    NReturn visit(NLambda01* element, NParam a, NParam b, NParam c, NParam d, NParam e)
    {
        ((Fragment*)a)->onDestroyView();
        return 0;
    }

    //void onDestroy()
    NReturn visit(NMu01* element, NParam a, NParam b, NParam c, NParam d, NParam e)
    {
        ((Fragment*)a)->onDestroy();
        return 0;
    }

    //void onDetach()
    NReturn visit(NNu01* element, NParam a, NParam b, NParam c, NParam d, NParam e)
    {
        ((Fragment*)a)->onDetach();
        return 0;
    }

    //void onCreateOptionsMenu(Menu menu, MenuInflater inflater)
    NReturn visit(NXi01* element, NParam a, NParam b, NParam c, NParam d, NParam e)
    {
        NReturn vcRet = 0;

        if (b == -1 && c == 2) {
            vcRet = (NReturn)NWrapper::w->mNNoObject->pointer<Menu>();
        }
        if (b == -1 && c == 1) {
            vcRet = (NReturn)NWrapper::w->mNNoObject->pointer<MenuInflater>();
        }
        if (b != -1) {
            ((Fragment*)a)->onCreateOptionsMenu((Menu*)b, (MenuInflater*)c);
        }
        return vcRet;
    }

    //void onPrepareOptionsMenu(Menu menu)
    NReturn visit(NOmicron01* element, NParam a, NParam b, NParam c, NParam d, NParam e)
    {
        NReturn vcRet = 0;

        if (b == -1 && c == 1) {
            vcRet = (NReturn)NWrapper::w->mNNoObject->pointer<Menu>();
        }
        if (b != -1) {
            ((Fragment*)a)->onPrepareOptionsMenu((Menu*)b);
        }
        return vcRet;
    }

    //boolean onOptionsItemSelected(MenuItem item)
    NReturn visit(NPi01* element, NParam a, NParam b, NParam c, NParam d, NParam e)
    {
        NReturn vcRet = 0;

        if (b == -1 && c == 1) {
            vcRet = (NReturn)NWrapper::w->mNNoObject->pointer<MenuItem>();
        }
        if (b != -1) {
            vcRet = (NReturn)((Fragment*)a)->onOptionsItemSelected((MenuItem*)b);
        }
        return vcRet;
    }
};

} // END namespace

#endif
