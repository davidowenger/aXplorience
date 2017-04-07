#ifndef __NVisitorAppActivity_H__
#define __NVisitorAppActivity_H__

namespace NSNATIVE
{

class NVisitorAppActivity : public NKrossVisitor
{
public:
    NVisitorAppActivity(NWrapper* w)
        : NKrossVisitor(w)
    {
    }

    virtual ~NVisitorAppActivity()
    {
    }

    NReturn visit(NAlpha00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
    {
        NReturn vcRet = 0;
        if (b == -1 && c == 1) vcRet = (NReturn)mNWrapper->mNKrossWrapper->mNKrossFriend->pointer<Bundle>();
        if (b != -1) {
            LOGE("onCreate");
            ((Activity*)a)->onCreate((Bundle*)b);
        }
        return vcRet;
    }

    NReturn visit(NBeta00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
    {
        LOGE("onRestart");
        ((Activity*)a)->onRestart();
        return 0;
    }

    NReturn visit(NGamma00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
    {
        LOGE("onStart");
        ((Activity*)a)->onStart();
        return 0;
    }

    NReturn visit(NDelta00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
    {
        LOGE("onResume");
        ((Activity*)a)->onResume();
        return 0;
    }

    NReturn visit(NEpsilon00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
    {
        LOGE("onPause");
        ((Activity*)a)->onPause();
        return 0;
    }

    NReturn visit(NDzeta00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
    {
        LOGE("onStop");
        ((Activity*)a)->onStop();
        return 0;
    }

    NReturn visit(NEta00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
    {
        LOGE("onDestroy");
        ((Activity*)a)->onDestroy();
        return 0;
    }

    //TODO: restore Android API
    NReturn visit(NTheta00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
    {
        ((Activity*)a)->onActivityResult((nint)b, (nint)c, (nint)d, (nint)e);
        return 0;
    }

    NReturn visit(NKhi00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
    {
        ((Activity*)a)->onBackPressed();
        return 0;
    }

    NReturn visit(NIota00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
    {
        NReturn vcRet = 0;
        if (b == -1 && c == 1) vcRet = (NReturn)mNWrapper->mNKrossWrapper->mNKrossFriend->pointer<Menu>();
        if (b != -1) vcRet = ((Activity*)a)->onCreateOptionsMenu((Menu*)b);
        return vcRet;
    }

    NReturn visit(NLambda00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
    {
        NReturn vcRet = 0;
        if (b == -1 && c == 1) vcRet = (NReturn)mNWrapper->mNKrossWrapper->mNKrossFriend->pointer<MenuItem>();
        if (b != -1) vcRet = ((Activity*)a)->onOptionsItemSelected((MenuItem*)b);
        return vcRet;
    }

    NReturn visit(NKappa00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
    {
        NReturn vcRet = 0;
        if (b == -1 && c == 1) vcRet = (NReturn)mNWrapper->mNKrossWrapper->mNKrossFriend->pointer<Menu>();
        if (b != -1) vcRet = ((Activity*)a)->onPrepareOptionsMenu((Menu*)b);
        return vcRet;
    }

    NReturn visit(NOmicron00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
    {
        ((Activity*)a)->onReceiveDiscoveryFinished();
        return 0;
    }

    NReturn visit(NPi00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
    {
        ((Activity*)a)->onReceiveDiscoveryStarted();
        return 0;
    }

    NReturn visit(NRho00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
    {
        NReturn vcRet = 0;
        if (b == -1 && c == 1) vcRet = (NReturn)mNWrapper->mNKrossWrapper->mNKrossFriend->pointer<BluetoothDevice>();
        if (b != -1) ((Activity*)a)->onReceiveFoundDevice((BluetoothDevice*)b);
        return vcRet;
    }

    NReturn visit(NSigma00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
    {
        ((Activity*)a)->onReceiveLocalName(mNWrapper->mNKrossWrapper->mNKrossSystem->tGetString(mNWrapper->mNKrossWrapper->mNKrossSystem->tRunObject((NParam)b)));
        return 0;
    }

    NReturn visit(NTau00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
    {
        ((Activity*)a)->onReceiveScanMode((nint)b, (nint)c);
        return 0;
    }

    NReturn visit(NUpsilon00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
    {
        ((Activity*)a)->onReceiveState((nint)b, (nint)c);
        return 0;
    }

    NReturn visit(NPhi00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
    {
        mNWrapper->mNKrossWrapper->mNKrossSystem->tAttachCurrentThread();
        ((Activity*)a)->handleMessage(b);
        return 0;
    }
};

} // END namespace

#endif
