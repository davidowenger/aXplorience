#include "Common.h"
#include "Theme.h"

namespace NSDEVICE
{

WidgetAR::WidgetAR(Wrapper* const w)
    : Widget(w), SurfaceHolder::Callback(), mcPadding((nint)(15*w->mcDensity))
{
    LinearLayout::LayoutParams vWidgetParams = LinearLayout::LayoutParams(0, LinearLayout::LayoutParams::MATCH_PARENT, 1);
    setLayoutParams(&vWidgetParams);
    setGravity(Gravity::TOP);
    setOrientation(LinearLayout::HORIZONTAL);
    setPadding(0, 0, 0, 0);
    setOnTouchListener(this);

    mSurfaceHolder = w->mSurfaceView->getHolder();
    mSurfaceHolder->addCallback(this);
    addView(w->mSurfaceView);
}

WidgetAR::~WidgetAR()
{
    if (w->mSurface) {
        delete w->mSurface;
    }
    delete mSurfaceHolder;
}

void WidgetAR::init()
{
}

void WidgetAR::onCreate()
{
    // Use renderer thread to bind resource callbacks
    LOGI("Creating AR");

    if (w->mcARState < 2) {
        w->mcARState = 2;
        w->mOpUnitAnim->sendOp(w->mOpUnitAnimId, w->mNWrapper->mNKrossWrapper->mNBeta00, new Op());
    }
    onResume();
}

void WidgetAR::onResume()
{
    LOGI("Resuming AR");
    w->mcARState = 3;
}

void WidgetAR::onPause()
{
    // Three is no "onDestroy" callback in the renderer thread, so unbind resources here
    LOGI("Pausing AR");

    if (w->mcARSurface) {
        w->mcARState = 4;
    } else {
        w->mcARState = 0;
    }
}

void WidgetAR::onDestroy()
{
    LOGI("Destroying AR");
    w->mcARState = 0;
}

void WidgetAR::surfaceChanged(SurfaceHolder* holder, int format, int width, int height)
{
    // This callback is called from the main Activity UI thread
    LOGI("surfaceChanged");
    w->mSurfaceWidth = width;
    w->mSurfaceHeight = height;
    w->mSurface = holder->getSurface();
    w->mcARSurface = 2;
}

void WidgetAR::surfaceCreated(SurfaceHolder* holder)
{
    // This callback is called from the main Activity UI thread
    LOGI("surfaceCreated");
    w->mcARSurface = 1;
}

void WidgetAR::surfaceDestroyed(SurfaceHolder* holder)
{
    // This callback is called from the main Activity UI thread
    LOGI("surfaceDestroyed");
    w->mcARSurface = 0;
    onDestroy();
}

//*******************************************************************************************//
//**************************************  OnTouchListener  **********************************//
//*******************************************************************************************//
bool WidgetAR::onTouch(View* vView, MotionEvent* event)
{
    if (w->mTouchState == 3) {
        w->mTouchState = 0;
    }
    return true;
}

} // End namespace

//private void initFBO(int width, int height) {
//  hFBOTex = new int[1];
//  GLES20.glGenTextures(1,hFBOTex,0);
//  GLES20.glBindTexture(GLES20.GL_TEXTURE_2D, hFBOTex[0]);
//  GLES20.glTexImage2D(GLES20.GL_TEXTURE_2D,0,GLES20.GL_RGBA,width,height,0,GLES20.GL_RGBA,GLES20.GL_UNSIGNED_BYTE,null);
//  GLES20.glTexParameteri(GLES20.GL_TEXTURE_2D, GLES20.GL_TEXTURE_WRAP_S, GLES20.GL_CLAMP_TO_EDGE);
//  GLES20.glTexParameteri(GLES20.GL_TEXTURE_2D, GLES20.GL_TEXTURE_WRAP_T, GLES20.GL_CLAMP_TO_EDGE);
//  GLES20.glTexParameteri(GLES20.GL_TEXTURE_2D, GLES20.GL_TEXTURE_MIN_FILTER, GLES20.GL_NEAREST);
//  GLES20.glTexParameteri(GLES20.GL_TEXTURE_2D, GLES20.GL_TEXTURE_MAG_FILTER, GLES20.GL_NEAREST);
//
//  hFBO = new int[1];
//  GLES20.glGenFramebuffers(1,hFBO,0);
//  GLES20.glBindFramebuffer(GLES20.GL_FRAMEBUFFER,hFBO[0]);
//  GLES20.glFramebufferTexture2D(GLES20.GL_FRAMEBUFFER,GLES20.GL_COLOR_ATTACHMENT0,GLES20.GL_TEXTURE_2D,hFBOTex[0],0);
//
//  int[] depth;
//  depth = new int[1];
//  GLES20.glGenRenderbuffers(1,depth,0);
//  GLES20.glBindRenderbuffer(GLES20.GL_RENDERBUFFER,depth[0]);
//  GLES20.glRenderbufferStorage(GLES20.GL_RENDERBUFFER,GLES20.GL_DEPTH_COMPONENT16,width,height);
//  GLES20.glFramebufferRenderbuffer(GLES20.GL_FRAMEBUFFER,GLES20.GL_DEPTH_ATTACHMENT,GLES20.GL_RENDERBUFFER,depth[0]);
//
//  if ( GLES20.glGetError() != GLES20.GL_NO_ERROR) Log.i("mr","initFBO - rbo");
//
//  if(GLES20.glCheckFramebufferStatus(GLES20.GL_FRAMEBUFFER) != GLES20.GL_FRAMEBUFFER_COMPLETE)
//    Log.e("mr","initFBO");
//}
//
//public void onDrawFrame ( GL10 unused ) {
//  GLES20.glBindFramebuffer(GLES20.GL_FRAMEBUFFER,hFBO[0]);
//  // draw somethings to FBO
//
//  GLES20.glFlush();
//  // read a block of pixels from back buffer in double-buffered configurations
//  ByteBuffer buf = ByteBuffer.allocateDirect(width*height*4);
//  GLES20.glReadPixels(0, 0, width, height, GLES20.GL_RGBA, GLES20.GL_UNSIGNED_BYTE, buf);
//
//  GLES20.glBindFramebuffer(GLES20.GL_FRAMEBUFFER,0);
//  // draw somethings to frame(back) buffer
//  // you can use hFBOTex[0] as a texture
//}
