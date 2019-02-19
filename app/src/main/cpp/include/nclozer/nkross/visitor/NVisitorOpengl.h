#ifndef __NVisitorOpengl_H__
#define __NVisitorOpengl_H__

namespace NSNATIVE
{

class NVisitorOpengl : public NKrossVisitor
{
public:
    NVisitorOpengl(NWrapper* w)
        : NKrossVisitor(w)
    {
    }

   ~NVisitorOpengl()
    {
    }

    //*******************************************************************************************
    //***************************** EGLWindowSurfaceFactory *************************************
    //*******************************************************************************************
    // EGLSurface* createWindowSurface(GL10* gll, EGLDisplay* display, EGLConfig* config, Object* nativeWindow)
    NReturn visit(NDelta00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
    {
        return (NReturn)((GLSurfaceView::EGLWindowSurfaceFactory*)a)->createWindowSurface(nullptr, nullptr, nullptr, nullptr);
    }

    // void destroySurface(GL10* gll, EGLDisplay* display, EGLSurface* surface)
    NReturn visit(NEpsilon00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
    {
        NReturn vcRet = 0;
        if (a == 0 && b == 1) vcRet = (NReturn)nullptr;
        if (a != 0) ((GLSurfaceView::EGLWindowSurfaceFactory*)a)->destroySurface(nullptr, nullptr, nullptr);
        return vcRet;
    }

    //*******************************************************************************************
    //***************************************** Renderer ****************************************
    //*******************************************************************************************
    // void onDrawFrame(GL10 gl)
    NReturn visit(NAlpha00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
    {
        ((GLSurfaceView::Renderer*)a)->onDrawFrame(nullptr);
        return 0;
    }

    // void onSurfaceChanged(GL10 gl, int width, int height)
    NReturn visit(NBeta00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
    {
        ((GLSurfaceView::Renderer*)a)->onSurfaceChanged(nullptr, c, d);
        return 0;
    }

    // void onSurfaceCreated(GL10 gl, EGLConfig config)
    NReturn visit(NGamma00* element, NParam a, NParam b, NParam c, NParam d, NParam e)
    {
        ((GLSurfaceView::Renderer*)a)->onSurfaceCreated(nullptr, nullptr);
        return 0;
    }
};

} // END namespace

#endif
